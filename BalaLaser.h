#pragma once
#include "Recurso.h"

class BalaLaser : public Recurso {
private:
    int velocidad;
    bool explotando;
    int velocidadAnim;
    int contadorAnim;

public:
    BalaLaser(int x, int y, int velocidad);
    ~BalaLaser();

    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override;
    void dibujar(Graphics^ canvas) override;

    void iniciarExplosion();

    bool BalaLaser::estaExplotando() { return explotando; }
	Rectangle getRectangle(){ return getRectangleBala(); } //usar hitbox del recurso
	Rectangle getRectangleBala();

};
