    #include "BalaLaser.h"


    BalaLaser::BalaLaser(int x, int y, int velocidad) : Recurso(x, y) {
        this->velocidad = velocidad;
        dx = velocidad;
        dy = 0;

        explotando = false;
        velocidadAnim = 3;   // frames por cambio de sprite
        contadorAnim = 0;

        indiceX = 0;
        indiceY = 0;         // fila 0 = bala
    }

    BalaLaser::~BalaLaser() {
    }


    void BalaLaser::mover(Direccion tecla, int limiteAncho, int limiteAlto) {
        if (!activo) return;

        if (!explotando) {

            // Movimiento hacia la derecha
            x += dx;

            // Animación normal de la bala (si quieres animarla)
            contadorAnim++;
            if (contadorAnim >= velocidadAnim) {
                indiceX++;
                if (indiceX >= columnas) indiceX = 0;
                contadorAnim = 0;
            }

            // Si sale de la pantalla por la derecha
            if (x > limiteAncho)
                activo = false;
        }
        else {
            // EXPLOSIÓN — se mueve lentamente a la izquierda
            x -= 1;

            contadorAnim++;
            if (contadorAnim >= velocidadAnim) {
                indiceX++;
                contadorAnim = 0;

                if (indiceX >= columnas) {
                    activo = false;  // explosion terminó
                }
            }
        }
    }


    void BalaLaser::iniciarExplosion() {
        if (explotando) return;
        explotando = true;
        dx = -1;             // se empieza a mover a la izquierda para simular movimiento
        indiceX = 0;        // empezar animación
        indiceY = 1;        // fila 1 = explosión
        contadorAnim = 0;
  
        
      
    }



	Rectangle BalaLaser::getRectangleBala() {

		int anchoColision = (int)(ancho * 0.6);
		int altoColision = (int)(alto * 0.2);
		// Centrar el área de colisión en el sprite
		int desplazamientoX = (ancho - anchoColision) / 2 - 20;
		int desplazamientoY = (alto - altoColision) / 3 - 10;
		return Rectangle(x + desplazamientoX, y + desplazamientoY, anchoColision, altoColision);

	}

    void BalaLaser::dibujar(Graphics^ canvas) {
        if (!activo) return;

        if (image != nullptr) {
            Bitmap^ bmap = gcnew Bitmap(gcnew System::String(image));
            Rectangle cuadroOrigen(indiceX * ancho, indiceY * alto, ancho, alto);
            Rectangle cuadroDestino(x, y, ancho * 0.8, alto * 0.8);
            canvas->DrawImage(bmap, cuadroDestino, cuadroOrigen, GraphicsUnit::Pixel);
            delete bmap;
        }
        else {
            // bala por defecto si no hay sprite
            SolidBrush^ b = gcnew SolidBrush(Color::Yellow);
            canvas->FillRectangle(b, x, y, 6, 12);
            delete b;
        }
    }
