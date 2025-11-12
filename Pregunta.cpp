#include "Pregunta.h"
#include <cstring>

Pregunta::Pregunta(char* pregunta, vector<char*> opts, int respuesta) {
    textoPregunta = new char[strlen(pregunta) + 1];
    strcpy(textoPregunta, pregunta);

    for (int i = 0; i < opts.size(); i++) {
        char* opcion = new char[strlen(opts[i]) + 1];
        strcpy(opcion, opts[i]);
        opciones.push_back(opcion);
    }

    respuestaCorrecta = respuesta;
}

Pregunta::~Pregunta() {
    delete[] textoPregunta;
    for (int i = 0; i < opciones.size(); i++) {
        delete[] opciones[i];
    }
    opciones.clear();
}

char* Pregunta::getTextoPregunta() {
    return textoPregunta;
}

vector<char*>& Pregunta::getOpciones() {
    return opciones;
}

int Pregunta::getRespuestaCorrecta() {
    return respuestaCorrecta;
}

bool Pregunta::esRespuestaCorrecta(int respuesta) {
    return respuesta == respuestaCorrecta;
}
