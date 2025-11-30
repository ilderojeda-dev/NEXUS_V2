#include "MundoColabService.h"

#include <cstdlib>
#include <ctime>
#include "ConfiguracionSprite.h"
using namespace System::Drawing;


MundoColabService::MundoColabService(int ancho, int alto, int vidasIniciales)
: Mundo(ancho, alto, vidasIniciales) {
nave = new Nave(50, 50);

necesitaRecargar = false;
srand(time(NULL)); // Inicializar la semilla para números aleatorios
mostrandoPregunta = false;
respuestaSeleccionada = -1;
respuestaCorrecta = -1;


}
MundoColabService::~MundoColabService() {
	for (Enemigo* enemigo : enemigos) {
		delete enemigo;
	}
	enemigos.clear();

	for (EstrellaRecurso* estrella : estrellas) {
		delete estrella;
	}
	estrellas.clear();
	delete nave;

	if (aliadoR2D2 != nullptr) {
		delete aliadoR2D2;
	}
	for (BalaLaser* bala : balas) {
		delete bala;
	}
	balas.clear();
}
//NAVE
//---------------------------------------------------------------------------------//
void MundoColabService::CargarSpriteNave(char* ruta, int filas, int columnas) {
    if (nave == nullptr) {
        nave = new Nave(100, 400);
    }
    nave->cargarImagen(ruta, filas, columnas);

    // Configurar para Mundo Colab (igual que humano)
    nave->setConfiguracion(ConfiguracionSprite::ConfiguracionMundoColab());
}

void MundoColabService::moverNave(Direccion tecla) {
	if(nave->getNaveActiva()) nave->mover(tecla, this->anchoPanel, this->altoPanel);
}

//METEORITO - ENEMIGOS
//---------------------------------------------------------------------------------//

void MundoColabService::spawnMeteorito(int cantidadMeteoritos) {
	char rutaMeteorito[] = "MeteoritoSprite.png";
	for (int i = 0; i < cantidadMeteoritos; i++) {
		int yRandom = rand() % altoPanel;
		MeteoritoEnemigo* meteoritoEnemigo = new MeteoritoEnemigo(anchoPanel- 50, yRandom, 10);
		meteoritoEnemigo->cargarImagen(rutaMeteorito, 1, 4);
		meteoritoEnemigo->setActivo(true);
		enemigos.push_back(meteoritoEnemigo);
	}
}


void MundoColabService::moverMeteorito() {

	//se mueven los meteoritos
	for (int i = 0; i < enemigos.size(); i++) {
		if (enemigos[i]->getActivo())
			enemigos[i]->mover(Direccion::Ninguno, this->anchoPanel, this->altoPanel);
	}
	
	//se eliminan los que salen de la pantalla
	for (int i = 0; i < enemigos.size(); i++) {

		// Si sale totalmente por la izquierda o está desactivado
		if (!enemigos[i]->getActivo() ||
			enemigos[i]->getX() < -enemigos[i]->getAncho())
		{
			delete enemigos[i];
			enemigos.erase(enemigos.begin() + i);
			i--; // Ajustar índice después del erase
		}
	}

	// ---- 2. REPOSICIÓN (mínimo asegurado) ----
	while (enemigos.size() < minMeteoritos) {
		spawnMeteoritosAleatorios();
	}

	//probabilidad de spawn de enemigos aleatoriamente
	if (enemigos.size() < maxMeteoritos) {
		int prob = rand() % 50;  // 5% de probabilidad por frame
		if (prob < 5) {
			spawnMeteoritosAleatorios();
		}
	}
	verificarColisiones();
}


void MundoColabService::spawnMeteoritosAleatorios() {
	if (enemigos.size() > maxMeteoritos) return;
	char rutaMeteorito[] = "MeteoritoSprite.png";

	int yRandom = rand() % altoPanel;

	//velocidad aleatoria				//modificar para aumentar velocidad de meteoritos
	int velocidadRandom = 10 + rand() % 30;
		
	//tamaño aleatorio
	double tamaño = 0.5 + (rand() % 200) / 100.0 ;


	MeteoritoEnemigo* meteoritoEnemigo = new MeteoritoEnemigo(anchoPanel - 50, yRandom, velocidadRandom);
	meteoritoEnemigo->cargarImagen(rutaMeteorito, 1, 4);
	meteoritoEnemigo->setActivo(true);

	meteoritoEnemigo->setTamaño(tamaño);

	enemigos.push_back(meteoritoEnemigo);

}

//ESTRELLA - RECURSOS
//---------------------------------------------------------------------------------//

