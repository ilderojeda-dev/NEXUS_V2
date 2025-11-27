#pragma once
#include <iostream>
#include "Enemigo.h"
#include "Sprite.h"
class MeteoritoEnemigo : public Enemigo
{
private:
	int tiempo; 

	double tamaño = 1.0;

 
public:		
	
	MeteoritoEnemigo();
	  MeteoritoEnemigo(int x, int y, int velocidad);
	  ~MeteoritoEnemigo();
	  void mover(Direccion direccion, int limiteAncho, int limiteAlto) override;

	  void dibujar(Graphics^ canvas) override;

	  void aplicarEfectoAlJugador(Jugador& jugador) override;

	  void setTamaño(double tamaño) { tamaño = tamaño; }

	  Rectangle getRectangle() override { return getRectangleMeteorito();  } //para usar el hitbox personalizado
	  Rectangle getRectangleMeteorito();
};

