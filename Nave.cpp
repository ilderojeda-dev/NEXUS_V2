#include "Nave.h"
using namespace System::Drawing;

Nave::Nave() : Jugador() {
	setVidas(3);				//por ahora que jugador es protectes
	setVelocidad(10);
}

Nave::Nave(int x, int y) : Jugador(x, y) {
	setVidas(3);
	setVelocidad(10);
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
	x += dx * 10; //(10) es velocidad
	y += dy * 10;
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if (x > limiteAncho - ancho) x = limiteAncho - ancho;
	if (y > limiteAlto - alto) y = limiteAlto - alto;
}

//hitbox nave
Rectangle Nave::getRectangleNave() { 
	int anchoColision = (int)(ancho * 0.85);
	int altoColision = (int)(alto * 0.2);

	// Centrar el área de colisión en el sprite
	int desplazamientoX = (ancho - anchoColision) / 2;
	int desplazamientoY = (alto - altoColision) / 2 + 5;

	return Rectangle(x + desplazamientoX, y + desplazamientoY, anchoColision, altoColision);
}


void Nave::dibujar(Graphics^ canvas) {
	if (ancho == 0 || alto == 0 || image == nullptr) return;
	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));
	Rectangle cuadroOrigen = Rectangle(ancho * indiceX, alto * indiceY, ancho, alto); 
	Rectangle cuadroDestino = Rectangle(x, y, ancho * 1, alto * 1); 
	canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
	delete bitmap;
}

