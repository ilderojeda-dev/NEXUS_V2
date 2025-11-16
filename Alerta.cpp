#include "Alerta.h"
using namespace System::Drawing;

Alerta::Alerta() : Recurso() {

}
Alerta::Alerta(int x, int y) : Recurso(x, y) {
    indiceX = 0;
    indiceY = 0;
}


Alerta::~Alerta() {

}

void Alerta::mover(Direccion tecla, int limiteAncho, int limiteAlto)  {
    indiceX++;
    if (indiceX >= columnas) indiceX = 0;
}
void Alerta::dibujar(Graphics^ canvas)  {
    if (activo && image != nullptr && ancho > 0 && alto > 0) {
        Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(image));

        Rectangle cuadroOrigen = Rectangle(
            indiceX * ancho,
            indiceY * alto,
            ancho,
            alto
        );

        // Escala especifica para moneda (mas pequeña)
        Rectangle cuadroDestino = Rectangle(
            x,
            y,
            ancho * 0.5,
            alto * 0.5
        );

        canvas->DrawImage(bitmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
        delete bitmap;
    }
}
