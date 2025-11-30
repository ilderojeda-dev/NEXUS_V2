#include "EstrellaRecurso.h"
#include <cstdlib>

EstrellaRecurso::EstrellaRecurso(){
	velocidadEstrella = 8;
	}
EstrellaRecurso::EstrellaRecurso(int x, int y, int velocidad) : Recurso(x, y){
	dx = -1;
	dy = 0;
	this->activo = true;
	this->velocidadEstrella = velocidad;
	}
EstrellaRecurso::~EstrellaRecurso(){

	}

void EstrellaRecurso::mover(Direccion tecla, int limiteAncho, int limiteAlto) {
	indiceX++;
	if (indiceX >= columnas)indiceX = 0;

	x += dx * velocidadEstrella; //mover de derecha a izquierda

	if (x < -ancho) { //si sale de la pantalla por la izquierda, reaparece por la derecha en una posicion aleatoria en y
		x = limiteAncho + ancho;
		y = rand() % (limiteAlto - alto);
	}	
}

void EstrellaRecurso::dibujar(Graphics^ canvas) {
	if (ancho == 0 || alto == 0 || image == nullptr) return;

	// Generar mapa de Bits
	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));

	//rectangulo seleccionado de la imagen
	Rectangle cuadroOrigen = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);

	//rectangulo en el panel donde se pegará el otro rectangulo 
	Rectangle cuadroDestino = Rectangle(x, y, ancho * 0.5, alto *0.5); 

	canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
	delete bitmap;

	}

Rectangle EstrellaRecurso::getRectangleEstrella() {
	int anchoColision = (int)(ancho * 0.4);
	int altoColision = (int)(alto * 0.3);

	// Centrar el área de colisión en el sprite
	int desplazamientoX = (ancho - anchoColision) / 2 - 45;
	int desplazamientoY = (alto - altoColision) / 3 - 30;

	return Rectangle(x + desplazamientoX, y + desplazamientoY, anchoColision, altoColision);
}