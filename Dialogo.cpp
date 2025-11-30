#include "Dialogo.h"

Dialogo::Dialogo() {
    textoCompleto = "";
    textoActual = "";
    indice = 0;
    contador = 0;
    enProgreso = false;

    // ? AGREGAR ESTAS INICIALIZACIONES
    autoCerrar = false;
    tiempoVisible = 0;
    tiempoMaximo = 0;
}

Dialogo::~Dialogo() {
}

void Dialogo::iniciar(string texto) {
    textoCompleto = texto;
    textoActual = "";
    indice = 0;
    contador = 0;
    enProgreso = true;
    tiempoVisible = 0; // ? Resetear contador
}

string Dialogo::getTextoActual() {
    return textoActual;
}

bool Dialogo::estaEnProgreso() {
    return enProgreso;
}

void Dialogo::detener() {
    enProgreso = false;
}

bool Dialogo::actualizar() {
    // Si el diálogo terminó de escribirse
    if (!enProgreso) {
        if (autoCerrar) {
            tiempoVisible++;
            if (tiempoVisible >= tiempoMaximo) {
                return false; // Señal para cerrar
            }
            return true; // ? Mantener visible mientras cuenta
        }
        return true; // ? Mantener visible hasta que el usuario presione Enter
    }

    // Escribir 3 caracteres por frame
    for (int i = 0; i < 3; i++) {
        if (indice < textoCompleto.length()) {
            textoActual += textoCompleto[indice];
            indice++;
        }
        else {
            enProgreso = false;
            return true; // ? Completado pero seguir mostrando
        }
    }

    return true;
}