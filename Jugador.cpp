#include "Jugador.h"

Jugador::Jugador() : Sprite() {
    vida = 3;
    velocidad = 10;
    saltando = false;
    velocidadSalto = 0;
    gravedadSalto = 2;
    alturaInicial = 0;
}

Jugador::Jugador(int x, int y) : Sprite(x, y) {
    vida = 3;
    velocidad = 10;
    saltando = false;
    velocidadSalto = 0;
    gravedadSalto = 2;
    alturaInicial = y;
}

Jugador::~Jugador() {}

void Jugador::saltar() {
    if (!saltando) {
        saltando = true;
        velocidadSalto = -20;  // Velocidad inicial hacia arriba (negativa)
        alturaInicial = y;
    }
}

void Jugador::actualizarSalto(int limiteAlto) {
    if (saltando) {
        // Aplicar velocidad de salto
        y += velocidadSalto;

        // Aplicar gravedad
        velocidadSalto += gravedadSalto;

        // Verificar si llegó al suelo
        if (y >= alturaInicial) {
            y = alturaInicial;
            saltando = false;
            velocidadSalto = 0;
        }

        // Limitar altura máxima (opcional)
        if (y < 50) {
            y = 50;
            velocidadSalto = 0;
        }
    }
}

void Jugador::mover(Direccion tecla, int limiteAncho, int limiteAlto) {
    if (tecla == Direccion::Ninguno) return;

    // Configurar dirección y animación
    if (tecla == Direccion::Arriba) {
        dx = 0;
        dy = -1;
        indiceY = 3;
    }
    if (tecla == Direccion::Abajo) {
        dx = 0;
        dy = 1;
        indiceY = 0;
    }
    if (tecla == Direccion::Izquierda) {
        dx = -1;
        dy = 0;
        indiceY = 1;
    }
    if (tecla == Direccion::Derecha) {
        dx = 1;
        dy = 0;
        indiceY = 2;
    }

    // Actualizar animación
    indiceX++;
    if (indiceX >= columnas) indiceX = 0;

    // Calcular dimensiones escaladas
    int anchoEscalado = (int)(ancho * escala);
    int altoEscalado = (int)(alto * escala);

    // Aplicar movimiento horizontal (no vertical si está saltando)
    if (!saltando) {
        x += dx * velocidad;
        y += dy * velocidad;
    }
    else {
        // Solo movimiento horizontal al saltar
        x += dx * velocidad;
    }

    // Límites ajustados con escala
    if (x < 110)
        x = 110;
    if (y < 0)
        y = 0;
    if (x > limiteAncho - anchoEscalado)
        x = limiteAncho - anchoEscalado;
    if (y > limiteAlto - altoEscalado)
        y = limiteAlto - altoEscalado;
}

void Jugador::dibujar(Graphics^ canvas) {
    Bitmap^ bmp = gcnew Bitmap(gcnew System::String(image));
    int anchoEscalado = (int)(ancho * escala);
    int altoEscalado = (int)(alto * escala);

    Rectangle seccion = Rectangle(
        indiceX * ancho,
        indiceY * alto,
        ancho,
        alto
    );

    Rectangle destino = Rectangle(x, y, anchoEscalado, altoEscalado);
    canvas->DrawImage(bmp, destino, seccion, GraphicsUnit::Pixel);
    delete bmp;
}

int Jugador::getVelocidad() {
    return velocidad;
}

int Jugador::getVidas() {
    return vida;
}