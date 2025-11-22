#pragma once
#include "MundoHumanoService.h"
#include "Jugador.h"
#include "FrmModulo1.h"
#include "FrmModulo2.h"
#include "FrmModulo3.h"
#include "FrmModulo4.h"


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
			service = new MundoHumanoService(pnlMundo->Width, pnlMundo->Height, 3);
			char rutaFondo[] = "MundoHumano.png";
			service->cargarFondo(rutaFondo);

			char rutaJugador[] = "Astronauta.png"; //aqui se pasa el path de la imagen del jugador
			service->cargarSpriteJugador(rutaJugador, 4, 4);
			service->generarAlertas();
			this->KeyPreview = true;
			this->SetStyle(ControlStyles::Selectable, false);//
			teclaPresionada = Direccion::Ninguno;  

		


			


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
		Direccion teclaPresionada;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnSalir;

	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Button^ btnPuntos;
	private: System::Windows::Forms::Label^ lblPosY;
	private: System::Windows::Forms::Label^ lblPosX;
	private: System::Windows::Forms::Button^ btnArriba;
	private: System::Windows::Forms::Button^ btnAbajo;
	private: System::Windows::Forms::Button^ btnDerecha;
	private: System::Windows::Forms::Button^ btnIzquierda;









	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		MundoHumanoService* service;
	
		


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
			this->btnPuntos = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->lblPosY = (gcnew System::Windows::Forms::Label());
			this->lblPosX = (gcnew System::Windows::Forms::Label());
			this->btnArriba = (gcnew System::Windows::Forms::Button());
			this->btnAbajo = (gcnew System::Windows::Forms::Button());
			this->btnDerecha = (gcnew System::Windows::Forms::Button());
			this->btnIzquierda = (gcnew System::Windows::Forms::Button());
			this->pnlMundo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pnlMundo
			// 
			this->pnlMundo->BackColor = System::Drawing::Color::LavenderBlush;
			this->pnlMundo->Controls->Add(this->btnPuntos);
			this->pnlMundo->Location = System::Drawing::Point(0, -1);
			this->pnlMundo->Name = L"pnlMundo";
			this->pnlMundo->Size = System::Drawing::Size(1498, 1080);
			this->pnlMundo->TabIndex = 0;
			this->pnlMundo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMundoHumano::pnlMundo_Paint);
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
			this->lblVidas->Location = System::Drawing::Point(1564, 156);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(17, 22);
			this->lblVidas->TabIndex = 4;
			this->lblVidas->Text = L"-";
			// 
			// lblPosY
			// 
			this->lblPosY->AutoSize = true;
			this->lblPosY->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->lblPosY->Font = (gcnew System::Drawing::Font(L"Snap ITC", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPosY->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lblPosY->Location = System::Drawing::Point(1553, 82);
			this->lblPosY->Name = L"lblPosY";
			this->lblPosY->Size = System::Drawing::Size(16, 22);
			this->lblPosY->TabIndex = 5;
			this->lblPosY->Text = L"-";
			// 
			// lblPosX
			// 
			this->lblPosX->AutoSize = true;
			this->lblPosX->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->lblPosX->Font = (gcnew System::Drawing::Font(L"Snap ITC", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPosX->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lblPosX->Location = System::Drawing::Point(1710, 82);
			this->lblPosX->Name = L"lblPosX";
			this->lblPosX->Size = System::Drawing::Size(16, 22);
			this->lblPosX->TabIndex = 6;
			this->lblPosX->Text = L"-";
			this->lblPosX->Click += gcnew System::EventHandler(this, &FrmMundoHumano::lblPosX_Click);
			// 
			// btnArriba
			// 
			this->btnArriba->Location = System::Drawing::Point(1699, 217);
			this->btnArriba->Name = L"btnArriba";
			this->btnArriba->Size = System::Drawing::Size(75, 23);
			this->btnArriba->TabIndex = 1;
			this->btnArriba->Text = L"Arriba";
			this->btnArriba->UseVisualStyleBackColor = true;
			this->btnArriba->Click += gcnew System::EventHandler(this, &FrmMundoHumano::btnArriba_Click);
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
			// btnDerecha
			// 
			this->btnDerecha->Location = System::Drawing::Point(1756, 254);
			this->btnDerecha->Name = L"btnDerecha";
			this->btnDerecha->Size = System::Drawing::Size(75, 23);
			this->btnDerecha->TabIndex = 8;
			this->btnDerecha->Text = L"Derecha";
			this->btnDerecha->UseVisualStyleBackColor = true;
			this->btnDerecha->Click += gcnew System::EventHandler(this, &FrmMundoHumano::btnDerecha_Click);
			// 
			// btnIzquierda
			// 
			this->btnIzquierda->Location = System::Drawing::Point(1638, 256);
			this->btnIzquierda->Name = L"btnIzquierda";
			this->btnIzquierda->Size = System::Drawing::Size(75, 23);
			this->btnIzquierda->TabIndex = 9;
			this->btnIzquierda->Text = L"Izquierda";
			this->btnIzquierda->UseVisualStyleBackColor = true;
			this->btnIzquierda->Click += gcnew System::EventHandler(this, &FrmMundoHumano::btnIzquierda_Click);
			// 
			// FrmMundoHumano
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1920, 1080);
			this->Controls->Add(this->btnIzquierda);
			this->Controls->Add(this->btnDerecha);
			this->Controls->Add(this->btnAbajo);
			this->Controls->Add(this->btnArriba);
			this->Controls->Add(this->lblPosX);
			this->Controls->Add(this->lblPosY);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FrmMundoHumano_Load(System::Object^ sender, System::EventArgs^ e) {
		timer1->Start();

	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {


		int colision = service->verificarColisionAlerta();

		switch (colision) {

		case 0: {
			FrmModulo1^ m = gcnew FrmModulo1();
			m->Show();
			break;
		}
		case 1: {
			FrmModulo2^ m = gcnew FrmModulo2();
			m->Show();
			break;
		}
		case 2: {
			FrmModulo3^ m = gcnew FrmModulo3();
			m->Show();
			break;
		}
		case 3: {
			FrmModulo4^ m = gcnew FrmModulo4();
			m->Show();
			break;
		}
		}

		service->moverAlertas();


		service->moverJugador(teclaPresionada);
		Graphics^ canvas = pnlMundo->CreateGraphics();
		BufferedGraphicsContext^ espacio_buffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio_buffer->Allocate(canvas, pnlMundo->ClientRectangle);

		service->dibujarTodo(buffer->Graphics);
		buffer->Render(canvas);
		lblVidas->Text = "Vidas: " + Convert::ToString(service->getVidas());
		//mostras la posición del btnPuntos en las etiquetas lblPosX y lblPosY
		lblPosX->Text = "Pos X: " + Convert::ToString(btnPuntos->Left);
		lblPosY->Text = "Pos Y: " + Convert::ToString(btnPuntos->Top);


		delete buffer;
		delete canvas;


	}
	private: System::Void FrmMundoHumano_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
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
private: System::Void lblPosX_Click(System::Object^ sender, System::EventArgs^ e) {
}

};
}
