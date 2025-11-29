#include "Jugador.h"

Jugador::Jugador() : Sprite() {
    vida = 3;
    velocidad = 10;
    saltando = false;
    velocidadSalto = 0.0f;
    gravedadSalto = 0.6f;
    alturaInicial = 0;
    duracionSaltoActual = 0;
    direccionSalto = Direccion::Ninguno;
    config = ConfiguracionSprite();
}

Jugador::Jugador(int x, int y) : Sprite(x, y) {
    vida = 3;
    velocidad = 10;
    saltando = false;
    velocidadSalto = 0.0f;
    gravedadSalto = 0.6f;
    alturaInicial = y;
    duracionSaltoActual = 0;
    direccionSalto = Direccion::Ninguno;
    config = ConfiguracionSprite();
}

Jugador::~Jugador() {}

void Jugador::setConfiguracion(ConfiguracionSprite configuracion) {
    config = configuracion;
    duracionSaltoMaxima = config.getFramesSalto() * 3;
}

void Jugador::saltar(Direccion direccion) {
    if (saltando) return;

    saltando = true;
    velocidadSalto = -12.0f;
    alturaInicial = y;
    duracionSaltoActual = 0;
    direccionSalto = direccion;
    indiceX = 0;

    // Establecer animación según dirección
    if (direccion == Direccion::Izquierda) {
        indiceY = config.getIndiceSaltoIzquierda();
    }
    else if (direccion == Direccion::Derecha) {
        indiceY = config.getIndiceSaltoDerecha();
    }
    else {
        // Salto sin dirección (mantener última)
        if (dx < 0 || indiceY == config.getIndiceIzquierda()) {
            indiceY = config.getIndiceSaltoIzquierda();
            direccionSalto = Direccion::Izquierda;
        }
        else {
            indiceY = config.getIndiceSaltoDerecha();
            direccionSalto = Direccion::Derecha;
        }
    }
}

void Jugador::actualizarSalto(int limiteAlto) {
    if (!saltando) return;

    // Aplicar física
    y += (int)velocidadSalto * 2;
    velocidadSalto += gravedadSalto;

    // Movimiento horizontal durante salto
    if (direccionSalto == Direccion::Izquierda) {
        x -= velocidad;
    }
    else if (direccionSalto == Direccion::Derecha) {
        x += velocidad;
    }

    // Animación
    duracionSaltoActual++;
    int frameCalculado = duracionSaltoActual / 2;
    indiceX = (frameCalculado >= config.getFramesSalto() - 1) ?
        config.getFramesSalto() - 1 : frameCalculado;

    // Verificar aterrizaje
    if (y >= alturaInicial) {
        y = alturaInicial;
        saltando = false;
        velocidadSalto = 0.0f;
        duracionSaltoActual = 0;
        indiceX = 0;

        // Restaurar animación de correr
        indiceY = (direccionSalto == Direccion::Izquierda) ?
            config.getIndiceIzquierda() : config.getIndiceDerecha();
    }

    // Límite altura máxima
    if (y < alturaInicial - 120) {
        y = alturaInicial - 120;
        velocidadSalto = 0.0f;
    }
}

void Jugador::mover(Direccion tecla, int limiteAncho, int limiteAlto, int velocidads) {
    if (tecla == Direccion::Ninguno) return;

    // Control en el aire
    if (saltando) {
        if (tecla == Direccion::Izquierda) x -= velocidad * 2;
        if (tecla == Direccion::Derecha) x += velocidad * 2;
        return;
    }

    // Configurar animación
    int maxFrames = config.getFramesAbajo();
    dx = 0; dy = 0;

    switch (tecla) {
    case Direccion::Arriba:
        dy = -1;
        indiceY = config.getIndiceArriba();
        maxFrames = config.getFramesArriba();
        break;
    case Direccion::Abajo:
        dy = 1;
        indiceY = config.getIndiceAbajo();
        maxFrames = config.getFramesAbajo();
        break;
    case Direccion::Izquierda:
        dx = -1;
        indiceY = config.getIndiceIzquierda();
        maxFrames = config.getFramesIzquierda();
        break;
    case Direccion::Derecha:
        dx = 1;
        indiceY = config.getIndiceDerecha();
        maxFrames = config.getFramesDerecha();
        break;
    }

    // Animación
    indiceX = (indiceX >= maxFrames - 1) ? 0 : indiceX + 1;

    // Movimiento
    x += dx * velocidad;
    y += dy * velocidad;

    // Límites
    int anchoEscalado = (int)(ancho * escala);
    int altoEscalado = (int)(alto * escala);

    if (x < 110) x = 110;
    if (y < 0) y = 0;
    if (x > limiteAncho - anchoEscalado) x = limiteAncho - anchoEscalado;
    if (y > limiteAlto - altoEscalado) {
        y = limiteAlto - altoEscalado;
        alturaInicial = y;
    }
}

void Jugador::dibujar(Graphics^ canvas) {
    Bitmap^ bmp = gcnew Bitmap(gcnew System::String(image));
    int anchoEscalado = (int)(ancho * escala);
    int altoEscalado = (int)(alto * escala);

    Rectangle seccion = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
    Rectangle destino = Rectangle(x, y, anchoEscalado, altoEscalado);

    canvas->DrawImage(bmp, destino, seccion, GraphicsUnit::Pixel);
    delete bmp;
}