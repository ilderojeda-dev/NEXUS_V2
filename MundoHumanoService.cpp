#include "MundoHumanoService.h"
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <sstream>

using namespace std;

MundoHumanoService::MundoHumanoService(int ancho, int alto, int vidasIniciales) : Mundo(ancho, alto, vidasIniciales) {
	srand(time(NULL));

	archivoService = new ArchivoService();
	jugador = nullptr;
	dialogoActual = new Dialogo();
	vozTerrestre = nullptr;

	cargarParametrosDelArchivo();

	if (jugador == nullptr) {
		jugador = new Jugador(700, 200);
	} 
	jugador->setVelocidad(16);
	cambiarTraje(TipoTraje::Normal);
}

MundoHumanoService::~MundoHumanoService() {
	if (dialogoActual) delete dialogoActual;

	for (int i = 0; i < alertas.size(); i++) delete alertas[i];
	alertas.clear();

	for (int i = 0; i < enemigos.size(); i++) delete enemigos[i];
	enemigos.clear();

	for (int i = 0; i < papelSeñal.size(); i++) delete papelSeñal[i];
	papelSeñal.clear();

	if (vozTerrestre != nullptr) delete vozTerrestre;
	if (archivoService != nullptr) delete archivoService;
}

// PARÁMETROS (ARCHIVO + BACKUP HARDCODE)
void MundoHumanoService::cargarParametrosDelArchivo() {
	string ruta = "Files/PARAMETERS.txt";

	// Verificar si existe
	if (!archivoService->archivoExiste(ruta)) {
		CargarValoresPorDefecto();  
		return;
	}

	vector<string> lineas = archivoService->leerTodasLineas(ruta);

	// Verificar que tenga datos suficientes (mínimo unas líneas)
	if (lineas.size() < 5) {
		CargarValoresPorDefecto();
		return;
	}

	int idx = 0;//Inicializar la linea desde donde empezara a leer los datos
	try {
		// 1. LEER VIDAS (Línea 0)
		int vidasLeidas = stoi(lineas[idx++]);
		this->setVidas(vidasLeidas);

		// 2. LEER JUGADOR (Línea 1)
		stringstream ssJug(lineas[idx++]);
		string jX, jY;
		getline(ssJug, jX, ';');
		getline(ssJug, jY);
		this->jugador = new Jugador(stoi(jX), stoi(jY));

		// 3. LEER ENEMIGOS ELÉCTRICOS
		int cantElec = stoi(lineas[idx++]);
		char rutaCorto[] = "DescargaElectrica.png";

		for (int i = 0; i < cantElec; i++) {
			stringstream ss(lineas[idx++]);
			string eX, eY;
			getline(ss, eX, ';');
			getline(ss, eY);

			CortoCircuito* enemigo = new CortoCircuito(stoi(eX), stoi(eY), 2);
			enemigo->cargarImagen(rutaCorto, 1, 3);
			enemigos.push_back(enemigo);
		}

		// 4. LEER ENEMIGOS GAS
		int cantGas = stoi(lineas[idx++]); 
		char rutaGas[] = "GasToxico.png";

		for (int i = 0; i < cantGas; i++) {
			stringstream ss(lineas[idx++]);
			string gX, gY;
			getline(ss, gX, ';');
			getline(ss, gY);

			GasToxico* gas = new GasToxico(stoi(gX), stoi(gY), 2);
			gas->cargarImagen(rutaGas, 1, 4);
			enemigos.push_back(gas);
		}

		// 5. LEER ALIADOS (Papel)
		int cantAliados = stoi(lineas[idx++]);
		char rutaPapel[] = "PapelSeñal.png";

		for (int i = 0; i < cantAliados; i++) {
			stringstream ss(lineas[idx++]);
			string aX, aY;
			getline(ss, aX, ';');
			getline(ss, aY);

			PapelSeñal* papel = new PapelSeñal(stoi(aX), stoi(aY));
			papel->cargarImagen(rutaPapel, 1, 3);
			papelSeñal.push_back(papel);
		}
		// 6. ALERTAS
		int cantAlertas = stoi(lineas[idx++]);	 
		char rutaAlerta[] = "Alerta.png";
		for (int k = 0; k < cantAlertas; k++) {
			stringstream ss(lineas[idx++]);  
			string alX, alY;

			getline(ss, alX, ';');
			getline(ss, alY);

			Alerta* nuevaAlerta = new Alerta(stoi(alX), stoi(alY));
			nuevaAlerta->cargarImagen(rutaAlerta, 1, 4);
 			nuevaAlerta->setTipoAlerta(k);
			alertas.push_back(nuevaAlerta);
		}
		// 7. LEER MUROS (Formato: x;y;ancho;alto)
		int cantMuros = stoi(lineas[idx++]); 

		for (int k = 0; k < cantMuros; k++) {
			stringstream ss(lineas[idx++]);
			string mX, mY, mW, mH;

			getline(ss, mX, ';');
			getline(ss, mY, ';');
			getline(ss, mW, ';');
			getline(ss, mH);

			muros.push_back(Muro(stoi(mX), stoi(mY), stoi(mW), stoi(mH)));
		}
	}
	catch (...) {
		// Si algo falla leyendo (formato incorrecto), cargamos default
		System::Windows::Forms::MessageBox::Show("Error leyendo PARAMETERS.txt. Se usaran valores por defecto.");
		CargarValoresPorDefecto();
	}
}
// --- VALORES POR DEFECTO (Datos hardcoded originales) ---
void MundoHumanoService::CargarValoresPorDefecto() {
	this->setVidas(3);
	if (this->jugador == nullptr) this->jugador = new Jugador(700, 200);
	else { this->jugador->setX(700); this->jugador->setY(200); }

	// Usamos las funciones de generación Hardcoded como respaldo
	generarEnemigosCortoCircuito();
	generarEnemigosGasToxico();
	generarPapelSeñal();
	generarAlertas();
	inicializarMuros();
}

