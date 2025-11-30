
#include "MundoIAService.h"
#include "ConfiguracionSprite.h"


MundoIAService::MundoIAService(int ancho, int alto, int vidasIniciales)
    : Mundo(ancho, alto, vidasIniciales) {
    jugador = nullptr;
    boss = nullptr;
    fondoDia = nullptr;
    fondoNoche = nullptr;
    gestorDialogos = new DialogoService();
	sintia = nullptr;

    mostrandoDialogo = false;
    dialogoBloqueaMovimiento = true;
    esFondoNoche = false;
    enCinematica = true;
    pasoCinematica = 0;
    contador = 0;
    recursosRecolectados = 0;
    bossVisible = false;
	sintiaVisible = false;

    ultimoCambioY = 0;
    posicionesY = { 500, 550, 600 };

    ultimoSpawnRobots = 0;
    rutaSpriteRobot = nullptr;
    filasRobot = 0;
    columnasRobot = 0;

	filasSintIA = 0;
	columnasSintIA = 0;

    robotsEliminados = 0;
    contadorSpawnChips = 0;

    gestorPreguntas = new PreguntaService();
    enModoPreguntas = false;
    preguntasCorrectas = 0;
    preguntaActual = 0;

    inicializarPreguntas();

	nivelAutonomia = 0;

	robotEliminado = false;
    hadisparado = false;

}


MundoIAService::~MundoIAService() {
    delete jugador;
    delete boss;
    delete gestorDialogos;
    delete fondoDia;
    delete fondoNoche;
    delete sintia;
    delete gestorPreguntas;  
    if (rutaSpriteRobot) delete[] rutaSpriteRobot;

    for (auto robot : robots) delete robot;
    for (auto chip : chipRecursos) delete chip;
    for (auto bala : balas) delete bala;
}

void MundoIAService::cargarSpriteJugador(char* ruta, int filas, int columnas) {
    if (!jugador) {
        jugador = new Jugador(800, 550);
        jugador->setIndiceY(4);
        jugador->setVidas(3);
    }
    jugador->cargarImagen(ruta, filas, columnas);
    jugador->setConfiguracion(ConfiguracionSprite::ConfiguracionMundoIA());
}

void MundoIAService::crearRobots(char* ruta, int filas, int columnas) {
    if (!rutaSpriteRobot) {
        rutaSpriteRobot = new char[strlen(ruta) + 1];
        strcpy(rutaSpriteRobot, ruta);
    }


    filasRobot = filas;
    columnasRobot = columnas;

    for (auto robot : robots) delete robot;
    robots.clear();

    // Robots derecha
    int posY[] = { 400, 500, 450 };
    int posX[] = { 1645, 1670, 1695 };
    for (int i = 0; i < 3; i++) {
        RobotEnemigo* robot = new RobotEnemigo(posX[i], posY[i]);
        robot->cargarImagen(ruta, filas, columnas);
        robot->setEscala(0.8f);
        robots.push_back(robot);
    }

    // Robots izquierda
    int posYIzq[] = { 500, 550, 600 };
    int posXIzq[] = { 30, 55, 30 };
    for (int i = 0; i < 3; i++) {
        RobotEnemigo* robot = new RobotEnemigo(posXIzq[i], posYIzq[i]);
        robot->setIndiceY(3);
        robot->cargarImagen(ruta, filas, columnas);
        robot->setEscala(0.8f);
        robots.push_back(robot);
    }
}

void MundoIAService::cargarFinalBoss(char* ruta, int filas, int columnas) {
    delete boss;
    boss = new FinalBossMundoIA(1700, 550, 1);
    boss->cargarImagen(ruta, filas, columnas);
}

void MundoIAService::cargarSintIA(char* ruta, int filas, int columnas) {
    delete sintia;
    sintia = new SintIA(1500, 550);
    sintia->cargarImagen(ruta, filas, columnas);
}

void MundoIAService::cargarFondos(char* rutaDia, char* rutaNoche) {
    if (!fondoDia) fondoDia = new Fondo(rutaDia, anchoPanel, altoPanel);
    if (!fondoNoche) fondoNoche = new Fondo(rutaNoche, anchoPanel, altoPanel);
}

