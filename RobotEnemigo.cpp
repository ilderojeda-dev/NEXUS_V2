#include "RobotEnemigo.h"

RobotEnemigo::RobotEnemigo()
	:Sprite()
{

}
RobotEnemigo::RobotEnemigo(int x, int y)
	:Sprite(x, y)
{

}
RobotEnemigo::~RobotEnemigo()
{

}

void RobotEnemigo::mover(Direccion direccion, int limiteAncho, int limiteAlto) {
    // Actualizar animación
    indiceX++;
    if (indiceX >= columnas) indiceX = 0;

    // Calcular dimensiones escaladas
    int anchoEscalado = (int)(ancho * escala);
    int altoEscalado = (int)(alto * escala);

    // Aplicar movimiento
    x += dx;
    y += dy;

    // Patrullaje en rectángulo con dimensiones escaladas
    // Borde superior derecho: ir a la derecha
    if (x < limiteAncho - anchoEscalado && y == 20) {
        dx = 5;
        dy = 0;
        indiceY = 3;
    }

    // Esquina derecha: bajar
    if (x >= limiteAncho - anchoEscalado && y < limiteAlto - altoEscalado) {
        dx = 0;
        dy = 5;
        indiceY = 2;
    }

    // Borde inferior: ir a la izquierda
    if (y >= limiteAlto - altoEscalado && x > 20) {
        dx = -5;
        dy = 0;
        indiceY = 1;
    }

    // Esquina izquierda: subir
    if (x <= 20 && y > 20) {
        dx = 0;
        dy = -5;
        indiceY = 0;
    }
}
void RobotEnemigo::dibujar(Graphics^ canvas) {

    if (image != nullptr) {
        Bitmap^ bmp = gcnew Bitmap(gcnew System::String(image));

        int anchoFrame = bmp->Width / columnas;
        int altoFrame = bmp->Height / filas;

        Rectangle porcion = Rectangle(
            indiceX * anchoFrame,
            indiceY * altoFrame,
            anchoFrame,
            altoFrame
        );

        // Usar la escala definida
        Rectangle destino = Rectangle(
            x,
            y,
            (int)(anchoFrame * escala),
            (int)(altoFrame * escala)
        );

        canvas->DrawImage(bmp, destino, porcion, GraphicsUnit::Pixel);
        delete bmp;
    }

}