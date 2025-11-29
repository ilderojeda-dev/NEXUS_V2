// MundoIAService.h
#pragma once
#include "Mundo.h"
#include "Jugador.h"
#include "RobotEnemigo.h"
#include "DialogoService.h"
#include "FinalBossMundoIA.h"
#include "ChipRecurso.h"
#include "Bala.h"
#include <vector>

using namespace System;
using namespace System::Drawing;
using namespace std;

class MundoIAService : public Mundo
{
private:
    Jugador* jugador;
    vector<RobotEnemigo*> robots;
    FinalBossMundoIA* boss;
    vector<ChipRecurso*> chipRecursos;
    vector<Bala*> balas;

    Fondo* fondoDia;
    Fondo* fondoNoche;
    bool esFondoNoche;

    DialogoService* gestorDialogos;
    bool mostrandoDialogo;
    int indiceRobotColision;

    bool enCinematica;
    int pasoCinematica;
    int contador;

    int recursosRecolectados;
    bool jefeInvocado;
    bool juegoTerminado;

public:
    MundoIAService(int ancho, int alto, int vidas);
    ~MundoIAService();

    // Carga de recursos
    void cargarSpriteJugador(char* ruta, int filas, int columnas);
    void crearRobots(char* ruta, int filas, int columnas);
    void cargarFondos(char* rutaDia, char* rutaNoche);
    void cargarFinalBoss(char* ruta, int filas, int columnas);
    void crearChipsRecursos(char* ruta, int filas, int columnas);

    // Movimiento y lógica
    void moverJugador(Direccion tecla);
    void moverRobotsAuto();
    void verificarColisiones();
    void cambiarFondo();

    // Diálogos
    void actualizarDialogo();
    void cerrarDialogo();
    void forzarDialogo(string texto);
    string getDialogoActual();

    // Cinemática
    void actualizarCinematica();

    // Combate
    void dispararJugador();
    void actualizarProyectiles();
    void verificarEstadoJuego();

    // Renderizado
    void dibujarTodo(Graphics^ canvas);
    void dibujarDialogo(Graphics^ canvas);
    void dibujarRecursos(Graphics^ canvas);

    // Condiciones
    bool haLlegadoAlFinal();

    // Getters
    Jugador* getJugador() { return jugador; }
    FinalBossMundoIA* getFinalBoss() { return boss; }
    vector<RobotEnemigo*>& getRobots() { return robots; }
    vector<ChipRecurso*>& getChips() { return chipRecursos; }
    bool getMostrandoDialogo() { return mostrandoDialogo; }
    bool getEnCinematica() { return enCinematica; }
    int getCinematica() { return pasoCinematica; }
    int getContador() { return contador; }
    void setContador(int c) { contador = c; }
};
