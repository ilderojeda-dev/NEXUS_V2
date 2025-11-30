#include "Sprite.h"
#include <cstring>

Sprite::Sprite() : x(0), y(0), dx(0), dy(0), indiceX(0), indiceY(0),
ancho(0), alto(0), filas(0), columnas(0) {
    image = new char[100];
}

Sprite::Sprite(int x, int y) : x(x), y(y), dx(0), dy(0), indiceX(0), indiceY(0),
ancho(0), alto(0), filas(0), columnas(0) {
    image = new char[100];
    escala = 1.0f;  
}

Sprite::~Sprite() {
    if (image != nullptr) {
        delete[] image;
    }
}

void Sprite::cargarImagen(char* ruta, int filas, int columnas) {
    strcpy_s(image, 100, ruta);
    this->filas = filas;
    this->columnas = columnas;

    Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));
    ancho = bitmap->Width / columnas;
    alto = bitmap->Height / filas;
    delete bitmap;
}

float Sprite::getEscala() { return escala; }
void Sprite::setEscala(float e) { escala = e; }

int Sprite::getX() { return x; }
int Sprite::getY() { return y; }
int Sprite::getAncho() { return ancho; }
int Sprite::getAlto() { return alto; }
void Sprite::setX(int x) { this->x = x; }
void Sprite::setY(int y) { this->y = y; }

Rectangle Sprite::getRectangle() {
    // Aplicar escala primero a las dimensiones base
    int anchoEscalado = (int)(ancho * escala);
    int altoEscalado = (int)(alto * escala);

    // Reducir el área de colisión al 60% del tamaño escalado
    // Esto evita colisiones con espacios transparentes del spritesheet
    int anchoColision = (int)(anchoEscalado * 0.6);
    int altoColision = (int)(altoEscalado * 0.6);

    // Centrar el área de colisión en el sprite escalado
    int desplazamientoX = (anchoEscalado - anchoColision) / 2;
    int desplazamientoY = (altoEscalado - altoColision) / 2;

    return Rectangle(
        x + desplazamientoX,
        y + desplazamientoY,
        anchoColision,
        altoColision
    );
}
