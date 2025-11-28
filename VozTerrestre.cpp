#include "VozTerrestre.h"

VozTerrestre::VozTerrestre() : Aliado() {
    // Por seguridad
    indiceX = 0;
    indiceY = 0;
    activo = false;
}

VozTerrestre::VozTerrestre(int x, int y, int velocidad, int tipoMovimiento)
    : Aliado(x, y, velocidad, tipoMovimiento) {

    indiceX = 0;
    indiceY = 0;
    activo = false;   // Se enciende desde el service con setActivo(true)
}

VozTerrestre::~VozTerrestre() {}

void VozTerrestre::mover(Direccion tecla, int limiteAncho, int limiteAlto) {
    // No se mueve, solo podríamos animar si tuvieras varias columnas
    // indiceX = (indiceX + 1) % columnas;  // si algún día quieres animarla
}