#include "GasToxico.h"
using namespace System::Drawing;
GasToxico::GasToxico() : Enemigo() {
}
GasToxico::GasToxico(int x, int y, int v) : Enemigo(x, y, v, 0) {
	indiceX = 0;
	indiceY = 0;
}
GasToxico::~GasToxico() {
}
void GasToxico::mover(Direccion tecla, int limiteAncho, int limiteAlto) {
	dx = 0;
	dy = 0;

	indiceX++;
	if (indiceX >= columnas) indiceX = 0;
	x = x + dx * velocidad;
	y = y + dy * velocidad;

}
void GasToxico::aplicarEfectoAlJugador(Jugador& jugador) {
	// Al tocar al jugador, le reduce la vida en 1
	// Suponiendo que el jugador tiene un método para reducir vida
	// jugador.reducirVida(1);
}
void GasToxico::dibujar(Graphics^ canvas) {
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