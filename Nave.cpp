#include "Nave.h"
using namespace System::Drawing;

Nave::Nave() : Jugador() {
	vidaa = 3;
	velocidadd = 10;
}

Nave::Nave(int x, int y) : Jugador(x, y) {
	vidaa = 3;
	velocidadd = 10;
}

Nave::~Nave() {
}

void Nave::mover(Direccion tecla, int limiteAncho, int limiteAlto) {
	if (tecla == Direccion::Ninguno) return;
	if (tecla == Direccion::Arriba) { dx = 0;  dy = -1; }
	if (tecla == Direccion::Abajo) { dx = 0;  dy = 1;  }
	if (tecla == Direccion::Izquierda) { dx = -1; dy = 0; }
	if (tecla == Direccion::Derecha) { dx = 1;  dy = 0;}
	indiceY = 0; //solo una columna
	indiceX++;
	if (indiceX >= columnas) indiceX = 0;
	x += dx * velocidadd;
	y += dy * velocidadd;
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if (x > limiteAncho - ancho * 2) x = limiteAncho - ancho * 2;
	if (y > limiteAlto - alto * 2) y = limiteAlto - alto * 2;
}

void Nave::dibujar(Graphics^ canvas) {
	if (ancho == 0 || alto == 0 || image == nullptr) return;
	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));
	Rectangle cuadroOrigen = Rectangle(ancho * indiceX, alto * indiceY, ancho, alto); 
	Rectangle cuadroDestino = Rectangle(x, y, ancho * 2, alto * 2); 
	canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
	delete bitmap;
}