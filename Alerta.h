#pragma once
#include "Recurso.h"

class Alerta: public Recurso
{
private:
	int contadorAnimacion;
	int velocidadAnimacion;
public:
	Alerta();
	Alerta(int x, int y);
	~Alerta();

	void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
	void dibujar(Graphics^ canvas) override;



};

