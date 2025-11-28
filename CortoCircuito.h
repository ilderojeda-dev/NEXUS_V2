#pragma once
#include "Enemigo.h"	
class CortoCircuito : public Enemigo
{
private:
	
	public:
	CortoCircuito();
	CortoCircuito(int x, int y, int v);
	~CortoCircuito();
	void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
	void aplicarEfectoAlJugador(Jugador& jugador) override;
	void dibujar(Graphics^ canvas) override;	
};

