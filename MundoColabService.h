#pragma once
#include "Mundo.h"
#include "Nave.h"
#include "MeteoritoEnemigo.h"
#include "EstrellaRecurso.h"
class MundoColabService : public Mundo
{
private:

	int maxMeteoritos = 20;	//manejar el numero max y minimo de meteoritos
	int minMeteoritos = 5;

	int maxEstrellas = 5; //manejar el numero max y minimo de estrellas
	int minEstrellas = 2;




	Nave* nave;	
	vector<Enemigo*> enemigos;
	vector<EstrellaRecurso*> estrellas;
public:
	MundoColabService(int ancho, int alto, int vidasIniciales);
	~MundoColabService();

	//nave
	
	void CargarSpriteNave(char* ruta, int filas, int columnas);
	void moverNave(Direccion tecla);

	//meteorito-enemigo
	//void CargarSpriteMeteorito(char* ruta, int filas, int columnas);
	void moverMeteorito();
	void spawnMeteorito(int cantidadMeteoritos);
	void spawnMeteoritosAleatorios();

	//aliado-estrella
	void moverEstrella();
	void spawnEstrella(int cantidadEstrellas);
	void spawnEstrellasAleatorias();


	//colisiones
	void verificarColisiones();




	//dibujo
	void dibujarTodo(Graphics^ canvas) override;

};

