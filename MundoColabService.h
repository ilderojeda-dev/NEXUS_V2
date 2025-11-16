#pragma once
#include "Mundo.h"
#include "Nave.h"
class MundoColabService : public Mundo
{
private:
	Nave* nave;	

public:
	MundoColabService(int ancho, int alto, int vidasIniciales);
	~MundoColabService();

	void CargarSpriteNave(char* ruta, int filas, int columnas);
	void moverNave(Direccion tecla);
	//Nave* getNave() { return ; }
	void dibujarTodo(Graphics^ canvas) override;

};

