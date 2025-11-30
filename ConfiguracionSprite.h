#pragma once

enum TipoMundo {MundoHumano, MundoIA, MundoColab};

class ConfiguracionSprite {
private:
    // Configuración de índices Y para cada dirección
    int indiceIzquierda;
    int indiceDerecha;
    int indiceArriba;
    int indiceAbajo;
    int indiceSaltoIzquierda;
    int indiceSaltoDerecha;

    // Cantidad de frames por animación
    int framesIzquierda;
    int framesDerecha;
    int framesArriba;
    int framesAbajo;
    int framesSalto;

public:    
    ConfiguracionSprite();

	int getFramesSalto() { return framesSalto; }
	int getIndiceSaltoIzquierda() { return indiceSaltoIzquierda; }
	int getIndiceSaltoDerecha() { return indiceSaltoDerecha; }
	int getIndiceIzquierda() { return indiceIzquierda; }
	int getIndiceDerecha() { return indiceDerecha; }
	int getIndiceArriba() { return indiceArriba; }
	int getIndiceAbajo() { return indiceAbajo; }
	int getFramesIzquierda() { return framesIzquierda; }
	int getFramesDerecha() { return framesDerecha; }
	int getFramesArriba() { return framesArriba; }
	int getFramesAbajo() { return framesAbajo; }

    // Métodos estáticos para configuración
    static ConfiguracionSprite ConfiguracionMundoIA();
    static ConfiguracionSprite ConfiguracionMundoHumano();
    static ConfiguracionSprite ConfiguracionMundoColab();
};