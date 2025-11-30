#pragma once
#include "Recurso.h"
class EstrellaRecurso : public Recurso 
{private:
	int velocidadEstrella;

public:

	EstrellaRecurso();
	EstrellaRecurso(int x, int y, int velocidad);
	~EstrellaRecurso();
	void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
	void dibujar(Graphics^ canvas) override;

	Rectangle getRectangleEstrella();

};

