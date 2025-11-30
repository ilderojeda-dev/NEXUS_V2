#pragma once
#include "MundoHumanoService.h"
#include <vector>
#include "SoundManager.h"
namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmModulo3
	/// </summary>
	public ref class FrmModulo3 : public System::Windows::Forms::Form
	{
	public:
		FrmModulo3(MundoHumanoService* serviceRef)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			service = serviceRef;
			generarNumerosAleatoreos();
			gestorSonido = gcnew NEXUS_V2::Service::SoundManager();
			

			

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmModulo3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlModulo3;
	private: System::Windows::Forms::Button^ btnOeste;
	private: System::Windows::Forms::Button^ btnSur;
	private: System::Windows::Forms::Button^ btnEste;
	private: System::Windows::Forms::Button^ btnNorte;
	private: NEXUS_V2::Service::SoundManager^ gestorSonido;
	private: System::Windows::Forms::PictureBox^ picRadar;
	private: System::Windows::Forms::ProgressBar^ prgSeñal;
		   int btnNorteValue = 0;
		   int btnEsteValue = 0;
		   int btnSurValue = 0;
		   int btnOesteValue = 0;

	private: System::ComponentModel::IContainer^ components;





	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		MundoHumanoService* service; // puntero nativo


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmModulo3::typeid));
			this->pnlModulo3 = (gcnew System::Windows::Forms::Panel());
			this->picRadar = (gcnew System::Windows::Forms::PictureBox());
			this->prgSeñal = (gcnew System::Windows::Forms::ProgressBar());
			this->btnOeste = (gcnew System::Windows::Forms::Button());
			this->btnSur = (gcnew System::Windows::Forms::Button());
			this->btnEste = (gcnew System::Windows::Forms::Button());
			this->btnNorte = (gcnew System::Windows::Forms::Button());
			this->pnlModulo3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picRadar))->BeginInit();
			this->SuspendLayout();
			// 
			// pnlModulo3
			// 
			this->pnlModulo3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlModulo3.BackgroundImage")));
			this->pnlModulo3->Controls->Add(this->picRadar);
			this->pnlModulo3->Controls->Add(this->prgSeñal);
			this->pnlModulo3->Controls->Add(this->btnOeste);
			this->pnlModulo3->Controls->Add(this->btnSur);
			this->pnlModulo3->Controls->Add(this->btnEste);
			this->pnlModulo3->Controls->Add(this->btnNorte);
			this->pnlModulo3->Location = System::Drawing::Point(-6, -52);
			this->pnlModulo3->Name = L"pnlModulo3";
			this->pnlModulo3->Size = System::Drawing::Size(1032, 923);
			this->pnlModulo3->TabIndex = 0;
			this->pnlModulo3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmModulo3::pnlModulo3_Paint);
			// 
			// picRadar
			// 
			this->picRadar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picRadar.BackgroundImage")));
			this->picRadar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picRadar->Location = System::Drawing::Point(338, 359);
			this->picRadar->Name = L"picRadar";
			this->picRadar->Size = System::Drawing::Size(336, 330);
			this->picRadar->TabIndex = 6;
			this->picRadar->TabStop = false;
			// 
			// prgSeñal
			// 
			this->prgSeñal->Location = System::Drawing::Point(663, 263);
			this->prgSeñal->Name = L"prgSeñal";
			this->prgSeñal->Size = System::Drawing::Size(219, 31);
			this->prgSeñal->TabIndex = 5;
			// 
			// btnOeste
			// 
			this->btnOeste->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOeste->Location = System::Drawing::Point(813, 533);
			this->btnOeste->Name = L"btnOeste";
			this->btnOeste->Size = System::Drawing::Size(54, 57);
			this->btnOeste->TabIndex = 3;
			this->btnOeste->Text = L"W";
			this->btnOeste->UseVisualStyleBackColor = true;
			this->btnOeste->Click += gcnew System::EventHandler(this, &FrmModulo3::btnOeste_Click);
			// 
			// btnSur
			// 
			this->btnSur->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSur->Location = System::Drawing::Point(730, 533);
			this->btnSur->Name = L"btnSur";
			this->btnSur->Size = System::Drawing::Size(54, 57);
			this->btnSur->TabIndex = 2;
			this->btnSur->Text = L"S";
			this->btnSur->UseVisualStyleBackColor = true;
			this->btnSur->Click += gcnew System::EventHandler(this, &FrmModulo3::btnSur_Click);
			// 
			// btnEste
			// 
			this->btnEste->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEste->Location = System::Drawing::Point(813, 453);
			this->btnEste->Name = L"btnEste";
			this->btnEste->Size = System::Drawing::Size(54, 57);
			this->btnEste->TabIndex = 1;
			this->btnEste->Text = L"E";
			this->btnEste->UseVisualStyleBackColor = true;
			this->btnEste->Click += gcnew System::EventHandler(this, &FrmModulo3::btnEste_Click);
			// 
			// btnNorte
			// 
			this->btnNorte->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNorte->Location = System::Drawing::Point(730, 453);
			this->btnNorte->Name = L"btnNorte";
			this->btnNorte->Size = System::Drawing::Size(54, 57);
			this->btnNorte->TabIndex = 0;
			this->btnNorte->Text = L"N";
			this->btnNorte->UseVisualStyleBackColor = true;
			this->btnNorte->Click += gcnew System::EventHandler(this, &FrmModulo3::btnNorte_Click);
			// 
			// FrmModulo3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 870);
			this->Controls->Add(this->pnlModulo3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FrmModulo3";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmModulo3";
			this->Load += gcnew System::EventHandler(this, &FrmModulo3::FrmModulo3_Load);
			this->pnlModulo3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picRadar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		void generarNumerosAleatoreos() {
			// Lista de valores posibles
			cli::array<int>^ valores = gcnew cli::array<int>(4) { 25, 50, 75, 100 };

			// Mezclar aleatoriamente los valores
			Random^ rand = gcnew Random();
			for (int i = 0; i < valores->Length; i++) {
				int j = rand->Next(i, valores->Length);
				int temp = valores[i];
				valores[i] = valores[j];
				valores[j] = temp;
			}

			// Asignar los valores mezclados a los botones
			btnNorteValue = valores[0];
			btnEsteValue = valores[1];
			btnSurValue = valores[2];
			btnOesteValue = valores[3];
		}
	private: System::Void FrmModulo3_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void pnlModulo3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void btnNorte_Click(System::Object^ sender, System::EventArgs^ e) {
		//cambiar la imagen del radar para que gire hacia el norte
		picRadar->Image = Image::FromFile("RadarNorte.png");
		//aumentar el valor de la barra de progreso al maximo
		prgSeñal->Value = btnNorteValue;	
		if (prgSeñal->Value == 100) {
			prgSeñal->Value = 99;
			//MOSTRAR UN MENSAJES QUE DIGA Q SE LOGRO RESTABLECER LA SEÑAL CON LA TIERRA. y QUE EL MODULO SE COMPLETO. 
			gestorSonido->ReproducirEfecto("EfectoRespuestaCorrecta.wav", 0.7);
			MessageBox::Show("¡Se logró restablecer la señal con la Tierra!\nMódulo completado.", "Confirmación", MessageBoxButtons::OK, MessageBoxIcon::Information);
			service->aplicarResultadoModulo(2, true);
			this->Close();
		}
		else {
			//si no es 100, mostrar un mensaje que diga que la señal no se restablecio y que intente con otra direccion
			gestorSonido->ReproducirEfecto("EfectoRespuestaIncorrecta.wav", 0.7);
			MessageBox::Show("La señal no se restableció.\nIntenta con otra dirección.", "Error de señal", MessageBoxButtons::OK, MessageBoxIcon::Error);
			service->aplicarResultadoModulo(2, false);
		}
	
	}
	private: System::Void btnEste_Click(System::Object^ sender, System::EventArgs^ e) {
		picRadar->Image = Image::FromFile("RadarEste.png");
		prgSeñal->Value = btnEsteValue;
		if (prgSeñal->Value == 100) {
			prgSeñal->Value = 99;
			gestorSonido->ReproducirEfecto("EfectoRespuestaCorrecta.wav", 0.7);
			MessageBox::Show("¡Se logró restablecer la señal con la Tierra!\nMódulo completado.", "Confirmación", MessageBoxButtons::OK, MessageBoxIcon::Information);
			service->aplicarResultadoModulo(2, true);
			this->Close();
		}
		else {
			//si no es 100, mostrar un mensaje que diga que la señal no se restablecio y que intente con otra direccion
			gestorSonido->ReproducirEfecto("EfectoRespuestaIncorrecta.wav", 0.7);
			MessageBox::Show("La señal no se restableció.\nIntenta con otra dirección.", "Error de señal", MessageBoxButtons::OK, MessageBoxIcon::Error);
			service->aplicarResultadoModulo(2, false);
		}
	}
	private: System::Void btnSur_Click(System::Object^ sender, System::EventArgs^ e) {
		picRadar->Image = Image::FromFile("RadarSur.png");
		prgSeñal->Value = btnSurValue;
		if (prgSeñal->Value == 100) {
			prgSeñal->Value = 99;
			gestorSonido->ReproducirEfecto("EfectoRespuestaCorrecta.wav", 0.7);
			service->aplicarResultadoModulo(2, true);
			MessageBox::Show("¡Se logró restablecer la señal con la Tierra!\nMódulo completado.", "Confirmación", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}
		else {
			//si no es 100, mostrar un mensaje que diga que la señal no se restablecio y que intente con otra direccion
			gestorSonido->ReproducirEfecto("EfectoRespuestaIncorrecta.wav", 0.7);
			MessageBox::Show("La señal no se restableció.\nIntenta con otra dirección.", "Error de señal", MessageBoxButtons::OK, MessageBoxIcon::Error);
			service->aplicarResultadoModulo(2, false);
		}
	}
	private: System::Void btnOeste_Click(System::Object^ sender, System::EventArgs^ e) {
		picRadar->Image = Image::FromFile("RadarOeste.png");
		prgSeñal->Value = btnOesteValue;
		if (prgSeñal->Value == 100) {
			prgSeñal->Value = 99;
			gestorSonido->ReproducirEfecto("EfectoRespuestaCorrecta.wav", 0.7);
			service->aplicarResultadoModulo(2, true);
			MessageBox::Show("¡Se logró restablecer la señal con la Tierra!\nMódulo completado.", "Confirmación", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}
		else {
			//si no es 100, mostrar un mensaje que diga que la señal no se restablecio y que intente con otra direccion
			gestorSonido->ReproducirEfecto("EfectoRespuestaIncorrecta.wav", 0.7);
			MessageBox::Show("La señal no se restableció.\nIntenta con otra dirección.", "Error de señal", MessageBoxButtons::OK, MessageBoxIcon::Error);
			service->aplicarResultadoModulo(2, false);
		}
	}
	

};
}
