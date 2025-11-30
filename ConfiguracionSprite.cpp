#include "ConfiguracionSprite.h"

ConfiguracionSprite::ConfiguracionSprite() {
    indiceIzquierda = 1;
    indiceDerecha = 2;
    indiceArriba = 3;
    indiceAbajo = 0;
    indiceSaltoIzquierda = 1;
    indiceSaltoDerecha = 2;

    framesIzquierda = 4;
    framesDerecha = 4;
    framesArriba = 4;
    framesAbajo = 4;
    framesSalto = 4;
}

// Configuración para Mundo IA
 ConfiguracionSprite ConfiguracionSprite::ConfiguracionMundoIA() {
    ConfiguracionSprite config;
    config.indiceIzquierda = 0;      
    config.indiceDerecha = 1;        
    config.indiceArriba = 2;         
    config.indiceAbajo = 2;          
    config.indiceSaltoIzquierda = 3; 
    config.indiceSaltoDerecha = 4;   

    config.framesIzquierda = 8;
    config.framesDerecha = 8;
    config.framesArriba = 6;
    config.framesAbajo = 6;
    config.framesSalto = 5;

    return config;
}

// Configuración para Mundo Humano
 ConfiguracionSprite ConfiguracionSprite::ConfiguracionMundoHumano() {
    ConfiguracionSprite config;
    config.indiceIzquierda = 1;
    config.indiceDerecha = 2;
    config.indiceArriba = 3;
    config.indiceAbajo = 0;
    config.indiceSaltoIzquierda = 1;
    config.indiceSaltoDerecha = 2;

    config.framesIzquierda = 4;
    config.framesDerecha = 4;
    config.framesArriba = 4;
    config.framesAbajo = 4;
    config.framesSalto = 4;

    return config;
}

// Configuración para Mundo Colab
 ConfiguracionSprite ConfiguracionSprite::ConfiguracionMundoColab() {
    return ConfiguracionMundoHumano(); // Misma config que humano
}