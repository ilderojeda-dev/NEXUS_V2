#include "Playlist.h"
#include <algorithm>

Playlist::Playlist() {
    aliasCounter = 0;
    volumenMaestro = 1.0f;
}

Playlist::~Playlist() {
    detenerTodos();
    cerrarTodos();
}

void Playlist::aplicarVolumen(const Sonido& s) {
    int nivel = static_cast<int>(max(0.f, min(1.f, s.volumen * volumenMaestro)) * 1000.f);
    string cmd = "setaudio " + s.alias + " volume to " + to_string(nivel);
    mciSendStringA(cmd.c_str(), nullptr, 0, nullptr);
}

bool Playlist::agregar(const string& nombre, const string& ruta) {
    if (sonidos.count(nombre)) return false;

    Sonido s;
    s.ruta = ruta;
    s.alias = "snd" + to_string(++aliasCounter);
    s.reproduciendo = false;
    s.volumen = 1.0f;
    sonidos[nombre] = s;
    return true;
}

void Playlist::agregarLista(const vector<pair<string, string>>& items) {
    for (const auto& p : items)
        agregar(p.first, p.second);
}

bool Playlist::existe(const string& nombre) const {
    return sonidos.count(nombre) > 0;
}

void Playlist::eliminar(const string& nombre) {
    if (!existe(nombre)) return;
    string cmd = "close " + sonidos.at(nombre).alias;
    mciSendStringA(cmd.c_str(), nullptr, 0, nullptr);
    sonidos.erase(nombre);
}

void Playlist::cerrarTodos() {
    for (auto& kv : sonidos) {
        string cmd = "close " + kv.second.alias;
        mciSendStringA(cmd.c_str(), nullptr, 0, nullptr);
    }
    sonidos.clear();
}

void Playlist::reproducir(const string& nombre, bool loop) {
    if (!existe(nombre)) return;

    Sonido& s = sonidos[nombre];
    string cmd = "open \"" + s.ruta + "\" type mpegvideo alias " + s.alias;
    mciSendStringA(cmd.c_str(), nullptr, 0, nullptr);

    aplicarVolumen(s);

    cmd = "play " + s.alias;
    if (loop) cmd += " repeat";
    mciSendStringA(cmd.c_str(), nullptr, 0, nullptr);

    s.reproduciendo = true;
}

void Playlist::pausar(const string& nombre) {
    if (!existe(nombre)) return;
    string cmd = "pause " + sonidos[nombre].alias;
    mciSendStringA(cmd.c_str(), nullptr, 0, nullptr);
    sonidos[nombre].reproduciendo = false;
}

void Playlist::continuar(const string& nombre) {
    if (!existe(nombre)) return;
    string cmd = "resume " + sonidos[nombre].alias;
    mciSendStringA(cmd.c_str(), nullptr, 0, nullptr);
    sonidos[nombre].reproduciendo = true;
}

void Playlist::detener(const string& nombre) {
    if (!existe(nombre)) return;
    string cmd = "stop " + sonidos[nombre].alias;
    mciSendStringA(cmd.c_str(), nullptr, 0, nullptr);
    sonidos[nombre].reproduciendo = false;
}

void Playlist::detenerTodos() {
    for (auto& kv : sonidos)
        detener(kv.first);
}

void Playlist::setVolumen(const string& nombre, float vol01) {
    if (!existe(nombre)) return;
    Sonido& s = sonidos[nombre];
    s.volumen = max(0.f, min(1.f, vol01));
    aplicarVolumen(s);
}

float Playlist::getVolumen(const string& nombre) const {
    if (!existe(nombre)) return 0.f;
    return sonidos.at(nombre).volumen;
}

void Playlist::setVolumenMaestro(float vol01) {
    volumenMaestro = max(0.f, min(1.f, vol01));
    for (auto& kv : sonidos)
        aplicarVolumen(kv.second);
}

float Playlist::getVolumenMaestro() const {
    return volumenMaestro;
}

bool Playlist::estaReproduciendo(const string& nombre) const {
    if (!existe(nombre)) return false;
    return sonidos.at(nombre).reproduciendo;
}

string Playlist::getRuta(const string& nombre) const {
    if (!existe(nombre)) return "";
    return sonidos.at(nombre).ruta;
}
