#pragma once
#include "MundoIAService.h"

namespace NEXUSV2 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FrmMundoIA : public System::Windows::Forms::Form
	{
	public:
		FrmMundoIA(void)
		{
			InitializeComponent();
			
			mundoIAService = new MundoIAService(pnlMundoIA->Width, pnlMundoIA->Height, 3);

			// Cargar fondos
			mundoIAService->cargarFondos("FondoMundoIA.png", "FondoMundoIANoche.png");

			// Cargar jugador
			mundoIAService->cargarSpriteJugador("PersonajeMundoIA.png", 5, 8);
			mundoIAService->getJugador()->setEscala(0.4f);

			// Crear robots
			mundoIAService->crearRobots("RobotMundoIA.png", 4, 9);
			for (RobotEnemigo* robot : mundoIAService->getRobots()) {
				robot->setEscala(1.2f);
			}

			// Cargar boss
			mundoIAService->cargarFinalBoss("FinalBossMundoIA.png", 5, 8);
			mundoIAService->getFinalBoss()->setEscala(0.4f);

			// Crear chips
			mundoIAService->crearChipsRecursos("Chip.png", 1, 4);

			teclaPresionada = Ninguno;
			this->KeyPreview = true;
			pnlDialogo->Visible = false; 
			pnlDialogo->BringToFront();
		}

	protected:
		~FrmMundoIA()
		{
			if (components) delete components;
		}

	private: 
		System::Windows::Forms::Panel^ pnlMundoIA;
		System::ComponentModel::IContainer^ components;
		MundoIAService* mundoIAService;
		System::Windows::Forms::Timer^ timer1;
		System::Windows::Forms::Label^ lblCinematica;
		System::Windows::Forms::Label^ lblContador;
		System::Windows::Forms::Panel^ pnlDialogo;
		Direccion teclaPresionada;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlMundoIA = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblCinematica = (gcnew System::Windows::Forms::Label());
			this->lblContador = (gcnew System::Windows::Forms::Label());
			this->pnlDialogo = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// pnlMundoIA
			this->pnlMundoIA->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->pnlMundoIA->Location = System::Drawing::Point(2, 2);
			this->pnlMundoIA->Name = L"pnlMundoIA";
			this->pnlMundoIA->Size = System::Drawing::Size(1967, 781);
			this->pnlMundoIA->TabIndex = 0;
			this->pnlMundoIA->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMundoIA::panel1_Paint);
			// timer1
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMundoIA::timer1_Tick);
			// lblCinematica
			this->lblCinematica->AutoSize = true;
			this->lblCinematica->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 20.25F, System::Drawing::FontStyle::Bold));
			this->lblCinematica->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lblCinematica->Location = System::Drawing::Point(12, 858);
			this->lblCinematica->Name = L"lblCinematica";
			this->lblCinematica->Size = System::Drawing::Size(183, 36);
			this->lblCinematica->TabIndex = 0;
			this->lblCinematica->Text = L"Cinematica: ";
			// lblContador
			this->lblContador->AutoSize = true;
			this->lblContador->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 20.25F, System::Drawing::FontStyle::Bold));
			this->lblContador->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lblContador->Location = System::Drawing::Point(12, 961);
			this->lblContador->Name = L"lblContador";
			this->lblContador->Size = System::Drawing::Size(193, 36);
			this->lblContador->TabIndex = 2;
			this->lblContador->Text = L"CONTADOR: ";
			// pnlDialogo
			this->pnlDialogo->BackColor = System::Drawing::Color::AliceBlue;
			this->pnlDialogo->Location = System::Drawing::Point(544, 803);
			this->pnlDialogo->Name = L"pnlDialogo";
			this->pnlDialogo->Size = System::Drawing::Size(675, 210);
			this->pnlDialogo->TabIndex = 3;
			// FrmMundoIA
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->pnlDialogo);
			this->Controls->Add(this->lblContador);
			this->Controls->Add(this->lblCinematica);
			this->Controls->Add(this->pnlMundoIA);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FrmMundoIA";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoIA::FrmMundoIA_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoIA::FrmMundoIA_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: 
		System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			timer1->Start();
		}

		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			mundoIAService->setContador(mundoIAService->getContador() + 1);
			lblContador->Text = "CONTADOR: " + mundoIAService->getContador();
			lblCinematica->Text = "Cinematica: " + (mundoIAService->getEnCinematica() ? "SI" : "NO") + 
				"  Numero: " + mundoIAService->getCinematica();

			if (mundoIAService->getEnCinematica()) {
				mundoIAService->actualizarCinematica();
			}
			else {
				mundoIAService->actualizarProyectiles();
				mundoIAService->verificarEstadoJuego();

				if (mundoIAService->getJugador() != nullptr) {
					mundoIAService->getJugador()->actualizarSalto(pnlMundoIA->Height);
				}

				mundoIAService->moverRobotsAuto();
				mundoIAService->verificarColisiones();
				mundoIAService->cambiarFondo();

				if (mundoIAService->haLlegadoAlFinal()) {
					timer1->Stop();
					MessageBox::Show("¡La Humanidad ha sido salvada! El pensamiento crítico prevalece.");
					this->Close();
				}
			}

			mundoIAService->actualizarDialogo();

			// Renderizar escena principal
			Graphics^ canvas = pnlMundoIA->CreateGraphics();
			BufferedGraphicsContext^ espacio_buffer = BufferedGraphicsManager::Current;
			BufferedGraphics^ buffer = espacio_buffer->Allocate(canvas, pnlMundoIA->ClientRectangle);
			
			mundoIAService->dibujarTodo(buffer->Graphics);
			if (mundoIAService->getCinematica() == 5) {
				mundoIAService->dibujarRecursos(buffer->Graphics);
			}
			
			buffer->Render(canvas);
			delete buffer;
			delete canvas;

			// Renderizar diálogo
			if (mundoIAService->getMostrandoDialogo()) {
				pnlDialogo->Visible = true;
				Graphics^ canvasDialogo = pnlDialogo->CreateGraphics();
				BufferedGraphicsContext^ espacio_buffer_dialogo = BufferedGraphicsManager::Current;
				BufferedGraphics^ bufferDialogo = espacio_buffer_dialogo->Allocate(canvasDialogo, pnlDialogo->ClientRectangle);
				
				bufferDialogo->Graphics->Clear(System::Drawing::Color::Transparent);
				mundoIAService->dibujarDialogo(bufferDialogo->Graphics);
				
				bufferDialogo->Render(canvasDialogo);
				delete bufferDialogo;
				delete canvasDialogo;
			}
			else {
				pnlDialogo->Visible = false;
			}
		}

		System::Void FrmMundoIA_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			// Cerrar diálogo
			if (e->KeyCode == Keys::Enter && mundoIAService->getMostrandoDialogo()) {
				mundoIAService->cerrarDialogo();
				return;
			}

			// Disparar
			if (e->KeyCode == Keys::F) {
				mundoIAService->dispararJugador();
				return;
			}

			// Bloquear movimiento en cinemática
			if (mundoIAService->getEnCinematica()) return;

			// Salto
			if (e->KeyCode == Keys::Space && mundoIAService->getJugador() != nullptr) {
				int jugadorX = mundoIAService->getJugador()->getX();
				
				if (teclaPresionada == Direccion::Izquierda && jugadorX > 220) {
					mundoIAService->getJugador()->saltar(Direccion::Izquierda);
				}
				else if (teclaPresionada == Direccion::Derecha && jugadorX < 1500) {
					mundoIAService->getJugador()->saltar(Direccion::Derecha);
				}
				else if (jugadorX < 1500 && jugadorX > 220) {
					mundoIAService->getJugador()->saltar(Direccion::Ninguno);
				}
				return;
			}

			// Movimiento (solo si no está saltando)
			if (mundoIAService->getJugador() != nullptr && !mundoIAService->getJugador()->estaSaltando()) {
				int jugadorX = mundoIAService->getJugador()->getX();
				int jugadorY = mundoIAService->getJugador()->getY();

				switch (e->KeyCode) {
				case Keys::A:
					if (jugadorX > 10) {
						teclaPresionada = Direccion::Izquierda;
						mundoIAService->moverJugador(teclaPresionada);
					}
					break;
				case Keys::D:
					if (jugadorX < 1600) {
						teclaPresionada = Direccion::Derecha;
						mundoIAService->moverJugador(teclaPresionada);
					}
					break;
				case Keys::W:
					if (jugadorY > 500) {
						mundoIAService->getJugador()->setY(jugadorY - 50);
					}
					break;
				case Keys::S:
					if (jugadorY < 600) {
						mundoIAService->getJugador()->setY(jugadorY + 50);
					}
					break;
				default:
					teclaPresionada = Direccion::Ninguno;
					break;
				}
			}
		}

		System::Void FrmMundoIA_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::W || e->KeyCode == Keys::S ||
				e->KeyCode == Keys::A || e->KeyCode == Keys::D) {
				teclaPresionada = Ninguno;
			}
		}
	};
}