void MundoColabService::spawnEstrella(int cantidadEstrella) {
	char rutaEstrella[] = "SpriteEstrella.png";
	for (int i = 0; i < cantidadEstrella; i++) {
		int yRandom = rand() % altoPanel;
		EstrellaRecurso* estrellaRecurso = new EstrellaRecurso(anchoPanel - 50, yRandom, 8);
		estrellaRecurso->cargarImagen(rutaEstrella, 1, 4);
		estrellaRecurso->setActivo(true);
		estrellas.push_back(estrellaRecurso);
	}
}
void MundoColabService::moverEstrella() {
	//se mueven las estrellas
	for (int i = 0; i < estrellas.size(); i++) {
		if (estrellas[i]->getActivo())
			estrellas[i]->mover(Direccion::Ninguno, this->anchoPanel, this->altoPanel);
	}
	//se eliminan las que salen de la pantalla
	for (int i = 0; i < estrellas.size(); i++) {
		// Si sale totalmente por la izquierda o está desactivado
		if (!estrellas[i]->getActivo() ||
			estrellas[i]->getX() < -estrellas[i]->getAncho())
		{
			delete estrellas[i];
			estrellas.erase(estrellas.begin() + i);
			i--; // Ajustar índice después del erase
		}
	}
	// ---- 2. REPOSICIÓN (mínimo asegurado) ----
	while (estrellas.size() < minEstrellas) {
		spawnEstrellasAleatorias();
	}
	//probabilidad de spawn de enemigos aleatoriamente
	if (estrellas.size() < maxEstrellas) {
		int prob = rand() % 100;  // 5% de probabilidad por frame
		if (prob < 1) {
			spawnEstrellasAleatorias();
		}
	}
}
void MundoColabService::spawnEstrellasAleatorias() {
	if (estrellas.size() > maxEstrellas) return;
	char rutaEstrella[] = "SpriteEstrella.png";

	int yRandom = rand() % altoPanel; 

	//velocidad aleatoria				//modificar para aumentar velocidad de meteoritos
	int velocidadRandom = 10 + rand() % 30;

	//tamaño aleatorio
	


	EstrellaRecurso* estrellaRecurso = new EstrellaRecurso(anchoPanel - 50, yRandom, velocidadRandom);
	estrellaRecurso->cargarImagen(rutaEstrella, 1, 4);
	estrellaRecurso->setActivo(true);


	estrellas.push_back(estrellaRecurso);

}

//BALAS LASER
void MundoColabService::disparar() {

	// Si estás mostrando una pregunta, no puedes disparar
	if (mostrandoPregunta) return;

	// Si NO hay balas ? activar recarga y bloquear disparo
	if (balasDisponibles <= 0) {
		necesitaRecargar = true;
		return;
	}

	// Si hay balas ? disparas normalmente
	if (nave == nullptr) return;

	int salidaX = nave->getX() + nave->getAncho() - 30;
	int salidaY = nave->getY() + nave->getAlto() / 2 - 20;

	BalaLaser* b = new BalaLaser(salidaX, salidaY, 15);
	b->cargarImagen("Bala.png", 2, 4);
	b->setActivo(true);

	balasDisponibles--;
	balas.push_back(b);

	// Si se agotan las balas justo con este disparo
	if (balasDisponibles <= 0)
		necesitaRecargar = true;
}

void MundoColabService::moverBalas() {

	for (int i = 0; i < balas.size(); i++) {
		balas[i]->mover(Direccion::Derecha, this->anchoPanel, this->altoPanel);

		if (!balas[i]->getActivo() || balas[i]->getX() < -balas[i]->getAncho()){
			delete balas[i];
			balas.erase(balas.begin() + i);
			i--;
		}
	}
}


void MundoColabService::procesarRecargaPorRespuesta(bool correcta) {

	mostrandoPregunta = false; // <- SE TERMINÓ LA PREGUNTA

	if (!necesitaRecargar) return;

	if (correcta) {
		respuestasCorrectas++;

		int base = 1;
		int bono = (int)(respuestasCorrectas * 1.2);
		int extra = rand() % 4;

		int total = base + bono + extra;
		if (total > balasMaximas) total = balasMaximas;

		balasDisponibles = total;
	}

	necesitaRecargar = false;
}












//----------------------------------------------------------------//
//ALIADO
void MundoColabService::cargarR2D2(char* ruta, int filas, int columnas) {
	if (aliadoR2D2 != nullptr) return;

	aliadoR2D2 = new AliadoR2D2(90, -90);	//posicion de sprite
	aliadoR2D2->cargarImagen(ruta, 1, 4);
	aliadoR2D2->setActivo(true);
}

//aparte pq va en otro panel
void MundoColabService::dibujarAliadoR2D2(Graphics^ canvas) {
	if (aliadoR2D2 != nullptr && aliadoR2D2->getActivo()) {
		aliadoR2D2->dibujar(canvas);
	}
}
void MundoColabService::animarAliado() {
	if (aliadoR2D2 != nullptr && aliadoR2D2->getActivo()) {
		aliadoR2D2->animar();
	}
}








