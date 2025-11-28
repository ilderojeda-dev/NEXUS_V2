#include "PapelSeñal.h"
using namespace System::Drawing;
PapelSeñal::PapelSeñal() : Recurso() {
}
PapelSeñal::PapelSeñal(int x, int y) : Recurso(x, y) {
	indiceX = 0;
	indiceY = 0;
	
}
PapelSeñal::~PapelSeñal() {
}
void PapelSeñal::mover(Direccion tecla, int limiteAncho, int limiteAlto) {
	dx = 0;
	dy = 0;
	indiceX++;
	if (indiceX >= columnas) indiceX = 0;
	x = x + dx;
	y = y + dy;
}
void PapelSeñal::dibujar(Graphics^ canvas) {
	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));
	Rectangle cuadroOrigen = Rectangle(
		indiceX * ancho,
		indiceY * alto,
		ancho,
		alto
	);
	Rectangle cuadroDestino = Rectangle(
		x,
		y,
		ancho * 1,
		alto * 1
	);
	canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
	delete bitmap;
}	

