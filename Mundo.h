#pragma once

#include "Fondo.h"

#include "Jugador.h"

#include "PreguntaService.h"

#include "DialogoService.h"



using namespace System;

using namespace System::Drawing;



class Mundo {

protected:

    int anchoPanel;

    int altoPanel;

    Fondo* fondo;



    // Personaje principal (comun a todos los modos)

    Jugador* jugador;



    // Gestores (comunes a todos los modos)

    PreguntaService* gestorPreguntas;

    DialogoService* gestorDialogos;



    // Estado del juego (comun a todos los modos)

    bool juegoEnPausa;

    int vidas;



public:

    Mundo(int ancho, int alto, int vidasIniciales);

    virtual ~Mundo();



    void cargarFondo(char* ruta);

    virtual void dibujarTodo(Graphics^ canvas) = 0;



    int getAnchoPanel();

    int getAltoPanel();

    int getVelocidad() { return 20; } // Velocidad comun para todos los modos

    Fondo* getFondo();



    // Metodos de Hamp (comunes a todos los modos)

    void cargarSpriteJugador(char* ruta, int filas, int columnas);

    void moverJugador(Direccion tecla);

    Jugador* getJugador();



    // Estado del juego (comun a todos los modos)

    bool estaEnPausa() { return juegoEnPausa; }

    void setPausa(bool pausa) { juegoEnPausa = pausa; }

    int getVidas() { return vidas; }

    void setVidas(int v) { vidas = v; }

};