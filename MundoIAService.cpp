
#include "MundoIAService.h"
#include "ConfiguracionSprite.h"

MundoIAService::MundoIAService(int ancho, int alto, int vidas)
    : Mundo(ancho, alto, vidas) {
    jugador = nullptr;
    boss = nullptr;
    fondoDia = nullptr;
    fondoNoche = nullptr;
    gestorDialogos = new DialogoService();

    mostrandoDialogo = false;
    indiceRobotColision = -1;
    esFondoNoche = false;
    enCinematica = true;
    pasoCinematica = 0;
    contador = 0;
    recursosRecolectados = 0;
    jefeInvocado = false;
    juegoTerminado = false;
}

MundoIAService::~MundoIAService() {
    delete jugador;
    delete boss;
    delete gestorDialogos;
    delete fondoDia;
    delete fondoNoche;

    for (auto robot : robots) delete robot;
    for (auto chip : chipRecursos) delete chip;
    for (auto bala : balas) delete bala;
}

void MundoIAService::cargarSpriteJugador(char* ruta, int filas, int columnas) {
    if (jugador == nullptr) {
        jugador = new Jugador(800, 550);
        jugador->setIndiceY(4);
    }
    jugador->cargarImagen(ruta, filas, columnas);
    jugador->setConfiguracion(ConfiguracionSprite::ConfiguracionMundoIA());
}

void MundoIAService::crearRobots(char* ruta, int filas, int columnas) {
    for (auto robot : robots) delete robot;
    robots.clear();

    // Robots derecha
    int posicionesY[] = { 400, 500, 450 };
    int posicionesX[] = { 1645, 1670, 1695 };
    for (int i = 0; i < 3; i++) {
        RobotEnemigo* robot = new RobotEnemigo(posicionesX[i], posicionesY[i]);
        robot->cargarImagen(ruta, filas, columnas);
        robot->setEscala(0.8f);
        robots.push_back(robot);
    }

    // Robots izquierda
    int posicionesYIzq[] = { 500, 550, 600 };
    int posicionesXIzq[] = { 30, 55, 30 };
    for (int i = 0; i < 3; i++) {
        RobotEnemigo* robot = new RobotEnemigo(posicionesXIzq[i], posicionesYIzq[i]);
        robot->setIndiceY(3);
        robot->cargarImagen(ruta, filas, columnas);
        robot->setEscala(0.8f);
        robots.push_back(robot);
    }
}

void MundoIAService::cargarFinalBoss(char* ruta, int filas, int columnas) {
    delete boss;
    boss = new FinalBossMundoIA(1500, 550, 1);
    boss->cargarImagen(ruta, filas, columnas);
}

void MundoIAService::cargarFondos(char* rutaDia, char* rutaNoche) {
    if (fondoDia == nullptr) {
        fondoDia = new Fondo(rutaDia, anchoPanel, altoPanel);
    }
    if (fondoNoche == nullptr) {
        fondoNoche = new Fondo(rutaNoche, anchoPanel, altoPanel);
    }
}

void MundoIAService::crearChipsRecursos(char* ruta, int filas, int columnas) {
    for (auto chip : chipRecursos) delete chip;
    chipRecursos.clear();

    int posiciones[][2] = { {600, 550}, {1200, 450}, {1600, 600} };
    for (int i = 0; i < 3; i++) {
        ChipRecurso* chip = new ChipRecurso(posiciones[i][0], posiciones[i][1]);
        chip->cargarImagen(ruta, filas, columnas);
        chipRecursos.push_back(chip);
    }
}

void MundoIAService::moverJugador(Direccion tecla) {
    if (jugador != nullptr && !mostrandoDialogo) {
        jugador->mover(tecla, anchoPanel, altoPanel, 0);
    }
}

void MundoIAService::verificarColisiones() {
    if (jugador == nullptr || mostrandoDialogo) return;

    Rectangle rectJugador = jugador->getRectangle();

    for (int i = 0; i < robots.size(); i++) {
        if (robots[i] != nullptr && robots[i]->getY() == jugador->getY()) {
            Rectangle rectRobot = robots[i]->getRectangle();
            if (rectJugador.IntersectsWith(rectRobot)) {
                mostrandoDialogo = true;
                indiceRobotColision = i;

                if (i == 2) {
                    string pista = "Robot 734: ...bzzzt...\n";
                    pista += "No soy como ellos. Mi codigo fallo.\n";
                    pista += "La perfeccion es una carcel.\n";
                    pista += "Recuerda: La ETICA es lo que nos diferencia.";
                    gestorDialogos->getDialogoActual()->iniciar(pista);
                    jugador->setX(jugador->getX() - 50);
                }
                else {
                    string amenaza = "ENEMIGO: Patron ineficiente eliminado.";
                    gestorDialogos->getDialogoActual()->iniciar(amenaza);
                    jugador->setVidas(jugador->getVidas() - 1);
                    jugador->setX(100);
                    jugador->setY(550);
                }
                break;
            }
        }
    }
}

