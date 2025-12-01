#pragma once
#include "MundoHumanoService.h"
#include "FrmFinMundoHumano.h"
#include "Jugador.h"
#include "FrmModulo1.h"
#include "FrmModulo2.h"
#include "FrmModulo3.h"
#include "SoundManager.h"
#include "DialogoService.h"
#include "GasToxico.h"
#include "CortoCircuito.h"
#include <string>
#include "Sesion.h"


namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMundoHumano
	/// </summary>
	public ref class FrmMundoHumano : public System::Windows::Forms::Form
	{
	public:
		FrmMundoHumano(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		// 1. Guardar los datos en variables locales
			lblNombreJugador->Text = Sesion::NombreJugador;
			this->esModoHistoria = Sesion::EsModoHistoria;
			
			// 1. Configuración de Sonido
			gestorSonido = gcnew NEXUS_V2::Service::SoundManager();
			gestorSonido->ReproducirMusica("MusicaFondoMundoHumano.wav", 0.5);

			// 2. Inicializar el Servicio
			service = new MundoHumanoService(pnlMundo->Width, pnlMundo->Height, 3);
			
			// 3. Cargar Fondo
			char rutaFondo[] = "MundoHumano.png";
			service->cargarFondo(rutaFondo);

			// 4. Configurar Visuales
			ConfigurarHUD();

			// 5. Diálogos
			gestorDialogo = new DialogoService();
			gestorDialogo->inicializarDialogos();

			// 6. Configuración del Formulario
			this->KeyPreview = true;
			this->SetStyle(ControlStyles::Selectable, false);
			teclaPresionada = Direccion::Ninguno;

			// Estados iniciales
			lblMensajeTerrestre->Visible = false;
			lblMensaje->Visible = false;
			finPendiente = false;
			finPendienteGano = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMundoHumano()
		{
			if (components)
			{
				delete components;
			}
		}
	protected: virtual bool ProcessCmdKey(Message% msg, Keys keyData) override {
		switch (keyData) {
		case Keys::Up: teclaPresionada = Direccion::Arriba; return true;  
		case Keys::Down: teclaPresionada = Direccion::Abajo; return true; 
		case Keys::Left: teclaPresionada = Direccion::Izquierda; return true; 
		case Keys::Right: teclaPresionada = Direccion::Derecha; return true; 
		}
		return __super::ProcessCmdKey(msg, keyData);
	}

	private: System::Windows::Forms::Panel^ pnlMundo;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ pbHub;
	private: System::Windows::Forms::Button^ btnSalir;
	private: NEXUS_V2::Service::SoundManager^ gestorSonido	;
		   

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		MundoHumanoService* service;
		Direccion teclaPresionada;
		DialogoService* gestorDialogo;
		bool esModoHistoria;
		

		bool mensajePapelMostrado = false;
		bool mensajeTerrestreMostrado = false;
		bool mensajeTrajeElecMostrado = false;
		bool mensajeTrajeGasMostrado = false;
		bool mensajeModulo1Mostrado = false;
		bool mensajeModulo2Mostrado = false;

		bool reproduciendoPasos = false;
		bool mensajePapelActivo = false;

		bool finDeMundoMostrado = false;
		bool finPendiente;      // hay fin de mundo esperando mostrar formulario
		bool finPendienteGano;  // true = ganó, false = perdió

	private: System::Windows::Forms::Label^ lblMensaje;
	private: System::Windows::Forms::Label^ lblEstabilidad;
	private: System::Windows::Forms::Label^ lblCriterio;
	private: System::Windows::Forms::Label^ lblProgreso;
	private: System::Windows::Forms::PictureBox^ pbTrajeGasMapa;
	private: System::Windows::Forms::PictureBox^ pbTrajeElecMapa;
	private: System::Windows::Forms::PictureBox^ pbTrajeElecHUD;
	private: System::Windows::Forms::PictureBox^ pbTrajeGasHUD;
	private: System::Windows::Forms::Label^ lblTituloEquipoProteccion;
	private: System::Windows::Forms::PictureBox^ pbTrajeNormalHUB;
	private: System::Windows::Forms::Button^ btnUsarTrajeNormal;
	private: System::Windows::Forms::Button^ btnUsarTrajeElec;
	private: System::Windows::Forms::Button^ btnUsarTrajeGas;
	private: System::Windows::Forms::PictureBox^ pbPrototipoA;
	private: System::Windows::Forms::PictureBox^ pbPrototivoB;
	private: System::Windows::Forms::PictureBox^ pbFotoJugador;
	private: System::Windows::Forms::Label^ lblNombreJugador;
	private: System::Windows::Forms::Panel^ pnlFondoEstabilidad;
	private: System::Windows::Forms::Panel^ pnlBarraEstabilidad;
	private: System::Windows::Forms::Panel^ pnlFondoCriterio;
	private: System::Windows::Forms::Panel^ pnlBarraCriterio;
	private: System::Windows::Forms::Panel^ pnlFondoProgreso;
	private: System::Windows::Forms::Panel^ pnlBarraProgreso;
	private: System::Windows::Forms::PictureBox^ pbVida2;
	private: System::Windows::Forms::PictureBox^ pbVida1;
	private: System::Windows::Forms::PictureBox^ pbVida3;
	private: System::Windows::Forms::Label^ lblMensajeTerrestre;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMundoHumano::typeid));
			this->pnlMundo = (gcnew System::Windows::Forms::Panel());
			this->pbTrajeGasMapa = (gcnew System::Windows::Forms::PictureBox());
			this->pbTrajeElecMapa = (gcnew System::Windows::Forms::PictureBox());
			this->lblMensajeTerrestre = (gcnew System::Windows::Forms::Label());
			this->lblMensaje = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pbHub = (gcnew System::Windows::Forms::PictureBox());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->lblEstabilidad = (gcnew System::Windows::Forms::Label());
			this->lblCriterio = (gcnew System::Windows::Forms::Label());
			this->lblProgreso = (gcnew System::Windows::Forms::Label());
			this->pbTrajeElecHUD = (gcnew System::Windows::Forms::PictureBox());
			this->pbTrajeGasHUD = (gcnew System::Windows::Forms::PictureBox());
			this->lblTituloEquipoProteccion = (gcnew System::Windows::Forms::Label());
			this->pbTrajeNormalHUB = (gcnew System::Windows::Forms::PictureBox());
			this->btnUsarTrajeNormal = (gcnew System::Windows::Forms::Button());
			this->btnUsarTrajeElec = (gcnew System::Windows::Forms::Button());
			this->btnUsarTrajeGas = (gcnew System::Windows::Forms::Button());
			this->pbPrototipoA = (gcnew System::Windows::Forms::PictureBox());
			this->pbPrototivoB = (gcnew System::Windows::Forms::PictureBox());
			this->pbFotoJugador = (gcnew System::Windows::Forms::PictureBox());
			this->lblNombreJugador = (gcnew System::Windows::Forms::Label());
			this->pnlFondoEstabilidad = (gcnew System::Windows::Forms::Panel());
			this->pnlBarraEstabilidad = (gcnew System::Windows::Forms::Panel());
			this->pnlFondoCriterio = (gcnew System::Windows::Forms::Panel());
			this->pnlBarraCriterio = (gcnew System::Windows::Forms::Panel());
			this->pnlFondoProgreso = (gcnew System::Windows::Forms::Panel());
			this->pnlBarraProgreso = (gcnew System::Windows::Forms::Panel());
			this->pbVida2 = (gcnew System::Windows::Forms::PictureBox());
			this->pbVida1 = (gcnew System::Windows::Forms::PictureBox());
			this->pbVida3 = (gcnew System::Windows::Forms::PictureBox());
			this->pnlMundo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeGasMapa))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeElecMapa))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbHub))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeElecHUD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeGasHUD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeNormalHUB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPrototipoA))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPrototivoB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFotoJugador))->BeginInit();
			this->pnlFondoEstabilidad->SuspendLayout();
			this->pnlFondoCriterio->SuspendLayout();
			this->pnlFondoProgreso->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVida2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVida1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVida3))->BeginInit();
			this->SuspendLayout();
			// 
			// pnlMundo
			// 
			this->pnlMundo->BackColor = System::Drawing::Color::LavenderBlush;
			this->pnlMundo->Controls->Add(this->pbTrajeGasMapa);
			this->pnlMundo->Controls->Add(this->pbTrajeElecMapa);
			this->pnlMundo->Controls->Add(this->lblMensajeTerrestre);
			this->pnlMundo->Controls->Add(this->lblMensaje);
			this->pnlMundo->Location = System::Drawing::Point(0, -1);
			this->pnlMundo->Name = L"pnlMundo";
			this->pnlMundo->Size = System::Drawing::Size(1498, 1080);
			this->pnlMundo->TabIndex = 0;
			this->pnlMundo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMundoHumano::pnlMundo_Paint);
			// 
			// pbTrajeGasMapa
			// 
			this->pbTrajeGasMapa->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->pbTrajeGasMapa->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbTrajeGasMapa.Image")));
			this->pbTrajeGasMapa->Location = System::Drawing::Point(1252, 593);
			this->pbTrajeGasMapa->Name = L"pbTrajeGasMapa";
			this->pbTrajeGasMapa->Size = System::Drawing::Size(45, 68);
			this->pbTrajeGasMapa->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbTrajeGasMapa->TabIndex = 14;
			this->pbTrajeGasMapa->TabStop = false;
			// 
			// pbTrajeElecMapa
			// 
			this->pbTrajeElecMapa->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->pbTrajeElecMapa->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbTrajeElecMapa.Image")));
			this->pbTrajeElecMapa->Location = System::Drawing::Point(998, 593);
			this->pbTrajeElecMapa->Name = L"pbTrajeElecMapa";
			this->pbTrajeElecMapa->Size = System::Drawing::Size(46, 68);
			this->pbTrajeElecMapa->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbTrajeElecMapa->TabIndex = 13;
			this->pbTrajeElecMapa->TabStop = false;
			this->pbTrajeElecMapa->Click += gcnew System::EventHandler(this, &FrmMundoHumano::pbTrajeElecMapa_Click);
			// 
			// lblMensajeTerrestre
			// 
			this->lblMensajeTerrestre->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->lblMensajeTerrestre->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->lblMensajeTerrestre->ForeColor = System::Drawing::Color::Yellow;
			this->lblMensajeTerrestre->Location = System::Drawing::Point(508, 388);
			this->lblMensajeTerrestre->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblMensajeTerrestre->Name = L"lblMensajeTerrestre";
			this->lblMensajeTerrestre->Padding = System::Windows::Forms::Padding(8);
			this->lblMensajeTerrestre->Size = System::Drawing::Size(597, 341);
			this->lblMensajeTerrestre->TabIndex = 12;
			this->lblMensajeTerrestre->Visible = false;
			// 
			// lblMensaje
			// 
			this->lblMensaje->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->lblMensaje->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->lblMensaje->ForeColor = System::Drawing::Color::Yellow;
			this->lblMensaje->Location = System::Drawing::Point(288, 298);
			this->lblMensaje->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblMensaje->Name = L"lblMensaje";
			this->lblMensaje->Padding = System::Windows::Forms::Padding(8);
			this->lblMensaje->Size = System::Drawing::Size(879, 418);
			this->lblMensaje->TabIndex = 10;
			this->lblMensaje->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMundoHumano::timer1_Tick);
			// 
			// pbHub
			// 
			this->pbHub->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbHub.BackgroundImage")));
			this->pbHub->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pbHub->Location = System::Drawing::Point(1473, 0);
			this->pbHub->Name = L"pbHub";
			this->pbHub->Size = System::Drawing::Size(448, 1080);
			this->pbHub->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbHub->TabIndex = 1;
			this->pbHub->TabStop = false;
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::Gold;
			this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->btnSalir->Location = System::Drawing::Point(1645, 989);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(114, 48);
			this->btnSalir->TabIndex = 2;
			this->btnSalir->TabStop = false;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmMundoHumano::btnSalir_Click);
			// 
			// lblEstabilidad
			// 
			this->lblEstabilidad->AutoSize = true;
			this->lblEstabilidad->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->lblEstabilidad->Font = (gcnew System::Drawing::Font(L"Snap ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEstabilidad->ForeColor = System::Drawing::Color::Yellow;
			this->lblEstabilidad->Location = System::Drawing::Point(1546, 347);
			this->lblEstabilidad->Name = L"lblEstabilidad";
			this->lblEstabilidad->Size = System::Drawing::Size(249, 22);
			this->lblEstabilidad->TabIndex = 13;
			this->lblEstabilidad->Text = L"Estabilidad de la nave: ";
			// 
			// lblCriterio
			// 
			this->lblCriterio->AutoSize = true;
			this->lblCriterio->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->lblCriterio->Font = (gcnew System::Drawing::Font(L"Snap ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCriterio->ForeColor = System::Drawing::Color::Yellow;
			this->lblCriterio->Location = System::Drawing::Point(1546, 447);
			this->lblCriterio->Name = L"lblCriterio";
			this->lblCriterio->Size = System::Drawing::Size(178, 22);
			this->lblCriterio->TabIndex = 14;
			this->lblCriterio->Text = L"Criterio humano:";
			// 
			// lblProgreso
			// 
			this->lblProgreso->AutoSize = true;
			this->lblProgreso->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->lblProgreso->Font = (gcnew System::Drawing::Font(L"Snap ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblProgreso->ForeColor = System::Drawing::Color::Yellow;
			this->lblProgreso->Location = System::Drawing::Point(1547, 537);
			this->lblProgreso->Name = L"lblProgreso";
			this->lblProgreso->Size = System::Drawing::Size(234, 22);
			this->lblProgreso->TabIndex = 15;
			this->lblProgreso->Text = L"Progreso de la mision:";
			// 
			// pbTrajeElecHUD
			// 
			this->pbTrajeElecHUD->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->pbTrajeElecHUD->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbTrajeElecHUD.Image")));
			this->pbTrajeElecHUD->Location = System::Drawing::Point(1651, 722);
			this->pbTrajeElecHUD->Name = L"pbTrajeElecHUD";
			this->pbTrajeElecHUD->Size = System::Drawing::Size(91, 134);
			this->pbTrajeElecHUD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbTrajeElecHUD->TabIndex = 16;
			this->pbTrajeElecHUD->TabStop = false;
			// 
			// pbTrajeGasHUD
			// 
			this->pbTrajeGasHUD->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->pbTrajeGasHUD->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbTrajeGasHUD.Image")));
			this->pbTrajeGasHUD->Location = System::Drawing::Point(1763, 722);
			this->pbTrajeGasHUD->Name = L"pbTrajeGasHUD";
			this->pbTrajeGasHUD->Size = System::Drawing::Size(86, 134);
			this->pbTrajeGasHUD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbTrajeGasHUD->TabIndex = 17;
			this->pbTrajeGasHUD->TabStop = false;
			// 
			// lblTituloEquipoProteccion
			// 
			this->lblTituloEquipoProteccion->AutoSize = true;
			this->lblTituloEquipoProteccion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->lblTituloEquipoProteccion->Font = (gcnew System::Drawing::Font(L"Snap ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTituloEquipoProteccion->ForeColor = System::Drawing::Color::Crimson;
			this->lblTituloEquipoProteccion->Location = System::Drawing::Point(1599, 683);
			this->lblTituloEquipoProteccion->Name = L"lblTituloEquipoProteccion";
			this->lblTituloEquipoProteccion->Size = System::Drawing::Size(219, 22);
			this->lblTituloEquipoProteccion->TabIndex = 18;
			this->lblTituloEquipoProteccion->Text = L"Equipo de protección";
			// 
			// pbTrajeNormalHUB
			// 
			this->pbTrajeNormalHUB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->pbTrajeNormalHUB->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbTrajeNormalHUB.Image")));
			this->pbTrajeNormalHUB->Location = System::Drawing::Point(1544, 722);
			this->pbTrajeNormalHUB->Name = L"pbTrajeNormalHUB";
			this->pbTrajeNormalHUB->Size = System::Drawing::Size(91, 134);
			this->pbTrajeNormalHUB->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbTrajeNormalHUB->TabIndex = 20;
			this->pbTrajeNormalHUB->TabStop = false;
			// 
			// btnUsarTrajeNormal
			// 
			this->btnUsarTrajeNormal->Enabled = false;
			this->btnUsarTrajeNormal->Location = System::Drawing::Point(1562, 862);
			this->btnUsarTrajeNormal->Name = L"btnUsarTrajeNormal";
			this->btnUsarTrajeNormal->Size = System::Drawing::Size(55, 45);
			this->btnUsarTrajeNormal->TabIndex = 21;
			this->btnUsarTrajeNormal->Text = L"Traje base";
			this->btnUsarTrajeNormal->UseVisualStyleBackColor = true;
			this->btnUsarTrajeNormal->Click += gcnew System::EventHandler(this, &FrmMundoHumano::btnUsarTrajeNormal_Click);
			// 
			// btnUsarTrajeElec
			// 
			this->btnUsarTrajeElec->Enabled = false;
			this->btnUsarTrajeElec->Location = System::Drawing::Point(1657, 862);
			this->btnUsarTrajeElec->Name = L"btnUsarTrajeElec";
			this->btnUsarTrajeElec->Size = System::Drawing::Size(75, 45);
			this->btnUsarTrajeElec->TabIndex = 22;
			this->btnUsarTrajeElec->Text = L"Prototipo A";
			this->btnUsarTrajeElec->UseVisualStyleBackColor = true;
			this->btnUsarTrajeElec->Click += gcnew System::EventHandler(this, &FrmMundoHumano::btnUsarTrajeElec_Click);
			// 
			// btnUsarTrajeGas
			// 
			this->btnUsarTrajeGas->Enabled = false;
			this->btnUsarTrajeGas->Location = System::Drawing::Point(1772, 862);
			this->btnUsarTrajeGas->Name = L"btnUsarTrajeGas";
			this->btnUsarTrajeGas->Size = System::Drawing::Size(75, 45);
			this->btnUsarTrajeGas->TabIndex = 23;
			this->btnUsarTrajeGas->Text = L"Prototipo B";
			this->btnUsarTrajeGas->UseVisualStyleBackColor = true;
			this->btnUsarTrajeGas->Click += gcnew System::EventHandler(this, &FrmMundoHumano::btnUsarTrajeGas_Click);
			// 
			// pbPrototipoA
			// 
			this->pbPrototipoA->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->pbPrototipoA->Location = System::Drawing::Point(1651, 722);
			this->pbPrototipoA->Name = L"pbPrototipoA";
			this->pbPrototipoA->Size = System::Drawing::Size(91, 134);
			this->pbPrototipoA->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbPrototipoA->TabIndex = 24;
			this->pbPrototipoA->TabStop = false;
			// 
			// pbPrototivoB
			// 
			this->pbPrototivoB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->pbPrototivoB->Location = System::Drawing::Point(1760, 722);
			this->pbPrototivoB->Name = L"pbPrototivoB";
			this->pbPrototivoB->Size = System::Drawing::Size(89, 134);
			this->pbPrototivoB->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbPrototivoB->TabIndex = 25;
			this->pbPrototivoB->TabStop = false;
			// 
			// pbFotoJugador
			// 
			this->pbFotoJugador->Location = System::Drawing::Point(1550, 67);
			this->pbFotoJugador->Name = L"pbFotoJugador";
			this->pbFotoJugador->Size = System::Drawing::Size(115, 108);
			this->pbFotoJugador->TabIndex = 26;
			this->pbFotoJugador->TabStop = false;
			// 
			// lblNombreJugador
			// 
			this->lblNombreJugador->AutoSize = true;
			this->lblNombreJugador->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->lblNombreJugador->Font = (gcnew System::Drawing::Font(L"Snap ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNombreJugador->ForeColor = System::Drawing::Color::Yellow;
			this->lblNombreJugador->Location = System::Drawing::Point(1676, 73);
			this->lblNombreJugador->Name = L"lblNombreJugador";
			this->lblNombreJugador->Size = System::Drawing::Size(162, 22);
			this->lblNombreJugador->TabIndex = 27;
			this->lblNombreJugador->Text = L"Name of player";
			// 
			// pnlFondoEstabilidad
			// 
			this->pnlFondoEstabilidad->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pnlFondoEstabilidad->Controls->Add(this->pnlBarraEstabilidad);
			this->pnlFondoEstabilidad->Location = System::Drawing::Point(1566, 371);
			this->pnlFondoEstabilidad->Name = L"pnlFondoEstabilidad";
			this->pnlFondoEstabilidad->Size = System::Drawing::Size(277, 21);
			this->pnlFondoEstabilidad->TabIndex = 28;
			// 
			// pnlBarraEstabilidad
			// 
			this->pnlBarraEstabilidad->BackColor = System::Drawing::Color::LawnGreen;
			this->pnlBarraEstabilidad->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlBarraEstabilidad->Location = System::Drawing::Point(0, 0);
			this->pnlBarraEstabilidad->Name = L"pnlBarraEstabilidad";
			this->pnlBarraEstabilidad->Size = System::Drawing::Size(150, 21);
			this->pnlBarraEstabilidad->TabIndex = 29;
			// 
			// pnlFondoCriterio
			// 
			this->pnlFondoCriterio->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pnlFondoCriterio->Controls->Add(this->pnlBarraCriterio);
			this->pnlFondoCriterio->Location = System::Drawing::Point(1564, 471);
			this->pnlFondoCriterio->Name = L"pnlFondoCriterio";
			this->pnlFondoCriterio->Size = System::Drawing::Size(277, 21);
			this->pnlFondoCriterio->TabIndex = 30;
			// 
			// pnlBarraCriterio
			// 
			this->pnlBarraCriterio->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->pnlBarraCriterio->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlBarraCriterio->Location = System::Drawing::Point(0, 0);
			this->pnlBarraCriterio->Name = L"pnlBarraCriterio";
			this->pnlBarraCriterio->Size = System::Drawing::Size(150, 21);
			this->pnlBarraCriterio->TabIndex = 29;
			// 
			// pnlFondoProgreso
			// 
			this->pnlFondoProgreso->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pnlFondoProgreso->Controls->Add(this->pnlBarraProgreso);
			this->pnlFondoProgreso->Location = System::Drawing::Point(1566, 561);
			this->pnlFondoProgreso->Name = L"pnlFondoProgreso";
			this->pnlFondoProgreso->Size = System::Drawing::Size(275, 21);
			this->pnlFondoProgreso->TabIndex = 31;
			// 
			// pnlBarraProgreso
			// 
			this->pnlBarraProgreso->BackColor = System::Drawing::Color::Gold;
			this->pnlBarraProgreso->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlBarraProgreso->Location = System::Drawing::Point(0, 0);
			this->pnlBarraProgreso->Name = L"pnlBarraProgreso";
			this->pnlBarraProgreso->Size = System::Drawing::Size(150, 21);
			this->pnlBarraProgreso->TabIndex = 29;
			// 
			// pbVida2
			// 
			this->pbVida2->BackColor = System::Drawing::Color::Transparent;
			this->pbVida2->Location = System::Drawing::Point(1651, 207);
			this->pbVida2->Name = L"pbVida2";
			this->pbVida2->Size = System::Drawing::Size(40, 40);
			this->pbVida2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbVida2->TabIndex = 32;
			this->pbVida2->TabStop = false;
			// 
			// pbVida1
			// 
			this->pbVida1->BackColor = System::Drawing::Color::Transparent;
			this->pbVida1->Location = System::Drawing::Point(1592, 207);
			this->pbVida1->Name = L"pbVida1";
			this->pbVida1->Size = System::Drawing::Size(40, 40);
			this->pbVida1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbVida1->TabIndex = 33;
			this->pbVida1->TabStop = false;
			this->pbVida1->WaitOnLoad = true;
			// 
			// pbVida3
			// 
			this->pbVida3->BackColor = System::Drawing::Color::Transparent;
			this->pbVida3->Location = System::Drawing::Point(1714, 207);
			this->pbVida3->Name = L"pbVida3";
			this->pbVida3->Size = System::Drawing::Size(40, 40);
			this->pbVida3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbVida3->TabIndex = 34;
			this->pbVida3->TabStop = false;
			// 
			// FrmMundoHumano
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1920, 1080);
			this->Controls->Add(this->pbVida3);
			this->Controls->Add(this->pbVida1);
			this->Controls->Add(this->pbVida2);
			this->Controls->Add(this->pnlFondoProgreso);
			this->Controls->Add(this->pnlFondoCriterio);
			this->Controls->Add(this->pnlFondoEstabilidad);
			this->Controls->Add(this->lblNombreJugador);
			this->Controls->Add(this->pbFotoJugador);
			this->Controls->Add(this->pbPrototivoB);
			this->Controls->Add(this->pbPrototipoA);
			this->Controls->Add(this->btnUsarTrajeGas);
			this->Controls->Add(this->btnUsarTrajeElec);
			this->Controls->Add(this->btnUsarTrajeNormal);
			this->Controls->Add(this->pbTrajeNormalHUB);
			this->Controls->Add(this->lblTituloEquipoProteccion);
			this->Controls->Add(this->pbTrajeGasHUD);
			this->Controls->Add(this->pbTrajeElecHUD);
			this->Controls->Add(this->lblProgreso);
			this->Controls->Add(this->lblCriterio);
			this->Controls->Add(this->lblEstabilidad);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->pbHub);
			this->Controls->Add(this->pnlMundo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FrmMundoHumano";
			this->Text = L"FrmMundoHumano";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmMundoHumano::FrmMundoHumano_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoHumano::FrmMundoHumano_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoHumano::FrmMundoHumano_KeyUp);
			this->pnlMundo->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeGasMapa))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeElecMapa))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbHub))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeElecHUD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeGasHUD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeNormalHUB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPrototipoA))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPrototivoB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFotoJugador))->EndInit();
			this->pnlFondoEstabilidad->ResumeLayout(false);
			this->pnlFondoCriterio->ResumeLayout(false);
			this->pnlFondoProgreso->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVida2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVida1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVida3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void FrmMundoHumano_Load(System::Object^ sender, System::EventArgs^ e) {
		timer1->Start();

	}
		   // A. VERIFICAR COLISIONES (Enemigos y Puzzles)
		   void VerificarColisiones() {
			   System::Drawing::Rectangle rectJugador = service->getJugador()->getRectangle();

			   // 1. COLISIÓN CON ENEMIGOS 
			   if (service->hayColisionEnemigos(rectJugador)) {
				   Enemigo* enemigoColisionado = nullptr;
				   for (Enemigo* enemigo : service->getEnemigos()) {
					   if (rectJugador.IntersectsWith(enemigo->getRectangle())) {
						   enemigoColisionado = enemigo;
						   break;
					   }
				   }

				   if (enemigoColisionado != nullptr) {

					   GasToxico* gas = dynamic_cast<GasToxico*>(enemigoColisionado);
					   CortoCircuito* corto = dynamic_cast<CortoCircuito*>(enemigoColisionado);
					   TipoTraje traje = service->getTrajeActivo();
					   
					   if (gas != nullptr && traje != TipoTraje::AntiGas) {
						   gestorSonido->ReproducirEfecto("EfectoPerderVida.wav", 0.5);
						   AplicarDaño(
							   "Has inhalado gas toxico. Pierdes 1 vida.",
							   "Entrar a zonas con fugas sin la proteccion adecuada no es solo un error: "
							   "es una decision que compromete tu mision."
						   );
					   }
					   else if (corto != nullptr && traje != TipoTraje::AntiElectricidad) {
						   gestorSonido->ReproducirEfecto("EfectoPerderVida.wav", 0.5);
						   AplicarDaño(
							   "Has recibido una descarga electrica. Pierdes 1 vida.",
							   "Acercarte a sistemas inestables sin el equipo correcto tiene consecuencias. "
							   "Observa el entorno y decide con mas criterio antes de avanzar."
						   );
					   }
				   }
			   }

			   // 2. COLISIÓN CON PUZZLES (Módulos)
			   int puzzleColision = service->verificarColisionAlerta();
			   if (puzzleColision != -1) {
				   teclaPresionada = Direccion::Ninguno;
				   gestorSonido->DetenerSonidoBucle();
				   reproduciendoPasos = false;

				   //timer1->Stop(); 

				   switch (puzzleColision) {
				   case 0: { FrmModulo1^ m = gcnew FrmModulo1(service); m->ShowDialog(); break; }
				   case 1: { FrmModulo2^ m = gcnew FrmModulo2(service); m->ShowDialog(); break; }
				   case 2: { FrmModulo3^ m = gcnew FrmModulo3(service); m->ShowDialog(); break; }
				   }

				   //timer1->Start(); 
				   teclaPresionada = Direccion::Ninguno;
			   }
		   }

		   // Helper para restar vida y mostrar mensaje
		   void AplicarDaño(String^ mensaje, String^ consejo) {
			   teclaPresionada = Direccion::Ninguno;
			   service->setVidas(service->getVidas() - 1);
			   // Restar criterio humano por tomar riesgo sin proteccion
			   int crit = service->getIndiceCriterio();
			   crit -= 5;                // cada golpe te baja 5 de criterio
			   if (crit < 0) crit = 0;   // clamp
			   service->setIndiceCriterio(crit);

			   // Reposicionar al jugador 
			   service->getJugador()->setX(700);
			   service->getJugador()->setY(200);

			   // Mostrar mensaje 
			   MessageBox::Show(mensaje + "\n" + consejo, "Alerta", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }

		   void VerificarCondicionesFin() {
			   int vidas = service->getVidas();
			   int est = service->getEstabilidadNave();
			   bool m1 = service->estaModuloCompletado(0);
			   bool m2 = service->estaModuloCompletado(1);
			   bool m3 = service->estaModuloCompletado(2);

			   // 1. CASO DERROTA 
			   if (vidas <= 0 || est <= 0) {
				   finPendiente = true;
				   finPendienteGano = false;

				   // Detener acciones
				   teclaPresionada = Direccion::Ninguno;
				   gestorSonido->DetenerSonidoBucle();
				   gestorSonido->DetenerMusica();
				   gestorSonido->ReproducirEfecto("EfectoGameOver.wav", 0.8);

				   string textoDerrota =
					   "Mision fallida...\n\n"
					   "La nave ya no puede sostenerse y tus decisiones no fueron suficientes para estabilizar el sistema.\n\n"
					   "No es solo 'responder mal': dejar problemas criticos sin priorizar a tiempo tambien tiene un costo.\n\n"
					   "Presiona X para ver el reporte de tu criterio humano.";

				   lblMensaje->Text = gcnew System::String(textoDerrota.c_str());
				   lblMensaje->Visible = true;
				   lblMensaje->BringToFront();
			   }
			   // 2. CASO VICTORIA
			   else if (m1 && m2 && m3 && est > 0 && vidas > 0) {

				   if (HayMensajeActivo()) return;
				   finPendiente = true;
				   finPendienteGano = true;
				   teclaPresionada = Direccion::Ninguno;
				   gestorSonido->DetenerSonidoBucle();

				   string textoVictoria =
					   "Mision completada.\n\n"
					   "Has estabilizado los modulos criticos de la nave y evitado el colapso.\n"
					   "No ganaste por adivinar, sino por analizar, priorizar y asumir consecuencias.\n\n"
					   "El criterio humano prevalecio sobre el caos del sistema.\n\n"
					   "Se acerca una lluvia de meteoritos....\n"
					   "Aliado IA restaurado, su nombre es R2D2, te ayudara a recargar municioneS. Sobrevive hasta llegar a tu destino.\n\n"
					   "Buena suerte.\n\n"
					   "Presiona X para continuar.";
				   lblMensaje->Text = gcnew System::String(textoVictoria.c_str());
				   lblMensaje->Visible = true;
				   lblMensaje->BringToFront();
			   }
		   }

		   // C. EJECUTAR EL CAMBIO DE FORMULARIO PARA ESTADISTICAS
		   void EjecutarFinDeJuego() {
			   timer1->Enabled = false;
			   timer1->Stop();

			   FrmFinMundoHumano^ fin = gcnew FrmFinMundoHumano(
				   finPendienteGano,
				   esModoHistoria,
				   service->getVidas(),
				   service->getEstabilidadNave(),
				   service->getIndiceCriterio(),
				   service->getProgresoMision()
			   );
			   this->Hide();//oculta este firnukario
			   // 2. Mostramos las estadísticas y ESPERAMOS la respuesta (OK o Cancel)
			   System::Windows::Forms::DialogResult respuesta = fin->ShowDialog();

			   // 3. PASAMOS LA RESPUESTA HACIA ARRIBA (Al FrmInicio)
			   if (respuesta == System::Windows::Forms::DialogResult::OK) {
				   // El usuario dio clic en "Siguiente Nivel"
				   this->DialogResult = System::Windows::Forms::DialogResult::OK;
			   }
			   else {
				   // El usuario dio clic en "Volver al Menú"
				   this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			   }

			   this->Close();
		   }

 		   // D. MENSAJES DE HISTORIA (Papel, Trajes, Voz)
 		   void VerificarMensajesHistoria() {
			   // 1. Mensaje del Papel
			   if (!mensajePapelActivo && !mensajePapelMostrado) {
				   if (service->hayColisionPapelSeñal(service->getJugador()->getRectangle())) {
					   gestorSonido->ReproducirEfecto("EfectoColisionRecurso.wav", 0.5);
					   mensajePapelActivo = true;
					   mensajePapelMostrado = true;
					   teclaPresionada = Direccion::Ninguno;

					   string txt =
						   "Explorador...\n\n"
						   "Si estas leyendo esto, es porque aqui las cosas se salieron de control.\n"
						   "Hubo decisiones rapidas, sistemas saturados y recursos mal usados.\n\n"
						   "La nave dejo de 'hablar' con la Tierra hace tiempo.\n"
						   "Mira a tu alrededor: cuando entiendas que parte guardaba su voz, "
						   "sabras por donde empezar a recuperarla.\n\n"
						   "- Un colega que aun cree en ti.";

					   lblMensaje->Text = gcnew System::String(txt.c_str());
					   lblMensaje->Visible = true;
					   lblMensaje->BringToFront();
				   }
			   }

			   // 2. Recoger Trajes
			   System::Drawing::Rectangle rectJugador = service->getJugador()->getRectangle();

			   if (!service->getTieneTrajeAntiElectricidad() && pbTrajeElecMapa->Visible) {
				   if (rectJugador.IntersectsWith(pbTrajeElecMapa->Bounds)) {
					   gestorSonido->ReproducirEfecto("EfectoColisionRecurso.wav", 0.5);
					   pbTrajeElecMapa->Visible = false;
					   service->setTieneTrajeAntiElectricidad(true);
					   pbPrototipoA->Visible = false;
					   btnUsarTrajeElec->Enabled = true;

					   if (service->estaModuloCompletado(2) && !mensajeTrajeElecMostrado) {
						   mensajeTrajeElecMostrado = true;
						   service->generarVozTerrestre();
						   MostrarMensajeTerrestre(
							   "Base terrestre...\n\n"
							   "Detectamos que recuperaste un traje aislante de alta resistencia.\n"
							   "Te protegera de descargas y cortocircuitos cerca de cables expuestos y chispas.\n\n"
							   "No elimina el riesgo, pero te permite acercarte con mas criterio a zonas electrificadas.Recuerda activarlo antes de cruzar areas con cables sueltos o chispas visibles.\n\n"
							   "Preciona los botones en el HUD para cambiar de traje cuando lo necesites.\n\n"
							   "Toca X para cerrar este mensaje."

						   );
					   }
				   }
			   }
			   if (!service->getTieneTrajeAntiGas() && pbTrajeGasMapa->Visible) {
				   if (rectJugador.IntersectsWith(pbTrajeGasMapa->Bounds)) {
					   gestorSonido->ReproducirEfecto("EfectoColisionRecurso.wav", 0.5);
					   pbTrajeGasMapa->Visible = false;
					   service->setTieneTrajeAntiGas(true);
					   pbPrototivoB->Visible = false;
					   btnUsarTrajeGas->Enabled = true;

					   if (service->estaModuloCompletado(2) && !mensajeTrajeGasMostrado) {
						   mensajeTrajeGasMostrado = true;
						   service->generarVozTerrestre();
						   MostrarMensajeTerrestre(
							   "Base terrestre...\n\n"
							   "Has obtenido un equipo de filtrado de gases.\n"
							   "Reducira el impacto de fugas toxicas y vapores inestables cerca de tanques y conductos.\n\n"
							   "Toca X para cerrar este mensaje."
						   );
					   }
				   }
			   }

			   // 3. Módulos Completados
			   if (service->estaModuloCompletado(0) && !mensajeModulo1Mostrado) {
				   mensajeModulo1Mostrado = true;
				   service->generarVozTerrestre();
				   MostrarMensajeTerrestre(
					   "Base terrestre...\n\n"
					   "Registro actualizado: el modulo de energia se encuentra estabilizado.\n"
					   "Has reducido el riesgo de sobrecargas y fallos en cadena en toda la nave.\n\n"
					   "Tu decision sobre que reparar primero marco la diferencia en la seguridad del sistema."
				   );
			   }
			   if (service->estaModuloCompletado(1) && !mensajeModulo2Mostrado) {
				   mensajeModulo2Mostrado = true;
				   service->generarVozTerrestre();
				   MostrarMensajeTerrestre(
					   "Base terrestre...\n\n"
					   "Los sensores indican que las fugas de gas estan contenidas.\n"
					   "El ambiente interno es ahora mucho mas seguro para cualquier futura tripulacion.\n\n"
					   "Controlar riesgos invisibles tambien es una forma de pensar con criterio."
				   );
			   }
			   // Comunicaciones (Módulo 3 - índice 2)
			   if (service->estaModuloCompletado(2) && !mensajeTerrestreMostrado) {
				   mensajeTerrestreMostrado = true;
				   service->generarVozTerrestre();
				   MostrarMensajeTerrestre(
					   "Canal restablecido...\n\n"
					   "Aqui base terrestre. Por fin recibimos tu señal.\n"
					   "Desde aqui solo podemos orientarte; las decisiones siguen siendo tuyas.\n\n"
					   "No esperes ordenes perfectas: confia en tu criterio humano para priorizar y decidir que reparar y cuando hacerlo."
				   );
			   }
		   }

		   void MostrarMensajeTerrestre(String^ texto) {
			   lblMensajeTerrestre->Text = texto;
			   lblMensajeTerrestre->Visible = true;
			   lblMensajeTerrestre->BringToFront();
			   teclaPresionada = Direccion::Ninguno;
		   }

		   // Helper para saber si hay algún mensaje en pantalla
		   bool HayMensajeActivo() {
			   return lblMensaje->Visible || lblMensajeTerrestre->Visible;
		   }

		   void ActualizarHUD() {
			   // 1. ACTUALIZAR BARRAS
			   int valEstabilidad = service->getEstabilidadNave();
			   int valCriterio = service->getIndiceCriterio();
			   int valProgreso = service->getProgresoMision();
			   // Asegurar límites (0 a 100)
			   valEstabilidad = Math::Max(0, Math::Min(100, valEstabilidad));
			   valCriterio = Math::Max(0, Math::Min(100, valCriterio));
			   valProgreso = Math::Max(0, Math::Min(100, valProgreso));

			   // BARRA ESTABILIDAD
			   if (pnlFondoEstabilidad != nullptr) {
				   int anchoTotal = pnlFondoEstabilidad->Width;
				   pnlBarraEstabilidad->Width = (valEstabilidad * anchoTotal) / 100;

				   if (valEstabilidad < 30) pnlBarraEstabilidad->BackColor = System::Drawing::Color::Red;
				   else pnlBarraEstabilidad->BackColor = System::Drawing::Color::LawnGreen;
			   }

			   // BARRA CRITERIO
			   if (pnlFondoCriterio != nullptr) {
				   int anchoTotal = pnlFondoCriterio->Width;
				   pnlBarraCriterio->Width = (valCriterio * anchoTotal) / 100;
			   }

			   // BARRA PROGRESO
			   if (pnlFondoProgreso != nullptr) {
				   int anchoTotal = pnlFondoProgreso->Width;
				   pnlBarraProgreso->Width = (valProgreso * anchoTotal) / 100;
			   }

			   // 2. ACTUALIZAR ICONOS DE VIDA 
			   int vidas = service->getVidas();

			   try {
				   String^ rutaFull = "VidaFull.png";
				   String^ rutaEmpty = "VidaEmpty.png";
				   if (vidas >= 1) pbVida1->Image = Image::FromFile(rutaFull);
				   else            pbVida1->Image = Image::FromFile(rutaEmpty);
				   if (vidas >= 2) pbVida2->Image = Image::FromFile(rutaFull);
				   else            pbVida2->Image = Image::FromFile(rutaEmpty);
				   if (vidas >= 3) pbVida3->Image = Image::FromFile(rutaFull);
				   else            pbVida3->Image = Image::FromFile(rutaEmpty);
			   }
			   catch (Exception^ ex) {
			   }
		   }

	private: void ConfigurarHUD() {
		// --- 1. ESTILOS MEJORADOS (Fuentes más grandes) ---
		System::Drawing::Font^ fuenteTitulos = gcnew System::Drawing::Font("Consolas", 11, FontStyle::Bold);
		System::Drawing::Font^ fuenteDatos = gcnew System::Drawing::Font("Consolas", 13, FontStyle::Bold);
		System::Drawing::Font^ fuenteBotones = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);

		System::Drawing::Color colorNeon = System::Drawing::Color::FromArgb(0, 217, 255);
		System::Drawing::Color colorTexto = System::Drawing::Color::White;
		System::Drawing::Color colorFondoBotones = System::Drawing::Color::FromArgb(13, 27, 42);

		// Vida 1
		pbVida1->Parent = pbHub;
		pbVida1->BackColor = System::Drawing::Color::Transparent;
		pbVida1->Location = Point(80, 185);

		// Vida 2
		pbVida2->Parent = pbHub;
		pbVida2->BackColor = System::Drawing::Color::Transparent;
		pbVida2->Location = Point(120, 185); 

		// Vida 3
		pbVida3->Parent = pbHub;
		pbVida3->BackColor = System::Drawing::Color::Transparent;
		pbVida3->Location = Point(160, 185); 

		pbVida1->BringToFront();
		pbVida2->BringToFront();
		pbVida3->BringToFront();

		// 2. POSICIONAR ETIQUETAS (Ajustado a la derecha) ---

		// Nombre Jugador
		lblNombreJugador->Parent = pbHub;
		lblNombreJugador->BackColor = System::Drawing::Color::Transparent;
		lblNombreJugador->ForeColor = colorNeon;
		lblNombreJugador->Font = fuenteDatos;
		lblNombreJugador->Text = "Nombre: " + Sesion::NombreJugador;
		lblNombreJugador->Location = Point(220, 60);

		
		// Título Estabilidad
		lblEstabilidad->Parent = pbHub;
		lblEstabilidad->BackColor = System::Drawing::Color::Transparent;
		lblEstabilidad->ForeColor = colorTexto;
		lblEstabilidad->Font = fuenteTitulos;
		lblEstabilidad->Text = "ESTABILIDAD NAVE";
		lblEstabilidad->Location = Point(85, 347); 

		// Título Criterio
		lblCriterio->Parent = pbHub;
		lblCriterio->BackColor = System::Drawing::Color::Transparent;
		lblCriterio->ForeColor = colorTexto;
		lblCriterio->Font = fuenteTitulos;
		lblCriterio->Text = "CRITERIO HUMANO";
		lblCriterio->Location = Point(85, 447);

		// Título Progreso
		lblProgreso->Parent = pbHub;
		lblProgreso->BackColor = System::Drawing::Color::Transparent;
		lblProgreso->ForeColor = colorTexto;
		lblProgreso->Font = fuenteTitulos;
		lblProgreso->Text = "PROGRESO MISION";
		lblProgreso->Location = Point(85, 537);

		// Título Equipo
		lblTituloEquipoProteccion->Parent = pbHub;
		lblTituloEquipoProteccion->BackColor = System::Drawing::Color::Transparent;
		lblTituloEquipoProteccion->ForeColor = colorNeon;
		lblTituloEquipoProteccion->Font = fuenteTitulos;
		lblTituloEquipoProteccion->Text = "EQUIPO DE PROTECCION";
		lblTituloEquipoProteccion->TextAlign = ContentAlignment::MiddleCenter;
		lblTituloEquipoProteccion->Location = Point(135, 680); 

		// --- 3. BOTONES ---
		ConfigurarBoton(btnUsarTrajeNormal, "BASE", colorFondoBotones, colorNeon, fuenteBotones);
		ConfigurarBoton(btnUsarTrajeElec, "PROTO A", colorFondoBotones, colorNeon, fuenteBotones);
		ConfigurarBoton(btnUsarTrajeGas, "PROTO B", colorFondoBotones, colorNeon, fuenteBotones);

		// Botón Salir
		btnSalir->FlatStyle = FlatStyle::Flat;
		btnSalir->FlatAppearance->BorderSize = 0;
		btnSalir->BackColor = System::Drawing::Color::Gold;
		btnSalir->ForeColor = System::Drawing::Color::Black;
		btnSalir->Font = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);
		btnSalir->BringToFront();
	}

	void ConfigurarBoton(Button^ btn, String^ texto, System::Drawing::Color fondo, System::Drawing::Color borde, System::Drawing::Font^ fuente) {
	   btn->Text = texto;
	   btn->FlatStyle = FlatStyle::Flat;
	   btn->BackColor = fondo;
	   btn->ForeColor = System::Drawing::Color::White;
	   btn->FlatAppearance->BorderColor = borde;
	   btn->FlatAppearance->BorderSize = 1;
	   btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(0, 50, 70);
	   btn->Font = fuente;
	   btn->Cursor = Cursors::Hand;
	   btn->BringToFront();
	}
	private: System::Void FrmMundoHumano_FormClosing(
			System::Object^ sender,
			System::Windows::Forms::FormClosingEventArgs^ e)
		{
			timer1->Enabled = false;
			timer1->Stop();
		}
	 
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		if (HayMensajeActivo()) {
			teclaPresionada = Direccion::Ninguno;
		}
		// FASE 1: TRANSICIÓN (SI EL JUEGO YA TERMINÓ)
		if (finPendiente) {
			if (HayMensajeActivo()) {
			}
			else {
				EjecutarFinDeJuego();
				return; 
			}
		}
		else {
			// FASE 2: JUEGO ACTIVO (Lógica normal)

			// 1. Mover Entidades
			service->moverJugador(teclaPresionada);
			service->moverAlertas();
			service->moverEnemigos();
			service->moverAliadoPapelSeñal();

			// 2. Lógica del Juego (Funciones separadas para orden)
			VerificarColisiones();      
			VerificarMensajesHistoria();  

			// 3. Sonido de Pasos
			if (teclaPresionada != Direccion::Ninguno) {
				if (!reproduciendoPasos) {
					gestorSonido->ReproducirSonidoBucle("PasosJugador.wav", 0.5);
					reproduciendoPasos = true;
				}
			}
			else {
				if (reproduciendoPasos) {
					gestorSonido->DetenerSonidoBucle();
					reproduciendoPasos = false;
				}
			}

			// 4. Verificar si Ganó o Perdió
			VerificarCondicionesFin();
		}

		// FASE 3: DIBUJADO (TU MÉTODO ORIGINAL)
		if (this->IsDisposed || pnlMundo == nullptr || pnlMundo->IsDisposed) return;

		Graphics^ canvas = pnlMundo->CreateGraphics();
		BufferedGraphicsContext^ espacio_buffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio_buffer->Allocate(canvas, pnlMundo->ClientRectangle);

		service->dibujarTodo(buffer->Graphics);
		buffer->Render(canvas);

		ActualizarHUD();

		delete buffer;
		delete canvas;
	}

	private: System::Void FrmMundoHumano_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		
		if (lblMensaje->Visible) {
			if (e->KeyCode == Keys::X) {
				lblMensaje->Visible = false;
				lblMensaje->Text = "";
			}
			return;  
		}

		if (lblMensajeTerrestre->Visible) {
			if (e->KeyCode == Keys::X) {
				lblMensajeTerrestre->Visible = false;
				lblMensajeTerrestre->Text = "";
				service->mostrarVozTerrestre(false);   
			}
			return;  
		}
		  
		switch (e->KeyCode) {
		case Keys::Up:
		case Keys::W:
			teclaPresionada = Direccion::Arriba;
			break;
		case Keys::Down:
		case Keys::S:
			teclaPresionada = Direccion::Abajo;
			break;
		case Keys::Left:
		case Keys::A:
			teclaPresionada = Direccion::Izquierda;
			break;
		case Keys::Right:
		case Keys::D:
			teclaPresionada = Direccion::Derecha;
			break;
		}
	
	}
	private: System::Void FrmMundoHumano_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		teclaPresionada = Direccion::Ninguno;
	}
	
	
	private: System::Void pnlMundo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	
	}
	
	
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		gestorSonido->DetenerMusica();
		gestorSonido->DetenerSonidoBucle(); 
		this->Close();
	}
	
	
	
	private: System::Void pbTrajeElecMapa_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnUsarTrajeElec_Click(System::Object^ sender, System::EventArgs^ e) {
		gestorSonido->ReproducirEfecto("EfectoCambioSking.wav", 0.4);
		if (service->getTieneTrajeAntiElectricidad()) {
			service->cambiarTraje(TipoTraje::AntiElectricidad);
			btnUsarTrajeElec->Enabled = false;
			btnUsarTrajeNormal->Enabled = true;
			if (service->getTieneTrajeAntiGas())
				btnUsarTrajeGas->Enabled = true;
		}
	}
	private: System::Void btnUsarTrajeGas_Click(System::Object^ sender, System::EventArgs^ e) {
		gestorSonido->ReproducirEfecto("EfectoCambioSking.wav", 0.4);
		if (service->getTieneTrajeAntiGas()) {
			service->cambiarTraje(TipoTraje::AntiGas);
			btnUsarTrajeGas->Enabled = false;
			btnUsarTrajeNormal->Enabled = true;
			if (service->getTieneTrajeAntiElectricidad())	
				btnUsarTrajeElec->Enabled = true;
		}
	}
	private: System::Void btnUsarTrajeNormal_Click(System::Object^ sender, System::EventArgs^ e) {
		gestorSonido->ReproducirEfecto("EfectoCambioSking.wav", 0.4);
		service->cambiarTraje(TipoTraje::Normal);
		btnUsarTrajeNormal->Enabled = false;
		if (service->getTieneTrajeAntiElectricidad())
			btnUsarTrajeElec->Enabled = true;
		if (service->getTieneTrajeAntiGas())
			btnUsarTrajeGas->Enabled = true;
	}

};
}
