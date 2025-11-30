    #include "PreguntaDialogoServiceMundoColab.h"

    // Constructor: llama a cargarPreguntas() heredada indirectamente usando agregarPregunta()
    PreguntaDialogoServiceMundoColab::PreguntaDialogoServiceMundoColab() : PreguntaService() {
        preguntaActual = nullptr;
        cargarPreguntas();
	    cargarDialogos();
    }

    PreguntaDialogoServiceMundoColab::~PreguntaDialogoServiceMundoColab() {
        // Nada especial: la clase base libera las preguntas en su destructor si así se implementó.
    }

    // Devuelve la 'pregunta actual' usando la API pública de la clase base.
    // Aquí simplemente devolvemos obtenerPreguntaActual() (la clase base debe implementar eso).
    Pregunta* PreguntaDialogoServiceMundoColab::obtenerPregunta() {
        // Intentamos obtener la pregunta actual de la clase base
        Pregunta* p = this->obtenerPreguntaActual();
        if (p == nullptr) {
            // si no hay 'actual', intentamos avanzar y volver a obtenerla
            if (this->hayMasPreguntas()) {
                this->avanzarSiguientePregunta();
                p = this->obtenerPreguntaActual();
            }
        }
        preguntaActual = p;
        return preguntaActual;
    }
    Dialogo* PreguntaDialogoServiceMundoColab::obtenerDialogo(int indice) {
        if (indice >= 0 && indice < dialogosLista.size()) {
            dialogoActual = dialogosLista[indice];
            return dialogoActual;
        }
        return nullptr;
    }
    void PreguntaDialogoServiceMundoColab::cargarPreguntas() {

        agregarPregunta(new Pregunta(
            (char*)"¿Cual es el planeta mas grande del sistema solar?",
            { (char*)"Tierra", (char*)"Jipiter", (char*)"Saturno", (char*)"Neptuno" },
            1
        ));

        agregarPregunta(new Pregunta(
            (char*)"¿Que estrella esta mas cerca de la Tierra?",
            { (char*)"Sirio", (char*)"Proxima Centauri", (char*)"Sol", (char*)"Betelgeuse" },
            2
        ));

        agregarPregunta(new Pregunta(
            (char*)"¿Que planeta es conocido como el planeta rojo?",
            { (char*)"Venus", (char*)"Marte", (char*)"Mercurio", (char*)"Pluton" },
            1
        ));

        agregarPregunta(new Pregunta(
            (char*)"¿Cual es la galaxia donde vivimos?",
            { (char*)"Andromeda", (char*)"Via Lactea", (char*)"Sombrero", (char*)"Triangulo" },
            1
        ));

        agregarPregunta(new Pregunta(
            (char*)"¿Cual es el satelite natural de la Tierra?",
            { (char*)"Europa", (char*)"La Luna", (char*)"Titan", (char*)"Io" },
            1
        ));

        agregarPregunta(new Pregunta(
            (char*)"¿Que planeta tiene un sistema de anillos muy prominente?",
            { (char*)"Urano", (char*)"Jupiter", (char*)"Saturno", (char*)"Neptuno" },
            2
        ));

        agregarPregunta(new Pregunta(
            (char*)"¿Como se llama la fuerza que mantiene a los planetas en orbita?",
            { (char*)"Magnetismo", (char*)"Viento solar", (char*)"Inercia", (char*)"Gravedad" },
            3
        ));

        agregarPregunta(new Pregunta(
            (char*)"¿Cual es el planeta mas cercano al Sol?",
            { (char*)"Venus", (char*)"Mercurio", (char*)"Marte", (char*)"Tierra" },
            1
        ));

        agregarPregunta(new Pregunta(
            (char*)"¿Que tipo de astro es el Sol?",
            { (char*)"Una estrella enana amarilla", (char*)"Un planeta gigante gaseoso", (char*)"Un agujero negro", (char*)"Una nebulosa" },
            0
        ));

        agregarPregunta(new Pregunta(
            (char*)"¿Qué planeta es conocido por sus enormes tormentas llamadas 'Mancha Roja'?",
            { (char*)"Saturno", (char*)"Neptuno", (char*)"Jupiter", (char*)"Urano" },
            2
        ));

        agregarPregunta(new Pregunta(
            (char*)"¿Cual es el planeta más frio del sistema solar?",
            { (char*)"Urano", (char*)"Neptuno", (char*)"Pluton", (char*)"Saturno" },
            0
        ));

        agregarPregunta(new Pregunta(
            (char*)"¿Como se llama nuestra galaxia vecina mas grande?",
            { (char*)"Galaxia del Sombrero", (char*)"Andromeda", (char*)"Centauro A", (char*)"Pequeña Nube de Magallanes" },
            1
        ));

        agregarPregunta(new Pregunta(
            (char*)"¿Que planeta tiene la mayor cantidad de lunas conocidas?",
            { (char*)"Saturno", (char*)"Jupiter", (char*)"Neptuno", (char*)"Urano" },
            0
        ));

        agregarPregunta(new Pregunta(
            (char*)"¿Como se llama el punto donde nada puede escapar de un agujero negro?",
            { (char*)"Horizonte de sucesos", (char*)"Singularidad", (char*)"Evento cuantico", (char*)"Corte gravitacional" },
            0
        ));

        agregarPregunta(new Pregunta(
            (char*)"¿Que planeta tiene un día más largo que su año?",
            { (char*)"Mercurio", (char*)"Venus", (char*)"Tierra", (char*)"Marte" },
            1
        ));
    }

    void PreguntaDialogoServiceMundoColab::cargarDialogos() {
        dialogosLista.clear();

        dialogosLista.push_back(new Dialogo("Ten cuidado, no queremos volvernos basura espacial."));
        dialogosLista.push_back(new Dialogo("Cuidado, meteoritos acercandose!."));
        dialogosLista.push_back(new Dialogo("Mantente alerta! Los meteoritos aumentan."));
        dialogosLista.push_back(new Dialogo("Ya casi lo logras, solo resiste un poco más."));
        dialogosLista.push_back(new Dialogo("Todas las municiones son necesarias, conservalas hasta que sea necesario usarlas"));
        dialogosLista.push_back(new Dialogo("Yo te ayudo a recargar! tu solo encargate de no chocar!"));
    }