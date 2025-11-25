#pragma once
#include "Mundo.h"
#include "Jugador.h"
#include "RobotEnemigo.h"
#include "DialogoService.h"
#include <vector>

using namespace System;
using namespace System::Drawing;
using namespace std;

class MundoIAService : public Mundo
{
private:
    Jugador* jugador;
    vector<RobotEnemigo*> robots;
    DialogoService* gestorDialogos;
    bool mostrandoDialogo;
    int indiceRobotColision;
    bool esFondoNoche;  // ← CAMBIO: era "fondoNoche" (bool)
    Fondo* fondoDia;
    Fondo* fondoNochePtr;  // ← CAMBIO: era "fondoNoche" (Fondo*)

public:
    MundoIAService(int ancho, int alto, int vidas);
    ~MundoIAService();

    void cargarSpriteJugador(char* ruta, int filas, int columnas);
    void cargarSpriteRobot(char* ruta, int filas, int columnas);
    void crearRobots(char* ruta, int filas, int columnas);  // ← NUEVO
    void cargarFondos(char* rutaDia, char* rutaNoche);  // ← NUEVO

    void moverJugador(Direccion tecla);
    void moverRobots();  // ← CAMBIO: plural
    void verificarColisiones();  // ← NUEVO
    void cambiarFondo();  // ← NUEVO
    void actualizarDialogo();  // ← NUEVO

    Jugador* getJugador();
    vector<RobotEnemigo*>& getRobots();  // ← CAMBIO
    bool getMostrandoDialogo() { return mostrandoDialogo; }
    string getDialogoActual();  // ← NUEVO

    void dibujarTodo(Graphics^ canvas);
    void cerrarDialogo();
};