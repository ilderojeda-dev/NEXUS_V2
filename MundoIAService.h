#pragma once
#include "Mundo.h"
#include "Jugador.h"
#include "RobotEnemigo.h"
#include "DialogoService.h"
#include "FinalBossMundoIA.h"
#include "ChipRecurso.h"
#include "Bala.h"
#include "SintIA.h"
#include <vector>
#include "ArchivoService.h"
 
#include "PreguntaService.h"

using namespace System::Drawing;
using namespace std;

class MundoIAService : public Mundo
{
private:
    // Entidades principales
    Jugador* jugador;
    vector<RobotEnemigo*> robots;
    FinalBossMundoIA* boss;
    SintIA* sintia;
    vector<ChipRecurso*> chipRecursos;
    vector<Bala*> balas;
    PreguntaService* gestorPreguntas;
    bool enModoPreguntas;
    int preguntasCorrectas;
    int preguntaActual;

    // Fondos
    Fondo* fondoDia;
    Fondo* fondoNoche;
    bool esFondoNoche;

    // Sistema de diálogos
    DialogoService* gestorDialogos;
    bool mostrandoDialogo;
    bool dialogoBloqueaMovimiento;

    // Control de cinemática
    bool enCinematica;
    int pasoCinematica;
    int contador;

    // Recursos del jugador
    int recursosRecolectados;
    int robotsEliminados;
    bool bossVisible;
    bool sintiaVisible;

    // Control de spawn
    int ultimoCambioY;
    int ultimoSpawnRobots;
    int contadorSpawnChips;
    vector<int> posicionesY;

    // Configuración de robots
    char* rutaSpriteRobot;
    int filasRobot;
    int columnasRobot;

	char* rutaSpriteSintIA;
	int filasSintIA;
	int columnasSintIA;

    // Constantes
    static const int INTERVALO_SPAWN_CHIPS = 100;
    static const int MAX_CHIPS_SIMULTANEOS = 1;
    static const int MAX_ROBOTS_SIMULTANEOS = 14;
    static const int INTERVALO_SPAWN_ROBOTS = 100;
    static const int LIMITE_IZQUIERDO = 100;
    static const int LIMITE_DERECHO = 1700;

    int nivelAutonomia;

    bool robotEliminado;

	bool hadisparado;
    ArchivoService* archivoService;

public:
    MundoIAService(int ancho, int alto, int vidas);
    ~MundoIAService();
    void cargarParametrosDelArchivo();
    void CargarValoresPorDefecto();
    // Inicialización
    void cargarSpriteJugador(char* ruta, int filas, int columnas);
    void crearRobots(char* ruta, int filas, int columnas);
    void cargarFondos(char* rutaDia, char* rutaNoche);
    void cargarFinalBoss(char* ruta, int filas, int columnas);
    void cargarSintIA(char* ruta, int filas, int columnas); //

    // Lógica del juego
    void moverJugador(Direccion tecla);
    void moverRobotsAuto();
    void moverBoss();
    void moverSintIA(); //
    void verificarColisiones();
    void cambiarFondo();
    void generarRobotsAutomaticos();
    void generarChipAleatorio();
    void verificarRecoleccionChips();
    void actualizarChips();
    void verificarEstadoJuego();
    void eliminarTodosLosRobots(); //

    // Sistema de diálogos
    void actualizarDialogo();
    void cerrarDialogo();
    void forzarDialogo(string texto, bool bloquearMovimiento = true);
    string getDialogoActual();
    bool dialogoTerminado();

    // Cinemática
    void actualizarCinematica();

    // Combate
    void dispararJugador();
    void actualizarProyectiles();
    void invocarBoss();
    void invocarSintIA(); //

    // Renderizado
    void dibujarTodo(Graphics^ canvas);
    void dibujarDialogo(Graphics^ canvas);
    void dibujarRecursos(Graphics^ canvas);

    // Condiciones de juego
    bool haLlegadoAlFinal();
    

    // Getters esenciales
    Jugador* getJugador() { return jugador; }
    FinalBossMundoIA* getFinalBoss() { return boss; }
    SintIA* getSintIA() { return sintia; }
    vector<RobotEnemigo*>& getRobots() { return robots; }
    bool getMostrandoDialogo() { return mostrandoDialogo; }
    bool getEnCinematica() { return enCinematica; }
    int getContador() { return contador; }
    void setContador(int c) { contador = c; }
    int getRobotsEliminados() { return robotsEliminados; }
    int getRecursosRecolectados() { return recursosRecolectados; }

    bool getBossVisible() { return bossVisible; }
    bool getSintiaVisible() { return sintiaVisible; }
    
    void inicializarPreguntas();
    void iniciarModoPreguntas();
    void verificarRespuesta(int respuesta);
    void dibujarPregunta(Graphics^ canvas);
    bool getEnModoPreguntas() { return enModoPreguntas; }
    Pregunta* getPreguntaActual();
    
	void setNivelAutonomia(int nivel) { nivelAutonomia = nivel; }   
	int getNivelAutonomia() { return nivelAutonomia; }

    bool esRespuestaCorrecta(int respuesta);

	bool getRobotEliminado() { return robotEliminado; }
	void setRobotEliminado(bool eliminado) { robotEliminado = eliminado; }
    bool getHaDisparado() { return hadisparado; }
	void setHaDisparado(bool disparo) { hadisparado = disparo; }
};