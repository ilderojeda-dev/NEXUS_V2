#pragma once
#include "Mundo.h"
#include "Muro.h"
#include "Alerta.h"
#include <vector>
#include "Jugador.h"
#include "Dialogo.h"

using namespace System::Drawing;


class MundoHumanoService : public Mundo
{
private:
	Dialogo* dialogoActual;
	vector<Alerta*> alertas;

	vector<Muro> muros;


public:
	MundoHumanoService(int ancho, int alto, int vidasIniciales);
	~MundoHumanoService();
	void inicializarMuros();
	bool hayColisionMuros(Rectangle rectJugador);

	//Alertas
	void agregarAlerta(Alerta* alerta);
	void generarAlertas();
	void moverAlertas();
	vector<Alerta*> getAlertas();
	int verificarColisionAlerta();
	



	

	void moverJugador(Direccion tecla);//en este caso se sobreescribe el metodo moverJugador de la clase base Mundo

	void dibujarTodo(Graphics^ canvas);
};

