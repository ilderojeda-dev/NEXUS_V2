#pragma once
#include <vector>

using namespace std;

class Pregunta {
private:
    char* textoPregunta;
    vector<char*> opciones;  // 3-4 opciones
    int respuestaCorrecta;   // Índice de la respuesta correcta (0, 1, 2, 3)

public:
    Pregunta(char* pregunta, vector<char*> opts, int respuesta);
    ~Pregunta();

    char* getTextoPregunta();
    vector<char*>& getOpciones();
    int getRespuestaCorrecta();
    bool esRespuestaCorrecta(int respuesta);
};
