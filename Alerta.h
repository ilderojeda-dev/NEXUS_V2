#pragma once
#include "Recurso.h"
#include "string"
using namespace std;

class Alerta: public Recurso
{
private:
	int contadorAnimacion;
	int velocidadAnimacion;
	int numeroAlerta;

public:
	Alerta();
	Alerta(int x, int y);
	Alerta(int x, int y, int n);
	~Alerta();
	int getTipoAlerta();
	void setTipoAlerta(int n);

	void mover(Direccion tecla, int limiteAncho, int limiteAlto, int velocidad) override;
	void dibujar(Graphics^ canvas) override;



};

