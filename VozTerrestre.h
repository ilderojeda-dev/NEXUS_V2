#pragma once
#include "Aliado.h"

class VozTerrestre : public Aliado {
public:
    VozTerrestre();
    VozTerrestre(int x, int y, int velocidad, int tipoMovimiento);
    ~VozTerrestre();

    // No se mueve, solo se dibuja
    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
};