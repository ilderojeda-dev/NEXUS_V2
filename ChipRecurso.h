
#pragma once
#include "Recurso.h" 

using namespace System::Drawing;

class ChipRecurso : public Recurso
{
public:
    ChipRecurso(int x, int y);
    ~ChipRecurso();

    void dibujar(Graphics^ canvas) override;
    void mover(Direccion tecla, int limiteAncho, int limiteAlto, int velocidad) override {}
};