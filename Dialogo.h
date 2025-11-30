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
    bool autoCerrar;
    int tiempoVisible;
    int tiempoMaximo;

public:
    Dialogo();
    Dialogo(string texto); //nuevo
    ~Dialogo();

    void iniciar(string texto);
    bool actualizar();

    string getTextoActual();
    bool estaEnProgreso();
    void detener();


    void setAutoCerrar(bool ac, int tiempo = 180) {
        autoCerrar = ac;
        tiempoMaximo = tiempo;
        tiempoVisible = 0;
    }

    string getTextoCompleto() { return textoCompleto; }

};
