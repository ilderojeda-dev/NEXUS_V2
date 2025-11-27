#include "MeteoritoEnemigo.h"
#include "Nave.h"

#include <cstdlib>


MeteoritoEnemigo::MeteoritoEnemigo() :Enemigo() {
}
MeteoritoEnemigo::MeteoritoEnemigo(int x, int y, int velocidad) :Enemigo(x, y, velocidad, -1) {
	tiempo = 0;
	dx = -1; 
	dy = 0;
	this->activo = true;
}
MeteoritoEnemigo::~MeteoritoEnemigo() {
}
void MeteoritoEnemigo::mover(Direccion direccion, int limiteAncho, int limiteAlto) {
	indiceX++;
	if (indiceX >= columnas)indiceX = 0;

	x += dx * velocidad; //mover de derecha a izquierda

	if (x < -ancho) { //si sale de la pantalla por la izquierda, reaparece por la derecha en una posicion aleatoria en y
		x = limiteAncho + ancho;
		y = rand() % (limiteAlto - alto);
	}

}

void MeteoritoEnemigo::dibujar(Graphics^ canvas) {
	//validar que exista imagen
	if (ancho == 0 || alto == 0 || image == nullptr) return;

	// Generar mapa de Bits
	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));

	//rectangulo seleccionado de la imagen
	Rectangle cuadroOrigen = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);

	//rectangulo en el panel donde se pegará el otro rectangulo 
	Rectangle cuadroDestino = Rectangle(x, y, ancho * tamaño, alto * tamaño); //se usa el tamaño del private

	canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
	delete bitmap;

}

Rectangle MeteoritoEnemigo::getRectangleMeteorito() {
	int anchoColision = (int)(ancho * 0.85);
	int altoColision = (int)(alto * 0.2);

	// Centrar el área de colisión en el sprite
	int desplazamientoX = (ancho - anchoColision) / 2;
	int desplazamientoY = (alto - altoColision) / 2 + 5;

	return Rectangle(x + desplazamientoX, y + desplazamientoY, anchoColision, altoColision);
}

void MeteoritoEnemigo::aplicarEfectoAlJugador(Jugador& jugador) {
	jugador.setVidas(jugador.getVidas() - 1);
}
