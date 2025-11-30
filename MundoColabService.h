#pragma once
#include "Mundo.h"
#include "Nave.h"
#include "MeteoritoEnemigo.h"
#include "EstrellaRecurso.h"
#include "AliadoR2D2.h"
#include "BalaLaser.h"
#include "PreguntaDialogoServiceMundoColab.h"
#include "Pregunta.h"
#include "Dialogo.h"
#include "ArchivoService.h"	





class MundoColabService : public Mundo
{
private:

	int maxMeteoritos = 20;	//manejar el numero max y minimo de meteoritos
	int minMeteoritos = 5;

	int maxEstrellas = 5; //manejar el numero max y minimo de estrellas
	int minEstrellas = 2;

	int balasDisponibles = 10;
	int balasMinimas = 5;
	int balasMaximas = 10;
	bool necesitaRecargar;

	int respuestasCorrectas = 0;
	bool mostrandoPregunta;
	int respuestaSeleccionada;
	int respuestaCorrecta;

	bool colisionBala;
	bool meteoritoNave;
	bool estrellaNave;


	PreguntaDialogoServiceMundoColab preguntaServiceMundoColab;
	Pregunta* preguntaActual;
	Nave* nave;		
	AliadoR2D2* aliadoR2D2 = nullptr;
	vector<BalaLaser*> balas;
	vector<Enemigo*> enemigos;
	vector<EstrellaRecurso*> estrellas;
	ArchivoService* archivoService;
public:
	MundoColabService(int ancho, int alto, int vidasIniciales);
	~MundoColabService();

	
	void cargarParametrosDelArchivo();
	void CargarValoresPorDefecto();
//nave
	void CargarSpriteNave(char* ruta, int filas, int columnas);
	void moverNave(Direccion tecla);

	//meteorito-enemigo
	//void CargarSpriteMeteorito(char* ruta, int filas, int columnas);
	void moverMeteorito();
	void spawnMeteorito(int cantidadMeteoritos);
	void spawnMeteoritosAleatorios();

	//recurso-estrella
	void moverEstrella();
	void spawnEstrella(int cantidadEstrellas);
	void spawnEstrellasAleatorias();

	//recurso-Bala laser
	void disparar();
	void moverBalas();
	
	void procesarRecargaPorRespuesta(bool respuestaCorrecta);


	//Aliado-R2D2
	void cargarR2D2(char* ruta, int filas, int columnas);
	void dibujarAliadoR2D2(Graphics^ canvas);
	void animarAliado();

	//colisiones
	void verificarColisiones();
	

	bool getColisionBala() { return colisionBala; };
	void resetColisioBala() { colisionBala = false; };


	bool getMeteorito() { return meteoritoNave; };
	void resetColisionMeteorito() { meteoritoNave = false; };

	bool getEstrella(){ return estrellaNave; }
	void resetColisioEstrella() { estrellaNave = false; }


	int getBalasDisponibles() { return balasDisponibles; }
	int getBalasMaximas() { return balasMaximas; }
	bool getNecesitaRecargar() { return necesitaRecargar; }	
	int getVidasNave() { return nave->getVidas(); }
	int getRespuestasCorrectas() { return respuestasCorrectas; }
	PreguntaDialogoServiceMundoColab* getPreguntaServiceMundoColab() {	return &preguntaServiceMundoColab;}
	//dibujo
	void dibujarTodo(Graphics^ canvas) override;

};

