#pragma once
#include "Mundo.h"
#include "Muro.h"
#include "Alerta.h"
#include <vector>
#include "Jugador.h"
#include "Dialogo.h"
#include "CortoCircuito.h"
#include "GasToxico.h"
#include "PapelSeñal.h"
#include "VozTerrestre.h"
using namespace System::Drawing;
enum class TipoTraje {
	Normal = 0,
	AntiElectricidad = 1,
	AntiGas = 2
};


class MundoHumanoService : public Mundo
{
private:
	Dialogo* dialogoActual;
	vector<Alerta*> alertas;
	vector<Enemigo*> enemigos;
	vector<PapelSeñal*> papelSeñal;
	VozTerrestre* vozTerrestre; 
	// ---- ESTO SÍ, y solo esto para trajes ----
	bool tieneTrajeAntiElectricidad = false;
	bool tieneTrajeAntiGas = false;
	TipoTraje trajeActivo = TipoTraje::Normal;


	vector<Muro> muros;
	int estabilidadNave = 65;
	int indiceCriterio = 50;   
	int progresoMision = 0;
	bool modulosCompletados[3] = { false, false, false };
	


public:
	MundoHumanoService(int ancho, int alto, int vidasIniciales);
	~MundoHumanoService();
	void aplicarResultadoModulo(int idModulo, bool respuestaCorrecta);
	bool estaModuloCompletado(int idModulo) {
		return modulosCompletados[idModulo];
	}

	void inicializarMuros();
	bool hayColisionMuros(Rectangle rectJugador);
	int getEstabilidadNave() { return estabilidadNave; }
	void setEstabilidadNave(int est) { estabilidadNave = est; }
	int getIndiceCriterio() { return indiceCriterio; }
	void setIndiceCriterio(int ind) { indiceCriterio = ind; }
	int getProgresoMision() { return progresoMision; }
	void setProgresoMision(int prog) { progresoMision = prog; }


	//Alertas
	void agregarAlerta(Alerta* alerta);
	void generarAlertas();
	void moverAlertas();
	vector<Alerta*> getAlertas();
	int verificarColisionAlerta();
	

	//enemigos 
	void generarEnemigosCortoCircuito();
	void generarEnemigosGasToxico();
	void agregarEnemigo(Enemigo* enemigo);
	vector<Enemigo*> getEnemigos() { return enemigos; }
	void moverEnemigos();
	bool hayColisionEnemigos(Rectangle rectJugador);
	void eliminarEnemigosCortoCircuito();
	void eliminarEnemigosGasToxico();

	//Recursos
	void generarAliadoPapelSeñal();
	vector<PapelSeñal*> getAliado() { return papelSeñal; }
	bool hayColisionPapelSeñal(Rectangle rectJugador);
	void moverAliadoPapelSeñal();	

	// Aliados
	void generarVozTerrestre();          // crea/activa
	void mostrarVozTerrestre(bool on);   // solo ON/OFF del panel
	VozTerrestre* getVozTerrestre() { return vozTerrestre; }

	void moverJugador(Direccion tecla);//en este caso se sobreescribe el metodo moverJugador de la clase base Mundo

	//trejes
	void cambiarTraje(TipoTraje tipo);      // 👈 nuevo método
	TipoTraje getTrajeActivo() { return trajeActivo; }
	void setTieneTrajeAntiElectricidad(bool tiene) { tieneTrajeAntiElectricidad = tiene; }
	void setTieneTrajeAntiGas(bool tiene) { tieneTrajeAntiGas = tiene; }

	bool getTieneTrajeAntiElectricidad() { return tieneTrajeAntiElectricidad; }
	bool getTieneTrajeAntiGas() { return tieneTrajeAntiGas; }



	void dibujarTodo(Graphics^ canvas);
};

