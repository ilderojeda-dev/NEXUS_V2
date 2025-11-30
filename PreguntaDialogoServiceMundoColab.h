#pragma once
#include "DialogoService.h"
#include "PreguntaService.h" // ya incluye Pregunta.h indirectamente si corresponde

class PreguntaDialogoServiceMundoColab : public PreguntaService {
private:
    // almacenamos la última pregunta seleccionada (puntero gestionado por la clase base)
    Pregunta* preguntaActual;
    Dialogo* dialogoActual;
	vector<Dialogo*> dialogosLista;
  

public:
    PreguntaDialogoServiceMundoColab();
    ~PreguntaDialogoServiceMundoColab();
  

    void cargarPreguntas();
    void cargarDialogos();


    // Devuelve un puntero a la pregunta actual (no libera)
    // Implementación: usará obtenerPreguntaActual() de la clase base
    Pregunta* obtenerPregunta();
	Dialogo* obtenerDialogo(int indice);
    // accessor simple
    Pregunta* getPreguntaActual() { return preguntaActual; }
    Dialogo* getDialogoActual() { return dialogoActual; }
    int getCantidadDialogos() { return dialogosLista.size(); }
};