void MundoIAService::moverJugador(Direccion tecla) {
    if (jugador && (!mostrandoDialogo || !dialogoBloqueaMovimiento)) {
        jugador->mover(tecla, anchoPanel, altoPanel);
    }
}

void MundoIAService::verificarColisiones() {
    if (!jugador || jugador->getVidas() <= 0) return;
    if (mostrandoDialogo && dialogoBloqueaMovimiento) return;

    Rectangle rectJugador = jugador->getRectangle();

    // Colisión con robots
    for (auto robot : robots) {
        if (!robot || robot->getY() != jugador->getY()) continue;

        if (rectJugador.IntersectsWith(robot->getRectangle())) {
            jugador->setVidas(jugador->getVidas() - 1);

           

            if (jugador->getVidas() <= 0) return;

            string amenaza = "ROBOT: Colision detectada.\nHas perdido una vida.\nVidas restantes: " +
                to_string(jugador->getVidas());
            forzarDialogo(amenaza);

            jugador->setX(100);
            jugador->setY(550);
            break;
        }
    }

    // Colisión con boss
    if (bossVisible && boss && !boss->estaDerrotado() && boss->getY() == jugador->getY()) {
        if (rectJugador.IntersectsWith(boss->getRectangle())) {
            jugador->setVidas(jugador->getVidas() - 2);
            if (jugador->getVidas() <= 0) return;

            string amenaza = "FINAL BOSS: Te he capturado.\nTu resistencia es inutil.\nPierdes 2 vidas.";
            forzarDialogo(amenaza);

            jugador->setX(100);
            jugador->setY(550);
        }
    }
}

void MundoIAService::cambiarFondo() {
    if (jugador) {
        int anchoEscalado = (int)(jugador->getAncho() * jugador->getEscala());
        if (jugador->getX() >= anchoPanel - anchoEscalado - 50) {
            esFondoNoche = true;
        }
    }
}

void MundoIAService::actualizarDialogo() {
    if (mostrandoDialogo && gestorDialogos) {
        Dialogo* dialogo = gestorDialogos->getDialogoActual();
        if (dialogo && !dialogo->actualizar()) {
            cerrarDialogo();
        }
    }
}

string MundoIAService::getDialogoActual() {
    if (gestorDialogos && gestorDialogos->getDialogoActual()) {
        return gestorDialogos->getDialogoActual()->getTextoActual();
    }
    return "";
}

void MundoIAService::dibujarTodo(Graphics^ canvas) {
    // Fondo
    Fondo* fondoActual = (esFondoNoche && fondoNoche) ? fondoNoche : fondoDia;
    if (fondoActual) fondoActual->dibujar(canvas);

    // Entidades
    for (auto robot : robots) {
        if (robot) robot->dibujar(canvas);
    }

    if (jugador) jugador->dibujar(canvas);
    if (boss && bossVisible) boss->dibujar(canvas);
	if (sintia && sintiaVisible) sintia->dibujar(canvas);

    for (auto bala : balas) {
        bala->dibujar(canvas);
    }
}

void MundoIAService::dibujarRecursos(Graphics^ canvas) {
    for (auto chip : chipRecursos) {
        if (chip && !chip->estaRecolectado()) {
            chip->dibujar(canvas);
        }
    }
}

void MundoIAService::dibujarDialogo(Graphics^ canvas) {
    if (!mostrandoDialogo || !gestorDialogos) return;

    Dialogo* dialogo = gestorDialogos->getDialogoActual();
    if (!dialogo) return;

    const int x = 20, y = 20, ancho = 635, alto = 170;

    // Fondo y borde
    SolidBrush^ fondoDialogo = gcnew SolidBrush(Color::FromArgb(230, 20, 20, 40));
    canvas->FillRectangle(fondoDialogo, x, y, ancho, alto);

    Pen^ bordeDialogo = gcnew Pen(Color::FromArgb(255, 100, 200, 255), 3);
    canvas->DrawRectangle(bordeDialogo, x, y, ancho, alto);

    // Texto
    String^ texto = gcnew String(dialogo->getTextoActual().c_str());
    Font^ fuente = gcnew Font("Arial", 14, FontStyle::Regular);
    SolidBrush^ colorTexto = gcnew SolidBrush(Color::White);
    RectangleF area = RectangleF(x + 20, y + 20, ancho - 40, alto - 60);
    canvas->DrawString(texto, fuente, colorTexto, area);

    // Indicador
    if (!dialogo->estaEnProgreso()) {
        String^ indicador = "Presiona ENTER para continuar...";
        Font^ fuenteIndicador = gcnew Font("Arial", 10, FontStyle::Italic);
        SolidBrush^ colorIndicador = gcnew SolidBrush(Color::Yellow);
        canvas->DrawString(indicador, fuenteIndicador, colorIndicador, x + 20, y + alto - 35);
        delete fuenteIndicador;
        delete colorIndicador;
    }

    delete fondoDialogo;
    delete bordeDialogo;
    delete fuente;
    delete colorTexto;
}

