#include "MundoColabService.h"

#include <cstdlib>
#include <ctime>
using namespace System::Drawing;

MundoColabService::MundoColabService(int ancho, int alto, int vidasIniciales)
: Mundo(ancho, alto, vidasIniciales) {
nave = new Nave(50, 50);

srand(time(NULL)); // Inicializar la semilla para números aleatorios



}
MundoColabService::~MundoColabService() {
	for (Enemigo* enemigo : enemigos) {
		delete enemigo;
	}
	enemigos.clear();

	for (EstrellaRecurso* estrella : estrellas) {
		delete estrella;
	}
	delete nave;
	
}
//NAVE
//---------------------------------------------------------------------------------//
void MundoColabService::CargarSpriteNave(char* ruta, int filas, int columnas) {
	nave->cargarImagen(ruta, filas, columnas);
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
		int prob = rand() % 100;  // 1% de probabilidad por frame
		if (prob < 50) {
			spawnEstrellasAleatorias();
		}
	}
}
void MundoColabService::spawnEstrellasAleatorias() {
	if (enemigos.size() > maxEstrellas) return;
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
















//COLISIONES
void MundoColabService::verificarColisiones() {
	Rectangle rectNave = nave->getRectangleNave();

	for (int i = 0; i < enemigos.size(); i++) {
		if (!enemigos[i]->getActivo()) continue;

		Rectangle rectEnemigo;


		//uso del hitbox del meteorito (creo que podria usarlo para los recursos tambien)
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

			if (nave->getVidas() <= 0) {
				nave->setNaveActiva(false); //desactivar nave
				//mostrar el gameover
			}
		}

	}

	//estrellas
	for (int i = 0; i < estrellas.size(); i++) {
		if (!estrellas[i]->getActivo()) continue;
		Rectangle rectEstrella = estrellas[i]->getRectangleEstrella();

		if (rectNave.IntersectsWith(rectEstrella)) {
			nave->setVidas(nave->getVidas() + 1);		//suma la vida de la nave
				
			estrellas[i]->setActivo(false); //desactivar estrella

			delete estrellas[i];
			estrellas.erase(estrellas.begin() + i);
			i--;

		}
		if (nave->getVidas() > 3)nave->setVidas(3); 
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


		/*String^ texto = "Meteoritos: " + enemigos.size().ToString();
		Font^ f = gcnew Font("Arial", 12);
		SolidBrush^ b = gcnew SolidBrush(Color::White);
		canvas->DrawString(texto, f, b, 10, 10);
		delete f;
		delete b;
		*/

		String^ texto = "Estrellas: " + estrellas.size().ToString();
		Font^ f = gcnew Font("Arial", 12);
		SolidBrush^ b = gcnew SolidBrush(Color::White);
		canvas->DrawString(texto, f, b, 10, 10);
		delete f;
		delete b;


		Pen^ lapizHitbox = gcnew Pen(Color::LimeGreen, 2);
		canvas->DrawRectangle(lapizHitbox, nave->getRectangleNave());
		delete lapizHitbox;
		for (int i = 0; i < enemigos.size(); i++)
		{
			Pen^ lapizHitboxEnemigo = gcnew Pen(Color::Red, 1);
			canvas->DrawRectangle(lapizHitboxEnemigo, enemigos[i]->getRectangle());
			delete lapizHitboxEnemigo;
		}
		
		for (int i = 0; i < estrellas.size(); i++)
		{
			Pen^ lapizHitboxRecurso = gcnew Pen(Color::Blue, 3);
			canvas->DrawRectangle(lapizHitboxRecurso, estrellas[i]->getRectangleEstrella());
			delete lapizHitboxRecurso;
		}

	}
}