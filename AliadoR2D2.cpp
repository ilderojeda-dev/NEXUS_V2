#include "AliadoR2D2.h"
using namespace System::Drawing;

AliadoR2D2::AliadoR2D2() : Aliado() {
    hablando = false;
    velocidadAnimacion = 5;   // cada 5 ticks
    contadorAnimacion = 0;
}

AliadoR2D2::AliadoR2D2(int x, int y) : Aliado(x, y, 0, -2) {
    // NOTA: tipoMovimiento = 0 para evitar que se mueva
    hablando = false;
    velocidadAnimacion = 5;
    contadorAnimacion = 0;

    dx = 0;
    dy = 0;
}

AliadoR2D2::~AliadoR2D2() {
}
void AliadoR2D2::animar() {
	if (hablando) {
		contadorAnimacion++;
		if (contadorAnimacion >= velocidadAnimacion) {
			indiceX++;
			if (indiceX >= columnas) {
				indiceX = 0;
			}
			contadorAnimacion = 0;
		}
	}
}

void AliadoR2D2::dibujar(Graphics^ canvas) {
	if (ancho == 0 || alto == 0 || image == nullptr) return;
	// Generar mapa de Bits
	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));
	//rectangulo seleccionado de la imagen
	Rectangle cuadroOrigen = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	//rectangulo en el panel donde se pegará el otro rectangulo 
	Rectangle cuadroDestino = Rectangle(x, y, ancho * 1, alto * 1);
	canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
	delete bitmap;
}

