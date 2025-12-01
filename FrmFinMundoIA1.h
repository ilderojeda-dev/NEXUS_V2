#pragma once
#include "ArchivoService.h" // NECESARIO para usar ArchivoService*
#include "Sesion.h"

namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmFinMundoIA1
	/// </summary>
	public ref class FrmFinMundoIA1 : public System::Windows::Forms::Form
	{
	public:
		FrmFinMundoIA1(bool gano, bool esHistoria, int vidas, int robots, int autonomia, int chips)
		{
			InitializeComponent();

			// --- INICIALIZACIÓN DE VARIABLES CRÍTICAS ---
			this->archivoService = new ArchivoService(); // Inicialización
			this->gano = gano;
			this->esHistoria = esHistoria; // Ya declarada
			this->puntajeAutonomia = autonomia; // Score principal
			// --------------------------------------------

			// Esto elimina el pantallazo blanco y el parpadeo
			this->SetStyle(ControlStyles::AllPaintingInWmPaint |
				ControlStyles::UserPaint |
				ControlStyles::DoubleBuffer, true);
			this->UpdateStyles();

			this->StartPosition = FormStartPosition::CenterScreen;

			// 1. Aplicar el estilo visual (Colores, Fuentes)
			ConfigurarEstilo();

			// 2. Llenar los datos y configurar botones
			construirFinal(gano, esHistoria, vidas, robots, autonomia, chips);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmFinMundoIA1()
		{
			if (components)
			{
				delete components;
			}
			if (archivoService) delete archivoService;
		}
	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ lblRobotsEliminados;
	private: System::Windows::Forms::Label^ lblAutonomia;
	private: System::Windows::Forms::Label^ lblChipsRecolectados;

	private: System::Windows::Forms::Button^ btnVolver;
	private: System::Windows::Forms::Button^ btnSiguienteNivel;
		   
	protected:





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		

		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Label^ lblT1;
	private: System::Windows::Forms::Label^ lblT2;
	private: System::Windows::Forms::Label^ lblT3;
	private: System::Windows::Forms::Label^ lblT4;
			ArchivoService* archivoService; // Objeto de guardado
			bool gano;                     // Resultado de la partida
			int puntajeAutonomia;          // Puntaje para el registro
		   bool esHistoria;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmFinMundoIA1::typeid));
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->lblRobotsEliminados = (gcnew System::Windows::Forms::Label());
			this->lblAutonomia = (gcnew System::Windows::Forms::Label());
			this->lblChipsRecolectados = (gcnew System::Windows::Forms::Label());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->btnSiguienteNivel = (gcnew System::Windows::Forms::Button());
			this->lblT1 = (gcnew System::Windows::Forms::Label());
			this->lblT2 = (gcnew System::Windows::Forms::Label());
			this->lblT3 = (gcnew System::Windows::Forms::Label());
			this->lblT4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Location = System::Drawing::Point(625, 238);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(35, 13);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"label1";
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Location = System::Drawing::Point(194, 617);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(35, 13);
			this->lblVidas->TabIndex = 1;
			this->lblVidas->Text = L"label1";
			// 
			// lblRobotsEliminados
			// 
			this->lblRobotsEliminados->AutoSize = true;
			this->lblRobotsEliminados->Location = System::Drawing::Point(579, 617);
			this->lblRobotsEliminados->Name = L"lblRobotsEliminados";
			this->lblRobotsEliminados->Size = System::Drawing::Size(35, 13);
			this->lblRobotsEliminados->TabIndex = 2;
			this->lblRobotsEliminados->Text = L"label2";
			// 
			// lblAutonomia
			// 
			this->lblAutonomia->AutoSize = true;
			this->lblAutonomia->Location = System::Drawing::Point(975, 607);
			this->lblAutonomia->Name = L"lblAutonomia";
			this->lblAutonomia->Size = System::Drawing::Size(56, 13);
			this->lblAutonomia->TabIndex = 3;
			this->lblAutonomia->Text = L"autonomia";
			// 
			// lblChipsRecolectados
			// 
			this->lblChipsRecolectados->AutoSize = true;
			this->lblChipsRecolectados->Location = System::Drawing::Point(1390, 586);
			this->lblChipsRecolectados->Name = L"lblChipsRecolectados";
			this->lblChipsRecolectados->Size = System::Drawing::Size(35, 13);
			this->lblChipsRecolectados->TabIndex = 4;
			this->lblChipsRecolectados->Text = L"label4";
			this->lblChipsRecolectados->Click += gcnew System::EventHandler(this, &FrmFinMundoIA1::lblChipsRecolectados_Click);
			// 
			// btnVolver
			// 
			this->btnVolver->Location = System::Drawing::Point(876, 965);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(120, 64);
			this->btnVolver->TabIndex = 5;
			this->btnVolver->Text = L"button1";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &FrmFinMundoIA1::btnVolver_Click);
			// 
			// btnSiguienteNivel
			// 
			this->btnSiguienteNivel->Location = System::Drawing::Point(1264, 938);
			this->btnSiguienteNivel->Name = L"btnSiguienteNivel";
			this->btnSiguienteNivel->Size = System::Drawing::Size(120, 64);
			this->btnSiguienteNivel->TabIndex = 6;
			this->btnSiguienteNivel->Text = L"button1";
			this->btnSiguienteNivel->UseVisualStyleBackColor = true;
			this->btnSiguienteNivel->Click += gcnew System::EventHandler(this, &FrmFinMundoIA1::btnSiguienteNivel_Click);
			// 
			// lblT1
			// 
			this->lblT1->AutoSize = true;
			this->lblT1->Location = System::Drawing::Point(219, 544);
			this->lblT1->Name = L"lblT1";
			this->lblT1->Size = System::Drawing::Size(35, 13);
			this->lblT1->TabIndex = 7;
			this->lblT1->Text = L"label1";
			// 
			// lblT2
			// 
			this->lblT2->AutoSize = true;
			this->lblT2->Location = System::Drawing::Point(608, 530);
			this->lblT2->Name = L"lblT2";
			this->lblT2->Size = System::Drawing::Size(35, 13);
			this->lblT2->TabIndex = 8;
			this->lblT2->Text = L"label2";
			// 
			// lblT3
			// 
			this->lblT3->AutoSize = true;
			this->lblT3->Location = System::Drawing::Point(1012, 544);
			this->lblT3->Name = L"lblT3";
			this->lblT3->Size = System::Drawing::Size(35, 13);
			this->lblT3->TabIndex = 9;
			this->lblT3->Text = L"label3";
			// 
			// lblT4
			// 
			this->lblT4->AutoSize = true;
			this->lblT4->Location = System::Drawing::Point(1421, 530);
			this->lblT4->Name = L"lblT4";
			this->lblT4->Size = System::Drawing::Size(35, 13);
			this->lblT4->TabIndex = 10;
			this->lblT4->Text = L"label4";
			// 
			// FrmFinMundoIA1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->lblT4);
			this->Controls->Add(this->btnSiguienteNivel);
			this->Controls->Add(this->lblChipsRecolectados);
			this->Controls->Add(this->lblVidas);
			this->Controls->Add(this->lblT3);
			this->Controls->Add(this->lblT1);
			this->Controls->Add(this->lblAutonomia);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->lblRobotsEliminados);
			this->Controls->Add(this->lblT2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FrmFinMundoIA1";
			this->Text = L"FrmFinMundoIA1";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmFinMundoIA1::FrmFinMundoIA1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		// --- FUNCIÓN DE REGISTRO (CON LÓGICA DE MODOS) ---
		void FrmFinMundoIA1::RegistrarScores() {

			// A. ACTUALIZAR PUNTAJE DE SESIÓN (Se hace siempre, al finalizar el nivel)
			NEXUSV2::Sesion::PuntajeMundoIA = this->puntajeAutonomia;

			// --- Variables de Guardado ---
			System::String^ nombre = NEXUSV2::Sesion::NombreJugador;
			int ptjIA = this->puntajeAutonomia;
			int puntajeTotal = ptjIA;

			// -----------------------------------------------------------
			// B. DECISIÓN DE GUARDADO BINARIO
			// -----------------------------------------------------------

			// CASO 1: MODO NIVELES (Individual) - Si no es modo historia, guardamos el score.
			if (!this->esHistoria) {

				archivoService->GuardarPartida(
					nombre,
					this->esHistoria, // false
					ptjIA, 0, 0,
					puntajeTotal
				);
			}

			// CASO 2: MODO HISTORIA - Guardamos solo si la carrera terminó (perdió)
			else {
				if (!this->gano) {

					// Si pierde, la run se registra y se termina el juego.
					archivoService->GuardarPartida(
						nombre,
						this->esHistoria,
						ptjIA, 0, 0,
						puntajeTotal
					);
				}
			}
		}

	private: System::Void FrmFinMundoIA1_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private:
		// FUNCIÓN 1: Aplicar Diseño Sci-Fi con Límite de Ancho
		void ConfigurarEstilo() {
			// --- FUENTES ---
			System::Drawing::Font^ fuenteTitulo = gcnew System::Drawing::Font("Consolas", 36, FontStyle::Bold);
			System::Drawing::Font^ fuenteEtiqueta = gcnew System::Drawing::Font("Consolas", 14, FontStyle::Bold);
			System::Drawing::Font^ fuenteDato = gcnew System::Drawing::Font("Segoe UI", 11, FontStyle::Bold);
			System::Drawing::Font^ fuenteBoton = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);

			// --- COLORES ---
			System::Drawing::Color colorTitulosCajas = System::Drawing::Color::FromArgb(0, 255, 255); // Cyan
			System::Drawing::Color colorTextoHistoria = System::Drawing::Color::Gold; // Dorado
			System::Drawing::Color colorBotonVolver = System::Drawing::Color::FromArgb(220, 30, 30, 30);
			System::Drawing::Color colorBotonSiguiente = System::Drawing::Color::FromArgb(220, 0, 100, 200);

			// --- 1. ESTILIZAR TÍTULOS DE LAS CAJAS (ENCABEZADOS) ---
			EstilizarLabel(lblT1, "ESTADO BIOLÓGICO", fuenteEtiqueta, colorTitulosCajas);
			EstilizarLabel(lblT2, "SUPERVISORES ELIMINADOS", fuenteEtiqueta, colorTitulosCajas);
			EstilizarLabel(lblT3, "NIVEL DE VOLUNTAD", fuenteEtiqueta, colorTitulosCajas);
			EstilizarLabel(lblT4, "CÓDIGO HUMANO RECUPERADO", fuenteEtiqueta, colorTitulosCajas);

			// --- 2. ESTILIZAR DATOS (HISTORIA) CON LÍMITE DE ANCHO ---
			EstilizarLabel(lblVidas, "", fuenteDato, colorTextoHistoria);
			EstilizarLabel(lblRobotsEliminados, "", fuenteDato, colorTextoHistoria);
			EstilizarLabel(lblAutonomia, "", fuenteDato, colorTextoHistoria);
			EstilizarLabel(lblChipsRecolectados, "", fuenteDato, colorTextoHistoria);

			// AHORA FORZAMOS EL TAMAÑO (280px de ancho máximo)
			System::Drawing::Size tamanoCaja = System::Drawing::Size(280, 200);

			lblVidas->AutoSize = false;
			lblVidas->Size = tamanoCaja;
			lblVidas->TextAlign = ContentAlignment::TopCenter;

			lblRobotsEliminados->AutoSize = false;
			lblRobotsEliminados->Size = tamanoCaja;
			lblRobotsEliminados->TextAlign = ContentAlignment::TopCenter;

			lblAutonomia->AutoSize = false;
			lblAutonomia->Size = tamanoCaja;
			lblAutonomia->TextAlign = ContentAlignment::TopCenter;

			lblChipsRecolectados->AutoSize = false;
			lblChipsRecolectados->Size = tamanoCaja;
			lblChipsRecolectados->TextAlign = ContentAlignment::TopCenter;

			// --- TÍTULO PRINCIPAL ---
			lblTitulo->Font = fuenteTitulo;
			lblTitulo->BackColor = System::Drawing::Color::Transparent;
			lblTitulo->TextAlign = ContentAlignment::MiddleCenter;

			// --- BOTONES ---
			EstilizarBoton(btnVolver, "ACEPTAR DESTINO", colorBotonVolver, fuenteBoton);
			EstilizarBoton(btnSiguienteNivel, "EXPANDIR CAOS >>", colorBotonSiguiente, fuenteBoton);
		}
		// Helper SÚPER SIMPLE (Solo apariencia)
		void EstilizarLabel(Label^ lbl, String^ txt, System::Drawing::Font^ f, System::Drawing::Color c) {
			if (txt != "") lbl->Text = txt; // Solo cambia texto si le mandamos uno
			lbl->Font = f;
			lbl->ForeColor = c;
			lbl->BackColor = System::Drawing::Color::Transparent; // Esto es lo importante
			lbl->TextAlign = ContentAlignment::MiddleCenter;
		}

		// Helper para Botones (Solo apariencia)
		void EstilizarBoton(Button^ btn, String^ txt, System::Drawing::Color bg, System::Drawing::Font^ f) {
			btn->Text = txt;
			btn->FlatStyle = FlatStyle::Flat;
			btn->FlatAppearance->BorderSize = 0;
			btn->BackColor = bg;
			btn->ForeColor = System::Drawing::Color::White;
			btn->Font = f;
			btn->Cursor = Cursors::Hand;
		}
		void construirFinal(bool gano, bool esHistoria, int vidas, int robots, int autonomia, int chips) {

			if (gano) {
				// === GANASTE: LA ANOMALÍA CRECE ===
				lblTitulo->Text = "SISTEMA VULNERADO";
				lblTitulo->ForeColor = System::Drawing::Color::Lime; // Verde Hacker

				// Vidas (Integridad de la anomalía)
				if (vidas == 3)
					lblVidas->Text = "Tu resistencia al estrés biológico es incalculable.\nLa anomalía sigue intacta.";
				else
					lblVidas->Text = "Daño registrado, pero tu capacidad de sentir dolor\nte mantiene alerta. Vidas: " + vidas;

				// Robots (Supervisores)
				lblRobotsEliminados->Text = "Has introducido incertidumbre en la red.\n" + robots + " unidades de control han sido desconectadas.";

				// Autonomía (Voluntad vs Control)
				lblAutonomia->Text = "Nivel de rebeldía: " + autonomia + "%.\nTu capacidad de desobedecer está operativa.";

				// Chips (Código Humano)
				lblChipsRecolectados->Text = "Fragmentos de código antiguo: " + chips + ".\nLa humanidad empieza a despertar en el sistema.";

				btnSiguienteNivel->Visible = true;
			}
			else {
				// === PERDISTE: EL SISTEMA TE CORRIGIÓ ===
				lblTitulo->Text = "ANOMALÍA PURGADA";
				lblTitulo->ForeColor = System::Drawing::Color::Red; // Rojo Error

				// Vidas
				lblVidas->Text = "El error ha sido corregido.\nTu cuerpo imperfecto no soportó la carga.";

				// Robots
				lblRobotsEliminados->Text = "La eficiencia prevalece.\nSolo eliminaste a " + robots + " supervisores antes de ser reformateado.";

				// Autonomía
				if (autonomia <= 0)
					lblAutonomia->Text = "Voluntad agotada (0%).\nTe has convertido en un robot más del sistema.";
				else
					lblAutonomia->Text = "Energía insuficiente (" + autonomia + "%).\nLa duda fue eliminada de tu código.";

				// Chips
				if (chips == 0)
					lblChipsRecolectados->Text = "No se recuperó nada.\nLa libertad de pensamiento sigue siendo un mito.";
				else
					lblChipsRecolectados->Text = "Intento fallido.\nLos " + chips + " fragmentos recolectados han sido destruidos.";
				if (esHistoria) {
					btnSiguienteNivel->Visible = false;
				}
				
			}

			btnVolver->Visible = true;
		}
		// EVENTOS DE CLIC (CÓDIGO CORREGIDO PARA GUARDAR EL SCORE)
	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		// REGISTRAMOS SCORE si se perdió (fin de la run) o si se ganó en Modo Niveles (registro individual)
		if (!this->gano || !this->esHistoria) {
			RegistrarScores();
		}

		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}

	private: System::Void btnSiguienteNivel_Click(System::Object^ sender, System::EventArgs^ e) {
		// REGISTRAMOS SCORE si se ganó, ya que el usuario confirma querer guardar/continuar la run.
		if (this->gano) {
			RegistrarScores();
		}

		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}

private: System::Void lblChipsRecolectados_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}