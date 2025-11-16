#pragma once
#include "Sprite.h"
using namespace System::Drawing;

class Jugador : public Sprite
{
private:
    int vida;
    int velocidad;
public:
    Jugador();
    Jugador(int x, int y);
    ~Jugador();

    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
    void dibujar(Graphics^ canvas) override;
	int getVelocidad() { return velocidad; }
    void setVelocidad(int vel) { velocidad = vel; }

};