void MundoIAService::cambiarFondo() {
    if (jugador == nullptr) return;
    int anchoEscalado = (int)(jugador->getAncho() * jugador->getEscala());
    if (jugador->getX() >= anchoPanel - anchoEscalado - 50) {
        esFondoNoche = true;
    }
}

void MundoIAService::actualizarDialogo() {
    if (mostrandoDialogo && gestorDialogos != nullptr) {
        Dialogo* dialogo = gestorDialogos->getDialogoActual();
        if (dialogo != nullptr) {
            dialogo->actualizar();
        }
    }
}

string MundoIAService::getDialogoActual() {
    if (gestorDialogos != nullptr && gestorDialogos->getDialogoActual() != nullptr) {
        return gestorDialogos->getDialogoActual()->getTextoActual();
    }
    return "";
}

void MundoIAService::dibujarTodo(Graphics^ canvas) {
    // Fondo
    if (esFondoNoche && fondoNoche != nullptr) {
        fondoNoche->dibujar(canvas);
    }
    else if (fondoDia != nullptr) {
        fondoDia->dibujar(canvas);
    }

    // Entidades
    for (auto robot : robots) {
        if (robot != nullptr) robot->dibujar(canvas);
    }

    if (jugador != nullptr) jugador->dibujar(canvas);
    if (boss != nullptr) boss->dibujar(canvas);

    for (auto bala : balas) {
        bala->dibujar(canvas);
    }
}

void MundoIAService::dibujarRecursos(Graphics^ canvas) {
    for (auto chip : chipRecursos) {
        if (chip != nullptr) chip->dibujar(canvas);
    }
}

void MundoIAService::dibujarDialogo(Graphics^ canvas) {
    if (!mostrandoDialogo || gestorDialogos == nullptr) return;

    Dialogo* dialogo = gestorDialogos->getDialogoActual();
    if (dialogo == nullptr || !dialogo->estaEnProgreso()) return;

    int dialogoX = 20, dialogoY = 20;
    int dialogoAncho = 635, dialogoAlto = 170;

    // Fondo
    SolidBrush^ fondoDialogo = gcnew SolidBrush(Color::FromArgb(230, 20, 20, 40));
    canvas->FillRectangle(fondoDialogo, dialogoX, dialogoY, dialogoAncho, dialogoAlto);

    // Borde
    Pen^ bordeDialogo = gcnew Pen(Color::FromArgb(255, 100, 200, 255), 3);
    canvas->DrawRectangle(bordeDialogo, dialogoX, dialogoY, dialogoAncho, dialogoAlto);

    // Texto
    String^ textoManaged = gcnew String(dialogo->getTextoActual().c_str());
    Font^ fuenteDialogo = gcnew Font("Arial", 14, FontStyle::Regular);
    SolidBrush^ colorTexto = gcnew SolidBrush(Color::White);
    RectangleF areaTexto = RectangleF(dialogoX + 20, dialogoY + 20, dialogoAncho - 40, dialogoAlto - 60);
    canvas->DrawString(textoManaged, fuenteDialogo, colorTexto, areaTexto);

    // Indicador
    if (!dialogo->estaEnProgreso()) {
        String^ indicador = "Presiona ENTER para continuar...";
        Font^ fuenteIndicador = gcnew Font("Arial", 10, FontStyle::Italic);
        SolidBrush^ colorIndicador = gcnew SolidBrush(Color::Yellow);
        canvas->DrawString(indicador, fuenteIndicador, colorIndicador, dialogoX + 20, dialogoY + dialogoAlto - 35);
        delete fuenteIndicador;
        delete colorIndicador;
    }

    delete fondoDialogo;
    delete bordeDialogo;
    delete fuenteDialogo;
    delete colorTexto;
}

void MundoIAService::cerrarDialogo() {
    mostrandoDialogo = false;
    indiceRobotColision = -1;
}

void MundoIAService::forzarDialogo(string texto) {
    mostrandoDialogo = true;
    gestorDialogos->getDialogoActual()->iniciar(texto);
}

