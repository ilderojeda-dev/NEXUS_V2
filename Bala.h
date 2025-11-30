#pragma once
#include "Sprite.h"

using namespace System::Drawing;

class Bala : public Sprite {
private:
    Direccion direccion;

public:
    Bala(int x, int y, Direccion dir) : Sprite(x, y) {
        this->direccion = dir;
        this->image = nullptr;

        // Dimensiones según dirección
        if (dir == Direccion::Arriba || dir == Direccion::Abajo) {
            this->ancho = 2;
            this->alto = 6;
        }
        else {
            this->ancho = 6;
            this->alto = 2;
        }
    }

    bool fueraDePantalla(int anchoMundo, int altoMundo) {
        return (x < 0 || x > anchoMundo || y < 0 || y > altoMundo);
    }

    void dibujar(Graphics^ canvas) override {
        SolidBrush^ pincel = gcnew SolidBrush(System::Drawing::Color::Yellow);
        canvas->FillRectangle(pincel, x, y, ancho, alto);
        delete pincel;
    }

    void mover(Direccion tecla, int limiteAncho, int limiteAlto, int velocidad) override {
        switch (direccion) {
        case Direccion::Derecha:
            x += velocidad;
            break;
        case Direccion::Izquierda:
            x -= velocidad;
            break;
        case Direccion::Arriba:
            y -= velocidad;
            break;
        case Direccion::Abajo:
            y += velocidad;
            break;
        }
    }
};