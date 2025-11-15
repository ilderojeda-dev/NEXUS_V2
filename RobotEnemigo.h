#pragma once
#include "Sprite.h"
using namespace System::Drawing;
class RobotEnemigo : public Sprite
{
private:

public:

	RobotEnemigo();
	RobotEnemigo(int x, int y);
	~RobotEnemigo();

	void mover(Direccion direccion, int limiteAncho, int limiteAlto) override;
	void dibujar(Graphics^ canvas) override;



};

