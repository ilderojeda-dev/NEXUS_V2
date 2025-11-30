#pragma once
#include "Sprite.h"
#include "ConfiguracionSprite.h"

using namespace System::Drawing;

class Jugador : public Sprite
{
private:                  
    int vida;
    int velocidad;
    bool saltando;
    float velocidadSalto;
    float gravedadSalto;
    int alturaInicial;
    int duracionSaltoActual;
    int duracionSaltoMaxima;
    Direccion direccionSalto;
    ConfiguracionSprite config;

public:
    Jugador();
    Jugador(int x, int y);
    ~Jugador();

    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
    void dibujar(Graphics^ canvas) override;
    void saltar(Direccion direccion);
    void actualizarSalto(int limiteAlto);
    void setConfiguracion(ConfiguracionSprite configuracion);
    int getVelocidad() { return velocidad; }
    void setVelocidad(int vel) { velocidad = vel; }
    int getVidas() { return vida; }
    void setVidas(int v) { vida = v; }
    bool estaSaltando() { return saltando; }
    void setIndiceY(int ny) { this->indiceY = ny; }
    int getIndiceY() { return this->indiceY; }

};
