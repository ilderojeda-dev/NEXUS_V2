#include "ChipRecurso.h"

ChipRecurso::ChipRecurso(int x, int y) : Recurso(x, y) {
    this->escala = 0.05f;
    this->frameActual = 0;
    this->contadorAnimacion = 0;
    this->velocidadAnimacion = 4; // Cambia frame cada 10 ticks
    this->recolectado = false;
}

ChipRecurso::~ChipRecurso() {}

void ChipRecurso::actualizarAnimacion() {
    if (recolectado) return;

    contadorAnimacion++;

    if (contadorAnimacion >= velocidadAnimacion) {
        contadorAnimacion = 0;
        frameActual = (frameActual + 1) % 4; // Ciclar entre 0-3
        this->indiceX = frameActual;
    }
}

void ChipRecurso::dibujar(Graphics^ canvas) {
    if (image == nullptr || recolectado) return;

    Bitmap^ bmp = gcnew Bitmap(gcnew System::String(image));
    int anchoFrame = bmp->Width / columnas;
    int altoFrame = bmp->Height / filas;

    Rectangle porcion = Rectangle(
        frameActual * anchoFrame,
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