#include "Mundo.h"

Mundo::Mundo(int ancho, int alto, int vidasIniciales) {
    anchoPanel = ancho;
    altoPanel = alto;
    fondo = new Fondo();

    // Inicializar como nullptr - las clases hijas son responsables de crear Hamp
    jugador = nullptr;

    // Inicializar gestores
    gestorPreguntas = new PreguntaService();
    gestorDialogos = new DialogoService();

    // Estado inicial
    juegoEnPausa = false;
    vidas = vidasIniciales;
}

Mundo::~Mundo() {
    if (fondo != nullptr) {
        delete fondo;
    }
    if (jugador != nullptr) {
        delete jugador;
    }
    if (gestorPreguntas != nullptr) {
        delete gestorPreguntas;
    }
    if (gestorDialogos != nullptr) {
        delete gestorDialogos;
    }
}

void Mundo::cargarFondo(char* ruta) {
    fondo->cargarImagen(ruta, anchoPanel, altoPanel);
}

int Mundo::getAnchoPanel() {
    return anchoPanel;
}

int Mundo::getAltoPanel() {
    return altoPanel;
}


Fondo* Mundo::getFondo() {
    return fondo;
}

// Metodos de Hamp
void Mundo::cargarSpriteJugador(char* ruta, int filas, int columnas) {
    jugador->cargarImagen(ruta, filas, columnas);
}

void Mundo::moverJugador(Direccion tecla) {
    //jugador->mover(tecla, anchoPanel, altoPanel, muros);
}

Jugador* Mundo::getJugador() {
    return jugador;
}
