#pragma once
#include "MundoIAService.h"

namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmMundoIA
	/// </summary>
	public ref class FrmMundoIA : public System::Windows::Forms::Form
	{
	public:
		FrmMundoIA(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			mundoIAService = new MundoIAService(pnlMundoIA->Width, pnlMundoIA->Height, 3);

			// Cargar fondos (día y noche)
			char rutaDia[] = "FondoMundoIA.png";
			char rutaNoche[] = "FondoMundoIANoche.png";
			mundoIAService->cargarFondos(rutaDia, rutaNoche);

			// Cargar jugador
			char rutaJugador[] = "PersonajeMundoIA.png";
			mundoIAService->cargarSpriteJugador(rutaJugador, 4, 8);
			mundoIAService->getJugador()->setEscala(0.6f);

			// Crear 3 robots
			char rutaRobot[] = "RobotMundoIA.png";
			mundoIAService->crearRobots(rutaRobot, 4, 9);

			teclaPresionada = Ninguno;

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmMundoIA()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlMundoIA;
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		MundoIAService* mundoIAService;
	private: System::Windows::Forms::Timer^ timer1;
		   Direccion teclaPresionada;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlMundoIA = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// pnlMundoIA
			// 
			this->pnlMundoIA->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->pnlMundoIA->Location = System::Drawing::Point(2, 2);
			this->pnlMundoIA->Name = L"pnlMundoIA";
			this->pnlMundoIA->Size = System::Drawing::Size(1395, 551);
			this->pnlMundoIA->TabIndex = 0;
			this->pnlMundoIA->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMundoIA::panel1_Paint);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMundoIA::timer1_Tick);
			// 
			// FrmMundoIA
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->pnlMundoIA);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FrmMundoIA";
			this->Text = L"FrmMundoIA";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmMundoIA::FrmMundoIA_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoIA::FrmMundoIA_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoIA::FrmMundoIA_KeyUp_1);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			timer1->Start();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		// Actualizar salto del jugador
		if (mundoIAService->getJugador() != nullptr) {
			mundoIAService->getJugador()->actualizarSalto(pnlMundoIA->Height);
		}

		// Mover robots
		mundoIAService->moverRobots();

		// Verificar colisiones
		mundoIAService->verificarColisiones();

		// Cambiar fondo si llegó al borde
		mundoIAService->cambiarFondo();

		// Actualizar diálogo
		mundoIAService->actualizarDialogo();

		// Renderizar
		Graphics^ canvas = pnlMundoIA->CreateGraphics();
		BufferedGraphicsContext^ espacio_buffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio_buffer->Allocate(canvas, pnlMundoIA->ClientRectangle);

		mundoIAService->dibujarTodo(buffer->Graphics);
		buffer->Render(canvas);

		delete buffer;
		delete canvas;

	}
	private: System::Void FrmMundoIA_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		// Salto con barra espaciadora
		if (e->KeyCode == Keys::Space) {
			if (mundoIAService->getJugador() != nullptr) {
				mundoIAService->getJugador()->saltar();
			}
		}

		// Cerrar diálogo con Enter
		if (e->KeyCode == Keys::Enter && mundoIAService->getMostrandoDialogo()) {
			mundoIAService->cerrarDialogo();  // ← AGREGAR ESTE MÉTODO
		}

		// Movimiento normal
		switch (e->KeyCode) {
		case Keys::W:
			teclaPresionada = Arriba;
			break;
		case Keys::S:
			teclaPresionada = Abajo;
			break;
		case Keys::A:
			teclaPresionada = Izquierda;
			break;
		case Keys::D:
			teclaPresionada = Derecha;
			break;
		default:
			teclaPresionada = Ninguno;
			break;
		}

		mundoIAService->moverJugador(teclaPresionada);

	}
	
	private: System::Void FrmMundoIA_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		if (e->KeyCode == Keys::W || e->KeyCode == Keys::S ||
			e->KeyCode == Keys::A || e->KeyCode == Keys::D) {
			teclaPresionada = Ninguno;
		}

	}
private: System::Void FrmMundoIA_KeyUp_1(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

	if (e->KeyCode == Keys::W || e->KeyCode == Keys::S ||
		e->KeyCode == Keys::A || e->KeyCode == Keys::D) {
		teclaPresionada = Ninguno;
	}
}
private: System::Void FrmMundoIA_Load(System::Object^ sender, System::EventArgs^ e) {



}
};
}
