#pragma once
#include "MundoHumanoService.h"

namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmModulo2
	/// </summary>
	public ref class FrmModulo2 : public System::Windows::Forms::Form
	{
	public:
		FrmModulo2(MundoHumanoService* serviceRef)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			service = serviceRef;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmModulo2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlModulo2;
	protected:
	private: System::Windows::Forms::Button^ btnOpcion4;
	private: System::Windows::Forms::Button^ btnOpcion3;
	private: System::Windows::Forms::Button^ btnOpcion2;
	private: System::Windows::Forms::Button^ btnOpcion1;
	private: System::Windows::Forms::Label^ label1;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		MundoHumanoService* service; // puntero nativo

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmModulo2::typeid));
			this->pnlModulo2 = (gcnew System::Windows::Forms::Panel());
			this->btnOpcion4 = (gcnew System::Windows::Forms::Button());
			this->btnOpcion3 = (gcnew System::Windows::Forms::Button());
			this->btnOpcion2 = (gcnew System::Windows::Forms::Button());
			this->btnOpcion1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pnlModulo2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlModulo2
			// 
			this->pnlModulo2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlModulo2.BackgroundImage")));
			this->pnlModulo2->Controls->Add(this->btnOpcion4);
			this->pnlModulo2->Controls->Add(this->btnOpcion3);
			this->pnlModulo2->Controls->Add(this->btnOpcion2);
			this->pnlModulo2->Controls->Add(this->btnOpcion1);
			this->pnlModulo2->Controls->Add(this->label1);
			this->pnlModulo2->Location = System::Drawing::Point(-3, -1);
			this->pnlModulo2->Name = L"pnlModulo2";
			this->pnlModulo2->Size = System::Drawing::Size(1245, 832);
			this->pnlModulo2->TabIndex = 0;
			// 
			// btnOpcion4
			// 
			this->btnOpcion4->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Bold));
			this->btnOpcion4->Location = System::Drawing::Point(723, 743);
			this->btnOpcion4->Name = L"btnOpcion4";
			this->btnOpcion4->Size = System::Drawing::Size(60, 35);
			this->btnOpcion4->TabIndex = 4;
			this->btnOpcion4->Text = L"4";
			this->btnOpcion4->UseVisualStyleBackColor = true;
			this->btnOpcion4->Click += gcnew System::EventHandler(this, &FrmModulo2::btnOpcion4_Click);
			// 
			// btnOpcion3
			// 
			this->btnOpcion3->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Bold));
			this->btnOpcion3->Location = System::Drawing::Point(643, 743);
			this->btnOpcion3->Name = L"btnOpcion3";
			this->btnOpcion3->Size = System::Drawing::Size(57, 35);
			this->btnOpcion3->TabIndex = 3;
			this->btnOpcion3->Text = L"3";
			this->btnOpcion3->UseVisualStyleBackColor = true;
			this->btnOpcion3->Click += gcnew System::EventHandler(this, &FrmModulo2::btnOpcion3_Click);
			// 
			// btnOpcion2
			// 
			this->btnOpcion2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Bold));
			this->btnOpcion2->Location = System::Drawing::Point(555, 743);
			this->btnOpcion2->Name = L"btnOpcion2";
			this->btnOpcion2->Size = System::Drawing::Size(60, 35);
			this->btnOpcion2->TabIndex = 2;
			this->btnOpcion2->Text = L"2";
			this->btnOpcion2->UseVisualStyleBackColor = true;
			this->btnOpcion2->Click += gcnew System::EventHandler(this, &FrmModulo2::btnOpcion2_Click);
			// 
			// btnOpcion1
			// 
			this->btnOpcion1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOpcion1->Location = System::Drawing::Point(474, 743);
			this->btnOpcion1->Name = L"btnOpcion1";
			this->btnOpcion1->Size = System::Drawing::Size(52, 35);
			this->btnOpcion1->TabIndex = 1;
			this->btnOpcion1->Text = L"1";
			this->btnOpcion1->UseVisualStyleBackColor = true;
			this->btnOpcion1->Click += gcnew System::EventHandler(this, &FrmModulo2::btnOpcion1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(467, 710);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(162, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Selecciona una opcion:";
			// 
			// FrmModulo2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1242, 825);
			this->Controls->Add(this->pnlModulo2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FrmModulo2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmModulo2";
			this->Load += gcnew System::EventHandler(this, &FrmModulo2::FrmModulo2_Load);
			this->pnlModulo2->ResumeLayout(false);
			this->pnlModulo2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmModulo2_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void btnOpcion1_Click(System::Object^ sender, System::EventArgs^ e) {
	service->aplicarResultadoModulo(1, false);	
	MessageBox::Show("Mala elección.\nLa llave inglesa está oxidada y no sirve para reparar el sistema de flujo.\nIntenta nuevamente.", "Error de herramienta", MessageBoxButtons::OK, MessageBoxIcon::Error);

}
private: System::Void btnOpcion2_Click(System::Object^ sender, System::EventArgs^ e) {
	service->aplicarResultadoModulo(1, false);
	MessageBox::Show("Mala elección.\nLa cinta metálica no soporta la presión del sistema de oxígeno.\nIntenta nuevamente.", "Error de herramienta", MessageBoxButtons::OK, MessageBoxIcon::Error);
}

private: System::Void btnOpcion3_Click(System::Object^ sender, System::EventArgs^ e) {
	service->aplicarResultadoModulo(1, true);
	MessageBox::Show("¡Excelente elección!\nEl nuevo fijador de flujo de turbina es la mejor opción para restaurar el sistema de oxígeno.\nEl módulo comienza a estabilizarse.", "Reparación exitosa", MessageBoxButtons::OK, MessageBoxIcon::Information);
	this->Close();
}
private: System::Void btnOpcion4_Click(System::Object^ sender, System::EventArgs^ e) {
	service->aplicarResultadoModulo(1, false);
	MessageBox::Show("Mala elección.\nLa batería auxiliar no está conectada al sistema de ventilación.\nIntenta nuevamente.", "Error de herramienta", MessageBoxButtons::OK, MessageBoxIcon::Error);

}
};
}
