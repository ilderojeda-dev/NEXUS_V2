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
			gestorSonido = gcnew NEXUS_V2::Service::SoundManager();
			gestorSonido->ReproducirMusica("MusicaFondoMundoHumano.wav", 0.8); // Rep

			service = new MundoHumanoService(pnlMundo->Width, pnlMundo->Height, 3);
			char rutaFondo[] = "MundoHumano.png";
			service->cargarFondo(rutaFondo);
			gestorDialogo = new DialogoService();
			gestorDialogo->inicializarDialogos();
			
			service->generarAlertas();
			service->generarEnemigosCortoCircuito();
			service->generarEnemigosGasToxico();
			service->generarAliadoPapelSeñal();
			bufferImagen = gcnew Bitmap(pnlMundo->Width, pnlMundo->Height);
			bufferLapiz = Graphics::FromImage(bufferImagen);
			this->KeyPreview = true;
			this->SetStyle(ControlStyles::Selectable, false);//
			teclaPresionada = Direccion::Ninguno;
			lblMensajeTerrestre->Visible = false;
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
		
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnSalir;

	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Button^ btnPuntos;



	private: System::Windows::Forms::Button^ btnAbajo;


	private: NEXUS_V2::Service::SoundManager^ gestorSonido	;
		   bool reproduciendoPasos = false;
		   bool mensajePapelActivo = false;     // si está mostrando el mensaje ahora
		   
		  
		
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		MundoHumanoService* service;
		Direccion teclaPresionada;
		DialogoService* gestorDialogo;
		Bitmap^ bufferImagen;   // El "papel" en memoria
		Graphics^ bufferLapiz;
		bool mensajePapelMostrado = false;
		bool mensajeTerrestreMostrado = false;
		bool mensajeTrajeElecMostrado = false;
		bool mensajeTrajeGasMostrado = false;
		bool mensajeModulo1Mostrado = false;
		bool mensajeModulo2Mostrado = false;

		bool finDeMundoMostrado = false;
		bool finPendiente;      // hay fin de mundo esperando mostrar formulario
		bool finPendienteGano;  // true = ganó, false = perdió

	private: System::Windows::Forms::Label^ lblMensaje;
	private: System::Windows::Forms::ProgressBar^ pbEstabilidad;
	private: System::Windows::Forms::ProgressBar^ pbCriterio;
	private: System::Windows::Forms::ProgressBar^ pbProgreso;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pbTrajeGasMapa;
	private: System::Windows::Forms::PictureBox^ pbTrajeElecMapa;
	private: System::Windows::Forms::PictureBox^ pbTrajeElecHUD;
	private: System::Windows::Forms::PictureBox^ pbTrajeGasHUD;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::PictureBox^ pbTrajeNormalHUB;
