#pragma once
#include "Sprite.h"
#include "Jugador.h"
class Enemigo: public Sprite 
{
protected:
	int velocidad;
	bool activo;
	int tipoMovimiento;

public:
	Enemigo();
	Enemigo(int x, int y, int v, int tm);
	~Enemigo();
	virtual void mover(Direccion tecla, int limiteAncho, int limiteAlto) = 0;
	virtual void aplicarEfectoAlJugador(Jugador& jugador) = 0;
	virtual void dibujar(Graphics^ canvas) override =0;
	int getVelocidad();
	bool getActivo();
	void setVelocidad(int velocidad);
	void setActivo(bool activo);
	
};