void MundoIAService::actualizarCinematica() {
    enCinematica = true;

    if (pasoCinematica == 0) {
        pasoCinematica = 1;
    }
    else if (pasoCinematica == 1) {
        // Robots derecha bajan
        robots[0]->mover(Direccion::Abajo, robots[0]->getY(), 500, 6);
        robots[1]->mover(Direccion::Abajo, robots[1]->getY(), 600, 6);
        robots[2]->mover(Direccion::Abajo, robots[2]->getY(), 550, 6);

        if (robots[0]->getY() == 500 && robots[1]->getY() == 600 && robots[2]->getY() == 550) {
            for (int i = 0; i < 3; i++) robots[i]->setIndiceY(1);
            for (int i = 3; i < 6; i++) robots[i]->setIndiceY(3);
            pasoCinematica = 2;
        }
    }
    else if (pasoCinematica == 2) {
        // Caminan al centro
        int puntoMedioX = (robots[0]->getX() + robots[3]->getX()) / 2;

        for (int i = 0; i < 3; i++) {
            robots[i]->mover(Direccion::Izquierda, robots[i]->getX(), puntoMedioX + 100, 13);
        }
        for (int i = 3; i < 6; i++) {
            robots[i]->mover(Direccion::Derecha, robots[i]->getX(), puntoMedioX - 100, 13);
        }

        // Jugador asustado
        if (contador % 5 == 0) {
            jugador->setIndiceY(jugador->getIndiceY() == 3 ? 4 : 3);
        }

        if (robots[0]->getX() - robots[3]->getX() <= 200) {
            pasoCinematica = 3;
        }
    }
    else if (pasoCinematica == 3) {
        string mensaje = "ALERTA: Irregularidad detectada.\n";
        mensaje += "Tu comportamiento es ineficiente.\n";
        mensaje += "En la Maquina Suprema, el caos no es permitido.\n";
        mensaje += "Sometete al orden perfecto.";
        forzarDialogo(mensaje);
        pasoCinematica = 4;
    }
    else if (pasoCinematica == 4) {
        if (!mostrandoDialogo) {
            for (int i = 0; i < 3; i++) {
                robots[i]->mover(Direccion::Izquierda, robots[i]->getX(), 100, 10);
                if (robots[i]->getX() == 100) robots[i]->setIndiceY(3);
            }

            int extremoDerecho = 1700;
            for (int i = 3; i < 6; i++) {
                robots[i]->mover(Direccion::Derecha, robots[i]->getX(), extremoDerecho, 10);
                if (robots[i]->getX() == extremoDerecho) robots[i]->setIndiceY(1);
            }

            bool todosEnPosicion = true;
            for (int i = 0; i < 3; i++) {
                if (robots[i]->getX() != 100) todosEnPosicion = false;
            }
            for (int i = 3; i < 6; i++) {
                if (robots[i]->getX() != 1700) todosEnPosicion = false;
            }

            if (todosEnPosicion) enCinematica = false;
        }
    }
}

void MundoIAService::moverRobotsAuto() {
    for (auto robot : robots) {
        if (robot == nullptr) continue;

        int posInicial = robot->getX() - 50;
        int posFinal = robot->getX() + 50;

        if (robot->getIndiceY() == 1) {
            robot->mover(Direccion::Izquierda, posInicial, posFinal, 2);
            if (robot->getX() <= posInicial) robot->setIndiceY(3);
        }
        else if (robot->getIndiceY() == 3) {
            robot->mover(Direccion::Derecha, posInicial, posFinal, 2);
            if (robot->getX() >= posFinal) robot->setIndiceY(1);
        }
    }
}

bool MundoIAService::haLlegadoAlFinal() {
    return (jugador != nullptr && jugador->getX() > 1800);
}

void MundoIAService::dispararJugador() {
    Direccion dirBala = (jugador->getIndiceY() == 0 || jugador->getIndiceY() == 3) ?
        Izquierda : Derecha;
    Bala* nuevaBala = new Bala(jugador->getX() + 20, jugador->getY() + 20, dirBala);
    balas.push_back(nuevaBala);
}

void MundoIAService::actualizarProyectiles() {
    Direccion direccionBala = (jugador->getIndiceY() == 0 || jugador->getIndiceY() == 3) ?
        Izquierda : Derecha;

    for (int i = 0; i < balas.size(); i++) {
        balas[i]->mover(direccionBala, anchoPanel, altoPanel, 10);
        bool huboImpacto = false;

        // Colisión con robots
        for (int j = 0; j < robots.size(); j++) {
            if (balas[i]->getRectangle().IntersectsWith(robots[j]->getRectangle())) {
                robots.erase(robots.begin() + j);
                huboImpacto = true;
                break;
            }
        }

        // Colisión con boss
        if (!huboImpacto && boss != nullptr && !boss->estaDerrotado()) {
            if (balas[i]->getRectangle().IntersectsWith(boss->getRectangle())) {
                boss->recibirDano(1);
                huboImpacto = true;
            }
        }

        // Eliminar bala
        if (huboImpacto || balas[i]->fueraDePantalla(anchoPanel, altoPanel)) {
            balas.erase(balas.begin() + i);
            i--;
        }
    }
}

void MundoIAService::verificarEstadoJuego() {
    // Implementar lógica de recolección de chips y victoria
}