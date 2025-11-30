#pragma once
using namespace System;

namespace NEXUSV2 { // Usa tu namespace correcto
    public ref class Sesion {
    public:
        // 1. DATOS DEL JUGADOR (Se llenan en FrmInicio)
        static String^ NombreJugador = "Cadete";
        static bool EsModoHistoria = false;


        // 2. PUNTAJES DE CADA MUNDO (Se llenan al terminar cada nivel)
        static int PuntajeMundoIA = 0;       // Nivel 1: Humanidad
        static int PuntajeMundoHumano = 0;   // Nivel 2: Criterio
        static int PuntajeMundoColab = 0;    // Nivel 3: Confianza

        // 3. MÉTODO PARA REINICIAR (Llamar al volver al menú)
        static void Reiniciar() {
            NombreJugador = "Cadete";
            EsModoHistoria = false;
            PuntajeMundoIA = 0;
            PuntajeMundoHumano = 0;
            PuntajeMundoColab = 0;
        }
    };
}