//COLISIONES
void MundoColabService::verificarColisiones() {

	Rectangle rectNave = nave->getRectangleNave();

	


		//NAVE Y ENEMIGOS
	for (int i = 0; i < enemigos.size(); i++) {
		if (!enemigos[i]->getActivo()) continue;

		Rectangle rectEnemigo;


		//uso del hitbox del meteorito 
		MeteoritoEnemigo* meteorito = dynamic_cast<MeteoritoEnemigo*>(enemigos[i]);
		if (meteorito != nullptr) {

			rectEnemigo = meteorito->getRectangleMeteorito();
		}
		else {
			// sino el hitbox de enemigos normal
			rectEnemigo = enemigos[i]->getRectangle();
		}

		if (rectNave.IntersectsWith(rectEnemigo)) {
			nave->setVidas(nave->getVidas() - 1);		//resta la vida de la nave

			//nave->setIndiceY(nave->getIndiceY() + 1); (aun no hay IndiceY 1 para nave asi que por ahora esta comentado)

			enemigos[i]->setActivo(false); //desactivar meteorito
			delete enemigos[i];
			enemigos.erase(enemigos.begin() + i);
			i--;
			meteoritoNave = true;

			if (nave->getVidas() <= 0) nave->setNaveActiva(false); //desactivar nave
				//mostrar el gameover
			
		}
	}

		// ENEMIGOS Y BALAS
		for (int b = 0; b < balas.size(); b++) {
			if (balas[b]->estaExplotando()) continue; // si la bala explota ya no colisiona

			if (!balas[b]->getActivo()) continue;
			Rectangle rectBala = balas[b]->getRectangleBala();

			for (int i = 0; i < enemigos.size(); i++) {
				if (!enemigos[i]->getActivo()) continue;

				Rectangle rectEnemigo;
				MeteoritoEnemigo* meteorito = dynamic_cast<MeteoritoEnemigo*>(enemigos[i]);
				if (meteorito != nullptr) {

					rectEnemigo = meteorito->getRectangleMeteorito();
				}
				else
					rectEnemigo = enemigos[i]->getRectangle();

			if (rectBala.IntersectsWith(rectEnemigo)) {
				if (meteorito != nullptr) {

					

					meteorito->setVidasMeteorito(meteorito->getVidasMeteorito() - 1);

					if (meteorito->getVidasMeteorito() <= 0) {
															
						meteorito->setActivo(false);
						delete enemigos[i];
						enemigos.erase(enemigos.begin() + i);
						i--;
						balas[b]->iniciarExplosion();		
						colisionBala = true;//para el sonido de la explosion
					}// destruir bala
					else {
						delete balas[b];
						balas.erase(balas.begin() + b);
						b--;

					}
				}
				

				break;
			}

		}
	}

		// NAVE, BALAS Y ESTRELLA
		for (int i = 0; i < estrellas.size(); i++) {
			if (!estrellas[i]->getActivo()) continue;
			Rectangle rectEstrella = estrellas[i]->getRectangleEstrella();

			if (rectNave.IntersectsWith(rectEstrella)) {
		

				nave->setVidas(nave->getVidas() + 1);		//suma la vida de la nave

				delete estrellas[i];
				estrellas.erase(estrellas.begin() + i);
				i--;
				estrellaNave = true;

				if (nave->getVidas() > 3)nave->setVidas(3);
				continue;
			}
		

					// BALAS Y ESTRELLA
				for (int b = 0; b < balas.size(); b++) {

					if (balas[b]->estaExplotando()) continue;

					if (!balas[b]->getActivo()) continue;
					Rectangle rectBala = balas[b]->getRectangleBala();

					if (rectBala.IntersectsWith(rectEstrella)) {
						
						// destruir bala y estrella
						
						delete estrellas[i];
						estrellas.erase(estrellas.begin() + i);
						i--;
						balas[b]->iniciarExplosion();
						colisionBala = true;
						
						
						break;	
					}
				}

		}
		
}










void MundoColabService::dibujarTodo(Graphics^ canvas) {

	// Dibujar el fondo
	if (fondo != nullptr) {
		fondo->dibujar(canvas);
	}
	// Dibujar el jugador
	if (nave != nullptr && nave->getNaveActiva()) {
		nave->dibujar(canvas);
	}

	// Dibujar los meteoritos enemigos
	for (int i = 0; i < enemigos.size(); i++) {
		if (enemigos[i]->getActivo())
			enemigos[i]->dibujar(canvas);
	}
	// Dibujar las estrellas recurso
	for (int i = 0; i < estrellas.size(); i++) {
		if (estrellas[i]->getActivo())
			estrellas[i]->dibujar(canvas);


	}
	// Dibujar las balas
	for (int i = 0; i < balas.size(); i++) {
		if (balas[i]->getActivo())
			balas[i]->dibujar(canvas);
	}

}