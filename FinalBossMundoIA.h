// FinalBossMundoIA.h
#pragma once
#include "Sprite.h"
#include <cmath> 

using namespace System;
using namespace System::Drawing;

class FinalBossMundoIA : public Sprite
{
private:
    int vidaActual;
    int vidaMaxima;
    bool enFuria;
    float anguloFlotacion;
    int cooldownAtaque;

public:
    FinalBossMundoIA(int x, int y, int dificultad);
    ~FinalBossMundoIA();

    void mover(Direccion direccion, int posInicial, int PosFinal, int velocidad) override;
    void dibujar(Graphics^ canvas) override;
    void recibirDano(int cantidad);
    bool estaDerrotado();

    int getVida() { return vidaActual; }
    bool getEnFuria() { return enFuria; }
};