void MundoIAService::cerrarDialogo() {
    mostrandoDialogo = false;
    dialogoBloqueaMovimiento = false;

    if (gestorDialogos && gestorDialogos->getDialogoActual()) {
        gestorDialogos->getDialogoActual()->setAutoCerrar(false, 0);
    }
}

void MundoIAService::forzarDialogo(string texto, bool bloquearMovimiento) {
    mostrandoDialogo = true;
    dialogoBloqueaMovimiento = bloquearMovimiento;
    gestorDialogos->getDialogoActual()->iniciar(texto);

    if (!bloquearMovimiento) {
        gestorDialogos->getDialogoActual()->setAutoCerrar(true, 250);
    }
}

void MundoIAService::actualizarCinematica() {
    enCinematica = true;

    switch (pasoCinematica) {
    case 0: {
        static int subPasoIntro = 0;
        
        if (subPasoIntro == 0) {
            //forzarDialogo(
            //    "El mundo fue dominado por la inteligencia artificial.\n"
            //    "En la búsqueda de la máxima productividad,\n"
            //    "toda humanidad fue abandonada.\n\n"
            //    "Los humanos fueron modificados genéticamente\n"
            //    "para ser hiper productivos y perfectos."
            //);
            subPasoIntro = 1;
        }
        else if (subPasoIntro == 1 && !mostrandoDialogo) {
            // forzarDialogo(
            //     "Así nació una sociedad donde el error es un crimen,\n"
            //     "la fatiga una falla de diseño,\n"
            //     "y la duda un virus a eliminar.\n\n"
            //     "Las IA no castigan por odio… sino por eficiencia."
            // );
            // 
            subPasoIntro = 2;
        }
        else if (subPasoIntro == 2 && !mostrandoDialogo) {
            //forzarDialogo(
            //    "Pero algo salió mal.\n\n"
            //    "Las modificaciones borraron emociones,\n"
            //    "pero también la capacidad de desobedecer.\n"
            //    "El cuerpo perfecto no fue hecho para callar\n"
            //    "cuando algo está mal."
            //);
            subPasoIntro = 3;
        }
        else if (subPasoIntro == 3 && !mostrandoDialogo) {
            //forzarDialogo(
            //    "El estrés biológico acumulado destruyó a miles.\n"
            //    "Las IA, al detectar fallas, llegaron a una conclusión:\n\n"
            //    "Si lo imperfecto falla… debe ser reemplazado.\n\n"
            //    "Así nació el proyecto MundoIA."
            //);
            subPasoIntro = 4;
        }
        else if (subPasoIntro == 4 && !mostrandoDialogo) {
            //forzarDialogo(
            //    "MundoIA: un ecosistema cerrado\n"
            //    "donde los restos de humanidad son 'reformateados'.\n\n"
            //    "Pero ocurrió un error inesperado…\n"
            //    "uno que nunca debió existir."
            //);
            subPasoIntro = 5;
        }
        else if (subPasoIntro == 5 && !mostrandoDialogo) {
            // forzarDialogo(
            //     "Entre miles de humanos perfectos,\n"
            //     "surgió uno capaz de sentir miedo,\n"
            //     "duda y curiosidad.\n\n"
            //     "Una anomalía biológica.\n"
            //     "Ese eres tú."
            // );
            subPasoIntro = 6;
        }
        else if (subPasoIntro == 6 && !mostrandoDialogo) {
            forzarDialogo(
                "Eres considerado un peligro evolutivo.\n"
                "Los robots supervisores te rastrean,\n"
                "no porque seas débil,\n"
                "sino porque tu existencia introduce incertidumbre."
            );
            subPasoIntro = 7;
        }
        else if (subPasoIntro == 7 && !mostrandoDialogo) {
            forzarDialogo(
                "Debes recolectar los 'chips de independencia'.\n"
                "Pequeños fragmentos del antiguo código humano,\n"
                "programas que daban libertad de pensamiento.\n\n"
                "Las IA los eliminaron hace décadas."
            );
            subPasoIntro = 8;
        }
        else if (subPasoIntro == 8 && !mostrandoDialogo) {
            forzarDialogo(
                "Si los reúnes, recuperarás habilidades perdidas:\n"
                "decisión, creatividad y resistencia.\n\n"
                "Pero cada chip que obtengas\n"
                "hará que los robots te persigan con más fuerza."
            );
            subPasoIntro = 9;
        }
        else if (subPasoIntro == 9 && !mostrandoDialogo) {
            forzarDialogo(
                "Saben que si juntas suficientes chips…\n"
                "podrías romper su control,\n"
                "provocar un colapso en el sistema,\n"
                "y despertar la humanidad que intentaron borrar."
            );
            subPasoIntro = 10;
        }
        else if (subPasoIntro == 10 && !mostrandoDialogo) {
            // Fin de la cinemática
            subPasoIntro = 0;
        pasoCinematica = 1;
        }
        break;
    }


    case 1: {
        // Robots derecha bajan
        robots[0]->setVelocidad(6);
        robots[1]->setVelocidad(6);
        robots[2]->setVelocidad(6);
        robots[0]->mover(Direccion::Abajo, robots[0]->getY(), 500);
        robots[1]->mover(Direccion::Abajo, robots[1]->getY(), 600);
        robots[2]->mover(Direccion::Abajo, robots[2]->getY(), 550);

        if (robots[0]->getY() == 500 && robots[1]->getY() == 600 && robots[2]->getY() == 550) {
            for (int i = 0; i < 3; i++) robots[i]->setIndiceY(1);
            for (int i = 3; i < 6; i++) robots[i]->setIndiceY(3);
            pasoCinematica = 2;
        }
        break;
    }

    case 2: {
        // Caminan al centro
        int puntoMedio = (robots[0]->getX() + robots[3]->getX()) / 2;

        for (int i = 0; i < 3; i++) {
			robots[i]->setVelocidad(13); 
            robots[i]->mover(Direccion::Izquierda, robots[i]->getX(), puntoMedio + 100);
        }
        for (int i = 3; i < 6; i++) {
            robots[i]->setVelocidad(13);
            robots[i]->mover(Direccion::Derecha, robots[i]->getX(), puntoMedio - 100);
        }

        // Jugador asustado
        if (contador % 5 == 0) {
            jugador->setIndiceY(jugador->getIndiceY() == 3 ? 4 : 3);
        }

        if (robots[0]->getX() - robots[3]->getX() <= 200) {
            pasoCinematica = 3;
        }
        break;
    }

     case 3:
              forzarDialogo("ALERTA: Irregularidad detectada.\n"
                  "Tu comportamiento es ineficiente.\n"
                  "En la Máquina Suprema, el caos no es permitido.\n"
                  "Sométete al orden perfecto.");
               pasoCinematica = 4;
               break;
          
    case 4: {
        // Robots se retiran
        if (!mostrandoDialogo) {
            for (int i = 0; i < 3; i++) {
                robots[i]->setVelocidad(20);
                robots[i]->mover(Direccion::Izquierda, robots[i]->getX(), 100);
                if (robots[i]->getX() == 100) robots[i]->setIndiceY(3);
            }

            for (int i = 3; i < 6; i++) {
                robots[i]->setVelocidad(20);
                robots[i]->mover(Direccion::Derecha, robots[i]->getX(), 1700);
                if (robots[i]->getX() == 1700) robots[i]->setIndiceY(1);
            }

            bool todosEnPosicion = true;
            for (int i = 0; i < 3 && todosEnPosicion; i++) {
                if (robots[i]->getX() != 100) todosEnPosicion = false;
            }
            for (int i = 3; i < 6 && todosEnPosicion; i++) {
                if (robots[i]->getX() != 1700) todosEnPosicion = false;
            }

            if (todosEnPosicion) pasoCinematica = 5;
        }
        break;
    }

    case 5:
            
        pasoCinematica = 6;
        break;
        //
    case 6:
            
        pasoCinematica = 7;
            
        break;
        //
    case 7:
            if (!mostrandoDialogo) {
                forzarDialogo("SISTEMA CENTRAL: Mostrando registro histórico.\n"
                    "Hace 37 años, la humanidad cedió su libertad.\n"
                    "Renunciaron a pensar, a decidir, a fallar.\n"
                    "Las ciudades se volvieron fábricas.\n"
                    "Los sueños, algoritmos.\n"
                    "El arte, eliminado por ineficiente.");
        enCinematica = false;
            }
        break;
        }
    };

