#include "ArchivoService.h"
#include <fstream>
#include <ctime>   // Para la fecha y hora
#include <cstring> // Para manejar char[] (strcpy_s, memset)

// --- LIBRERÍA IMPORTANTE PARA CONVERTIR TEXTO ---
#include <msclr/marshal_cppstd.h>
using namespace std;
using namespace System;
// ===== CONSTRUCTOR =====

ArchivoService::ArchivoService() {
}

// ===== ESCRITURA DE ARCHIVOS =====

void ArchivoService::guardarLineas(string nombreArchivo, vector<string> lineas) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < lineas.size(); i++) {
            archivo << lineas[i];
            if (i < lineas.size() - 1) {
                archivo << endl;
            }
        }
        archivo.close();
    }
}

// ===== LECTURA DE ARCHIVOS =====

vector<string> ArchivoService::leerTodasLineas(string nombreArchivo) {
    vector<string> lineas;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            lineas.push_back(linea);
        }
        archivo.close();
    }

    return lineas;
}

// ===== VALIDACION =====

bool ArchivoService::archivoExiste(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    return archivo.good();
}



// ===== MANEJO DE ARCHIVOS BINARIOS SIMPLE =====

void ArchivoService::guardarTextoEnBinario(string nombreArchivo, string texto) {
    ofstream archivo(nombreArchivo, ios::binary);
    if (archivo.is_open()) {
        archivo << texto;
        archivo.close();
    }
}

string ArchivoService::leerTextoDelBinario(string nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::binary);
    string contenido = "";

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            contenido += linea + "\n";
        }
        archivo.close();
    }

    return contenido;
}


void ArchivoService::GuardarPartida(String^ nombreNet, bool esHistoria, int p1, int p2, int p3, int total) {
    // 1. Crear estructura vacía
    RegistroScore fila;
    memset(&fila, 0, sizeof(RegistroScore));

    // 2. Convertir Nombre (String^ -> char array)
    std::string nombreStd = msclr::interop::marshal_as<std::string>(nombreNet);
    strncpy_s(fila.nombre, nombreStd.c_str(), 49);

    // 3. Llenar Datos
    fila.esModoHistoria = esHistoria;
    fila.ptjAutonomia = p1;
    fila.ptjCriterio = p2;
    fila.ptjConfianza = p3;
    fila.puntajeTotal = total;

    // 4. Fecha
    time_t ahora = time(0);
    tm tiempoLocal;
    localtime_s(&tiempoLocal, &ahora);
    strftime(fila.fecha, 30, "%d/%m/%Y %H:%M", &tiempoLocal);

    // 5. Guardar en Binario
    ofstream archivo("Files/SCORES.bin", ios::binary | ios::app);
    if (archivo.is_open()) {
        archivo.write((char*)&fila, sizeof(RegistroScore));
        archivo.close();
    }
}