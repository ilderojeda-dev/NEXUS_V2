#include "MundoHumanoService.h"
#include <cstdlib>
#include <ctime>


MundoHumanoService::MundoHumanoService(int ancho, int alto, int vidasIniciales) : Mundo(ancho, alto, vidasIniciales) {
	srand(time(NULL));
	this->jugador = new Jugador(500, 200); // initialize base's jugador
	dialogoActual = new Dialogo(); 
	inicializarMuros();
	jugador->setVelocidad(16.5);

}
MundoHumanoService::~MundoHumanoService() {
	delete dialogoActual;
	for (int i = 0; i < alertas.size(); i++) {
		delete alertas[i];
	}
	alertas.clear();

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

	Alerta* alertaM4 = new Alerta(1179, 541);
	alertaM4->cargarImagen(rutaAlerta, 1, 4);
	alertaM4->setTipoAlerta(3);
	alertas.push_back(alertaM4);


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



/*void MundoHumanoService::moverJugador(Direccion tecla) {
	if (tecla == Direccion::Ninguno) return;

	// 1. Rectángulo actual del jugador
	Rectangle actual = jugador->getRectangle();

	// 2. Calcular siguiente posición (predicción)
	Rectangle siguiente = actual;
	int vel = getVelocidad();

	if (tecla == Direccion::Arriba)     siguiente.Y -= vel;
	if (tecla == Direccion::Abajo)      siguiente.Y += vel;
	if (tecla == Direccion::Izquierda)  siguiente.X -= vel;
	if (tecla == Direccion::Derecha)    siguiente.X += vel;

	// 3. Verificar colisión con muros
	if (!hayColisionMuros(siguiente)) {
		// 4. Movimiento real usando tu mover() original
		jugador->mover(tecla, anchoPanel, altoPanel);
	}
	else {
		// -- Aquí puedes poner efectos si rompes algo --
		// playlist.reproducir("choque.wav");
	}
}*/




void MundoHumanoService::dibujarTodo(Graphics^ canvas) {
	fondo->dibujar(canvas);
	for (int i = 0; i < alertas.size(); i++) {
		alertas[i]->dibujar(canvas);
	}

	jugador->dibujar(canvas);
	
	/*Pen^ p = gcnew Pen(Color::Red, 2);

	for (auto& m : muros) {
		Rectangle r = m.getRectangle();
		canvas->DrawRectangle(p, r);
	}*/
	


}