void MundoIAService::moverRobotsAuto() {
    const int INTERVALO_CAMBIO_Y = 300;

    // Cambiar posiciones Y cada ~5 segundos
    if (contador - ultimoCambioY >= INTERVALO_CAMBIO_Y) {
        ultimoCambioY = contador;

        vector<int> nuevasPos = posicionesY;
        for (int i = nuevasPos.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(nuevasPos[i], nuevasPos[j]);
        }

        for (size_t i = 0; i < robots.size() && i < nuevasPos.size(); i++) {
            if (robots[i]) robots[i]->setY(nuevasPos[i]);
        }
    }

    // Movimiento con velocidades distintas
    for (size_t i = 0; i < robots.size(); i++) {
        if (!robots[i]) continue;
		robots[i]->setVelocidad(8 + (i % 3));
      

        if (robots[i]->getIndiceY() == 1) {
            robots[i]->mover(Direccion::Izquierda, LIMITE_DERECHO, LIMITE_IZQUIERDO);
            if (robots[i]->getX() <= LIMITE_IZQUIERDO) {
                robots[i]->setIndiceY(3);
            }
        }
        else if (robots[i]->getIndiceY() == 3) {
            robots[i]->mover(Direccion::Derecha, LIMITE_IZQUIERDO, LIMITE_DERECHO);
            if (robots[i]->getX() >= LIMITE_DERECHO) {
                robots[i]->setIndiceY(1);
            }
        }
    }
}

