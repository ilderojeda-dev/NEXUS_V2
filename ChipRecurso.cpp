
#include "ChipRecurso.h"

ChipRecurso::ChipRecurso(int x, int y) : Recurso(x, y) {
    this->escala = 0.1f;
}

ChipRecurso::~ChipRecurso() {}

void ChipRecurso::dibujar(Graphics^ canvas) {
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