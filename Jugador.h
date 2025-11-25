#pragma once
#include "Sprite.h"
using namespace System::Drawing;

class Jugador : public Sprite
{
private:
    int vida;
    int velocidad;

    // Variables para el salto
    bool saltando;
    int velocidadSalto;
    int gravedadSalto;
    int alturaInicial;

public:
    Jugador();
    Jugador(int x, int y);
    ~Jugador();

    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
    void dibujar(Graphics^ canvas) override;
    void saltar(); 
    void actualizarSalto(int limiteAlto); 

    int getVelocidad();
    void setVelocidad(int vel) { velocidad = vel; }
    int getVidas();
    bool estaSaltando() { return saltando; }  
};