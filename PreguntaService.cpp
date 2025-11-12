#include "PreguntaService.h"

PreguntaService::PreguntaService() {
    indiceActual = 0;
}

PreguntaService::~PreguntaService() {
    for (int i = 0; i < preguntas.size(); i++) {
        delete preguntas[i];
    }
    preguntas.clear();
}

void PreguntaService::agregarPregunta(Pregunta* pregunta) {
    preguntas.push_back(pregunta);
}

Pregunta* PreguntaService::obtenerPreguntaActual() {
    if (indiceActual < preguntas.size()) {
        return preguntas[indiceActual];
    }
    return nullptr;
}

bool PreguntaService::hayMasPreguntas() {
    return indiceActual < preguntas.size();
}

void PreguntaService::avanzarSiguientePregunta() {
    indiceActual++;
}

int PreguntaService::getPreguntasRestantes() {
    return preguntas.size() - indiceActual;
}
