#pragma once
#include "Sprite.h"


using namespace System::Drawing;

class SintIA : public Sprite
{
private:

public:
    SintIA();
    SintIA(int x, int y);
    ~SintIA();


    void mover(Direccion direccion, int posInicial, int PosFinal) override;
   
    void dibujar(Graphics^ canvas) override;
 

    void setIndiceX(int idx) { indiceX = idx; }
    void setIndiceY(int idy) { indiceY = idy; }
    int getIndiceX() { return indiceX; }
    int getColumnas() { return columnas; }
    void setEscala(float e) { escala = e; }
};