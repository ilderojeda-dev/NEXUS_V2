#include "MundoIAService.h"
#include "cstdlib"
#include "ctime"

MundoIAService::MundoIAService(int ancho, int alto, int vidas)
	:Mundo(ancho, alto, vidas)
{
	jugador = new Jugador(80, 200);
	robot = new RobotEnemigo(20, 20);
	srand(time(nullptr));
}
MundoIAService::~MundoIAService() {
	delete jugador;
	delete robot;
}

void MundoIAService::cargarSpriteJugador(char* ruta, int filas, int columnas) {
	jugador->cargarImagen(ruta, filas, columnas);

}

void MundoIAService::cargarSpriteRobot(char* ruta, int filas, int columnas) {
	robot->cargarImagen(ruta, filas, columnas);
}
void MundoIAService::moverJugador(Direccion tecla) {
	jugador->mover(tecla, this->anchoPanel, this->altoPanel);
}

void MundoIAService::moverRobot() {
	robot->mover(Ninguno, this->anchoPanel, this->altoPanel);
}

Jugador* MundoIAService::getJugador() {
	return jugador;
}


void MundoIAService::dibujarTodo(Graphics^ canvas) {
	fondo->dibujar(canvas);
	jugador->dibujar(canvas);
	robot->dibujar(canvas);
}