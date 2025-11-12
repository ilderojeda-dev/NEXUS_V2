#include "DialogoService.h"

DialogoService::DialogoService() {
    dialogoActual = new Dialogo();
    inicializarDialogos();
}

DialogoService::~DialogoService() {
    delete dialogoActual;
    dialogos.clear();
}

void DialogoService::inicializarDialogos() {
    // Dialogos genericos para cualquier entidad del juego (suficientes para 15+ encuentros)
    dialogos.push_back("Alto ahi!\n\nAntes de continuar, debes demostrar tu conocimiento.\n\nResponde correctamente para avanzar...");
    dialogos.push_back("Impresionante...\n\nPero aun hay mas desafios por delante.\n\nPreparate para la siguiente pregunta...");
    dialogos.push_back("Muy bien!\n\nSigues avanzando en tu aprendizaje.\n\nResponde esta pregunta...");
    dialogos.push_back("Excelente progreso!\n\nEstas demostrando gran sabiduria.\n\nContinuemos...");
    dialogos.push_back("Casi llegamos!\n\nSolo un reto mas.\n\nDemuestra todo lo que has aprendido...");
    dialogos.push_back("Ultima prueba!\n\nEsta es tu oportunidad de brillar.\n\nEstas listo?");
    dialogos.push_back("Bienvenido!\n\nResponde correctamente y podras continuar.\n\nAdelante...");
    dialogos.push_back("Hola viajero!\n\nTengo una pregunta para ti.\n\nResponde con cuidado...");
    dialogos.push_back("Felicidades por llegar hasta aqui!\n\nAhora responde esta pregunta.\n\nBuena suerte...");
    dialogos.push_back("Vaya! Otro desafio mas!\n\nDemuestra lo que sabes.\n\nAdelante...");
    dialogos.push_back("Magnifico trabajo hasta ahora!\n\nPero aun no termina.\n\nResponde esta pregunta...");
    dialogos.push_back("Has llegado lejos!\n\nContinuemos con el aprendizaje.\n\nAqui va otra pregunta...");
    dialogos.push_back("Sigue asi!\n\nCada respuesta correcta te acerca mas.\n\nResponde esta...");
    dialogos.push_back("Increible!\n\nEstas dominando el tema.\n\nUna pregunta mas...");
    dialogos.push_back("Ya casi!\n\nDemuestra todo tu conocimiento.\n\nUltima pregunta!");


    // Dialogos especificos para recoleccion de monedas
    dialogos.push_back("Genial!\n\nHas encontrado una moneda dorada.\n\nSigue explorando para encontrar mas tesoros...");
    dialogos.push_back("Fantastico!\n\nTu perseverancia esta dando frutos.\n\nContinua tu aventura...");
    dialogos.push_back("Bien hecho!\n\nCada moneda te acerca a tu objetivo.\n\nNo te rindas ahora...");
    dialogos.push_back("Sorprendente!\n\nEres un verdadero recolector de tesoros.\n\nSigue asi campeón...");
    dialogos.push_back("Perfecto!\n\nTus habilidades mejoran con cada paso.\n\nEl exito esta cerca...");
    dialogos.push_back("Maravilloso!\n\nHas demostrado ser digno de estos tesoros.\n\nLa aventura continua...");
    dialogos.push_back("Estupendo!\n\nTu determinacion es admirable.\n\nSigue recolectando monedas...");
    dialogos.push_back("Asombroso!\n\nCada moneda es un paso hacia la victoria.\n\nNo te detengas...");
    dialogos.push_back("Brillante!\n\nEstas en el camino correcto.\n\nLa princesa estara orgullosa...");
    dialogos.push_back("Extraordinario!\n\nTu valentia sera recompensada.\n\nContinua tu mision...");
    dialogos.push_back("Soberbio!\n\nEstas demostrando ser un heroe.\n\nSigue adelante con valor...");

    dialogos.push_back("Wow!\n\nOtra moneda para tu coleccion.\n\nTu esfuerzo vale la pena...");
    dialogos.push_back("Que suerte!\n\nHas encontrado un tesoro brillante.\n\nBusca mas en el camino...");
    dialogos.push_back("Excelente!\n\nTu bolsa de monedas crece.\n\nLa fortuna te sonrie...");
    dialogos.push_back("Impecable!\n\nOtro tesoro agregado a tu coleccion.\n\nSigue asi aventurero...");
    dialogos.push_back("Formidable!\n\nEsta moneda te hara mas fuerte.\n\nNo pierdas el ritmo...");
    dialogos.push_back("Magnifico!\n\nTu riqueza aumenta.\n\nLa princesa necesita tu ayuda...");
    dialogos.push_back("Espectacular!\n\nOtra moneda resplandeciente.\n\nTu leyenda crece...");
    dialogos.push_back("Increible hallazgo!\n\nEste tesoro vale oro.\n\nContinua tu busqueda...");
    dialogos.push_back("Fabuloso!\n\nTu tesoro crece con cada moneda.\n\nEl reino contara tu historia...");
    dialogos.push_back("Sensacional!\n\nHas demostrado gran habilidad.\n\nSigue recolectando tesoros...");
    dialogos.push_back("Prodigioso!\n\nTu fortuna esta asegurada.\n\nAdelante valiente heroe...");
    dialogos.push_back("Admirable!\n\nOtro tesoro en tu poder.\n\nTu destino es grandioso...");
    dialogos.push_back("Glorioso!\n\nEsta moneda brilla especialmente.\n\nTu victoria esta cerca...");
    dialogos.push_back("Fenomenal!\n\nTu tesoro es invaluable.\n\nLa aventura continua...");
    dialogos.push_back("Esplendido!\n\nCada moneda cuenta tu historia.\n\nSigue escribiendo tu leyenda...");
}


string DialogoService::obtenerDialogo(int indice) {
    if (indice >= 0 && indice < dialogos.size()) {
        return dialogos[indice];
    }
    return "Alto ahi!\n\nResponde esta pregunta para continuar...";
}

Dialogo* DialogoService::getDialogoActual() {
    return dialogoActual;
}
