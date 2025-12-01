#pragma once
#include "Mundo.h"
#include "FrmMundoHumano.h"
#include "FrmMundoIA.h"
#include "SoundManager.h"
#include "FrmMundoColab.h"
#include "Sesion.h"
#include "ArchivoService.h"

namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	

	/// <summary>
	/// Summary for FrmInicio
	/// </summary>
	public ref class FrmInicio : public System::Windows::Forms::Form
	{
	public:

		FrmInicio(void)
		{
			InitializeComponent();
			// --- AGREGA ESTO ---
			gestorSonido = gcnew NEXUS_V2::Service::SoundManager();

			//Reproduce la música. Asegúrate de que "MusicaFondoInicio.wav"
			// esté en tu carpeta Resource y configurado para "Copiar siempre".
			gestorSonido->ReproducirMusica("MusicaFondoInicio.wav", 0.2); // 0.3 es volumen bajito (30%)
			ConfigurarMenuPrincipal();
			ConfigurarPanelNiveles();
			this->archivoService = new ArchivoService();
			pnlNiveles->Visible = false;
			if (this->pnlScores->Parent != nullptr && this->pnlScores->Parent != this)
			{
				this->pnlScores->Parent->Controls->Remove(this->pnlScores);
			}
			// 2. Añadir pnlScores directamente al formulario principal (this).
			this->Controls->Add(this->pnlScores);

			// 3. Asegurar que el panel esté al frente para que se vea correctamente.
			this->pnlScores->BringToFront();

			// 4. Ocultar pnlScores por defecto.
			this->pnlScores->Visible = false;

			if (this->pnlCreditos->Parent != nullptr && this->pnlCreditos->Parent != this->pnlFondo)
			{
				this->pnlCreditos->Parent->Controls->Remove(this->pnlCreditos);
			}
			this->pnlFondo->Controls->Add(this->pnlCreditos); // Lo agregamos al pnlFondo
			this->pnlCreditos->Visible = false;

			

			
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmInicio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlFondo;
	private: System::Windows::Forms::Panel^ pnlNiveles;
	private: System::Windows::Forms::Button^ btnNiveles;
	private: System::Windows::Forms::Button^ btnIniciarJuego;
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Button^ btnScores;
	private: System::Windows::Forms::Button^ btnVolver;
	private: System::Windows::Forms::Button^ btnNivel3;
	private: System::Windows::Forms::Button^ btnNivel2;
	private: NEXUS_V2::Service::SoundManager^ gestorSonido;
	protected:
	private: System::Windows::Forms::Button^ brnMundoIA;
	protected:

	protected:

	private: System::Windows::Forms::Button^ btnNivel1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnHistoria;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		ArchivoService* archivoService;

	private: System::Windows::Forms::Panel^ pnlMenuPrincipal;
	private: System::Windows::Forms::TextBox^ txtNombreJugador;
	private: System::Windows::Forms::Panel^ pnlScores;
	private: System::Windows::Forms::ListView^ lvScores;

	private: System::Windows::Forms::Label^ lblTituloScore;
	private: System::Windows::Forms::ColumnHeader^ colUsuario;
	private: System::Windows::Forms::ColumnHeader^ colMode;
	private: System::Windows::Forms::ColumnHeader^ colMundo1;
	private: System::Windows::Forms::ColumnHeader^ colMundo2;
	private: System::Windows::Forms::ColumnHeader^ colMundo3;
	private: System::Windows::Forms::ColumnHeader^ colPuntajeFinal;
	private: System::Windows::Forms::ColumnHeader^ colFecha;
	private: System::Windows::Forms::Button^ btnVolverScores;
	private: System::Windows::Forms::Panel^ pnlCreditos;
	private: System::Windows::Forms::Label^ lblProfesor;
	private: System::Windows::Forms::Label^ lblUniversidad;
	private: System::Windows::Forms::Label^ lblEstudiantes;
	private: System::Windows::Forms::Label^ lblMensajeAgradecimiento;
	private: System::Windows::Forms::Label^ lblTituloCreditos;
	private: System::Windows::Forms::Button^ btnVolverMenu;










	private: System::Windows::Forms::Label^ lblPromptNombre;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmInicio::typeid));
			this->brnMundoIA = (gcnew System::Windows::Forms::Button());
			this->pnlFondo = (gcnew System::Windows::Forms::Panel());
			this->pnlNiveles = (gcnew System::Windows::Forms::Panel());
			this->pnlCreditos = (gcnew System::Windows::Forms::Panel());
			this->lblProfesor = (gcnew System::Windows::Forms::Label());
			this->lblUniversidad = (gcnew System::Windows::Forms::Label());
			this->lblEstudiantes = (gcnew System::Windows::Forms::Label());
			this->lblMensajeAgradecimiento = (gcnew System::Windows::Forms::Label());
			this->lblTituloCreditos = (gcnew System::Windows::Forms::Label());
			this->btnVolverMenu = (gcnew System::Windows::Forms::Button());
			this->btnNivel3 = (gcnew System::Windows::Forms::Button());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->btnNivel1 = (gcnew System::Windows::Forms::Button());
			this->btnNivel2 = (gcnew System::Windows::Forms::Button());
			this->pnlScores = (gcnew System::Windows::Forms::Panel());
			this->btnVolverScores = (gcnew System::Windows::Forms::Button());
			this->lblTituloScore = (gcnew System::Windows::Forms::Label());
			this->lvScores = (gcnew System::Windows::Forms::ListView());
			this->colUsuario = (gcnew System::Windows::Forms::ColumnHeader());
			this->colMode = (gcnew System::Windows::Forms::ColumnHeader());
			this->colMundo1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->colMundo2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->colMundo3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->colPuntajeFinal = (gcnew System::Windows::Forms::ColumnHeader());
			this->colFecha = (gcnew System::Windows::Forms::ColumnHeader());
			this->pnlMenuPrincipal = (gcnew System::Windows::Forms::Panel());
			this->txtNombreJugador = (gcnew System::Windows::Forms::TextBox());
			this->lblPromptNombre = (gcnew System::Windows::Forms::Label());
			this->btnIniciarJuego = (gcnew System::Windows::Forms::Button());
			this->btnNiveles = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnScores = (gcnew System::Windows::Forms::Button());
			this->pnlFondo->SuspendLayout();
			this->pnlNiveles->SuspendLayout();
			this->pnlCreditos->SuspendLayout();
			this->pnlScores->SuspendLayout();
			this->pnlMenuPrincipal->SuspendLayout();
			this->SuspendLayout();
			// 
			// brnMundoIA
			// 
			this->brnMundoIA->Location = System::Drawing::Point(389, 360);
			this->brnMundoIA->Name = L"brnMundoIA";
			this->brnMundoIA->Size = System::Drawing::Size(75, 23);
			this->brnMundoIA->TabIndex = 0;
			this->brnMundoIA->Text = L"MUNDO IA";
			this->brnMundoIA->UseVisualStyleBackColor = true;
			// 
			// pnlFondo
			// 
			this->pnlFondo->BackColor = System::Drawing::Color::White;
			this->pnlFondo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlFondo.BackgroundImage")));
			this->pnlFondo->Controls->Add(this->pnlNiveles);
			this->pnlFondo->Controls->Add(this->pnlScores);
			this->pnlFondo->Controls->Add(this->pnlMenuPrincipal);
			this->pnlFondo->Location = System::Drawing::Point(-2, -1);
			this->pnlFondo->Name = L"pnlFondo";
			this->pnlFondo->Size = System::Drawing::Size(1922, 1086);
			this->pnlFondo->TabIndex = 3;
			// 
			// pnlNiveles
			// 
			this->pnlNiveles->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlNiveles.BackgroundImage")));
			this->pnlNiveles->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pnlNiveles->Controls->Add(this->pnlCreditos);
			this->pnlNiveles->Controls->Add(this->btnNivel3);
			this->pnlNiveles->Controls->Add(this->btnVolver);
			this->pnlNiveles->Controls->Add(this->btnNivel1);
			this->pnlNiveles->Controls->Add(this->btnNivel2);
			this->pnlNiveles->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->pnlNiveles->Location = System::Drawing::Point(200, 46);
			this->pnlNiveles->Name = L"pnlNiveles";
			this->pnlNiveles->Size = System::Drawing::Size(1534, 1009);
			this->pnlNiveles->TabIndex = 11;
			this->pnlNiveles->Visible = false;
			// 
			// pnlCreditos
			// 
			this->pnlCreditos->BackColor = System::Drawing::Color::Transparent;
			this->pnlCreditos->Controls->Add(this->lblProfesor);
			this->pnlCreditos->Controls->Add(this->lblUniversidad);
			this->pnlCreditos->Controls->Add(this->lblEstudiantes);
			this->pnlCreditos->Controls->Add(this->lblMensajeAgradecimiento);
			this->pnlCreditos->Controls->Add(this->lblTituloCreditos);
			this->pnlCreditos->Controls->Add(this->btnVolverMenu);
			this->pnlCreditos->Location = System::Drawing::Point(378, 332);
			this->pnlCreditos->Name = L"pnlCreditos";
			this->pnlCreditos->Size = System::Drawing::Size(961, 715);
			this->pnlCreditos->TabIndex = 12;
			// 
			// lblProfesor
			// 
			this->lblProfesor->AutoSize = true;
			this->lblProfesor->Location = System::Drawing::Point(494, 425);
			this->lblProfesor->Name = L"lblProfesor";
			this->lblProfesor->Size = System::Drawing::Size(35, 13);
			this->lblProfesor->TabIndex = 7;
			this->lblProfesor->Text = L"label1";
			// 
			// lblUniversidad
			// 
			this->lblUniversidad->AutoSize = true;
			this->lblUniversidad->Location = System::Drawing::Point(339, 332);
			this->lblUniversidad->Name = L"lblUniversidad";
			this->lblUniversidad->Size = System::Drawing::Size(35, 13);
			this->lblUniversidad->TabIndex = 6;
			this->lblUniversidad->Text = L"label1";
			// 
			// lblEstudiantes
			// 
			this->lblEstudiantes->AutoSize = true;
			this->lblEstudiantes->Location = System::Drawing::Point(459, 343);
			this->lblEstudiantes->Name = L"lblEstudiantes";
			this->lblEstudiantes->Size = System::Drawing::Size(35, 13);
			this->lblEstudiantes->TabIndex = 5;
			this->lblEstudiantes->Text = L"label1";
			// 
			// lblMensajeAgradecimiento
			// 
			this->lblMensajeAgradecimiento->AutoSize = true;
			this->lblMensajeAgradecimiento->Location = System::Drawing::Point(518, 297);
			this->lblMensajeAgradecimiento->Name = L"lblMensajeAgradecimiento";
			this->lblMensajeAgradecimiento->Size = System::Drawing::Size(35, 13);
			this->lblMensajeAgradecimiento->TabIndex = 4;
			this->lblMensajeAgradecimiento->Text = L"label1";
			// 
			// lblTituloCreditos
			// 
			this->lblTituloCreditos->AutoSize = true;
			this->lblTituloCreditos->Location = System::Drawing::Point(416, 121);
			this->lblTituloCreditos->Name = L"lblTituloCreditos";
			this->lblTituloCreditos->Size = System::Drawing::Size(35, 13);
			this->lblTituloCreditos->TabIndex = 3;
			this->lblTituloCreditos->Text = L"label1";
			// 
			// btnVolverMenu
			// 
			this->btnVolverMenu->Location = System::Drawing::Point(462, 502);
			this->btnVolverMenu->Name = L"btnVolverMenu";
			this->btnVolverMenu->Size = System::Drawing::Size(75, 23);
			this->btnVolverMenu->TabIndex = 2;
			this->btnVolverMenu->Text = L"button1";
			this->btnVolverMenu->UseVisualStyleBackColor = true;
			this->btnVolverMenu->Click += gcnew System::EventHandler(this, &FrmInicio::btnVolverMenu_Click);
			// 
			// btnNivel3
			// 
			this->btnNivel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(118)));
			this->btnNivel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNivel3.BackgroundImage")));
			this->btnNivel3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnNivel3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNivel3->Location = System::Drawing::Point(988, 332);
			this->btnNivel3->Name = L"btnNivel3";
			this->btnNivel3->Size = System::Drawing::Size(368, 460);
			this->btnNivel3->TabIndex = 8;
			this->btnNivel3->UseVisualStyleBackColor = false;
			this->btnNivel3->Click += gcnew System::EventHandler(this, &FrmInicio::btnNivel3_Click);
			// 
			// btnVolver
			// 
			this->btnVolver->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(118)));
			this->btnVolver->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnVolver->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnVolver->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnVolver->Location = System::Drawing::Point(586, 866);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(349, 45);
			this->btnVolver->TabIndex = 9;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &FrmInicio::btnVolver_Click);
			// 
			// btnNivel1
			// 
			this->btnNivel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(118)));
			this->btnNivel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNivel1.BackgroundImage")));
			this->btnNivel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnNivel1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNivel1->Location = System::Drawing::Point(144, 332);
			this->btnNivel1->Name = L"btnNivel1";
			this->btnNivel1->Size = System::Drawing::Size(364, 460);
			this->btnNivel1->TabIndex = 10;
			this->btnNivel1->UseVisualStyleBackColor = false;
			this->btnNivel1->Click += gcnew System::EventHandler(this, &FrmInicio::btnNivel1_Click_1);
			// 
			// btnNivel2
			// 
			this->btnNivel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(118)));
			this->btnNivel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNivel2.BackgroundImage")));
			this->btnNivel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnNivel2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNivel2->Location = System::Drawing::Point(578, 332);
			this->btnNivel2->Name = L"btnNivel2";
			this->btnNivel2->Size = System::Drawing::Size(350, 460);
			this->btnNivel2->TabIndex = 7;
			this->btnNivel2->UseVisualStyleBackColor = false;
			this->btnNivel2->Click += gcnew System::EventHandler(this, &FrmInicio::btnNivel2_Click);
			// 
			// pnlScores
			// 
			this->pnlScores->BackColor = System::Drawing::Color::Transparent;
			this->pnlScores->Controls->Add(this->btnVolverScores);
			this->pnlScores->Controls->Add(this->lblTituloScore);
			this->pnlScores->Controls->Add(this->lvScores);
			this->pnlScores->Location = System::Drawing::Point(390, 379);
			this->pnlScores->Name = L"pnlScores";
			this->pnlScores->Size = System::Drawing::Size(1070, 607);
			this->pnlScores->TabIndex = 11;
			this->pnlScores->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmInicio::pnlScores_Paint);
			// 
			// btnVolverScores
			// 
			this->btnVolverScores->Location = System::Drawing::Point(462, 502);
			this->btnVolverScores->Name = L"btnVolverScores";
			this->btnVolverScores->Size = System::Drawing::Size(75, 23);
			this->btnVolverScores->TabIndex = 2;
			this->btnVolverScores->Text = L"button1";
			this->btnVolverScores->UseVisualStyleBackColor = true;
			this->btnVolverScores->Click += gcnew System::EventHandler(this, &FrmInicio::btnVolverScores_Click);
			// 
			// lblTituloScore
			// 
			this->lblTituloScore->AutoSize = true;
			this->lblTituloScore->Font = (gcnew System::Drawing::Font(L"MS Gothic", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTituloScore->ForeColor = System::Drawing::Color::Yellow;
			this->lblTituloScore->Location = System::Drawing::Point(434, 42);
			this->lblTituloScore->Name = L"lblTituloScore";
			this->lblTituloScore->Size = System::Drawing::Size(225, 64);
			this->lblTituloScore->TabIndex = 1;
			this->lblTituloScore->Text = L"Scores";
			// 
			// lvScores
			// 
			this->lvScores->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {
				this->colUsuario, this->colMode,
					this->colMundo1, this->colMundo2, this->colMundo3, this->colPuntajeFinal, this->colFecha
			});
			this->lvScores->HideSelection = false;
			this->lvScores->Location = System::Drawing::Point(90, 129);
			this->lvScores->Name = L"lvScores";
			this->lvScores->Size = System::Drawing::Size(897, 349);
			this->lvScores->TabIndex = 0;
			this->lvScores->UseCompatibleStateImageBehavior = false;
			this->lvScores->View = System::Windows::Forms::View::Details;
			// 
			// colUsuario
			// 
			this->colUsuario->Text = L"Usuario";
			this->colUsuario->Width = 106;
			// 
			// colMode
			// 
			this->colMode->Text = L"Modo";
			this->colMode->Width = 105;
			// 
			// colMundo1
			// 
			this->colMundo1->Text = L"IA (Autonomía)";
			this->colMundo1->Width = 19;
			// 
			// colMundo2
			// 
			this->colMundo2->Text = L"Humano (Criterio)";
			this->colMundo2->Width = 82;
			// 
			// colMundo3
			// 
			this->colMundo3->Text = L"Colab (Confianza)";
			this->colMundo3->Width = 163;
			// 
			// colPuntajeFinal
			// 
			this->colPuntajeFinal->Text = L"Puntaje Total";
			this->colPuntajeFinal->Width = 111;
			// 
			// colFecha
			// 
			this->colFecha->Text = L"Fecha";
			this->colFecha->Width = 95;
			// 
			// pnlMenuPrincipal
			// 
			this->pnlMenuPrincipal->BackColor = System::Drawing::Color::Transparent;
			this->pnlMenuPrincipal->Controls->Add(this->txtNombreJugador);
			this->pnlMenuPrincipal->Controls->Add(this->lblPromptNombre);
			this->pnlMenuPrincipal->Controls->Add(this->btnIniciarJuego);
			this->pnlMenuPrincipal->Controls->Add(this->btnNiveles);
			this->pnlMenuPrincipal->Controls->Add(this->btnSalir);
			this->pnlMenuPrincipal->Controls->Add(this->btnCreditos);
			this->pnlMenuPrincipal->Controls->Add(this->btnScores);
			this->pnlMenuPrincipal->Location = System::Drawing::Point(254, 390);
			this->pnlMenuPrincipal->Name = L"pnlMenuPrincipal";
			this->pnlMenuPrincipal->Size = System::Drawing::Size(1303, 630);
			this->pnlMenuPrincipal->TabIndex = 12;
			// 
			// txtNombreJugador
			// 
			this->txtNombreJugador->BackColor = System::Drawing::Color::Chartreuse;
			this->txtNombreJugador->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->txtNombreJugador->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNombreJugador->Location = System::Drawing::Point(437, 282);
			this->txtNombreJugador->Name = L"txtNombreJugador";
			this->txtNombreJugador->Size = System::Drawing::Size(310, 35);
			this->txtNombreJugador->TabIndex = 6;
			// 
			// lblPromptNombre
			// 
			this->lblPromptNombre->AutoSize = true;
			this->lblPromptNombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPromptNombre->ForeColor = System::Drawing::Color::Yellow;
			this->lblPromptNombre->Location = System::Drawing::Point(475, 203);
			this->lblPromptNombre->Name = L"lblPromptNombre";
			this->lblPromptNombre->Size = System::Drawing::Size(216, 25);
			this->lblPromptNombre->TabIndex = 5;
			this->lblPromptNombre->Text = L"Ingresa tu nombre: ";
			// 
			// btnIniciarJuego
			// 
			this->btnIniciarJuego->BackColor = System::Drawing::Color::Turquoise;
			this->btnIniciarJuego->Cursor = System::Windows::Forms::Cursors::Default;
			this->btnIniciarJuego->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnIniciarJuego->Font = (gcnew System::Drawing::Font(L"Segoe MDL2 Assets", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIniciarJuego->Location = System::Drawing::Point(69, 167);
			this->btnIniciarJuego->Name = L"btnIniciarJuego";
			this->btnIniciarJuego->Size = System::Drawing::Size(283, 75);
			this->btnIniciarJuego->TabIndex = 1;
			this->btnIniciarJuego->Text = L"INICIAR JUEGO";
			this->btnIniciarJuego->UseVisualStyleBackColor = false;
			this->btnIniciarJuego->Click += gcnew System::EventHandler(this, &FrmInicio::btnIniciarJuego_Click);
			// 
			// btnNiveles
			// 
			this->btnNiveles->BackColor = System::Drawing::Color::Turquoise;
			this->btnNiveles->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnNiveles->Cursor = System::Windows::Forms::Cursors::Default;
			this->btnNiveles->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNiveles->Font = (gcnew System::Drawing::Font(L"Segoe MDL2 Assets", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNiveles->Location = System::Drawing::Point(87, 351);
			this->btnNiveles->Name = L"btnNiveles";
			this->btnNiveles->Size = System::Drawing::Size(259, 75);
			this->btnNiveles->TabIndex = 2;
			this->btnNiveles->Text = L"NIVELES";
			this->btnNiveles->UseVisualStyleBackColor = false;
			this->btnNiveles->Click += gcnew System::EventHandler(this, &FrmInicio::btnNiveles_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::DarkRed;
			this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(480, 504);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(204, 75);
			this->btnSalir->TabIndex = 0;
			this->btnSalir->Text = L"SALIR";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmInicio::btnSalir_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackColor = System::Drawing::Color::Turquoise;
			this->btnCreditos->Cursor = System::Windows::Forms::Cursors::Default;
			this->btnCreditos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Segoe MDL2 Assets", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->Location = System::Drawing::Point(773, 167);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(277, 75);
			this->btnCreditos->TabIndex = 4;
			this->btnCreditos->Text = L"CREDITOS";
			this->btnCreditos->UseVisualStyleBackColor = false;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &FrmInicio::btnCreditos_Click);
			// 
			// btnScores
			// 
			this->btnScores->BackColor = System::Drawing::Color::Turquoise;
			this->btnScores->Cursor = System::Windows::Forms::Cursors::Default;
			this->btnScores->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnScores->Font = (gcnew System::Drawing::Font(L"Segoe MDL2 Assets", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnScores->Location = System::Drawing::Point(782, 351);
			this->btnScores->Name = L"btnScores";
			this->btnScores->Size = System::Drawing::Size(283, 75);
			this->btnScores->TabIndex = 3;
			this->btnScores->Text = L"SCORES";
			this->btnScores->UseVisualStyleBackColor = false;
			this->btnScores->Click += gcnew System::EventHandler(this, &FrmInicio::btnHistoria_Click_1);
			// 
			// FrmInicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1920, 1080);
			this->Controls->Add(this->pnlFondo);
			this->Controls->Add(this->brnMundoIA);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FrmInicio";
			this->Text = L"FrmInicio";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmInicio::FrmInicio_Load);
			this->pnlFondo->ResumeLayout(false);
			this->pnlNiveles->ResumeLayout(false);
			this->pnlCreditos->ResumeLayout(false);
			this->pnlCreditos->PerformLayout();
			this->pnlScores->ResumeLayout(false);
			this->pnlScores->PerformLayout();
			this->pnlMenuPrincipal->ResumeLayout(false);
			this->pnlMenuPrincipal->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	 private:
	   // Función auxiliar para estilizar botones repetitivos
	   void EstilizarBotonMenu(Button^ btn, System::Drawing::Color colorTexto, System::Drawing::Color colorBorde) {
		   btn->FlatStyle = FlatStyle::Flat;
		   btn->BackColor = System::Drawing::Color::FromArgb(200, 10, 20, 30); // Azul oscuro semitransparente
		   btn->ForeColor = colorTexto;
		   btn->FlatAppearance->BorderColor = colorBorde;
		   btn->FlatAppearance->BorderSize = 2;
		   btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(255, 0, 100, 150); // Brillo al pasar mouse
		   btn->Font = gcnew System::Drawing::Font("Consolas", 12, FontStyle::Bold);
		   btn->Cursor = Cursors::Hand;
		   btn->Size = System::Drawing::Size(220, 60); // Tamaño uniforme
	   }
	   void ConfigurarMenuPrincipal() {
		   // --- 1. COLORES Y FUENTES ---
		   System::Drawing::Color colorNeon = System::Drawing::Color::FromArgb(0, 255, 255); // Cian brillante
		   System::Drawing::Color colorRojo = System::Drawing::Color::FromArgb(255, 70, 70);   // Rojo suave para salir
		   System::Drawing::Font^ fuenteLabel = gcnew System::Drawing::Font("Consolas", 14, FontStyle::Bold);
		   // Obtener el centro de la pantalla (o del panel si usas uno)
		   int centerX = pnlMenuPrincipal->Width / 2;
		   int startY = 150;
		   
		   // --- 2. CAJA DE TEXTO (NOMBRE) ---
		   // Hacemos que parezca una terminal: Fondo negro, letra cian, sin borde 3D
		   txtNombreJugador->BackColor = System::Drawing::Color::FromArgb(10, 10, 20); // Casi negro
		   txtNombreJugador->ForeColor = colorNeon;
		   txtNombreJugador->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		   txtNombreJugador->Font = gcnew System::Drawing::Font("Consolas", 16, FontStyle::Bold);
		   txtNombreJugador->TextAlign = HorizontalAlignment::Center;
		   txtNombreJugador->Size = System::Drawing::Size(410, 30);
		   // Centrar TextBox
		   txtNombreJugador->Location = Point(centerX - (txtNombreJugador->Width / 2), startY);
		   // Label "Ingresa tu nombre"
		   lblPromptNombre->Parent = pnlMenuPrincipal;
		   lblPromptNombre->BackColor = System::Drawing::Color::Transparent;
		   lblPromptNombre->ForeColor = System::Drawing::Color::Yellow; // O Blanco
		   lblPromptNombre->Font = fuenteLabel;
		   // Centrar Label justo arriba del TextBox
		   lblPromptNombre->Location = Point(centerX - (lblPromptNombre->Width / 2), startY - 30);
		   // --- 3. BOTONES (GRILLA 2x2) ---
		   int btnW = 220;
		   int btnH = 60;
		   int gap = 20; // Espacio entre botones
		   int botonesY = startY + 60; // Debajo del nombre
		   // Fila 1: INICIAR y NIVELES
		   EstilizarBotonMenu(btnIniciarJuego, colorNeon, colorNeon);
		   btnIniciarJuego->Location = Point(centerX - btnW - (gap / 2), botonesY);
		   EstilizarBotonMenu(btnNiveles, colorNeon, colorNeon);
		   btnNiveles->Location = Point(centerX + (gap / 2), botonesY);
		   // Fila 2: SCORES y CREDITOS
		   int fila2Y = botonesY + btnH + gap;
		   EstilizarBotonMenu(btnScores, colorNeon, colorNeon); // Asumiendo que se llama btnScores
		   btnScores->Location = Point(centerX - btnW - (gap / 2), fila2Y);
		   EstilizarBotonMenu(btnCreditos, colorNeon, colorNeon); // Asumiendo btnCreditos
		   btnCreditos->Location = Point(centerX + (gap / 2), fila2Y);
		   // BOTÓN SALIR (Centrado abajo y rojo)
		   EstilizarBotonMenu(btnSalir, colorRojo, colorRojo);
		   btnSalir->Width = 200; // Un poco más chico
		   btnSalir->Location = Point(centerX - (btnSalir->Width / 2), fila2Y + btnH + 30);
	   }
	   void ConfigurarPanelNiveles() {
		   // 1. ASEGURAR QUE EL PANEL ESTÉ AL FRENTE
		   pnlNiveles->BringToFront();
		   // 2. VINCULAR BOTONES AL PANEL (OBLIGATORIO)
		   // Esto hace que los botones sean "hijos" del panel para que se vean encima de él.
		   // Al cambiar el Parent, a veces se mueven, así que guardamos su posición visual actual
		   // y la restauramos inmediatamente para que NO SE MUEVAN.
		   Point pos1 = btnNivel1->Location; // Guardar posición actual
		   btnNivel1->Parent = pnlNiveles;   // Vincular
		   btnNivel1->Location = pos1;       // Restaurar posición
		   Point pos2 = btnNivel2->Location;
		   btnNivel2->Parent = pnlNiveles;
		   btnNivel2->Location = pos2;
		   Point pos3 = btnNivel3->Location;
		   btnNivel3->Parent = pnlNiveles;
		   btnNivel3->Location = pos3;
		   Point posVolver = btnVolver->Location;
		   btnVolver->Parent = pnlNiveles;
		   btnVolver->Location = posVolver;
		   // 3. ESTILO TRANSPARENTE PARA LOS MUNDOS (IA, Humano, Colab)
		   // Quitamos el fondo gris para que se vean solo tus imágenes bonitas
		   // IA
		   btnNivel1->BackColor = System::Drawing::Color::Transparent;
		   btnNivel1->FlatStyle = FlatStyle::Flat;
		   btnNivel1->FlatAppearance->BorderSize = 0;
		   btnNivel1->Cursor = Cursors::Hand;
		   btnNivel1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(0, 65, 118);
		   // Humano
		   btnNivel2->BackColor = System::Drawing::Color::Transparent;
		   btnNivel2->FlatStyle = FlatStyle::Flat;
		   btnNivel2->FlatAppearance->BorderSize = 0;
		   btnNivel2->Cursor = Cursors::Hand;
		   btnNivel2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(0, 65, 118);
		   // Colaborativo
		   btnNivel3->BackColor = System::Drawing::Color::Transparent;
		   btnNivel3->FlatStyle = FlatStyle::Flat;
		   btnNivel3->FlatAppearance->BorderSize = 0;
		   btnNivel3->Cursor = Cursors::Hand;
		   btnNivel3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(0, 65, 118);
		   // 4. ESTILO "SCI-FI ROJO" PARA EL BOTÓN VOLVER
		   btnVolver->BackColor = System::Drawing::Color::FromArgb(200, 200, 40, 40); // Rojo semitransparente
		   btnVolver->ForeColor = System::Drawing::Color::White;
		   btnVolver->FlatStyle = FlatStyle::Flat;
		   btnVolver->FlatAppearance->BorderColor = System::Drawing::Color::Red;
		   btnVolver->FlatAppearance->BorderSize = 2;
		   btnVolver->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(255, 139, 0, 0); // Rojo oscuro al pasar mouse
		   btnVolver->Font = gcnew System::Drawing::Font("Consolas", 12, FontStyle::Bold);
		   btnVolver->Cursor = Cursors::Hand;
		   btnVolver->Text = "VOLVER";
	   }
	private:
		void FrmInicio::ConfigurarPanelScores() {

			System::Drawing::Color fondoPanel = System::Drawing::Color::FromArgb(245, 5, 5, 20);
			this->pnlScores->BackColor = fondoPanel;

			// Título: Grande, NEÓN CYÁN y perfectamente centrado
			this->lblTituloScore->Text = "TABLA DE CLASIFICACIÓN GLOBAL";
			this->lblTituloScore->Font = gcnew System::Drawing::Font("Consolas", 26, FontStyle::Bold);
			this->lblTituloScore->ForeColor = System::Drawing::Color::FromArgb(0, 255, 255); // Cyan Neón
			this->lblTituloScore->TextAlign = ContentAlignment::MiddleCenter;

			// Botón Volver: Oscuro y con borde neón
			this->btnVolverScores->Text = "VOLVER AL MENÚ";
			this->btnVolverScores->BackColor = System::Drawing::Color::FromArgb(255, 20, 40, 60); // Azul oscuro sólido
			this->btnVolverScores->ForeColor = System::Drawing::Color::White;
			this->btnVolverScores->FlatStyle = FlatStyle::Flat;
			this->btnVolverScores->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(0, 255, 255);
			this->btnVolverScores->FlatAppearance->BorderSize = 3;
			this->btnVolverScores->Size = System::Drawing::Size(200, 65); // Más grande


			// --- 2. CONFIGURACIÓN DEL LISTVIEW (La Tabla) ---

			this->lvScores->View = View::Details;
			this->lvScores->GridLines = true;
			this->lvScores->FullRowSelect = true;

			// 🛑 CRÍTICO: Fondo de la tabla NEGRO PURO y Texto VERDE/CYAN
			this->lvScores->BackColor = System::Drawing::Color::Black;
			this->lvScores->ForeColor = System::Drawing::Color::FromArgb(128, 255, 128); // Verde Neón
			this->lvScores->Font = gcnew System::Drawing::Font("Consolas", 10, FontStyle::Regular);

			// Limpiar columnas
			this->lvScores->Columns->Clear();

			// Definición de las columnas y ALINEACIÓN CORRECTA
			this->lvScores->Columns->Add("Cadete", 150, HorizontalAlignment::Left);
			this->lvScores->Columns->Add("Modo", 80, HorizontalAlignment::Center);
			this->lvScores->Columns->Add("Autonomía (IA)", 120, HorizontalAlignment::Right); // Derecha para números
			this->lvScores->Columns->Add("Criterio (Humano)", 130, HorizontalAlignment::Right);
			this->lvScores->Columns->Add("Confianza (Colab)", 130, HorizontalAlignment::Right);
			this->lvScores->Columns->Add("TOTAL", 100, HorizontalAlignment::Right);
			this->lvScores->Columns->Add("Fecha", 150, HorizontalAlignment::Left);

			// Ajuste visual para centrar el título
			int anchoLista = this->lvScores->Width;
			this->lblTituloScore->Left = (this->pnlScores->Width - anchoLista) / 2;


			CargarDatosScores();
		}
		void FrmInicio::CargarDatosScores() {

			this->lvScores->Items->Clear();

			// Nota: Necesitas que ArchivoService esté inicializado.
			std::vector<RegistroScore> records = archivoService->LeerRegistrosBinarios("Files/SCORES.bin");

			for (const auto& record : records) {

				// Usamos el método de conversión de nuestro servicio
				System::String^ nombre = archivoService->ConvertCharToString(record.nombre);
				System::String^ fecha = archivoService->ConvertCharToString(record.fecha);
				System::String^ modo = record.esModoHistoria ? "Historia" : "Nivel";

				// Crear el primer ítem (Nombre)
				ListViewItem^ item = gcnew ListViewItem(nombre);

				// Añadir sub-ítems en el orden de las columnas:
				item->SubItems->Add(modo);
				item->SubItems->Add(Convert::ToString(record.ptjAutonomia));
				item->SubItems->Add(Convert::ToString(record.ptjCriterio));
				item->SubItems->Add(Convert::ToString(record.ptjConfianza));
				item->SubItems->Add(Convert::ToString(record.puntajeTotal)); // El score principal para el total
				item->SubItems->Add(fecha);

				this->lvScores->Items->Add(item);
			}
		}
		void FrmInicio::ConfigurarYPosicionarCreditos() {

			// VERIFICACIÓN CRÍTICA: Asegurar que los controles estén en el panel
			if (!this->pnlCreditos->Controls->Contains(this->lblTituloCreditos)) {
				this->pnlCreditos->Controls->Add(this->lblTituloCreditos);
			}
			if (!this->pnlCreditos->Controls->Contains(this->lblMensajeAgradecimiento)) {
				this->pnlCreditos->Controls->Add(this->lblMensajeAgradecimiento);
			}
			if (!this->pnlCreditos->Controls->Contains(this->lblEstudiantes)) {
				this->pnlCreditos->Controls->Add(this->lblEstudiantes);
			}
			if (!this->pnlCreditos->Controls->Contains(this->lblUniversidad)) {
				this->pnlCreditos->Controls->Add(this->lblUniversidad);
			}
			if (!this->pnlCreditos->Controls->Contains(this->lblProfesor)) {
				this->pnlCreditos->Controls->Add(this->lblProfesor);
			}
			if (!this->pnlCreditos->Controls->Contains(this->btnVolverMenu)) {
				this->pnlCreditos->Controls->Add(this->btnVolverMenu);
			}

			this->pnlCreditos->AutoScroll = false; // Desactivar scroll para centrado perfecto

			// Obtener las dimensiones del panel contenedor
			int anchoPanel = this->pnlCreditos->Width;
			int altoPanel = this->pnlCreditos->Height;

			// Ancho fijo para las secciones principales
			const int ANCHO_SECCION = 1080;

			// --- CÁLCULO DE ALTURAS TOTALES ---
			const int ALTURA_TITULO = 60;
			const int ESPACIO_TITULO = 70;
			const int ALTURA_MENSAJE = 70;
			const int ESPACIO_MENSAJE = 80;
			const int ALTURA_ESTUDIANTES = 120;
			const int ESPACIO_ESTUDIANTES = 130;
			const int ALTURA_UNIVERSIDAD = 40;
			const int ESPACIO_UNIVERSIDAD = 50;
			const int ALTURA_PROFESOR = 30;
			const int ESPACIO_PROFESOR = 50;
			const int ALTURA_BOTON = 50;

			// ✅ ALTURA TOTAL DEL CONTENIDO
			int alturaTotal = ALTURA_TITULO + ESPACIO_TITULO +
				ALTURA_MENSAJE + ESPACIO_MENSAJE +
				ALTURA_ESTUDIANTES + ESPACIO_ESTUDIANTES +
				ALTURA_UNIVERSIDAD + ESPACIO_UNIVERSIDAD +
				ALTURA_PROFESOR + ESPACIO_PROFESOR +
				ALTURA_BOTON;

			// ✅ CALCULAR POSICIÓN INICIAL PARA CENTRADO VERTICAL PERFECTO
			int yActual = (altoPanel - alturaTotal) / 2;

			// Si queda muy arriba, establecer un mínimo
			if (yActual <100) {
				yActual =100;
			}

			// --- Estilos de Colores ---
			System::Drawing::Color colorNeonCyan = System::Drawing::Color::FromArgb(0, 255, 255);
			System::Drawing::Color colorNeonMagenta = System::Drawing::Color::FromArgb(255, 0, 128);
			System::Drawing::Color colorConsola = System::Drawing::Color::White;

			// -----------------------------------------------------------------
			// 1. TÍTULO PRINCIPAL
			// -----------------------------------------------------------------
			this->lblTituloCreditos->Text = "NEXUS: CÓDIGO FINALIZADO";
			this->lblTituloCreditos->Font = gcnew System::Drawing::Font("Consolas", 36, FontStyle::Bold);
			this->lblTituloCreditos->ForeColor = colorNeonCyan;
			this->lblTituloCreditos->TextAlign = ContentAlignment::MiddleCenter;
			this->lblTituloCreditos->Width = ANCHO_SECCION;
			this->lblTituloCreditos->Left = (anchoPanel - ANCHO_SECCION) / 2;
			this->lblTituloCreditos->Top = yActual;
			this->lblTituloCreditos->Height = ALTURA_TITULO;

			yActual += ESPACIO_TITULO;

			// -----------------------------------------------------------------
			// 2. MENSAJE EMOCIONAL
			// -----------------------------------------------------------------
			this->lblMensajeAgradecimiento->Text =
				"Gracias por jugar.\nCreado por estudiantes que no durmieron mucho, pero valió la pena.";
			this->lblMensajeAgradecimiento->Font = gcnew System::Drawing::Font("Segoe UI", 16, FontStyle::Italic);
			this->lblMensajeAgradecimiento->ForeColor = colorConsola;
			this->lblMensajeAgradecimiento->TextAlign = ContentAlignment::MiddleCenter;
			this->lblMensajeAgradecimiento->Width = ANCHO_SECCION;
			this->lblMensajeAgradecimiento->Left = (anchoPanel - ANCHO_SECCION) / 2;
			this->lblMensajeAgradecimiento->Top = yActual;
			this->lblMensajeAgradecimiento->Height = ALTURA_MENSAJE;

			yActual += ESPACIO_MENSAJE;

			// -----------------------------------------------------------------
			// 3. ESTUDIANTES (CREADORES) - CENTRADO PERFECTO
			// -----------------------------------------------------------------
			this->lblEstudiantes->Text =
				"// DESARROLLADORES //\nIlder Ojeda\nGerardo Morales\nAdriano Matos";
			this->lblEstudiantes->Font = gcnew System::Drawing::Font("Consolas", 18, FontStyle::Bold);
			this->lblEstudiantes->ForeColor = colorNeonMagenta;
			this->lblEstudiantes->TextAlign = ContentAlignment::MiddleCenter;
			this->lblEstudiantes->Width = ANCHO_SECCION;
			this->lblEstudiantes->Left = (anchoPanel - ANCHO_SECCION) / 2;
			this->lblEstudiantes->Top = yActual;
			this->lblEstudiantes->Height = ALTURA_ESTUDIANTES;

			yActual += ESPACIO_ESTUDIANTES;

			// -----------------------------------------------------------------
			// 4. UNIVERSIDAD
			// -----------------------------------------------------------------
			this->lblUniversidad->Text = "Universidad Peruana de Ciencias Aplicadas (UPC)";
			this->lblUniversidad->Font = gcnew System::Drawing::Font("Segoe UI", 16, FontStyle::Regular);
			this->lblUniversidad->ForeColor = colorConsola;
			this->lblUniversidad->TextAlign = ContentAlignment::MiddleCenter;
			this->lblUniversidad->Width = ANCHO_SECCION;
			this->lblUniversidad->Left = (anchoPanel - ANCHO_SECCION) / 2;
			this->lblUniversidad->Top = yActual;
			this->lblUniversidad->Height = ALTURA_UNIVERSIDAD;

			yActual += ESPACIO_UNIVERSIDAD;

			// -----------------------------------------------------------------
			// 5. PROFESOR
			// -----------------------------------------------------------------
			this->lblProfesor->Text = "PROFESOR ASESOR: Herry Antonio Mendoza Puertas";
			this->lblProfesor->Font = gcnew System::Drawing::Font("Consolas", 12, FontStyle::Regular);
			this->lblProfesor->ForeColor = colorNeonCyan;
			this->lblProfesor->TextAlign = ContentAlignment::MiddleCenter;
			this->lblProfesor->Width = ANCHO_SECCION;
			this->lblProfesor->Left = (anchoPanel - ANCHO_SECCION) / 2;
			this->lblProfesor->Top = yActual;
			this->lblProfesor->Height = ALTURA_PROFESOR;

			yActual += ESPACIO_PROFESOR;

			// -----------------------------------------------------------------
			// 6. BOTÓN VOLVER - CENTRADO CON EL RESTO
			// -----------------------------------------------------------------
			this->btnVolverMenu->Text = "VOLVER AL MENÚ";
			this->btnVolverMenu->BackColor = System::Drawing::Color::FromArgb(255, 30, 40, 60);
			this->btnVolverMenu->ForeColor = colorConsola;
			this->btnVolverMenu->FlatStyle = FlatStyle::Flat;
			this->btnVolverMenu->FlatAppearance->BorderColor = colorNeonCyan;
			this->btnVolverMenu->FlatAppearance->BorderSize = 2;
			this->btnVolverMenu->Font = gcnew System::Drawing::Font("Consolas", 12, FontStyle::Bold);
			this->btnVolverMenu->Width = 250;
			this->btnVolverMenu->Height = ALTURA_BOTON;
			this->btnVolverMenu->Left = (anchoPanel - this->btnVolverMenu->Width) / 2;
			this->btnVolverMenu->Top = yActual; // ✅ Ahora está con el bloque, no al final

			// -----------------------------------------------------------------
			// APLICAR TRANSPARENCIA Y VISIBILIDAD
			// -----------------------------------------------------------------
			cli::array<System::Windows::Forms::Label^>^ labels = {
				lblTituloCreditos,
				lblMensajeAgradecimiento,
				lblEstudiantes,
				lblUniversidad,
				lblProfesor
			};

			for each (System::Windows::Forms::Label ^ lbl in labels) {
				lbl->BackColor = System::Drawing::Color::Transparent;
				lbl->Visible = true;
				lbl->AutoSize = false;
			}

			this->btnVolverMenu->Visible = true;
			this->btnVolverMenu->Enabled = true;
		}
	private: System::Void FrmInicio_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pnlFondo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	
	private: System::Void FrmInicio_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {


	}

		   
	private: System::Void AlCerrarMundo(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		this->Show(); 
		gestorSonido->ReproducirMusica("MusicaFondoInicio.wav", 0.2); 
	}

	private: System::Void AlCerrarMundoIA(System::Object^ sender, FormClosedEventArgs^ e) {
		FrmMundoIA^ mundo = (FrmMundoIA^)sender;

		if (mundo->DialogResult == System::Windows::Forms::DialogResult::OK && Sesion::EsModoHistoria) {
			FrmMundoHumano^ mundo2 = gcnew FrmMundoHumano();
			mundo2->FormClosed += gcnew FormClosedEventHandler(this, &FrmInicio::AlCerrarMundoHumano);
			mundo2->Show();
		}
		else {
			this->Show();
			gestorSonido->ReproducirMusica("MusicaFondoInicio.wav", 0.2);
		}
	}
	private: System::Void AlCerrarMundoHumano(System::Object^ sender, FormClosedEventArgs^ e) {
		FrmMundoHumano^ mundo = (FrmMundoHumano^)sender;
		if (mundo->DialogResult == System::Windows::Forms::DialogResult::OK && Sesion::EsModoHistoria) {
			FrmMundoColab^ mundo3 = gcnew FrmMundoColab();
			mundo3->FormClosed += gcnew FormClosedEventHandler(this, &FrmInicio::AlCerrarMundo);
			mundo3->Show();
		}
		else {
			this->Show();
			gestorSonido->ReproducirMusica("MusicaFondoInicio.wav", 0.2);
		}
	}
	private: System::Void btnNiveles_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtNombreJugador->Text->Trim() == "") {
			MessageBox::Show(
				"Acceso denegado.\nPor favor, ingrese su identificacion antes de continuar.",
				"Seguridad NEXUS",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);

			txtNombreJugador->Focus();
			return;
		}
		gestorSonido->ReproducirEfecto("EfectoClick.wav", 1.0);
		pnlMenuPrincipal->Visible = false;
		pnlNiveles->Visible = true;
	}
	private: System::Void btnIniciarJuego_Click(System::Object^ sender, System::EventArgs^ e) {
		// 1. VALIDACIÓN
		if (txtNombreJugador->Text->Trim() == "") {
			MessageBox::Show("Acceso denegado.\nIngrese su identificacion de cadete.", "Seguridad NEXUS", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			txtNombreJugador->Focus();
			return;
		}
		gestorSonido->ReproducirEfecto("EfectoClick.wav", 1.0);
		gestorSonido->DetenerMusica();

		// 1. Configurar Sesión MODO HISTORIA
		Sesion::Reiniciar();
		Sesion::NombreJugador = txtNombreJugador->Text;
		Sesion::EsModoHistoria = true; // <--- TRUE

		// 2. Abrir PRIMER MUNDO (IA)
		FrmMundoIA^ mundo1 = gcnew FrmMundoIA();

		// 3. Conectar al evento inteligente (que abrirá el Nivel 2 al ganar)
		mundo1->FormClosed += gcnew FormClosedEventHandler(this, &FrmInicio::AlCerrarMundoIA);

		mundo1->Show();
		this->Hide();
	}

	private: System::Void btnNivel1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		gestorSonido->ReproducirEfecto("EfectoClick.wav", 1.0);
		gestorSonido->DetenerMusica();

		// 1. Configurar Sesión
		Sesion::Reiniciar();
		Sesion::NombreJugador = txtNombreJugador->Text;
		Sesion::EsModoHistoria = false; // <--- Solo nivel suelto
		pnlNiveles->Visible = false;
		pnlMenuPrincipal->Visible = true;
		// 2. Abrir Mundo
		FrmMundoIA^ frmMundoIA = gcnew FrmMundoIA();

		// 3. ¡ESTA ES LA LÍNEA QUE TE FALTABA! (Conectar el regreso)
		frmMundoIA->FormClosed += gcnew FormClosedEventHandler(this, &FrmInicio::AlCerrarMundo);

		frmMundoIA->Show();
		this->Hide();


	}

	
	private: System::Void btnNivel2_Click(System::Object^ sender, System::EventArgs^ e) {
		gestorSonido->ReproducirEfecto("EfectoClick.wav", 1.0);
		gestorSonido->DetenerMusica();
		Sesion::Reiniciar(); // Limpiamos datos viejos
		Sesion::NombreJugador = txtNombreJugador->Text; // Guardamos el nombre
		Sesion::EsModoHistoria = false;
		FrmMundoHumano^ mundo = gcnew FrmMundoHumano();
		ArchivoService* archivoService;
		pnlNiveles->Visible = false;
		pnlMenuPrincipal->Visible = true;
		mundo->FormClosed += gcnew FormClosedEventHandler(this, &FrmInicio::AlCerrarMundoHumano);
		mundo->Show();
		this->Hide();
	}

	private: System::Void btnNivel3_Click(System::Object^ sender, System::EventArgs^ e) {
		gestorSonido->ReproducirEfecto("EfectoClick.wav", 1.0);
		gestorSonido->DetenerMusica();

		// 1. Configurar Sesión
		Sesion::Reiniciar();
		Sesion::NombreJugador = txtNombreJugador->Text;
		Sesion::EsModoHistoria = false;
		pnlNiveles->Visible = false;
		pnlMenuPrincipal->Visible = true;
		// 2. Abrir Mundo
		FrmMundoColab^ frmMundoColab = gcnew FrmMundoColab();

		// 3. Conectar regreso
		frmMundoColab->FormClosed += gcnew FormClosedEventHandler(this, &FrmInicio::AlCerrarMundo);

		frmMundoColab->Show();
		this->Hide();
	}
private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
	gestorSonido->ReproducirEfecto("EfectoClick.wav", 1.0);

	// Asegurar que pnlCreditos esté en el lugar correcto
	if (!this->pnlFondo->Controls->Contains(this->pnlCreditos)) {
		this->pnlFondo->Controls->Add(this->pnlCreditos);
	}

	// Configurar antes de mostrar
	ConfigurarYPosicionarCreditos();

	// Ocultar otros paneles y mostrar créditos
	this->pnlMenuPrincipal->Visible = false;
	this->pnlScores->Visible = false; // ← Asegurar que scores esté oculto
	this->pnlNiveles->Visible = false;

	this->pnlCreditos->Visible = true;
	this->pnlCreditos->BringToFront();
}
	
	private: System::Void btnHistoria_Click_1(System::Object^ sender, System::EventArgs^ e) {
		gestorSonido->ReproducirEfecto("EfectoClick.wav", 1.0);
		if (this->pnlScores->Visible) {
			// Si ya está visible, ocultarlo
			this->pnlScores->Visible = false;
		}
		else {
			// Cargar datos y aplicar diseño ANTES de mostrarlo
			ConfigurarPanelScores();
			this->pnlScores->Visible = true;
			this->pnlScores->BringToFront();
		}
	}
	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		pnlNiveles->Visible = false;       // Oculta niveles
		pnlMenuPrincipal->Visible = true;  // Muestra menú principal
	}

private: System::Void pnlScores_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void btnVolverScores_Click(System::Object^ sender, System::EventArgs^ e) {
	gestorSonido->ReproducirEfecto("EfectoClick.wav", 1.0);
	this->pnlScores->Visible = false;
}
private: System::Void btnVolverMenu_Click(System::Object^ sender, System::EventArgs^ e) {
	gestorSonido->ReproducirEfecto("EfectoClick.wav", 1.0);

	this->pnlCreditos->Visible = false;
	this->pnlMenuPrincipal->Visible = true;
	this->pnlMenuPrincipal->BringToFront();
}
};
	
}
