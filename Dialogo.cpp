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
tiempoVisible = 0; // Resetear contador
}

// --- ESTO VIENE DE MUNDO IA (Mantenlo) ---
string Dialogo::getTextoActual() {
    return textoActual;
}

bool Dialogo::estaEnProgreso() {
    return enProgreso;
}

void Dialogo::detener() {
    enProgreso = false;
}

// --- ESTO VIENE DE DEVELOP/COLABORATIVO (Mantenlo también) ---
Dialogo::Dialogo(string texto) { //nuevo
    iniciar(texto);
}

bool Dialogo::actualizar() {
    // Si el di�logo termin� de escribirse
    if (!enProgreso) {
        if (autoCerrar) {
            tiempoVisible++;
            if (tiempoVisible >= tiempoMaximo) {
                return false; // Se�al para cerrar
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