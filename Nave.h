#pragma once
#include "Jugador.h"
class Nave : public Jugador
{
private:
	bool naveActiva = true;


	Nave* nave;
public:
	Nave();
	Nave(int x, int y);
	~Nave();
	void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
	void dibujar(Graphics^ canvas) override;

	Rectangle getRectangleNave();


	//para cuando tenga el IndiceY de la nave
	int getIndiceY() { return indiceY; }						
	void setIndiceY(int indiceY) { this->indiceY = indiceY; }

	//para que la nave desaparezca cuando vidas = 0
	bool getNaveActiva() { return naveActiva; }
	void setNaveActiva(bool naveActiva) { this->naveActiva = naveActiva; }
};


