#include "Jugador.h"

using namespace System::Drawing;
Jugador::Jugador() : Sprite() {
	vida = 1;
	velocidad = 3;
}
Jugador::Jugador(int x, int y) : Sprite(x, y) {
	vida = 1;
	velocidad = 20;
}
Jugador::~Jugador() {
}
void Jugador::mover(Direccion tecla, int limiteAncho, int limiteAlto) {
    if (tecla == Direccion::Ninguno) return;

    if (tecla == Direccion::Arriba) { dx = 0;  dy = -1; indiceY = 3; }
    if (tecla == Direccion::Abajo) { dx = 0;  dy = 1;  indiceY = 0; }
    if (tecla == Direccion::Izquierda) { dx = -1; dy = 0;  indiceY = 1; }
    if (tecla == Direccion::Derecha) { dx = 1;  dy = 0;  indiceY = 2; }

    indiceX++;
    if (indiceX >= columnas) indiceX = 0;

    x += dx * velocidad;
    y += dy * velocidad;

    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x > limiteAncho - ancho * 2) x = limiteAncho - ancho * 2;
    if (y > limiteAlto - alto * 2) y = limiteAlto - alto * 2;
}
void Jugador::dibujar(Graphics^ canvas) {
    if (ancho == 0 || alto == 0 || image == nullptr) return;
    Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));
	Rectangle cuadroOrigen = Rectangle(ancho * indiceX, alto * indiceY, ancho, alto); // se multiplicar por el indice porque es un spritesheetq es decir varias imagenes en una sola
	Rectangle cuadroDestino = Rectangle(x, y, ancho * 2, alto * 2); //se multiplica por 2 para escalar el sprite es decir agrandarlo y si queremos mas pequeño se divide
    canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
    delete bitmap;
}