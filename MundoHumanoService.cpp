#include "MundoHumanoService.h"
#include <cstdlib>
#include <ctime>
#include <cstring> 


MundoHumanoService::MundoHumanoService(int ancho, int alto, int vidasIniciales) : Mundo(ancho, alto, vidasIniciales) {
	srand(time(NULL));
	this->jugador = new Jugador(700, 200); // initialize base's jugador
	dialogoActual = new Dialogo(); 
	inicializarMuros();
	vozTerrestre = nullptr;

	jugador->setVelocidad(16.5);
	cambiarTraje(TipoTraje::Normal);

}
MundoHumanoService::~MundoHumanoService() {
	delete dialogoActual;
	for (int i = 0; i < alertas.size(); i++) {
		delete alertas[i];
	}
	alertas.clear();
	if (vozTerrestre != nullptr) delete vozTerrestre;

}

void MundoHumanoService::aplicarResultadoModulo(int idModulo, bool respuestaCorrecta) {
	if (!respuestaCorrecta) {
		estabilidadNave -= 10;
		indiceCriterio -= 5;
	}
	else {
		estabilidadNave += 5;
		indiceCriterio += 10;

		// Solo si el módulo pasa de NO completado → completado
		if (!modulosCompletados[idModulo]) {
			modulosCompletados[idModulo] = true;
			progresoMision += 33;   // 3 modulos → ~99, luego lo clamp

			// 🔹 Aquí reaccionamos según el módulo
			switch (idModulo) {
			case 0: // Módulo 1 → electricidad
				eliminarEnemigosCortoCircuito();
				break;
			case 1: // Módulo 2 → gas
				eliminarEnemigosGasToxico();
				break;
			case 2: // Módulo 3 → comunicaciones
				// aquí no borramos enemigos, solo comunicaciones
				break;
			}
		}
	}

	// clamp
	if (estabilidadNave < 0)  estabilidadNave = 0;
	if (estabilidadNave > 100) estabilidadNave = 100;

	if (indiceCriterio < 0)   indiceCriterio = 0;
	if (indiceCriterio > 100) indiceCriterio = 100;

	if (progresoMision < 0)   progresoMision = 0;
	if (progresoMision > 100) progresoMision = 100;
}

void MundoHumanoService::inicializarMuros() {
	muros.clear();
	muros.push_back(Muro(109, 421, 430, 210));
	muros.push_back(Muro(109, 888, 450, 210));
	muros.push_back(Muro(935, 888, 450, 210));
	muros.push_back(Muro(519, 491, 80, 230));

	muros.push_back(Muro(889, 500, 100, 220));
	muros.push_back(Muro(969, 421, 410, 80));

	muros.push_back(Muro(929, 51, 497, 130));

	muros.push_back(Muro(69, 61, 490, 120)); //modulo 1

}

bool MundoHumanoService::hayColisionMuros(Rectangle rectJugador) {
	for (auto& m : muros) {
		if (rectJugador.IntersectsWith(m.getRectangle())) {
			return true;
		}
	}
	return false;
}


//Alertas
void MundoHumanoService::agregarAlerta(Alerta* alerta) {
	alertas.push_back(alerta);

}
void MundoHumanoService::generarAlertas() {
	char rutaAlerta[] = "Alerta.png";
	Alerta* alertaM1 = new Alerta(186, 161);
	alertaM1->cargarImagen(rutaAlerta, 1, 4);
	alertaM1->setTipoAlerta(0); // Tipo 1 para la primera alerta
	alertas.push_back(alertaM1);

	Alerta* alertaM2 = new Alerta(1169, 161);
	alertaM2->cargarImagen(rutaAlerta, 1, 4);
	alertaM2->setTipoAlerta(1); // Tipo 2 para la segunda alerta
	alertas.push_back(alertaM2);

	Alerta* alertaM3 = new Alerta(319, 601);
	alertaM3->cargarImagen(rutaAlerta, 1, 4);
	alertaM3->setTipoAlerta(2);
	alertas.push_back(alertaM3);

}
void MundoHumanoService::moverAlertas() {
	for (int i = 0; i < alertas.size(); i++) {
		alertas[i]->mover(Direccion::Ninguno, anchoPanel, altoPanel);
	}
}
vector<Alerta*> MundoHumanoService::getAlertas() {
	return alertas;
}
int MundoHumanoService::verificarColisionAlerta() {

	Rectangle rectJugador = jugador->getRectangle();

	for (int i = 0; i < alertas.size(); i++) {

		Rectangle rectAlerta = alertas[i]->getRectangle();

		if (rectJugador.IntersectsWith(rectAlerta)) {
			int tipoAlerta = alertas[i]->getTipoAlerta();

			delete alertas[i];
			alertas.erase(alertas.begin() + i);

			return tipoAlerta;   // ← devuelve la alerta que colisionó
		}
	}

	return -1; // ← NO hubo colisión
}

//enemigos

void MundoHumanoService::agregarEnemigo(Enemigo* enemigo) {
	enemigos.push_back(enemigo);
}
void MundoHumanoService::generarEnemigosCortoCircuito() {
	char rutaCortoCircuito[] = "DescargaElectrica.png";
	CortoCircuito* enemigo1 = new CortoCircuito(170, 287, 2);
	enemigo1->cargarImagen(rutaCortoCircuito, 1, 3);
	enemigos.push_back(enemigo1);

	CortoCircuito* enemigo2 = new CortoCircuito(400, 150, 2);
	enemigo2->cargarImagen(rutaCortoCircuito, 1, 3);
	enemigos.push_back(enemigo2);
}
void MundoHumanoService::generarEnemigosGasToxico() {
	char rutaGasToxico[] = "GasToxico.png";
	GasToxico* enemigoGas1 = new GasToxico(1000, 240, 2);
	enemigoGas1->cargarImagen(rutaGasToxico, 1, 4);
	enemigos.push_back(enemigoGas1);
	GasToxico* enemigoGas2 = new GasToxico(1150, 240, 2);
	enemigoGas2->cargarImagen(rutaGasToxico, 1, 4);
	enemigos.push_back(enemigoGas2);
}
void MundoHumanoService::moverEnemigos() {
	for (int i = 0; i < enemigos.size(); i++) {
		enemigos[i]->mover(Direccion::Ninguno, anchoPanel, altoPanel);
	}
}
bool MundoHumanoService::hayColisionEnemigos(Rectangle rectJugador) {
	for (auto& e : enemigos) {
		if (rectJugador.IntersectsWith(e->getRectangle())) {
			return true;
		}
	}
	return false;
}

