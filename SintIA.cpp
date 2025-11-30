#include "SintIA.h"

SintIA::SintIA() : Sprite() {}

SintIA::SintIA(int x, int y) : Sprite(x, y) {

}

SintIA::~SintIA() {}

void SintIA::mover(Direccion direccion, int posInicial, int posFinal, int velocidad) {
    switch (direccion) {
    case Direccion::Arriba:
        this->y -= velocidad;
        if (this->y < posFinal) this->y = posFinal;
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

    indiceX = (indiceX < 8) ? (indiceX + 1) % columnas : 0;
}

void SintIA::dibujar(Graphics^ canvas) {
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