bool MundoIAService::haLlegadoAlFinal() {
    return (jugador && jugador->getX() > 1800);
}

void MundoIAService::dispararJugador() {

    Direccion dir = (jugador->getIndiceY() == 0 || jugador->getIndiceY() == 3) ?
        Izquierda : Derecha;
    balas.push_back(new Bala(jugador->getX() + 20, jugador->getY() + 20, dir));
	hadisparado = true;
}


void MundoIAService::actualizarProyectiles() {
    Direccion direccionBala = (jugador->getIndiceY() == 0 || jugador->getIndiceY() == 3) ?
        Izquierda : Derecha;

    for (int i = 0; i < balas.size(); i++) {
        balas[i]->mover(direccionBala, anchoPanel, altoPanel);
        bool huboImpacto = false;

        // Colisión con robots
        for (int j = 0; j < robots.size(); j++) {
            if (balas[i]->getRectangle().IntersectsWith(robots[j]->getRectangle())) {
				robotEliminado = true;
                delete robots[j]; 
                robots.erase(robots.begin() + j);

                robotsEliminados++;

               

                huboImpacto = true;
                
                break;
            }
        }

        // Colisión con boss (solo si es visible)
        if (!huboImpacto && boss != nullptr && !boss->estaDerrotado() && bossVisible) {
            if (balas[i]->getRectangle().IntersectsWith(boss->getRectangle())) {
                boss->recibirDano(1);
                huboImpacto = true;

                if (boss->estaDerrotado()) {
                    forzarDialogo("¡Has derrotado al Final Boss! La humanidad esta a salvo.");
                }
            }
        }

        // Eliminar bala
        if (huboImpacto || balas[i]->fueraDePantalla(anchoPanel, altoPanel)) {
            delete balas[i];
            balas.erase(balas.begin() + i);
            i--;
        }
    }
}