void MundoHumanoService::eliminarEnemigosCortoCircuito() {
	// Recorremos de atrás hacia adelante para borrar seguro
	for (int i = enemigos.size() - 1; i >= 0; --i) {
		CortoCircuito* corto = dynamic_cast<CortoCircuito*>(enemigos[i]);
		if (corto != nullptr) {
			delete enemigos[i];
			enemigos.erase(enemigos.begin() + i);
		}
	}
}

void MundoHumanoService::eliminarEnemigosGasToxico() {
	for (int i = enemigos.size() - 1; i >= 0; --i) {
		GasToxico* gas = dynamic_cast<GasToxico*>(enemigos[i]);
		if (gas != nullptr) {
			delete enemigos[i];
			enemigos.erase(enemigos.begin() + i);
		}
	}
}

//aliados
void MundoHumanoService::generarAliadoPapelSeñal() {
	char rutaPapelSeñal[] = "PapelSeñal.png";
	PapelSeñal* racursoPapel = new PapelSeñal(600, 800);
	racursoPapel->cargarImagen(rutaPapelSeñal, 1, 3);
	papelSeñal.push_back(racursoPapel);

}
bool MundoHumanoService::hayColisionPapelSeñal(Rectangle rectJugador) {
	for (int i = 0; i < papelSeñal.size(); i++) {
		if (rectJugador.IntersectsWith(papelSeñal[i]->getRectangle())) {
			delete papelSeñal[i];
			papelSeñal.erase(papelSeñal.begin() + i);
			return true;
		}
		
	}
	return false;
}
void MundoHumanoService::moverAliadoPapelSeñal() {
	for (int i = 0; i < papelSeñal.size(); i++) {
		papelSeñal[i]->mover(Direccion::Ninguno, anchoPanel, altoPanel);
	}
}	

void MundoHumanoService::generarVozTerrestre() {
	if (vozTerrestre == nullptr) {
		char rutaVozTerrestre[] = "FondoMensajeTerrestre.png";
		// Ajusta (268, 286) según donde quieres el panel
		vozTerrestre = new VozTerrestre(272, 296, 0, 0);
		vozTerrestre->cargarImagen(rutaVozTerrestre, 1, 1);
	}
	vozTerrestre->setActivo(true);   // se dibuja
}

void MundoHumanoService::mostrarVozTerrestre(bool on) {
	if (vozTerrestre != nullptr)
		vozTerrestre->setActivo(on);
}
//ugador

void MundoHumanoService::moverJugador(Direccion tecla) {
	if (tecla == Direccion::Ninguno) return;
	Rectangle actual = jugador->getRectangle();
	
	Rectangle siguiente = actual;

	int vel = jugador->getVelocidad(); 
	if (tecla == Direccion::Arriba) siguiente.Y -= vel;
	if (tecla == Direccion::Abajo) siguiente.Y += vel;
	if (tecla == Direccion::Izquierda) siguiente.X -= vel;
	if (tecla == Direccion::Derecha) siguiente.X += vel;
	if (!hayColisionMuros(siguiente)) {
		jugador->mover(tecla, anchoPanel, altoPanel);
	}
	else {
		// Si quieres, aquí puedes poner sonido de choque
		// playlist.reproducir("golpe.wav");
	}
}



void MundoHumanoService::cambiarTraje(TipoTraje tipo)
{
	trajeActivo = tipo;

	char ruta[64];// ruta de la imagen del traje a cargar es decir la del jugador

	switch (tipo) {
	case TipoTraje::Normal:
		strcpy_s(ruta, "Astronauta.png");              // traje blanco, strcpy_s para copiar cadenas es decir la ruta
		break;

	case TipoTraje::AntiElectricidad:
		strcpy_s(ruta, "TrajeAntiElectricidad.png");   // AZUL
		break;

	case TipoTraje::AntiGas:
		strcpy_s(ruta, "TrajeAntiGas.png");            // NARANJA
		break;
	}

	// Usa las filas/columnas reales de tu sprite
	cargarSpriteJugador(ruta, 4, 4);
}



void MundoHumanoService::dibujarTodo(Graphics^ canvas) {
	fondo->dibujar(canvas);
	for (int i = 0; i < alertas.size(); i++) {
		alertas[i]->dibujar(canvas);
	}
	for (int i = 0; i < enemigos.size(); i++)	 {
		enemigos[i]->dibujar(canvas);
	}
	for (int i = 0; i < papelSeñal.size(); i++) {
		papelSeñal[i]->dibujar(canvas);
	}
	if (vozTerrestre != nullptr && vozTerrestre->getActivo())
		vozTerrestre->dibujar(canvas);   // 👈 panel sci-fi

	jugador->dibujar(canvas);
	
	
	/*Pen^ p = gcnew Pen(Color::Red, 2);

	for (auto& m : muros) {
		Rectangle r = m.getRectangle();
		canvas->DrawRectangle(p, r);
	}*/
	


}


