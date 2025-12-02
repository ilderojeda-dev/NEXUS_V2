# 🌌 NEXUS_V2 – Videojuego “IA vs Pensamiento Crítico”
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Windows Forms](https://img.shields.io/badge/.NET%20Framework-512BD4?style=for-the-badge&logo=dot-net&logoColor=white)
![Estado](https://img.shields.io/badge/Estado-FINALIZADO-brightgreen?style=for-the-badge)
![Trabajo Final](https://img.shields.io/badge/Trabajo%20Final-UPC-orange?style=for-the-badge)

NEXUS_V2 es un videojuego desarrollado en **C++** sobre **Windows Forms**, como Trabajo Final del curso  
**Algoritmos (1ACC0265) – UPC**.  

El proyecto explora la relación entre **IA, pensamiento humano y la colaboración**, a través de tres mundos con dinámicas, físicas y retos completamente diferentes.

---

## 🎮 Descripción General

El videojuego busca demostrar que:

- La **IA** aporta precisión, cálculos deterministas y eficiencia.  
- El **humano** aporta creatividad, intuición y toma de decisiones contextual.  
- La **combinación correcta de ambos** produce los mejores resultados.

NEXUS presenta tres mundos diseñados para simbolizar esta evolución.

---

## 🌉 Mundos del Juego

| Mundo | Enfoque | Representación |
| :--- | :--- | :--- |
| 🤖 **1. Mundo IA** | Algoritmos y Rigidez | Movimiento determinista, decisiones mecánicas y escenarios controlados. |
| 💡 **2. Mundo Humano** | Creatividad y Criterio | Caos ordenado, recursos limitados y adaptación inspirada en casos reales (ej: Apollo 13). |
| 🌉 **3. Mundo Colaborativo** | Equilibrio | La IA asiste, pero el jugador decide. Mezcla de precisión + intuición humana. |

---

## ⭐ Sistema de Puntuación (Score)

El puntaje final se calcula sumando valores generados en cada mundo:

- **Mundo IA:** Nivel de Autonomía  
- **Mundo Humano:** Índice de Criterio Humano  
- **Mundo Colaborativo:** Nivel de Confianza (Respuestas Correctas)

Se guarda en un archivo binario: **`/Files/SCORES.bin`**  
y se carga automáticamente al iniciar el juego.

---

## 🛠️ Tecnologías y Paradigmas Usados

- **Lenguaje:** C++ (C++/CLI)  
- **Interfaz Gráfica:** Windows Forms — Visual Studio 2022  
- **Paradigma:** Programación Orientada a Objetos (POO)  
- **Persistencia:**  
  - `PARAMETERS.txt` → Parámetros configurables  
  - `SCORES.bin` → Tabla de clasificación  
- **Control de Versiones:** Git + GitHub (main, develop, feature/*)

---

## 📂 Estructura del Proyecto

```text
NEXUS_V2/
├─ Files/
│  Contiene los archivos externos del juego:
│  - PARAMETERS.txt : configuración de parámetros del gameplay
│  - SCORES.bin : sistema de puntuaciones
│
├─ Model/
│  Contiene las clases del diseño del juego (entidades):
│  Jugador, Enemigos, Aliados, Recursos, Muros y demás estructuras base.
│
├─ Resource/
│  Contiene todos los recursos multimedia:
│  imágenes, sprites, sonidos y fondos utilizados en los tres mundos.
│
├─ Service/
│  Contiene la lógica central del videojuego:
│  servicios por cada mundo, controladores de actualización,
│  colisiones y comportamiento del gameplay.
│
├─ UI/
│  Contiene todos los formularios visuales del juego:
│  Menú principal, formularios de cada mundo y pantallas auxiliares.
│
└─ Principal.cpp
   Punto de entrada del videojuego (función main).
````

---

## 🚀 Cómo Ejecutar el Proyecto

1. Clonar el repositorio:

   ```bash
   git clone https://github.com/ilderojeda-dev/NEXUS_V2.git
   ```
2. Abrir el archivo **NEXUS_V2.sln** con **Visual Studio 2022**.
3. Asegurarse de tener instalada la carga de trabajo **"Desarrollo para el escritorio con C++"** y el componente **C++/CLI**.
4. Compilar para iniciar el juego,

---

## 🎥 Video de Demostración
Demostración completa del flujo de juego y la lógica de los tres mundos: 

👉 **[VER VIDEO DEMOSTRACIÓN DE NEXUS EN YOUTUBE](https://youtu.be/CR-qc-bOW58)**

---

## 👥 Equipo de Desarrollo – NEXUS

Este proyecto fue desarrollado íntegramente por el **Equipo NEXUS**.

| Estudiante                      | Rol                                 | GitHub                                                                 |
| :------------------------------ | :---------------------------------- | :--------------------------------------------------------------------- |
| **Ilder Jesús Ojeda García**    | Arquitectura / Integración General  | [ilderojeda-dev](https://github.com/ilderojeda-dev) |
| **Gerardo Jesús Morales Silva** | Lógica de Juego / Sistemas Internos | [Gergatopu](https://github.com/Gergatopu)           |
| **Adriano Matos Román**         | Diseño Visual / UI                  | [Adrianom-r](https://github.com/Adrianom-r)         |

Todos participaron en:

* Programación del gameplay
* Diseño e implementación de mundos
* Integración de recursos y UI
* Pruebas, depuración y mantenimiento
* Organización del repositorio GitHub

---

## 👨‍🏫 Docente del Curso
**Henry Antonio Mendoza Puerta**

GitHub: [hampcode](https://github.com/hampcode)

---

## 📸 Galería del Equipo

*(Aquí puedes agregar imágenes de la presentación final o el equipo.)*

---

