#include "MundoIAService.h"

MundoIAService::MundoIAService(int ancho, int alto, int vidas)
    : Mundo(ancho, alto, vidas) {
    jugador = nullptr;
    gestorDialogos = new DialogoService();
    mostrandoDialogo = false;
    indiceRobotColision = -1;
    esFondoNoche = false;  // ← CAMBIO
    fondoDia = nullptr;
    fondoNochePtr = nullptr;  // ← CAMBIO
}

MundoIAService::~MundoIAService() {
    if (jugador != nullptr) {
        delete jugador;
    }

    for (auto robot : robots) {
        if (robot != nullptr) {
            delete robot;
        }
    }
    robots.clear();

    if (gestorDialogos != nullptr) {
        delete gestorDialogos;
    }

    if (fondoDia != nullptr) {
        delete fondoDia;
    }

    if (fondoNochePtr != nullptr) {  // ← CAMBIO
        delete fondoNochePtr;
    }
}

void MundoIAService::cargarSpriteJugador(char* ruta, int filas, int columnas) {
    if (jugador == nullptr) {
        jugador = new Jugador(100, 400);  // Posición inicial
    }
    jugador->cargarImagen(ruta, filas, columnas);
}

void MundoIAService::crearRobots(char* ruta, int filas, int columnas) {
    // Limpiar robots existentes
    for (auto robot : robots) {
        if (robot != nullptr) {
            delete robot;
        }
    }
    robots.clear();

    // Crear 3 robots en diferentes posiciones Y
    int posicionesY[] = { 150, 350, 550 };

    for (int i = 0; i < 3; i++) {
        RobotEnemigo* robot = new RobotEnemigo(50, posicionesY[i]);
        robot->cargarImagen(ruta, filas, columnas);
        robot->setEscala(0.8f);
        robots.push_back(robot);
    }
}

void MundoIAService::cargarFondos(char* rutaDia, char* rutaNoche) {
    if (fondoDia == nullptr) {
        fondoDia = new Fondo(rutaDia, anchoPanel, altoPanel);
    }
    if (fondoNochePtr == nullptr) {  // ← CAMBIO
        fondoNochePtr = new Fondo(rutaNoche, anchoPanel, altoPanel);
    }
}

void MundoIAService::moverJugador(Direccion tecla) {
    if (jugador != nullptr && !mostrandoDialogo) {
        jugador->mover(tecla, anchoPanel, altoPanel);
    }
}

void MundoIAService::moverRobots() {
    for (auto robot : robots) {
        if (robot != nullptr) {
            // Movimiento simple de izquierda a derecha
            int x = robot->getX();
            int y = robot->getY();

            // Mover a la derecha
            robot->setX(x + 3);
            robot->setIndiceY(2);  // Animación derecha

            // Actualizar animación
            int indiceX = robot->getIndiceX();
            indiceX++;
            if (indiceX >= robot->getColumnas()) {
                indiceX = 0;
            }
            robot->setIndiceX(indiceX);

            // Si llega al borde derecho, reiniciar a la izquierda
            if (x > anchoPanel) {
                robot->setX(-100);  // Fuera del borde izquierdo
            }
        }
    }
}

void MundoIAService::verificarColisiones() {
    if (jugador == nullptr || mostrandoDialogo) return;

    Rectangle rectJugador = jugador->getRectangle();

    for (int i = 0; i < robots.size(); i++) {
        if (robots[i] != nullptr) {
            Rectangle rectRobot = robots[i]->getRectangle();

            // Verificar colisión
            if (rectJugador.IntersectsWith(rectRobot)) {
                // Activar diálogo
                mostrandoDialogo = true;
                indiceRobotColision = i;

                // Iniciar diálogo aleatorio
                string textoDialogo = gestorDialogos->obtenerDialogo(i % 15);
                gestorDialogos->getDialogoActual()->iniciar(textoDialogo);

                break;  // Solo una colisión a la vez
            }
        }
    }
}