// =========================================================
// 3. LÓGICA PRINCIPAL (DIBUJO Y MÓDULOS)
// =========================================================
void MundoHumanoService::dibujarTodo(Graphics^ canvas) {
	fondo->dibujar(canvas);

	for (int i = 0; i < alertas.size(); i++) alertas[i]->dibujar(canvas);
	for (int i = 0; i < enemigos.size(); i++) enemigos[i]->dibujar(canvas);
	for (int i = 0; i < papelSeñal.size(); i++) papelSeñal[i]->dibujar(canvas);

	if (vozTerrestre != nullptr && vozTerrestre->getActivo())
		vozTerrestre->dibujar(canvas);

	if (jugador) jugador->dibujar(canvas);
	//Solo para validar
	//dibuajr el rectangle del jugador para pruebas
	Pen^ p = gcnew Pen(Color::Blue, 2);
	Rectangle rJugador = jugador->getRectangle();
	canvas->DrawRectangle(p, rJugador);

	//dibujar rectangulos de las alertas para pruebas
	for (int i = 0; i < alertas.size(); i++) {
		Rectangle rAlerta = alertas[i]->getRectangle();
		canvas->DrawRectangle(p, rAlerta);
	}

	//dibujar rectangulos de los enemigos para pruebas	
	for (int i = 0; i < enemigos.size(); i++) {
		Rectangle rEnemigo = enemigos[i]->getRectangle();
		canvas->DrawRectangle(p, rEnemigo);
	}
	//dibujar rectangulos de los aliados papel señal para pruebas
	for (int i = 0; i < papelSeñal.size(); i++) {
		Rectangle rAliado = papelSeñal[i]->getRectangle();
		canvas->DrawRectangle(p, rAliado);
	}

}

void MundoHumanoService::inicializarMuros() {
	if (muros.size() > 0) return;
	muros.push_back(Muro(109, 421, 430, 210));
	muros.push_back(Muro(109, 888, 450, 210));
	muros.push_back(Muro(935, 888, 450, 210));
	muros.push_back(Muro(519, 491, 80, 230));
	muros.push_back(Muro(889, 500, 100, 220));
	muros.push_back(Muro(969, 421, 410, 80));
	muros.push_back(Muro(929, 51, 497, 130));
	muros.push_back(Muro(69, 61, 490, 120));
}
bool MundoHumanoService::hayColisionMuros(Rectangle rectJugador) {
	for (auto& m : muros) {
		if (rectJugador.IntersectsWith(m.getRectangle())) return true;
	}
	return false;
}

void MundoHumanoService::aplicarResultadoModulo(int idModulo, bool respuestaCorrecta) {
	if (!respuestaCorrecta) {
		estabilidadNave -= 20;
		indiceCriterio -= 10;
	}
	else {
		estabilidadNave += 20;

		if (!modulosCompletados[idModulo]) {
			modulosCompletados[idModulo] = true;
			progresoMision += 34;

			switch (idModulo) {
			case 0: eliminarEnemigosCortoCircuito(); break;
			case 1: eliminarEnemigosGasToxico(); break;
			case 2: break;
			}
		}
	}
	// Clamp manual
	if (estabilidadNave < 0) estabilidadNave = 0; if (estabilidadNave > 100) estabilidadNave = 100;
	if (indiceCriterio < 0) indiceCriterio = 0; if (indiceCriterio > 100) indiceCriterio = 100;
	if (progresoMision < 0) progresoMision = 0; if (progresoMision > 100) progresoMision = 100;
}
bool MundoHumanoService::estaModuloCompletado(int idModulo) {
	// Verificamos que el índice sea válido (0, 1 o 2)
	if (idModulo >= 0 && idModulo < 3) {
		return modulosCompletados[idModulo];
	}
	return false;
}

// =========================================================
// 4. JUGADOR
// =========================================================

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
}

