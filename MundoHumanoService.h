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
#include "ArchivoService.h"
#include <string>
#include <sstream>

using namespace std;
using namespace System::Drawing;
enum class TipoTraje {
	Normal = 0,
	AntiElectricidad = 1,
	AntiGas = 2
};

class MundoHumanoService : public Mundo
{
private:
	// --- ENTIDADES ---
	Dialogo* dialogoActual;
	vector<Alerta*> alertas;
	vector<Enemigo*> enemigos;
	vector<PapelSeñal*> papelSeñal;
	VozTerrestre* vozTerrestre;
	vector<Muro> muros;

	// --- VARIABLES DE JUGADOR (TRAJES) ---
	bool tieneTrajeAntiElectricidad = false;
	bool tieneTrajeAntiGas = false;
	TipoTraje trajeActivo = TipoTraje::Normal;

	// --- ESTADO DE LA MISI�N ---
	int estabilidadNave = 70;
	int indiceCriterio = 100;
	int progresoMision = 0;

	bool modulosCompletados[3] = { false, false, false };

	// --- ARCHIVOS ---
	ArchivoService* archivoService;

public:
	// 1. CONSTRUCTOR Y DESTRUCTOR
	MundoHumanoService(int ancho, int alto, int vidasIniciales);
	~MundoHumanoService();

	// 2. GESTI�N DE ARCHIVOS (CARGA)
	void cargarParametrosDelArchivo();
	void CargarValoresPorDefecto();

	// 3. L�GICA PRINCIPAL (DIBUJO Y M�DULOS)
	void dibujarTodo(Graphics^ canvas);
	void inicializarMuros();
	bool hayColisionMuros(Rectangle rectJugador);
	void aplicarResultadoModulo(int idModulo, bool respuestaCorrecta);
	bool estaModuloCompletado(int idModulo);

	// 4. JUGADOR
	void moverJugador(Direccion tecla);
	void cambiarTraje(TipoTraje tipo);
	TipoTraje getTrajeActivo() { return trajeActivo; }
	void setTieneTrajeAntiElectricidad(bool tiene) { tieneTrajeAntiElectricidad = tiene; }
	void setTieneTrajeAntiGas(bool tiene) { tieneTrajeAntiGas = tiene; }
	bool getTieneTrajeAntiElectricidad() { return tieneTrajeAntiElectricidad; }
	bool getTieneTrajeAntiGas() { return tieneTrajeAntiGas; }

	// 5. ENEMIGOS
	void agregarEnemigo(Enemigo* enemigo);
	void moverEnemigos();
	bool hayColisionEnemigos(Rectangle rectJugador);
	void eliminarEnemigosCortoCircuito();
	void eliminarEnemigosGasToxico();
	vector<Enemigo*> getEnemigos() { return enemigos; }

	// Funciones de generaci�n (Respaldo/Hardcode)
	void generarEnemigosCortoCircuito();
	void generarEnemigosGasToxico();

	// 6. ALERTAS
	void agregarAlerta(Alerta* alerta);
	void moverAlertas();
	int verificarColisionAlerta();
	vector<Alerta*> getAlertas();

	// Funci�n de generaci�n (Respaldo/Hardcode)
	void generarAlertas();

	// 7. RECURSOS Y ALIADOS
	void moverAliadoPapelSeñal();
	bool hayColisionPapelSeñal(Rectangle rectJugador);
	vector<PapelSeñal*> getPapelSeñal() { return papelSeñal; } // Getter simple inline

	// Funci�n de generaci�n (Respaldo/Hardcode)
	void generarPapelSeñal();

	// 8. VOZ TERRESTRE (ALIADO)
	void generarVozTerrestre();
	void mostrarVozTerrestre(bool on);
	VozTerrestre* getVozTerrestre() { return vozTerrestre; }

	// 9. GETTERS Y SETTERS (ESTAD�STICAS)
	int getEstabilidadNave() { return estabilidadNave; }
	void setEstabilidadNave(int est) { estabilidadNave = est; }
	int getIndiceCriterio() { return indiceCriterio; }
	void setIndiceCriterio(int ind) { indiceCriterio = ind; }
	int getProgresoMision() { return progresoMision; }
	void setProgresoMision(int prog) { progresoMision = prog; }
};