void MundoIAService::cambiarFondo() {
    if (jugador == nullptr) return;

    int anchoEscalado = (int)(jugador->getAncho() * jugador->getEscala());

    if (jugador->getX() >= anchoPanel - anchoEscalado - 50) {
        esFondoNoche = true;  // ← CAMBIO
    }
}

void MundoIAService::actualizarDialogo() {
    if (mostrandoDialogo && gestorDialogos != nullptr) {
        Dialogo* dialogo = gestorDialogos->getDialogoActual();

        if (dialogo != nullptr) {
            // Actualizar el efecto de escritura
            dialogo->actualizar();

            // Si el diálogo terminó, permitir cerrarlo
            if (!dialogo->estaEnProgreso()) {
                // El jugador puede presionar una tecla para cerrarlo
                // Esto se maneja en el formulario
            }
        }
    }
}

string MundoIAService::getDialogoActual() {
    if (gestorDialogos != nullptr && gestorDialogos->getDialogoActual() != nullptr) {
        return gestorDialogos->getDialogoActual()->getTextoActual();
    }
    return "";
}

Jugador* MundoIAService::getJugador() {
    return jugador;
}

vector<RobotEnemigo*>& MundoIAService::getRobots() {
    return robots;
}

void MundoIAService::dibujarTodo(Graphics^ canvas) {
    // Dibujar fondo (día o noche)
    // Dibujar fondo (día o noche)
    if (esFondoNoche && fondoNochePtr != nullptr) {  // ← CAMBIO
        fondoNochePtr->dibujar(canvas);  // ← CAMBIO
    }
    else if (fondoDia != nullptr) {
        fondoDia->dibujar(canvas);
    }


    // Dibujar robots
    for (auto robot : robots) {
        if (robot != nullptr) {
            robot->dibujar(canvas);
        }
    }

    // Dibujar jugador
    if (jugador != nullptr) {
        jugador->dibujar(canvas);
    }

    // Dibujar diálogo si está activo
    if (mostrandoDialogo && gestorDialogos != nullptr) {
        Dialogo* dialogo = gestorDialogos->getDialogoActual();
        if (dialogo != nullptr && dialogo->estaEnProgreso()) {
            // Dibujar cuadro de diálogo
            int dialogoX = anchoPanel / 2 - 300;
            int dialogoY = altoPanel - 200;
            int dialogoAncho = 600;
            int dialogoAlto = 150;

            // Fondo del diálogo
            SolidBrush^ fondoDialogo = gcnew SolidBrush(Color::FromArgb(230, 20, 20, 40));
            canvas->FillRectangle(fondoDialogo, dialogoX, dialogoY, dialogoAncho, dialogoAlto);

            // Borde del diálogo
            Pen^ bordeDialogo = gcnew Pen(Color::FromArgb(255, 100, 200, 255), 3);
            canvas->DrawRectangle(bordeDialogo, dialogoX, dialogoY, dialogoAncho, dialogoAlto);

            // Texto del diálogo
            String^ textoManaged = gcnew String(dialogo->getTextoActual().c_str());
            Font^ fuenteDialogo = gcnew Font("Arial", 14, FontStyle::Regular);
            SolidBrush^ colorTexto = gcnew SolidBrush(Color::White);

            RectangleF areaTexto = RectangleF(
                dialogoX + 20,
                dialogoY + 20,
                dialogoAncho - 40,
                dialogoAlto - 40
            );

            canvas->DrawString(textoManaged, fuenteDialogo, colorTexto, areaTexto);

            // Indicador de "presiona Enter para continuar" si terminó
            if (!dialogo->estaEnProgreso()) {
                String^ indicador = "Presiona ENTER para continuar...";
                Font^ fuenteIndicador = gcnew Font("Arial", 10, FontStyle::Italic);
                SolidBrush^ colorIndicador = gcnew SolidBrush(Color::Yellow);

                canvas->DrawString(
                    indicador,
                    fuenteIndicador,
                    colorIndicador,
                    dialogoX + 400,
                    dialogoY + dialogoAlto - 30
                );
            }
        }
    }
}

void MundoIAService::cerrarDialogo() {
    mostrandoDialogo = false;
    indiceRobotColision = -1;
}