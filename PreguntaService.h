#pragma once
#include "Pregunta.h"
#include <vector>

using namespace std;

class PreguntaService {
private:
    vector<Pregunta*> preguntas;
    int indiceActual;

public:
    PreguntaService();
    ~PreguntaService();

    void agregarPregunta(Pregunta* pregunta);
    Pregunta* obtenerPreguntaActual();
    bool hayMasPreguntas();
    void avanzarSiguientePregunta();
    int getPreguntasRestantes();
};
