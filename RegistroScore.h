#pragma once

// Estructura C++ Puro (Sin String^) para guardar en Binario
struct RegistroScore {
    char nombre[50];      // Nombre del Cadete

    bool esModoHistoria;  // ¿Jugó la historia completa?

 
    int ptjAutonomia;     // Nivel 1 (IA)
    int ptjCriterio;      // Nivel 2 (Humano)
    int ptjConfianza;     // Nivel 3 (Colaborativo)

    int puntajeTotal;     // Suma o Promedio

    char fecha[30];       // Fecha de la misión
};