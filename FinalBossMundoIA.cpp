#include "FinalBossMundoIA.h"
#include <algorithm>
FinalBossMundoIA::FinalBossMundoIA(int x, int y, int dificultad) : Sprite(x, y) {
    this->vidaMaxima = 50 * dificultad;
    this->vidaActual = vidaMaxima;
    this->escala = 2.5f;
    config = ConfiguracionSprite();
}

FinalBossMundoIA::~FinalBossMundoIA() {}

void FinalBossMundoIA::setConfiguracion(ConfiguracionSprite configuracion) {
    config = configuracion;
}

void FinalBossMundoIA::mover(Direccion tecla, int limiteAncho, int limiteAlto, int velocidads) {
    if (tecla == Direccion::Ninguno) return;

   
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
    x += dx;
    y += dy;

    int anchoEscalado = (int)(ancho * escala);

    if (x < 110) x = 110;
    if (x > limiteAncho - anchoEscalado)
        x = limiteAncho - anchoEscalado;

}

void FinalBossMundoIA::dibujar(Graphics^ canvas) {
    if (!image) return;

    Bitmap^ bmp = gcnew Bitmap(gcnew System::String(image));
    int anchoFrame = bmp->Width / columnas;
    int altoFrame = bmp->Height / filas;

    // Sprite
    Rectangle porcion = Rectangle(indiceX * anchoFrame, indiceY * altoFrame, anchoFrame, altoFrame);
    Rectangle destino = Rectangle(x, y, (int)(anchoFrame * escala), (int)(altoFrame * escala));
    canvas->DrawImage(bmp, destino, porcion, GraphicsUnit::Pixel);

    // Barra de vida
    int anchoBarra = (int)(anchoFrame * escala);
    int altoBarra = 10;
    int yBarra = y - 20;

    SolidBrush^ fondoBarra = gcnew SolidBrush(Color::Black);
    canvas->FillRectangle(fondoBarra, x, yBarra, anchoBarra, altoBarra);

    float porcentaje = (float)vidaActual / (float)vidaMaxima;
    int anchoActual = (int)(anchoBarra * porcentaje);
    SolidBrush^ rellenoBarra = gcnew SolidBrush(Color::LimeGreen);
    canvas->FillRectangle(rellenoBarra, x, yBarra, anchoActual, altoBarra);

    Pen^ borde = gcnew Pen(Color::White, 2);
    canvas->DrawRectangle(borde, x, yBarra, anchoBarra, altoBarra);

    delete bmp;
    delete fondoBarra;
    delete rellenoBarra;
    delete borde;
}

void FinalBossMundoIA::recibirDano(int cantidad) {
    vidaActual = max(0, vidaActual - cantidad);
}