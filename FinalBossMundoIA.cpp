
#include "FinalBossMundoIA.h"

FinalBossMundoIA::FinalBossMundoIA(int x, int y, int dificultad) : Sprite(x, y) {
    this->vidaMaxima = 50 * dificultad;
    this->vidaActual = vidaMaxima;
    this->enFuria = false;
    this->anguloFlotacion = 0.0f;
    this->cooldownAtaque = 0;
    this->escala = 2.5f;
}

FinalBossMundoIA::~FinalBossMundoIA() {}

void FinalBossMundoIA::mover(Direccion direccion, int posInicial, int posFinal, int velocidad) {
    // Movimiento según dirección
    switch (direccion) {
    case Direccion::Arriba:
        this->y -= velocidad;
        if (this->y < posInicial) this->y = posInicial;
        this->setIndiceY(0);
        break;
    case Direccion::Abajo:
        this->y += velocidad;
        if (this->y > posFinal) this->y = posFinal;
        this->setIndiceY(2);
        break;
    case Direccion::Izquierda:
        this->x -= velocidad;
        if (this->x < posInicial) this->x = posInicial;
        this->setIndiceY(1);
        break;
    case Direccion::Derecha:
        this->x += velocidad;
        if (this->x > posFinal) this->x = posFinal;
        this->setIndiceY(3);
        break;
    }

    // Efecto flotación
    anguloFlotacion += 0.1f;
    this->y += (int)(Math::Sin(anguloFlotacion) * 3);

    // Animación
    indiceX = (indiceX < 3) ? indiceX + 1 : 0;

    // Modo furia
    if (vidaActual < (vidaMaxima * 0.4)) {
        enFuria = true;
    }
}

void FinalBossMundoIA::dibujar(Graphics^ canvas) {
    if (image == nullptr) return;

    Bitmap^ bmp = gcnew Bitmap(gcnew System::String(image));

    // Aura de furia
    if (enFuria) {
        SolidBrush^ brushFuria = gcnew SolidBrush(Color::FromArgb(100, 255, 0, 0));
        int radio = (int)(ancho * escala);
        canvas->FillEllipse(brushFuria, x - 10, y - 10, radio + 20, (int)(alto * escala) + 20);
        delete brushFuria;
    }

    // Sprite
    int anchoFrame = bmp->Width / columnas;
    int altoFrame = bmp->Height / filas;

    Rectangle porcion = Rectangle(indiceX * anchoFrame, indiceY * altoFrame, anchoFrame, altoFrame);
    Rectangle destino = Rectangle(x, y, (int)(anchoFrame * escala), (int)(altoFrame * escala));
    canvas->DrawImage(bmp, destino, porcion, GraphicsUnit::Pixel);
    delete bmp;

    // Barra de vida
    int anchoBarra = (int)(anchoFrame * escala);
    int altoBarra = 10;
    int yBarra = y - 20;

    // Fondo barra
    SolidBrush^ fondoBarra = gcnew SolidBrush(Color::Black);
    canvas->FillRectangle(fondoBarra, x, yBarra, anchoBarra, altoBarra);

    // Vida actual
    float porcentajeVida = (float)vidaActual / (float)vidaMaxima;
    int anchoActual = (int)(anchoBarra * porcentajeVida);
    Color colorVida = enFuria ? Color::Red : Color::LimeGreen;
    SolidBrush^ rellenoBarra = gcnew SolidBrush(colorVida);
    canvas->FillRectangle(rellenoBarra, x, yBarra, anchoActual, altoBarra);

    // Borde
    Pen^ borde = gcnew Pen(Color::White, 2);
    canvas->DrawRectangle(borde, x, yBarra, anchoBarra, altoBarra);

    delete fondoBarra;
    delete rellenoBarra;
    delete borde;
}

void FinalBossMundoIA::recibirDano(int cantidad) {
    vidaActual -= cantidad;
    if (vidaActual < 0) vidaActual = 0;
}

bool FinalBossMundoIA::estaDerrotado() {
    return vidaActual <= 0;
}