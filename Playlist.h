#pragma once
#include <string>
#include <map>
#include <Windows.h>
#include <vector>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

class Playlist {
private:
    struct Sonido {
        string ruta;
        string alias;
        bool reproduciendo;
        float volumen;
    };

    map<string, Sonido> sonidos;
    int aliasCounter;
    float volumenMaestro;

    void aplicarVolumen(const Sonido& s);

public:
    Playlist();
    ~Playlist();

    // === Gestión de sonidos ===
    bool agregar(const string& nombre, const string& ruta);
    void agregarLista(const vector<pair<string, string>>& items);
    bool existe(const string& nombre) const;
    void eliminar(const string& nombre);
    void cerrarTodos();

    // === Reproducción ===
    void reproducir(const string& nombre, bool loop = false);
    void pausar(const string& nombre);
    void continuar(const string& nombre);
    void detener(const string& nombre);
    void detenerTodos();

    // === Volumen ===
    void setVolumen(const string& nombre, float vol01);
    float getVolumen(const string& nombre) const;
    void setVolumenMaestro(float vol01);
    float getVolumenMaestro() const;

    // === Información ===
    bool estaReproduciendo(const string& nombre) const;
    string getRuta(const string& nombre) const;
};
