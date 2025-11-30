#pragma once
#include "Recurso.h" 

using namespace System::Drawing;

class ChipRecurso : public Recurso
{
private:
    int frameActual;
    int contadorAnimacion;
    int velocidadAnimacion; // Frames que deben pasar para cambiar
    bool recolectado;

public:
    ChipRecurso(int x, int y);
    ~ChipRecurso();

    void dibujar(Graphics^ canvas) override;
    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override {}

    void actualizarAnimacion();
    bool estaRecolectado() { return recolectado; }
    void setRecolectado(bool r) { recolectado = r; }
};