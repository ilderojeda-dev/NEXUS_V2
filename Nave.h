#pragma once
#include "Jugador.h"
class Nave : public Jugador
{
private:
	int vidaa;
	int velocidadd;	//necesito redeclarar esto porque la clase jugador tiene estas variables privadas, seria bueno que lo puedan cambiar a protegidas
	Nave* nave;
public:
	Nave();
	Nave(int x, int y);
	~Nave();
	void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
	void dibujar(Graphics^ canvas) override;

	int getVidaa() { return vidaa; }
	int getVelocidadd() { return velocidadd; }
};


//mi sprite tiene solo una columna por eso estoy poniendolo como en 0 en indiceY, por eso hago una clase aparte.