#include "Recurso.h"

using namespace System::Drawing;

Recurso::Recurso() : Sprite() {
    activo = true;

}

Recurso::Recurso(int x, int y) : Sprite(x, y) {
    this->activo = true;

}

Recurso::~Recurso() {
}

bool Recurso::getActivo() { return activo; }
void Recurso::setActivo(bool activo) { this->activo = activo; }

 