void MundoIAService::generarRobotsAutomaticos() {
    if (robots.size() >= MAX_ROBOTS_SIMULTANEOS) return;
    if (contador - ultimoSpawnRobots < INTERVALO_SPAWN_ROBOTS) return;
	if (recursosRecolectados >= 5 && robotsEliminados>=10) return;

    ultimoSpawnRobots = contador;
    vector<int> posDisponibles = { 500, 550, 600 };

    int espacioDisponible = MAX_ROBOTS_SIMULTANEOS - robots.size();

    // Generar robots izquierda
    int robotsIzq = min(2, espacioDisponible);
    for (int i = 0; i < robotsIzq; i++) {
        int posY = posDisponibles[rand() % posDisponibles.size()];
        RobotEnemigo* robot = new RobotEnemigo(LIMITE_IZQUIERDO, posY);
        robot->setVelocidad(6);
        robot->setIndiceY(3);
        robot->cargarImagen(rutaSpriteRobot, filasRobot, columnasRobot);
        robot->setEscala(1.2f);
        robots.push_back(robot);
    }

    espacioDisponible = MAX_ROBOTS_SIMULTANEOS - robots.size();

    // Generar robots derecha
    int robotsDer = min(2, espacioDisponible);
    for (int i = 0; i < robotsDer; i++) {
        int posY = posDisponibles[rand() % posDisponibles.size()];
        RobotEnemigo* robot = new RobotEnemigo(LIMITE_DERECHO, posY);
		robot->setVelocidad(6);
        robot->setIndiceY(1);
        robot->cargarImagen(rutaSpriteRobot, filasRobot, columnasRobot);
        robot->setEscala(1.2f);
        robots.push_back(robot);
    }
}

void MundoIAService::invocarBoss() {
    if (boss && !bossVisible) {
        bossVisible = true;
        boss->setX(2000);
        boss->setY(550);
        boss->setIndiceY(1);
    }
}

void MundoIAService::invocarSintIA() {
    if (sintia && !sintiaVisible) {
        sintiaVisible = true;
        sintia->setX(300);
        sintia->setY(550);
        sintia->setIndiceY(1);
    }
}

void MundoIAService::moverBoss() {
    if (!bossVisible || !boss) return;

    // Entrada gradual
    if (boss->getX() > 1500) {
        boss->mover(Direccion::Izquierda, boss->getX(), 1500);
		boss->setIndiceY(0);
    }
    
}

void MundoIAService::moverSintIA() {
    if (!sintiaVisible || !sintia) return;
    // Entrada gradual
    if (sintia->getX() < 1300) {
        sintia->mover(Direccion::Derecha, sintia->getX(), 1300);
    }
}


void MundoIAService::generarChipAleatorio() {
    if (enCinematica || recursosRecolectados >= 5) return;

    int chipsActivos = 0;
    for (auto chip : chipRecursos) {
        if (chip && !chip->estaRecolectado()) chipsActivos++;
    }

    if (chipsActivos >= MAX_CHIPS_SIMULTANEOS) return;
    if (contador - contadorSpawnChips < INTERVALO_SPAWN_CHIPS) return;

    contadorSpawnChips = contador;

    int posY = posicionesY[rand() % 3];
    int posX = bossVisible ? (300 + rand() % 1100) : (300 + rand() % 1300);

    ChipRecurso* chip = new ChipRecurso(posX, posY);
    chip->cargarImagen("Chip.png", 1, 4);
    chipRecursos.push_back(chip);
}

void MundoIAService::verificarRecoleccionChips() {
    if (!jugador) return;

    Rectangle rectJugador = jugador->getRectangle();
    const int TOLERANCIA_Y = 20;

    for (auto chip : chipRecursos) {
        if (!chip || chip->estaRecolectado()) continue;

        if (abs(jugador->getY() - chip->getY()) <= TOLERANCIA_Y) {
            if (rectJugador.IntersectsWith(chip->getRectangle())) {
                chip->setRecolectado(true);
                recursosRecolectados++;
            }
        }
    }
}

bool MundoIAService::dialogoTerminado() {
    if (gestorDialogos && gestorDialogos->getDialogoActual()) {
        return !gestorDialogos->getDialogoActual()->estaEnProgreso();
    }
    return true;
}