void MundoHumanoService::cambiarTraje(TipoTraje tipo) {
	trajeActivo = tipo;
	char ruta[64];
	switch (tipo) {
	case TipoTraje::Normal: strcpy_s(ruta, "Astronauta.png"); break;
	case TipoTraje::AntiElectricidad: strcpy_s(ruta, "TrajeAntiElectricidad.png"); break;
	case TipoTraje::AntiGas: strcpy_s(ruta, "TrajeAntiGas.png"); break;
	}
	if (jugador) jugador->cargarImagen(ruta, 4, 4);
}
// =========================================================
// 5. ENEMIGOS (IMPLEMENTACIÓN Y HARDCODE)
// =========================================================

void MundoHumanoService::agregarEnemigo(Enemigo* enemigo) {
	enemigos.push_back(enemigo);
}

void MundoHumanoService::moverEnemigos() {
	for (int i = 0; i < enemigos.size(); i++) enemigos[i]->mover(Direccion::Ninguno, anchoPanel, altoPanel);
}

bool MundoHumanoService::hayColisionEnemigos(Rectangle rectJugador) {
	for (auto& e : enemigos) {
		if (rectJugador.IntersectsWith(e->getRectangle())) return true;
	}
	return false;
}

void MundoHumanoService::eliminarEnemigosCortoCircuito() {
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

// --- GENERACIÓN HARDCODE (RESPALDO) ---
void MundoHumanoService::generarEnemigosCortoCircuito() {
	char rutaCorto[] = "DescargaElectrica.png";
	CortoCircuito* e1 = new CortoCircuito(170, 287, 2); e1->cargarImagen(rutaCorto, 1, 3); enemigos.push_back(e1);
	CortoCircuito* e2 = new CortoCircuito(400, 150, 2); e2->cargarImagen(rutaCorto, 1, 3); enemigos.push_back(e2);
}

void MundoHumanoService::generarEnemigosGasToxico() {
	char rutaGas[] = "GasToxico.png";
	GasToxico* g1 = new GasToxico(1000, 240, 2); g1->cargarImagen(rutaGas, 1, 4); enemigos.push_back(g1);
	GasToxico* g2 = new GasToxico(1150, 240, 2); g2->cargarImagen(rutaGas, 1, 4); enemigos.push_back(g2);
}

// =========================================================
// 6. ALERTAS (IMPLEMENTACIÓN Y HARDCODE)
// =========================================================

void MundoHumanoService::agregarAlerta(Alerta* alerta) {
	alertas.push_back(alerta);
}

void MundoHumanoService::moverAlertas() {
	for (int i = 0; i < alertas.size(); i++) alertas[i]->mover(Direccion::Ninguno, anchoPanel, altoPanel);
}

int MundoHumanoService::verificarColisionAlerta() {
	Rectangle rectJugador = jugador->getRectangle();
	for (int i = 0; i < alertas.size(); i++) {
		if (rectJugador.IntersectsWith(alertas[i]->getRectangle())) {
			int tipo = alertas[i]->getTipoAlerta();
			delete alertas[i];
			alertas.erase(alertas.begin() + i);
			return tipo;
		}
	}
	return -1;
}
vector<Alerta*> MundoHumanoService::getAlertas() {
	return alertas;
}

// --- GENERACIÓN HARDCODE (RESPALDO) ---
void MundoHumanoService::generarAlertas() {
	char rutaAlerta[] = "Alerta.png";
	Alerta* a1 = new Alerta(186, 161); a1->cargarImagen(rutaAlerta, 1, 4); a1->setTipoAlerta(0); alertas.push_back(a1);
	Alerta* a2 = new Alerta(1169, 161); a2->cargarImagen(rutaAlerta, 1, 4); a2->setTipoAlerta(1); alertas.push_back(a2);
	Alerta* a3 = new Alerta(319, 601); a3->cargarImagen(rutaAlerta, 1, 4); a3->setTipoAlerta(2); alertas.push_back(a3);
}

// =========================================================
// 7. RECURSOS Y ALIADOS (IMPLEMENTACIÓN Y HARDCODE)
// =========================================================

void MundoHumanoService::moverAliadoPapelSeñal() {
	for (int i = 0; i < papelSeñal.size(); i++) papelSeñal[i]->mover(Direccion::Ninguno, anchoPanel, altoPanel);
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

void MundoHumanoService::generarVozTerrestre() {
	if (vozTerrestre == nullptr) {
		char rutaVoz[] = "FondoMensajeTerrestre.png";
		vozTerrestre = new VozTerrestre(272, 296, 0, 0);
		vozTerrestre->cargarImagen(rutaVoz, 1, 1);
	}
	vozTerrestre->setActivo(true);
}

void MundoHumanoService::mostrarVozTerrestre(bool on) {
	if (vozTerrestre) vozTerrestre->setActivo(on);
}

// --- GENERACIÓN HARDCODE (RESPALDO) ---
void MundoHumanoService::generarPapelSeñal() {
	char rutaPapel[] = "PapelSeñal.png";
	PapelSeñal* p = new PapelSeñal(600, 800);
	p->cargarImagen(rutaPapel, 1, 3);
	papelSeñal.push_back(p);
}