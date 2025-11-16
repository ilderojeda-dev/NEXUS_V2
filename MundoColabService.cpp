#include "MundoColabService.h"
#include "Nave.h"
#include <cstdlib>
#include <ctime>
MundoColabService::MundoColabService(int ancho, int alto, int vidasIniciales)
: Mundo(ancho, alto, vidasIniciales) {
nave = new Nave(50, 50);
srand(time(NULL)); // Inicializar la semilla para números aleatorios

}
MundoColabService::~MundoColabService() {
	delete jugador;
}

void MundoColabService::CargarSpriteNave(char* ruta, int filas, int columnas) {
	nave->cargarImagen(ruta, filas, columnas);
}
void MundoColabService::moverNave(Direccion tecla) {
	nave->mover(tecla, anchoPanel, altoPanel);
}

void MundoColabService::dibujarTodo(Graphics^ canvas) {

// Dibujar el fondo
if (fondo != nullptr) {
	fondo->dibujar(canvas);
}
// Dibujar el jugador
if (nave != nullptr) {
	nave->dibujar(canvas);
}
// Aquí se podrían agregar más elementos específicos del modo colaborativo
}