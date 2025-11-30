#pragma once
#include <string>

using namespace std;

class Dialogo {
private:
    string textoCompleto;
    string textoActual;
   
    int indice;
    int contador;
    bool enProgreso;

public:
    Dialogo();
    Dialogo(string texto); //nuevo
    ~Dialogo();

    void iniciar(string texto);
    bool actualizar();

    string getTextoActual();
    bool estaEnProgreso();
    void detener();
    string getTextoCompleto() { return textoCompleto; }
};
