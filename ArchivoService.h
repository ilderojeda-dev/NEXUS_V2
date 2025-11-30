#pragma once
#include <string>
#include <vector>
#include "RegistroScore.h"
using namespace std;


class ArchivoService {
public:
    ArchivoService();

    // Guardar lineas de texto en un archivo
    void guardarLineas(string nombreArchivo, vector<string> lineas);

    // Leer todas las lineas de un archivo
    vector<string> leerTodasLineas(string nombreArchivo);

    // Verificar si un archivo existe
    bool archivoExiste(string nombreArchivo);


    // Métodos simples para archivo binario con strings e int
    void guardarTextoEnBinario(string nombreArchivo, string texto);
    string leerTextoDelBinario(string nombreArchivo);
    void GuardarPartida(System::String^ nombreNet, bool esHistoria, int p1, int p2, int p3, int total);
};
