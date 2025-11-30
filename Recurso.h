#pragma once
#include "Sprite.h"

class Recurso : public Sprite {
protected:
    bool activo;

public:
    Recurso();
    Recurso(int x, int y);
    ~Recurso();

    virtual void mover(Direccion tecla, int limiteAncho, int limiteAlto) = 0;

    virtual void dibujar(Graphics^ canvas) override = 0;

    bool getActivo();
    void setActivo(bool activo);

};