private: System::Windows::Forms::Button^ btnUsarTrajeNormal;
private: System::Windows::Forms::Button^ btnUsarTrajeElec;
private: System::Windows::Forms::Button^ btnUsarTrajeGas;
private: System::Windows::Forms::PictureBox^ pbPrototipoA;
private: System::Windows::Forms::PictureBox^ pbPrototivoB;




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
			this->btnPuntos = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->btnAbajo = (gcnew System::Windows::Forms::Button());
			this->pbEstabilidad = (gcnew System::Windows::Forms::ProgressBar());
			this->pbCriterio = (gcnew System::Windows::Forms::ProgressBar());
			this->pbProgreso = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pbTrajeElecHUD = (gcnew System::Windows::Forms::PictureBox());
			this->pbTrajeGasHUD = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pbTrajeNormalHUB = (gcnew System::Windows::Forms::PictureBox());
			this->btnUsarTrajeNormal = (gcnew System::Windows::Forms::Button());
			this->btnUsarTrajeElec = (gcnew System::Windows::Forms::Button());
			this->btnUsarTrajeGas = (gcnew System::Windows::Forms::Button());
			this->pbPrototipoA = (gcnew System::Windows::Forms::PictureBox());
			this->pbPrototivoB = (gcnew System::Windows::Forms::PictureBox());
			this->pnlMundo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeGasMapa))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeElecMapa))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeElecHUD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeGasHUD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeNormalHUB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPrototipoA))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPrototivoB))->BeginInit();
			this->SuspendLayout();
			// 
			// pnlMundo
			// 
			this->pnlMundo->BackColor = System::Drawing::Color::LavenderBlush;
			this->pnlMundo->Controls->Add(this->pbTrajeGasMapa);
			this->pnlMundo->Controls->Add(this->pbTrajeElecMapa);
			this->pnlMundo->Controls->Add(this->lblMensajeTerrestre);
			this->pnlMundo->Controls->Add(this->lblMensaje);
			this->pnlMundo->Controls->Add(this->btnPuntos);
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
			// btnPuntos
			// 
			this->btnPuntos->Location = System::Drawing::Point(1382, 13);
			this->btnPuntos->Name = L"btnPuntos";
			this->btnPuntos->Size = System::Drawing::Size(75, 23);
			this->btnPuntos->TabIndex = 0;
			this->btnPuntos->Text = L"button1";
			this->btnPuntos->UseVisualStyleBackColor = true;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMundoHumano::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(1493, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(428, 1080);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::Gold;
			this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->btnSalir->Location = System::Drawing::Point(1670, 990);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(114, 48);
			this->btnSalir->TabIndex = 2;
			this->btnSalir->TabStop = false;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmMundoHumano::btnSalir_Click);
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->lblVidas->Font = (gcnew System::Drawing::Font(L"Snap ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVidas->ForeColor = System::Drawing::Color::Yellow;
			this->lblVidas->Location = System::Drawing::Point(1563, 128);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(17, 22);
			this->lblVidas->TabIndex = 4;
			this->lblVidas->Text = L"-";
			// 
			// btnAbajo
			// 
			this->btnAbajo->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btnAbajo->Location = System::Drawing::Point(1699, 300);
			this->btnAbajo->Name = L"btnAbajo";
			this->btnAbajo->Size = System::Drawing::Size(75, 23);
			this->btnAbajo->TabIndex = 7;
			this->btnAbajo->Text = L"Abajo";
			this->btnAbajo->UseVisualStyleBackColor = true;
			this->btnAbajo->Click += gcnew System::EventHandler(this, &FrmMundoHumano::btnAbajo_Click);
			// 
			// pbEstabilidad
			// 
			this->pbEstabilidad->BackColor = System::Drawing::Color::IndianRed;
			this->pbEstabilidad->Cursor = System::Windows::Forms::Cursors::Default;
			this->pbEstabilidad->ForeColor = System::Drawing::Color::Yellow;
			this->pbEstabilidad->Location = System::Drawing::Point(1542, 338);
			this->pbEstabilidad->Name = L"pbEstabilidad";
			this->pbEstabilidad->Size = System::Drawing::Size(318, 23);
			this->pbEstabilidad->TabIndex = 10;
			// 
			// pbCriterio
			// 
			this->pbCriterio->Location = System::Drawing::Point(1542, 439);
			this->pbCriterio->Name = L"pbCriterio";
			this->pbCriterio->Size = System::Drawing::Size(318, 23);
			this->pbCriterio->TabIndex = 11;
			// 
			// pbProgreso
			// 
			this->pbProgreso->Location = System::Drawing::Point(1542, 533);
			this->pbProgreso->Name = L"pbProgreso";
			this->pbProgreso->Size = System::Drawing::Size(318, 23);
			this->pbProgreso->TabIndex = 12;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Snap ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Yellow;
			this->label1->Location = System::Drawing::Point(1538, 299);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(249, 22);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Estabilidad de la nave: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Snap ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Yellow;
			this->label2->Location = System::Drawing::Point(1538, 414);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(178, 22);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Criterio humano:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Snap ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Yellow;
			this->label3->Location = System::Drawing::Point(1540, 496);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(234, 22);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Progreso de la mision:";
			// 
			// pbTrajeElecHUD
			// 
			this->pbTrajeElecHUD->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->pbTrajeElecHUD->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbTrajeElecHUD.Image")));
			this->pbTrajeElecHUD->Location = System::Drawing::Point(1658, 722);
			this->pbTrajeElecHUD->Name = L"pbTrajeElecHUD";
			this->pbTrajeElecHUD->Size = System::Drawing::Size(106, 134);
			this->pbTrajeElecHUD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbTrajeElecHUD->TabIndex = 16;
			this->pbTrajeElecHUD->TabStop = false;
			this->pbTrajeElecHUD->Click += gcnew System::EventHandler(this, &FrmMundoHumano::pbTrajeElecHUD_Click);
			// 
			// pbTrajeGasHUD
			// 
			this->pbTrajeGasHUD->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->pbTrajeGasHUD->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbTrajeGasHUD.Image")));
			this->pbTrajeGasHUD->Location = System::Drawing::Point(1785, 722);
			this->pbTrajeGasHUD->Name = L"pbTrajeGasHUD";
			this->pbTrajeGasHUD->Size = System::Drawing::Size(106, 134);
			this->pbTrajeGasHUD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbTrajeGasHUD->TabIndex = 17;
			this->pbTrajeGasHUD->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Snap ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Crimson;
			this->label4->Location = System::Drawing::Point(1599, 683);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(219, 22);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Equipo de protección";
			this->label4->Click += gcnew System::EventHandler(this, &FrmMundoHumano::label4_Click);
			// 
			// pbTrajeNormalHUB
			// 
			this->pbTrajeNormalHUB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->pbTrajeNormalHUB->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbTrajeNormalHUB.Image")));
			this->pbTrajeNormalHUB->Location = System::Drawing::Point(1526, 722);
			this->pbTrajeNormalHUB->Name = L"pbTrajeNormalHUB";
			this->pbTrajeNormalHUB->Size = System::Drawing::Size(106, 134);
			this->pbTrajeNormalHUB->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbTrajeNormalHUB->TabIndex = 20;
			this->pbTrajeNormalHUB->TabStop = false;
			// 
			// btnUsarTrajeNormal
			// 
			this->btnUsarTrajeNormal->Enabled = false;
			this->btnUsarTrajeNormal->Location = System::Drawing::Point(1542, 873);
			this->btnUsarTrajeNormal->Name = L"btnUsarTrajeNormal";
			this->btnUsarTrajeNormal->Size = System::Drawing::Size(75, 45);
			this->btnUsarTrajeNormal->TabIndex = 21;
			this->btnUsarTrajeNormal->Text = L"Traje base";
			this->btnUsarTrajeNormal->UseVisualStyleBackColor = true;
			this->btnUsarTrajeNormal->Click += gcnew System::EventHandler(this, &FrmMundoHumano::btnUsarTrajeNormal_Click);
			// 
			// btnUsarTrajeElec
			// 
			this->btnUsarTrajeElec->Enabled = false;
			this->btnUsarTrajeElec->Location = System::Drawing::Point(1679, 873);
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
			this->btnUsarTrajeGas->Location = System::Drawing::Point(1805, 873);
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
			this->pbPrototipoA->Location = System::Drawing::Point(1658, 722);
			this->pbPrototipoA->Name = L"pbPrototipoA";
			this->pbPrototipoA->Size = System::Drawing::Size(106, 134);
			this->pbPrototipoA->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbPrototipoA->TabIndex = 24;
			this->pbPrototipoA->TabStop = false;
			// 
			// pbPrototivoB
			// 
			this->pbPrototivoB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->pbPrototivoB->Location = System::Drawing::Point(1785, 722);
			this->pbPrototivoB->Name = L"pbPrototivoB";
			this->pbPrototivoB->Size = System::Drawing::Size(106, 134);
			this->pbPrototivoB->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbPrototivoB->TabIndex = 25;
			this->pbPrototivoB->TabStop = false;
			// 
			// FrmMundoHumano
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1920, 1080);
			this->Controls->Add(this->pbPrototivoB);
			this->Controls->Add(this->pbPrototipoA);
			this->Controls->Add(this->btnUsarTrajeGas);
			this->Controls->Add(this->btnUsarTrajeElec);
			this->Controls->Add(this->btnUsarTrajeNormal);
			this->Controls->Add(this->pbTrajeNormalHUB);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pbTrajeGasHUD);
			this->Controls->Add(this->pbTrajeElecHUD);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pbProgreso);
			this->Controls->Add(this->pbCriterio);
			this->Controls->Add(this->pbEstabilidad);
			this->Controls->Add(this->btnAbajo);
			this->Controls->Add(this->lblVidas);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->pictureBox1);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeElecHUD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeGasHUD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTrajeNormalHUB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPrototipoA))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPrototivoB))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void FrmMundoHumano_Load(System::Object^ sender, System::EventArgs^ e) {
		timer1->Start();

	}
		   // ---------------------------------------------------------
		   // A. VERIFICAR COLISIONES (Enemigos y Puzzles)
		   // ---------------------------------------------------------
		   void VerificarColisiones() {
			   Rectangle rectJugador = service->getJugador()->getRectangle();

			   // 1. COLISIÓN CON ENEMIGOS (Tu código original recuperado)
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

					   // Daño por Gas
					   if (gas != nullptr && traje != TipoTraje::AntiGas) {
						   AplicarDaño("Has inhalado gas toxico. Pierdes 1 vida.",
							   "Tal vez deberias usar otro equipo.");
					   }
					   // Daño por Electricidad
					   else if (corto != nullptr && traje != TipoTraje::AntiElectricidad) {
						   AplicarDaño("Has recibido una descarga electrica. Pierdes 1 vida.",
							   "Usa proteccion adecuada.");
					   }
				   }
			   }

			   // 2. COLISIÓN CON PUZZLES (Módulos)
			   int puzzleColision = service->verificarColisionAlerta();
			   if (puzzleColision != -1) {
				   teclaPresionada = Direccion::Ninguno;
				   gestorSonido->DetenerSonidoBucle();
				   reproduciendoPasos = false;

				   timer1->Stop(); // Pausar timer para evitar bugs visuales

				   switch (puzzleColision) {
				   case 0: { FrmModulo1^ m = gcnew FrmModulo1(service); m->ShowDialog(); break; }
				   case 1: { FrmModulo2^ m = gcnew FrmModulo2(service); m->ShowDialog(); break; }
				   case 2: { FrmModulo3^ m = gcnew FrmModulo3(service); m->ShowDialog(); break; }
						 // case 3: { FrmModulo4^ m = gcnew FrmModulo4(); m->ShowDialog(); break; }
				   }

				   timer1->Start(); // Reanudar
				   teclaPresionada = Direccion::Ninguno;
			   }
		   }

		   // Helper para restar vida y mostrar mensaje
		   void AplicarDaño(String^ mensaje, String^ consejo) {
			   teclaPresionada = Direccion::Ninguno;

			   // Restar vida
			   service->setVidas(service->getVidas() - 1);

			   // Reposicionar al jugador (Respawn seguro)
			   service->getJugador()->setX(700);
			   service->getJugador()->setY(200);

			   // Mostrar mensaje (Esto pausa la ejecución momentáneamente)
			   MessageBox::Show(mensaje + "\n" + consejo, "Alerta", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }

		   void VerificarCondicionesFin() {
			   int vidas = service->getVidas();
			   int est = service->getEstabilidadNave();
			   bool m1 = service->estaModuloCompletado(0);
			   bool m2 = service->estaModuloCompletado(1);
			   bool m3 = service->estaModuloCompletado(2);

			   // 1. CASO DERROTA (Prioridad Máxima: Si mueres, mueres al instante)
			   if (vidas <= 0 || est <= 0) {
				   finPendiente = true;
				   finPendienteGano = false;

				   // Detener acciones
				   teclaPresionada = Direccion::Ninguno;
				   gestorSonido->DetenerSonidoBucle();
				   gestorSonido->DetenerMusica();

				   std::string textoDerrota = "Mision Fallida...\n\nLa nave colapso o perdiste tus signos vitales.\nPresiona ENTER para ver el reporte.";

				   // Usamos tu función helper si la tienes, o el código directo:
				   lblMensaje->Text = gcnew System::String(textoDerrota.c_str());
				   lblMensaje->Visible = true;
				   lblMensaje->BringToFront();
			   }
			   // 2. CASO VICTORIA (Prioridad Baja: Espera turno)
			   else if (m1 && m2 && m3 && est > 0 && vidas > 0) {

				   // --- ¡AQUÍ ESTÁ LA CORRECCIÓN! ---
				   // Si todavía se está mostrando el mensaje del último módulo ("Canal Restablecido"),
				   // NO hacemos nada. El Timer volverá a intentar en el siguiente ciclo.
				   if (HayMensajeActivo()) return;
				   // ---------------------------------

				   finPendiente = true;
				   finPendienteGano = true;

				   teclaPresionada = Direccion::Ninguno;
				   gestorSonido->DetenerSonidoBucle();

				   std::string textoVictoria = "Mision Completada.\n\nSistemas criticos estables.\nEl criterio humano ha prevalecido.\n\nPresiona ENTER para continuar.";

				   lblMensaje->Text = gcnew System::String(textoVictoria.c_str());
				   lblMensaje->Visible = true;
				   lblMensaje->BringToFront();
			   }
		   }
		   // ---------------------------------------------------------
		   // C. EJECUTAR EL CAMBIO DE FORMULARIO
		   // ---------------------------------------------------------
		   void EjecutarFinDeJuego() {
			   timer1->Enabled = false;
			   timer1->Stop();

			   FrmFinMundoHumano^ fin = gcnew FrmFinMundoHumano(
				   finPendienteGano,
				   service->getVidas(),
				   service->getEstabilidadNave(),
				   service->getIndiceCriterio(),
				   service->getProgresoMision()
			   );

			   this->Hide(); // Ocultar este mundo
			   fin->ShowDialog(); // Mostrar estadísticas
			   this->Close(); // Cerrar definitivamente
		   }

		   // ---------------------------------------------------------
		   // D. MENSAJES DE HISTORIA (Papel, Trajes, Voz)
		   // ---------------------------------------------------------
		   void VerificarMensajesHistoria() {
			   // 1. Mensaje del Papel
			   if (!mensajePapelActivo && !mensajePapelMostrado) {
				   if (service->hayColisionPapelSeñal(service->getJugador()->getRectangle())) {
					   mensajePapelActivo = true;
					   mensajePapelMostrado = true;
					   teclaPresionada = Direccion::Ninguno;

					   std::string txt = "Explorador...\nSi lees esto, las cosas salieron mal.\nDecisiones apresuradas, sistemas saturados.\n\nEl corazon de la nave dejo de hablar.\nMira a tu alrededor para empezar.";
					   lblMensaje->Text = gcnew System::String(txt.c_str());
					   lblMensaje->Visible = true;
					   lblMensaje->BringToFront();
				   }
			   }

			   // 2. Recoger Trajes
			   Rectangle rectJugador = service->getJugador()->getRectangle();

			   // Traje Azul
			   if (!service->getTieneTrajeAntiElectricidad() && pbTrajeElecMapa->Visible) {
				   if (rectJugador.IntersectsWith(pbTrajeElecMapa->Bounds)) {
					   pbTrajeElecMapa->Visible = false;
					   service->setTieneTrajeAntiElectricidad(true);
					   pbPrototipoA->Visible = false;
					   btnUsarTrajeElec->Enabled = true;

					   if (service->estaModuloCompletado(2) && !mensajeTrajeElecMostrado) {
						   mensajeTrajeElecMostrado = true;
						   service->generarVozTerrestre();
						   MostrarMensajeTerrestre("Base terrestre...\nDetectamos traje antielectrico.\nProtege de descargas.");
					   }
				   }
			   }
			   // Traje Naranja
			   if (!service->getTieneTrajeAntiGas() && pbTrajeGasMapa->Visible) {
				   if (rectJugador.IntersectsWith(pbTrajeGasMapa->Bounds)) {
					   pbTrajeGasMapa->Visible = false;
					   service->setTieneTrajeAntiGas(true);
					   pbPrototivoB->Visible = false;
					   btnUsarTrajeGas->Enabled = true;

					   if (service->estaModuloCompletado(2) && !mensajeTrajeGasMostrado) {
						   mensajeTrajeGasMostrado = true;
						   service->generarVozTerrestre();
						   MostrarMensajeTerrestre("Base terrestre...\nTraje antigas obtenido.\nReduce riesgo en zonas toxicas.");
					   }
				   }
			   }

			   // 3. Módulos Completados
			   if (service->estaModuloCompletado(0) && !mensajeModulo1Mostrado) {
				   mensajeModulo1Mostrado = true;
				   service->generarVozTerrestre();
				   MostrarMensajeTerrestre("Base terrestre...\nModulo de energia estabilizado.\nRiesgo de sobrecarga reducido.");
			   }
			   if (service->estaModuloCompletado(1) && !mensajeModulo2Mostrado) {
				   mensajeModulo2Mostrado = true;
				   service->generarVozTerrestre();
				   MostrarMensajeTerrestre("Base terrestre...\nFugas de gas controladas.\nAmbiente estabilizado.");
			   }
			   // Comunicaciones (Módulo 3 - índice 2)
			   if (service->estaModuloCompletado(2) && !mensajeTerrestreMostrado) {
				   mensajeTerrestreMostrado = true;
				   service->generarVozTerrestre();
				   MostrarMensajeTerrestre("Canal restablecido.\nAqui base terrestre.\nConfia en tu criterio humano.");
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
			   int esta = service->getEstabilidadNave();
			   int crite = service->getIndiceCriterio();
			   int progre = service->getProgresoMision();

			   pbEstabilidad->Value = Math::Max(0, Math::Min(100, esta));
			   pbCriterio->Value = Math::Max(0, Math::Min(100, crite));
			   pbProgreso->Value = Math::Max(0, Math::Min(100, progre));

			   lblVidas->Text = "Vidas: " + Convert::ToString(service->getVidas());

			   
		   }
	private: System::Void FrmMundoHumano_FormClosing(
			System::Object^ sender,
			System::Windows::Forms::FormClosingEventArgs^ e)
		{
			timer1->Enabled = false;
			timer1->Stop();
		}
	 
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		// =======================================================
		// FASE 1: TRANSICIÓN (SI EL JUEGO YA TERMINÓ)
		// =======================================================
		if (finPendiente) {
			// El juego ya terminó (ganó o perdió).
			// ¿Hay un mensaje en pantalla (Label) que el usuario está leyendo?
			if (HayMensajeActivo()) {
				// SI: No hacemos nada lógico. Solo dejamos que dibuje (Fase 3)
				// para que la pantalla no se congele.
			}
			else {
				// NO: El usuario ya cerró el mensaje.
				// Ahora sí cambiamos de formulario.
				EjecutarFinDeJuego();
				return; // Cortamos aquí.
			}
		}
		else {
			// =======================================================
			// FASE 2: JUEGO ACTIVO (Lógica normal)
			// =======================================================

			// 1. Mover Entidades
			service->moverJugador(teclaPresionada);
			service->moverAlertas();
			service->moverEnemigos();
			service->moverAliadoPapelSeñal();

			// 2. Lógica del Juego (Funciones separadas para orden)
			VerificarColisiones();       // Enemigos y Puzzles
			VerificarMensajesHistoria(); // Textos de trama (Papel, Trajes)

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
			// Esta función activará 'finPendiente' si es necesario
			VerificarCondicionesFin();
		}

		// =======================================================
		// FASE 3: DIBUJADO (Siempre se ejecuta)
		// =======================================================
		if (this->IsDisposed || pnlMundo == nullptr || pnlMundo->IsDisposed) return;

		// 1. Buffer Manual (Para velocidad y evitar parpadeo)
		// Asegúrate de tener bufferLapiz y bufferImagen inicializados en el constructor
		if (bufferLapiz != nullptr) {
			bufferLapiz->Clear(System::Drawing::Color::LavenderBlush); // Limpiar fondo
			service->dibujarTodo(bufferLapiz);        // Dibujar juego

			// Dibujar en pantalla
			Graphics^ pantalla = pnlMundo->CreateGraphics();
			pantalla->DrawImageUnscaled(bufferImagen, 0, 0);
			delete pantalla;
		}

		// 2. Actualizar Barras y Textos
		ActualizarHUD();
	}

	private: System::Void FrmMundoHumano_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		// 1) Si está abierto el mensaje del papel, se cierra
		if (lblMensaje->Visible) {
			if (e->KeyCode == Keys::Enter || e->KeyCode == Keys::Space) {
				lblMensaje->Visible = false;
				lblMensaje->Text = "";
			}
			return;  // no mover mientras el mensaje está abierto
		}

		// 2) Si está abierto el mensaje terrestre, se cierra y apagamos el panel
		if (lblMensajeTerrestre->Visible) {
			if (e->KeyCode == Keys::Enter || e->KeyCode == Keys::Space) {
				lblMensajeTerrestre->Visible = false;
				lblMensajeTerrestre->Text = "";
				service->mostrarVozTerrestre(false);   
			}
			return;  // tampoco se mueve
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
	gestorSonido->DetenerSonidoBucle(); // Por si te fuiste caminando

	// 2. Cerrar este formulario (Esto disparará el evento en el menú)
	this->Close();
	
}


private: System::Void btnArriba_Click(System::Object^ sender, System::EventArgs^ e) {
	//Si se preciona el boton arriba mover boton 3 puntos arriba
	btnPuntos->Top -= 10;
	
}

private: System::Void btnIzquierda_Click(System::Object^ sender, System::EventArgs^ e) {
	//Si se preciona el boton izquierda mover boton 3 puntos a la izquierda
	btnPuntos->Left -= 10;
}
private: System::Void btnDerecha_Click(System::Object^ sender, System::EventArgs^ e) {
	//Si se preciona el boton derecha mover boton 3 puntos a la derecha
	btnPuntos->Left += 10;
}
private: System::Void btnAbajo_Click(System::Object^ sender, System::EventArgs^ e) {
	//Si se preciona el boton abajo mover boton 3 puntos abajo
	btnPuntos->Top += 10;
}

private: System::Void pbTrajeElecMapa_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnUsarTrajeElec_Click(System::Object^ sender, System::EventArgs^ e) {
	if (service->getTieneTrajeAntiElectricidad()) {
		service->cambiarTraje(TipoTraje::AntiElectricidad);
		btnUsarTrajeElec->Enabled = false;
		btnUsarTrajeNormal->Enabled = true;
		if (service->getTieneTrajeAntiGas())
			btnUsarTrajeGas->Enabled = true;
	}
}
private: System::Void btnUsarTrajeGas_Click(System::Object^ sender, System::EventArgs^ e) {
	if (service->getTieneTrajeAntiGas()) {
		service->cambiarTraje(TipoTraje::AntiGas);
		btnUsarTrajeGas->Enabled = false;
		btnUsarTrajeNormal->Enabled = true;
		if (service->getTieneTrajeAntiElectricidad())	
			btnUsarTrajeElec->Enabled = true;
	}
}
private: System::Void btnUsarTrajeNormal_Click(System::Object^ sender, System::EventArgs^ e) {
	service->cambiarTraje(TipoTraje::Normal);
	btnUsarTrajeNormal->Enabled = false;
	if (service->getTieneTrajeAntiElectricidad())
		btnUsarTrajeElec->Enabled = true;
	if (service->getTieneTrajeAntiGas())
		btnUsarTrajeGas->Enabled = true;
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pbTrajeElecHUD_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