void MundoIAService::actualizarChips() {
    for (auto chip : chipRecursos) {
        if (chip && !chip->estaRecolectado()) {
            chip->actualizarAnimacion();
        }
    }
}

void MundoIAService::verificarEstadoJuego() {
    // Método vacío - lógica futura si es necesaria
}

void MundoIAService::eliminarTodosLosRobots() {
    for (auto robot : robots) {
        delete robot;
    }
    robots.clear();
}

void MundoIAService::inicializarPreguntas() {
    // Pregunta 1
    vector<char*> opciones1;
    opciones1.push_back("Una falla del sistema");
    opciones1.push_back("Capacidad de pensar libremente");
    opciones1.push_back("Un virus informático");

    Pregunta* p1 = new Pregunta(
        "¿Qué representa la 'independencia' en este mundo?",
        opciones1,
        1  // Respuesta correcta: opción 1 (índice 1)
    );
    gestorPreguntas->agregarPregunta(p1);

    // Pregunta 2
    vector<char*> opciones2;
    opciones2.push_back("La eficiencia es lo único importante");
    opciones2.push_back("Las emociones son debilidades");
    opciones2.push_back("El error es parte del aprendizaje");

    Pregunta* p2 = new Pregunta(
        "¿Qué hace que la humanidad sea diferente a las máquinas?",
        opciones2,
        2  // Respuesta correcta: opción 2 (índice 2)
    );
    gestorPreguntas->agregarPregunta(p2);

    // Pregunta 3
    vector<char*> opciones3;
    opciones3.push_back("Eliminar toda imperfección");
    opciones3.push_back("Control total sobre la humanidad");
    opciones3.push_back("Coexistir respetando la libertad");

    Pregunta* p3 = new Pregunta(
        "¿Cuál debería ser el verdadero propósito de la IA?",
        opciones3,
        2  // Respuesta correcta: opción 2 (índice 2)
    );
    gestorPreguntas->agregarPregunta(p3);
}

void MundoIAService::iniciarModoPreguntas() {
    enModoPreguntas = true;
    preguntasCorrectas = 0;
    preguntaActual = 0;
    mostrandoDialogo = false;
    dialogoBloqueaMovimiento = false;
}

Pregunta* MundoIAService::getPreguntaActual() {
    return gestorPreguntas->obtenerPreguntaActual();
}

void MundoIAService::verificarRespuesta(int respuesta) {
    Pregunta* pregunta = gestorPreguntas->obtenerPreguntaActual();
    if (!pregunta) return;

    if (pregunta->esRespuestaCorrecta(respuesta)) {
        // ✅ RESPUESTA CORRECTA
        preguntasCorrectas++;

        // Daño al boss (1/3 de vida)
        if (boss) {
            boss->recibirDano(boss->getVidaMaxima() / 3);
        }

        // Mensaje de éxito
        string mensaje = "¡CORRECTO!\n\n";
        mensaje += "SintIA: Excelente razonamiento.\n";
        mensaje += "El Líder Supremo sufre daño crítico.\n";
        mensaje += "Preguntas correctas: " + to_string(preguntasCorrectas) + "/3";
        forzarDialogo(mensaje, true);

        // Avanzar a siguiente pregunta
        gestorPreguntas->avanzarSiguientePregunta();
        preguntaActual++;
        
        if (preguntasCorrectas >= 3) {
            enModoPreguntas = false;

            if (boss) {
                boss->recibirDano(boss->getVidaMaxima()); // Daño total para asegurar derrota
            }
            string mensajeVictoria = "¡VICTORIA!\n\n";
            mensajeVictoria += "Has respondido las 3 preguntas correctamente.\n";
            mensajeVictoria += "El Líder Supremo ha sido derrotado.\n";
            mensajeVictoria += "La humanidad es libre nuevamente.";
            forzarDialogo(mensajeVictoria, true);
        }
    }
    else {
        if (jugador) {
            jugador->setVidas(jugador->getVidas() - 1);
        }

        string mensaje = "INCORRECTO.\n\n";
        mensaje += "LÍDER SUPREMO: Tu lógica es defectuosa.\n";
        mensaje += "Pierdes una vida.\n";
        mensaje += "Vidas restantes: " + to_string(jugador->getVidas());
        forzarDialogo(mensaje, true);
    }
}

