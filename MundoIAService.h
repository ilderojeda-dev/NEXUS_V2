#pragma once
#include "Mundo.h"
#include "Jugador.h"
#include "RobotEnemigo.h"
using namespace System;
using namespace System::Drawing;
using namespace std;

class MundoIAService : public Mundo
{
private:
	Jugador* jugador;
	RobotEnemigo* robot;
public:

	MundoIAService(int ancho, int alto, int vidas);
	~MundoIAService();

	void cargarSpriteJugador(char* ruta, int filas, int columnas);
	void cargarSpriteRobot(char* ruta, int filas, int columnas);
	void moverJugador(Direccion tecla);
	void moverRobot();

	Jugador* getJugador();
	RobotEnemigo* getRobot();

	void dibujarTodo(Graphics^ canvas);

};

