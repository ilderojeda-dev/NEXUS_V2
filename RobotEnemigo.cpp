#include "RobotEnemigo.h"

RobotEnemigo::RobotEnemigo()
	:Sprite()
{

}
RobotEnemigo::RobotEnemigo(int x, int y)
	:Sprite(x, y)
{

}
RobotEnemigo::~RobotEnemigo()
{

}

void RobotEnemigo::mover(Direccion direccion, int limiteAncho, int limiteAlto) {
	indiceX++;
	if (indiceX >= columnas)indiceX = 0;

	x += dx;
	y += dy;

	if (x < limiteAncho - ancho && y == 20) { dx = 5; dy = 0; indiceY = 3; }
	if (x >= limiteAncho - ancho && y < limiteAlto - alto) { dx = 0; dy = 5; indiceY = 2; }
	if (y >= limiteAlto - alto && x > 20) { dx = -5; dy = 0; indiceY = 1; }
	if (x <= 20 && y > 20) { dx = 0; dy = -5; indiceY = 0; }

}
void RobotEnemigo::dibujar(Graphics^ canvas) {

	//validar que exista imagen
	if (ancho == 0 || alto == 0 || image == nullptr) return;

	// Generar mapa de Bits
	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));

	//rectangulo seleccionado de la imagen
	Rectangle cuadroOrigen = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);

	//rectangulo en el panel donde se pegará el otro rectangulo 
	Rectangle cuadroDestino = Rectangle(x, y, ancho, alto);

	canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
	delete bitmap;

}