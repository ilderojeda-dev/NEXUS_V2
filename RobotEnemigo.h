// RobotEnemigo.h
#pragma once
#include "Sprite.h"

using namespace System::Drawing;

class RobotEnemigo : public Sprite
{
public:
    RobotEnemigo();
    RobotEnemigo(int x, int y);
    ~RobotEnemigo();

    void mover(Direccion direccion, int posInicial, int PosFinal, int velocidad) override;
    void dibujar(Graphics^ canvas) override;

    void setIndiceX(int idx) { indiceX = idx; }
    void setIndiceY(int idy) { indiceY = idy; }
    int getIndiceX() { return indiceX; }
    int getColumnas() { return columnas; }
    void setEscala(float e) { escala = e; }
};
