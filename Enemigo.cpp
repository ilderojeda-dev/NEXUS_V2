#include "Enemigo.h"
#include <cstdlib>
#include <ctime>


using namespace System::Drawing;

Enemigo::Enemigo() : Sprite() {
    velocidad = 5;
    activo = true;
    tipoMovimiento = 2;  // Diagonal por defecto
    dx = 1;
    dy = 1;
}

Enemigo::Enemigo(int x, int y, int velocidad, int tipoMovimiento) : Sprite(x, y) {
    this->velocidad = velocidad;
    this->activo = true;
    this->tipoMovimiento = tipoMovimiento;

    // Configurar movimiento segun tipo
    if (tipoMovimiento == 0) {
        // Solo horizontal
        dx = 1;
        dy = 0;
        indiceY = 2;  // Derecha
    }
    else if (tipoMovimiento == 1) {
        // Solo vertical
        dx = 0;
        dy = 1;
        indiceY = 0;  // Abajo
    }
    else {
        // Diagonal
        dx = 1;
        dy = 1;
    }
}

Enemigo::~Enemigo() {
}



int Enemigo::getVelocidad() { return velocidad; }
bool Enemigo::getActivo() { return activo; }
void Enemigo::setVelocidad(int velocidad) { this->velocidad = velocidad; }
void Enemigo::setActivo(bool activo) { this->activo = activo; }
