#pragma once
#include "Sprite.h"
#include "ConfiguracionSprite.h"
using namespace System::Drawing;

using namespace std;
class FinalBossMundoIA : public Sprite
{
private:
    int vidaActual;
    int vidaMaxima;
    ConfiguracionSprite config;


public:
    FinalBossMundoIA(int x, int y, int dificultad);
    ~FinalBossMundoIA();

    void mover(Direccion direccion, int posInicial, int PosFinal, int velocidad) override;
    void dibujar(Graphics^ canvas) override;
    void recibirDano(int cantidad);
    bool estaDerrotado() { return vidaActual <= 0; }
    int getVida() { return vidaActual; }
    void setConfiguracion(ConfiguracionSprite configuracion);
    int getVidaMaxima() { return vidaMaxima; }

};
