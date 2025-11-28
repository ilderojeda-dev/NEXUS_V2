#pragma once
#include "Enemigo.h"
class GasToxico : public Enemigo
{
private:
		
public:
	GasToxico();
	GasToxico(int x, int y, int v);
	~GasToxico();
	void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
	void aplicarEfectoAlJugador(Jugador& jugador) override;
	void dibujar(Graphics^ canvas) override;

};

