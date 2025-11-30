#include "ArchivoService.h"
#include <fstream>

using namespace std;

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


// =========================================================
// MANEJO DE SCORES BINARIOS (Estructuras)
// =========================================================

//void ArchivoService::guardarScoreBinario(ScoreData data) {
//    // Usamos la ruta fija que pide la rúbrica
//    ofstream archivo("Files/SCORES.bin", ios::binary | ios::app);
//
//    if (archivo.is_open()) {
//        // Escribimos la memoria exacta de la estructura
//        archivo.write((char*)&data, sizeof(ScoreData));
//        archivo.close();
//    }
//}
//
//vector<ScoreData> ArchivoService::leerScoresBinario() {
//    vector<ScoreData> lista;
//    ifstream archivo("Files/SCORES.bin", ios::binary);
//
//    if (archivo.is_open()) {
//        ScoreData dataTemp;
//
//        // Leemos bloque por bloque del tamaño de ScoreData
//        while (archivo.read((char*)&dataTemp, sizeof(ScoreData))) {
//            lista.push_back(dataTemp);
//        }
//        archivo.close();
//    }
//    return lista;
//}


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
