#pragma once
#include "Mundo.h"
#include "FrmMundoHumano.h"
#include "FrmMundoIA.h"
#include "SoundManager.h"
#include "FrmMundoColab.h"
#include "Sesion.h"

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
			pnlNiveles->Visible = false;
			

			
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
	private: System::Windows::Forms::Button^ btnNiveles;
	private: System::Windows::Forms::Button^ btnIniciarJuego;
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Button^ btnScores;




	private: System::Windows::Forms::Button^ btnVolver;


	private: System::Windows::Forms::Button^ btnNivel3;
	private: System::Windows::Forms::Button^ btnNivel2;
		   // Variable para controlar el sonido en este formulario
	private: NEXUS_V2::Service::SoundManager^ gestorSonido;





	protected:

	private: System::Windows::Forms::Button^ brnMundoIA;
	protected:

	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ pnlFondo;
	private: System::Windows::Forms::Button^ btnVolver;

	private: System::Windows::Forms::Button^ btnNivel1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Button^ btnHistoria;
	private: System::Windows::Forms::Button^ btnNiveles;
	private: System::Windows::Forms::Button^ btnIniciarJuego;
	private: System::Windows::Forms::Button^ btnSalir;























	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;



	private: System::Windows::Forms::Panel^ pnlNiveles;
	private: System::Windows::Forms::Button^ btnNivel1;
	private: System::Windows::Forms::Panel^ pnlMenuPrincipal;
	private: System::Windows::Forms::TextBox^ txtNombreJugador;
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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pnlFondo = (gcnew System::Windows::Forms::Panel());
			this->pnlMenuPrincipal = (gcnew System::Windows::Forms::Panel());
			this->txtNombreJugador = (gcnew System::Windows::Forms::TextBox());
			this->lblPromptNombre = (gcnew System::Windows::Forms::Label());
			this->btnIniciarJuego = (gcnew System::Windows::Forms::Button());
			this->btnNiveles = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnScores = (gcnew System::Windows::Forms::Button());
			this->pnlNiveles = (gcnew System::Windows::Forms::Panel());
			this->btnNivel3 = (gcnew System::Windows::Forms::Button());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->btnNivel1 = (gcnew System::Windows::Forms::Button());
			this->btnNivel2 = (gcnew System::Windows::Forms::Button());
			this->brnMundoIA = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pnlFondo->SuspendLayout();
			this->pnlMenuPrincipal->SuspendLayout();
			this->pnlNiveles->SuspendLayout();
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
			// button2
			// 
			this->button2->Location = System::Drawing::Point(544, 360);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(701, 360);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// pnlFondo
			// 
			this->pnlFondo->BackColor = System::Drawing::Color::White;
			this->pnlFondo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlFondo.BackgroundImage")));
			this->pnlFondo->Controls->Add(this->pnlNiveles);
			this->pnlFondo->Controls->Add(this->pnlMenuPrincipal);
			this->pnlFondo->Location = System::Drawing::Point(-2, -1);
			this->pnlFondo->Name = L"pnlFondo";
			this->pnlFondo->Size = System::Drawing::Size(1922, 1086);
			this->pnlFondo->TabIndex = 3;
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
			this->pnlMenuPrincipal->Location = System::Drawing::Point(324, 390);
			this->pnlMenuPrincipal->Name = L"pnlMenuPrincipal";
			this->pnlMenuPrincipal->Size = System::Drawing::Size(1233, 606);
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
			// pnlNiveles
			// 
			this->pnlNiveles->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlNiveles.BackgroundImage")));
			this->pnlNiveles->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pnlNiveles->Controls->Add(this->btnNivel3);
			this->pnlNiveles->Controls->Add(this->btnVolver);
			this->pnlNiveles->Controls->Add(this->btnNivel1);
			this->pnlNiveles->Controls->Add(this->btnNivel2);
			this->pnlNiveles->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->pnlNiveles->Location = System::Drawing::Point(200, 46);
			this->pnlNiveles->Name = L"pnlNiveles";
			this->pnlNiveles->Size = System::Drawing::Size(1536, 988);
			this->pnlNiveles->TabIndex = 11;
			this->pnlNiveles->Visible = false;
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
			// brnMundoIA
			// 
			this->brnMundoIA->Location = System::Drawing::Point(389, 360);
			this->brnMundoIA->Name = L"brnMundoIA";
			this->brnMundoIA->Size = System::Drawing::Size(75, 23);
			this->brnMundoIA->TabIndex = 0;
			this->brnMundoIA->Text = L"MUNDO IA";
			this->brnMundoIA->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(544, 360);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(701, 360);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// FrmInicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1920, 1080);
			this->Controls->Add(this->pnlFondo);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->brnMundoIA);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FrmInicio";
			this->Text = L"FrmInicio";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmInicio::FrmInicio_Load);
			this->pnlFondo->ResumeLayout(false);
			this->pnlMenuPrincipal->ResumeLayout(false);
			this->pnlMenuPrincipal->PerformLayout();
			this->pnlNiveles->ResumeLayout(false);
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
	private: System::Void FrmInicio_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pnlFondo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	
	private: System::Void FrmInicio_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {


	}

	private: System::Void AlCerrarMundoHumano(System::Object^ sender, FormClosedEventArgs^ e) {
		FrmMundoHumano^ mundoCerrado = (FrmMundoHumano^)sender;

		// CASO 1: GANÓ EL NIVEL
		if (mundoCerrado->DialogResult == System::Windows::Forms::DialogResult::OK) {


		}
		// CASO 2: PERDIÓ O SALIÓ
		else {
			// En cualquier modo, si pierdes o sales, vuelves al menú
			this->Show();
			gestorSonido->ReproducirMusica("MusicaFondoInicio.wav", 0.2);
		}
	}
	private: System::Void AlCerrarMundo(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		this->Show();
		gestorSonido->ReproducirMusica("MusicaFondoInicio.wav", 0.2);
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
	
		// 2. SONIDO
		gestorSonido->ReproducirEfecto("EfectoClick.wav", 1.0);
		gestorSonido->DetenerMusica();
	
		// 2. GUARDAR EN LA SESIÓN GLOBAL (¡Aquí está la clave!)
		Sesion::Reiniciar(); // Limpiamos datos viejos
		Sesion::NombreJugador = txtNombreJugador->Text; // Guardamos el nombre
		Sesion::EsModoHistoria = true;

		// 3. Arrancar el primer mundo (IA)
		FrmMundoIA^ mundo1 = gcnew FrmMundoIA(); // Sin parámetros, ya están en Sesion
		mundo1->Show();
		this->Hide();
	}
	

	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		

		pnlNiveles->Visible = false;       // Oculta niveles
		pnlMenuPrincipal->Visible = true;  // Muestra menú principal
	}
	private: System::Void btnNivel2_Click(System::Object^ sender, System::EventArgs^ e) {
		gestorSonido->ReproducirEfecto("EfectoClick.wav", 1.0);
		gestorSonido->DetenerMusica();
		Sesion::Reiniciar(); // Limpiamos datos viejos
		Sesion::NombreJugador = txtNombreJugador->Text; // Guardamos el nombre
		Sesion::EsModoHistoria = false;
		FrmMundoHumano^ mundo = gcnew FrmMundoHumano();
		pnlNiveles->Visible = false;
		pnlMenuPrincipal->Visible = true;
		mundo->FormClosed += gcnew FormClosedEventHandler(this, &FrmInicio::AlCerrarMundoHumano);
		mundo->Show();
		this->Hide();
	}
	private: System::Void btnNivel1_Click(System::Object^ sender, System::EventArgs^ e) {
			gestorSonido->ReproducirEfecto("EfectoClick.wav", 1.0);
		
			FrmMundoIA^ frmMundoIA = gcnew FrmMundoIA();
			frmMundoIA->Show();
		
			this->Hide();
	
		}
	private: System::Void btnNivel3_Click(System::Object^ sender, System::EventArgs^ e) {
		gestorSonido->ReproducirEfecto("EfectoClick.wav", 1.0);
		FrmMundoColab^ frmMundoColab = gcnew FrmMundoColab();
		frmMundoColab->Show();
		this->Hide();
	}
	private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
		gestorSonido->ReproducirEfecto("EfectoClick.wav", 1.0);
		//Agregar formulario de creditos
	}
		   
	
private: System::Void btnHistoria_Click_1(System::Object^ sender, System::EventArgs^ e) {
	gestorSonido->ReproducirEfecto("EfectoClick.wav", 1.0);
	//Agregar formulario de historia
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
	
}
