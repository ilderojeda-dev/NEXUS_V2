#pragma once
#include "Aliado.h"
class AliadoR2D2 : public Aliado
{
private:
	bool hablando; //cuando haya dialogo, el sprite se movera
	int velocidadAnimacion;
	int contadorAnimacion; //contador de frames

public:

	AliadoR2D2();
	AliadoR2D2(int x, int y);
	~AliadoR2D2();

	void animar();
	void mover(Direccion tecla, int limiteAncho, int limiteAlto) override {} //no se mueve
	void dibujar(Graphics^ canvas) override;
	void setHablando(bool estado) { hablando = estado; }
	bool getHablando() { return hablando; }



};

