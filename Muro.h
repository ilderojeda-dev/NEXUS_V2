#pragma once
#include <algorithm>
using namespace System::Drawing;  // NECESARIO para usar Rectangle

class Muro {
private:
    int x;
    int y;
    int w;
    int h;

public:
    Muro(int x, int y, int w, int h)
        : x(x), y(y), w(w), h(h) {
    }

    // Getters
    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return w; }
    int getHeight() const { return h; }

    // Devuelve un Rectangle del .NET Framework
    Rectangle getRectangle() const {
        return Rectangle(x, y, w, h);
    }
};
