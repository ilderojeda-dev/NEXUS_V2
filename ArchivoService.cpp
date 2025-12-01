#include "ArchivoService.h"
#include <fstream>
#include <ctime>   // Para la fecha y hora
#include <cstring> // Para manejar char[] (strcpy_s, memset)
#include <algorithm> // Add this include for std::sort
#include "ArchivoService.h" 
#include <msclr/marshal_cppstd.h> // <<< SOLO LO AGREGAMOS AQUÍ
using namespace msclr::interop; // Usamos el namespace para simplificar el código
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


System::String^ ArchivoService::ConvertCharToString(const char* nativeString) {

    // Verificación básica para evitar errores si la cadena es nula o vacía
    if (!nativeString || nativeString[0] == '\0') {
        return System::String::Empty; // Retorna una cadena vacía de .NET
    }

    // La conversión se realiza aquí, en el ámbito aislado del .cpp
    return marshal_as<System::String^>(nativeString);
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
// ArchivoService.cpp

std::vector<RegistroScore> ArchivoService::LeerRegistrosBinarios(std::string nombreArchivo) {
    std::vector<RegistroScore> registros;
    RegistroScore registro; // Buffer de un solo registro

    // Abrir el archivo en modo lectura binaria
    std::ifstream archivo(nombreArchivo, std::ios::binary | std::ios::in);

    if (archivo.is_open()) {
        // Moverse por el archivo y leer cada estructura
        while (archivo.read((char*)&registro, sizeof(RegistroScore))) {
            registros.push_back(registro);
        }
        archivo.close();
    }

    // Opcional: ordenar los registros por puntajeTotal de mayor a menor
    std::sort(registros.begin(), registros.end(),
        [](const RegistroScore& a, const RegistroScore& b) {
            return a.puntajeTotal > b.puntajeTotal;
        });

    return registros;
    
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