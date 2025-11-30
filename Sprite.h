#pragma once
using namespace System::Drawing;

enum Direccion { Arriba, Abajo, Derecha, Izquierda, Ninguno, espacio };

class Sprite {
protected:
    int x, y;
    int dx, dy;
    char* image;
    int indiceX, indiceY;
    int ancho, alto;
    int filas, columnas;
    float escala; 

public:
    Sprite();
    Sprite(int x, int y);
    ~Sprite();

    void cargarImagen(char* ruta, int filas, int columnas);
    virtual void dibujar(Graphics^ canvas) = 0;
    virtual void mover(Direccion tecla, int limiteAncho, int limiteAlto) = 0;
    float getEscala();
    void setEscala(float e);

    int getX();
    int getY();
    int getAncho();
    int getAlto();
    void setX(int x);
    void setY(int y);

    Rectangle getRectangle();

    void setIndiceX(int ix) {
		indiceX = ix;
    }
    void setIndiceY(int iy) {
		indiceY = iy;
    }
    int getIndiceX() {
        return indiceX;
    }
    int getIndiceY() {
        return indiceY;
    }

    //virtual Rectangle getRectangle(); //cambio a virtual

};

