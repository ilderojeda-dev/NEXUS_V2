#pragma once
#include "Recurso.h"	
class PapelSeñal : public Recurso
{ 
private:
	 
public:
	PapelSeñal();
	PapelSeñal(int x, int y);
	~PapelSeñal();
	void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
	void dibujar(Graphics^ canvas) override;


};