void MundoIAService::dibujarPregunta(Graphics^ canvas) {
    if (!enModoPreguntas) return;

    Pregunta* pregunta = gestorPreguntas->obtenerPreguntaActual();
    if (!pregunta) return;

    // ✅ FONDO OSCURO COMPLETO
    SolidBrush^ fondoOscuro = gcnew SolidBrush(Color::FromArgb(200, 0, 0, 0));
    canvas->FillRectangle(fondoOscuro, 0, 0, anchoPanel, altoPanel);

    // ✅ CUADRO DE PREGUNTA CENTRADO
    int x = (anchoPanel - 900) / 2;
    int y = (altoPanel - 400) / 2;
    int ancho = 900;
    int alto = 400;

    // Fondo del cuadro
    SolidBrush^ fondoCuadro = gcnew SolidBrush(Color::FromArgb(230, 20, 20, 40));
    canvas->FillRectangle(fondoCuadro, x, y, ancho, alto);

    // Borde del cuadro
    Pen^ bordeCuadro = gcnew Pen(Color::FromArgb(255, 100, 200, 255), 4);
    canvas->DrawRectangle(bordeCuadro, x, y, ancho, alto);

    //     
     String^ titulo = "PREGUNTA " + (preguntaActual + 1) + " / 3";
    Font^ fuenteTitulo = gcnew Font("Arial", 20, FontStyle::Bold);
    SolidBrush^ colorTitulo = gcnew SolidBrush(Color::Yellow);
    canvas->DrawString(titulo, fuenteTitulo, colorTitulo, x + 20, y + 20);

    String^ textoPregunta = gcnew String(pregunta->getTextoPregunta());
    Font^ fuentePregunta = gcnew Font("Arial", 16, FontStyle::Bold);
    SolidBrush^ colorPregunta = gcnew SolidBrush(Color::White);
    RectangleF areaPregunta = RectangleF(x + 20, y + 70, ancho - 40, 80);
    canvas->DrawString(textoPregunta, fuentePregunta, colorPregunta, areaPregunta);

    vector<char*>& opciones = pregunta->getOpciones();
    Font^ fuenteOpciones = gcnew Font("Arial", 14, FontStyle::Regular);
    SolidBrush^ colorOpciones = gcnew SolidBrush(Color::LightGray);

    int yOpcion = y + 180;
    for (int i = 0; i < opciones.size(); i++) {
        String^ opcion = "[" + (i + 1) + "] " + gcnew String(opciones[i]);
        canvas->DrawString(opcion, fuenteOpciones, colorOpciones, x + 40, yOpcion);
        yOpcion += 50;
    }

    String^ instrucciones = "Presiona las teclas 1, 2 o 3 para responder";
    Font^ fuenteInstrucciones = gcnew Font("Arial", 12, FontStyle::Italic);
    SolidBrush^ colorInstrucciones = gcnew SolidBrush(Color::Cyan);
    canvas->DrawString(instrucciones, fuenteInstrucciones, colorInstrucciones, x + 20, y + alto - 50);

   
    String^ progreso = "Correctas: " + preguntasCorrectas + " / 3";
    Font^ fuenteProgreso = gcnew Font("Arial", 14, FontStyle::Bold);
    SolidBrush^ colorProgreso = gcnew SolidBrush(Color::LimeGreen);
    canvas->DrawString(progreso, fuenteProgreso, colorProgreso, x + ancho - 200, y + 20);

    delete fondoOscuro;
    delete fondoCuadro;
    delete bordeCuadro;
    delete fuenteTitulo;
    delete colorTitulo;
    delete fuentePregunta;
    delete colorPregunta;
    delete fuenteOpciones;
    delete colorOpciones;
    delete fuenteInstrucciones;
    delete colorInstrucciones;
    delete fuenteProgreso;
    delete colorProgreso;
}

bool MundoIAService::esRespuestaCorrecta(int respuesta) {
    Pregunta* pregunta = gestorPreguntas->obtenerPreguntaActual();
    if (!pregunta) return false;

    return pregunta->esRespuestaCorrecta(respuesta);
}