
#include "RobotEnemigo.h"

RobotEnemigo::RobotEnemigo() : Sprite() {}

RobotEnemigo::RobotEnemigo(int x, int y) : Sprite(x, y) {}

RobotEnemigo::~RobotEnemigo() {}

void RobotEnemigo::mover(Direccion direccion, int posInicial, int posFinal, int velocidad) {
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
        if (this->x < posFinal) this->x = posFinal;
        this->setIndiceY(1);
        break;
    case Direccion::Derecha:
        this->x += velocidad;
        if (this->x > posFinal) this->x = posFinal;
        this->setIndiceY(3);
        break;
    }

    // Animación
    indiceX = (indiceX < 8) ? (indiceX + 1) % columnas : 0;
}

void RobotEnemigo::dibujar(Graphics^ canvas) {
    if (image == nullptr) return;

    Bitmap^ bmp = gcnew Bitmap(gcnew System::String(image));
    int anchoFrame = bmp->Width / columnas;
    int altoFrame = bmp->Height / filas;

    Rectangle porcion = Rectangle(
        indiceX * anchoFrame,
        indiceY * altoFrame,
        anchoFrame,
        altoFrame
    );

    Rectangle destino = Rectangle(
        x, y,
        (int)(anchoFrame * escala),
        (int)(altoFrame * escala)
    );

    canvas->DrawImage(bmp, destino, porcion, GraphicsUnit::Pixel);
    delete bmp;
}