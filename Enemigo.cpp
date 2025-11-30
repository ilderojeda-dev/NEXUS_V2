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

}

Enemigo::~Enemigo() {
}



int Enemigo::getVelocidad() { return velocidad; }
bool Enemigo::getActivo() { return activo; }
void Enemigo::setVelocidad(int velocidad) { this->velocidad = velocidad; }
void Enemigo::setActivo(bool activo) { this->activo = activo; }
