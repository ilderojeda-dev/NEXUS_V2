#pragma once
#include "Mundo.h"
#include "FrmMundoHumano.h"
#include "FrmMundoIA.h"
#include "FrmMundoColab.h"

namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmInicio
	/// </summary>
	public ref class FrmInicio : public System::Windows::Forms::Form
	{
	public:
		FrmInicio(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
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


















	protected:

	private: System::Windows::Forms::Button^ brnMundoIA;
	protected:

	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ pnlFondo;
	private: System::Windows::Forms::Button^ btnVolver;
	private: System::Windows::Forms::Button^ btnNivel3;
	private: System::Windows::Forms::Button^ btnNivel2;
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
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->btnNivel3 = (gcnew System::Windows::Forms::Button());
			this->btnNivel2 = (gcnew System::Windows::Forms::Button());
			this->btnNivel1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnHistoria = (gcnew System::Windows::Forms::Button());
			this->btnNiveles = (gcnew System::Windows::Forms::Button());
			this->btnIniciarJuego = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->pnlFondo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
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
			this->pnlFondo->BackColor = System::Drawing::Color::LightCoral;
			this->pnlFondo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlFondo.BackgroundImage")));
			this->pnlFondo->Controls->Add(this->btnVolver);
			this->pnlFondo->Controls->Add(this->btnNivel3);
			this->pnlFondo->Controls->Add(this->btnNivel2);
			this->pnlFondo->Controls->Add(this->btnNivel1);
			this->pnlFondo->Controls->Add(this->pictureBox1);
			this->pnlFondo->Controls->Add(this->btnCreditos);
			this->pnlFondo->Controls->Add(this->btnHistoria);
			this->pnlFondo->Controls->Add(this->btnNiveles);
			this->pnlFondo->Controls->Add(this->btnIniciarJuego);
			this->pnlFondo->Controls->Add(this->btnSalir);
			this->pnlFondo->Location = System::Drawing::Point(-1, -3);
			this->pnlFondo->Name = L"pnlFondo";
			this->pnlFondo->Size = System::Drawing::Size(1922, 1086);
			this->pnlFondo->TabIndex = 3;
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
			this->btnVolver->Location = System::Drawing::Point(790, 934);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(349, 45);
			this->btnVolver->TabIndex = 9;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = false;
			this->btnVolver->Visible = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &FrmInicio::btnVolver_Click);
			// 
			// btnNivel3
			// 
			this->btnNivel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(118)));
			this->btnNivel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNivel3.BackgroundImage")));
			this->btnNivel3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNivel3->Location = System::Drawing::Point(1210, 338);
			this->btnNivel3->Name = L"btnNivel3";
			this->btnNivel3->Size = System::Drawing::Size(454, 549);
			this->btnNivel3->TabIndex = 8;
			this->btnNivel3->UseVisualStyleBackColor = false;
			this->btnNivel3->Visible = false;
			this->btnNivel3->Click += gcnew System::EventHandler(this, &FrmInicio::btnNivel3_Click);
			// 
			// btnNivel2
			// 
			this->btnNivel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(118)));
			this->btnNivel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNivel2.BackgroundImage")));
			this->btnNivel2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNivel2->Location = System::Drawing::Point(743, 338);
			this->btnNivel2->Name = L"btnNivel2";
			this->btnNivel2->Size = System::Drawing::Size(418, 549);
			this->btnNivel2->TabIndex = 7;
			this->btnNivel2->UseVisualStyleBackColor = false;
			this->btnNivel2->Visible = false;
			this->btnNivel2->Click += gcnew System::EventHandler(this, &FrmInicio::btnNivel2_Click);
			// 
			// btnNivel1
			// 
			this->btnNivel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(118)));
			this->btnNivel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNivel1.BackgroundImage")));
			this->btnNivel1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNivel1->Location = System::Drawing::Point(279, 338);
			this->btnNivel1->Name = L"btnNivel1";
			this->btnNivel1->Size = System::Drawing::Size(413, 546);
			this->btnNivel1->TabIndex = 6;
			this->btnNivel1->UseVisualStyleBackColor = false;
			this->btnNivel1->Visible = false;
			this->btnNivel1->Click += gcnew System::EventHandler(this, &FrmInicio::btnNivel1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(118)));
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(200, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1529, 1013);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackColor = System::Drawing::Color::Turquoise;
			this->btnCreditos->Cursor = System::Windows::Forms::Cursors::Default;
			this->btnCreditos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Segoe MDL2 Assets", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->Location = System::Drawing::Point(777, 789);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(323, 75);
			this->btnCreditos->TabIndex = 4;
			this->btnCreditos->Text = L"CREDITOS";
			this->btnCreditos->UseVisualStyleBackColor = false;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &FrmInicio::btnCreditos_Click);
			// 
			// btnHistoria
			// 
			this->btnHistoria->BackColor = System::Drawing::Color::Turquoise;
			this->btnHistoria->Cursor = System::Windows::Forms::Cursors::Default;
			this->btnHistoria->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHistoria->Font = (gcnew System::Drawing::Font(L"Segoe MDL2 Assets", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnHistoria->Location = System::Drawing::Point(777, 672);
			this->btnHistoria->Name = L"btnHistoria";
			this->btnHistoria->Size = System::Drawing::Size(323, 75);
			this->btnHistoria->TabIndex = 3;
			this->btnHistoria->Text = L"HISTORIA";
			this->btnHistoria->UseVisualStyleBackColor = false;
			this->btnHistoria->Click += gcnew System::EventHandler(this, &FrmInicio::btnHistoria_Click);
			// 
			// btnNiveles
			// 
			this->btnNiveles->BackColor = System::Drawing::Color::Turquoise;
			this->btnNiveles->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnNiveles->Cursor = System::Windows::Forms::Cursors::Default;
			this->btnNiveles->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNiveles->Font = (gcnew System::Drawing::Font(L"Segoe MDL2 Assets", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNiveles->Location = System::Drawing::Point(777, 560);
			this->btnNiveles->Name = L"btnNiveles";
			this->btnNiveles->Size = System::Drawing::Size(323, 75);
			this->btnNiveles->TabIndex = 2;
			this->btnNiveles->Text = L"NIVELES";
			this->btnNiveles->UseVisualStyleBackColor = false;
			this->btnNiveles->Click += gcnew System::EventHandler(this, &FrmInicio::btnNiveles_Click);
			// 
			// btnIniciarJuego
			// 
			this->btnIniciarJuego->BackColor = System::Drawing::Color::Turquoise;
			this->btnIniciarJuego->Cursor = System::Windows::Forms::Cursors::Default;
			this->btnIniciarJuego->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnIniciarJuego->Font = (gcnew System::Drawing::Font(L"Segoe MDL2 Assets", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIniciarJuego->Location = System::Drawing::Point(777, 451);
			this->btnIniciarJuego->Name = L"btnIniciarJuego";
			this->btnIniciarJuego->Size = System::Drawing::Size(323, 75);
			this->btnIniciarJuego->TabIndex = 1;
			this->btnIniciarJuego->Text = L"INICIAR JUEGO";
			this->btnIniciarJuego->UseVisualStyleBackColor = false;
			this->btnIniciarJuego->Click += gcnew System::EventHandler(this, &FrmInicio::btnIniciarJuego_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(844, 912);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(204, 75);
			this->btnSalir->TabIndex = 0;
			this->btnSalir->Text = L"SALIR";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmInicio::btnSalir_Click);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmInicio_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pnlFondo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnIniciarJuego_Click(System::Object^ sender, System::EventArgs^ e) {
		FrmMundoHumano^ frmMundoHumano = gcnew FrmMundoHumano();
		frmMundoHumano->Show();
		this->Hide();
	}
	private: System::Void btnNiveles_Click(System::Object^ sender, System::EventArgs^ e) {

		btnNivel1->Visible = true;
		btnNivel2->Visible = true;
		btnNivel3->Visible = true;
		btnVolver->Visible = true;
		pictureBox1->Visible = true;
	}

	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {

		btnNivel1->Visible = false;
		btnNivel2->Visible = false;
		btnNivel3->Visible = false;
		btnVolver->Visible = false;
		pictureBox1->Visible = false;

	}
	private: System::Void btnNivel2_Click(System::Object^ sender, System::EventArgs^ e) {
		FrmMundoHumano^ frmMundoHumano = gcnew FrmMundoHumano();
		frmMundoHumano->Show();
		this->Hide();
	}
private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
	//Agregar formulario de creditos
}
private: System::Void btnNivel1_Click(System::Object^ sender, System::EventArgs^ e) {
	FrmMundoIA^ frmMundoIA = gcnew FrmMundoIA();
	frmMundoIA->Show();
	this->Hide();

}
private: System::Void btnNivel3_Click(System::Object^ sender, System::EventArgs^ e) {
	FrmMundoColab^ frmMundoColab = gcnew FrmMundoColab();
	frmMundoColab->Show();
	this->Hide();
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}






private: System::Void btnHistoria_Click(System::Object^ sender, System::EventArgs^ e) {
}



};



	
}
