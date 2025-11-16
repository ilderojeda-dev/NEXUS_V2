#pragma once

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
		FrmModulo3(void)
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
	private: System::Windows::Forms::Button^ btnSalir;




	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmModulo3::typeid));
			this->pnlModulo3 = (gcnew System::Windows::Forms::Panel());
			this->btnOeste = (gcnew System::Windows::Forms::Button());
			this->btnSur = (gcnew System::Windows::Forms::Button());
			this->btnEste = (gcnew System::Windows::Forms::Button());
			this->btnNorte = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->pnlModulo3->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlModulo3
			// 
			this->pnlModulo3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlModulo3.BackgroundImage")));
			this->pnlModulo3->Controls->Add(this->btnSalir);
			this->pnlModulo3->Controls->Add(this->btnOeste);
			this->pnlModulo3->Controls->Add(this->btnSur);
			this->pnlModulo3->Controls->Add(this->btnEste);
			this->pnlModulo3->Controls->Add(this->btnNorte);
			this->pnlModulo3->Location = System::Drawing::Point(-6, -52);
			this->pnlModulo3->Name = L"pnlModulo3";
			this->pnlModulo3->Size = System::Drawing::Size(1032, 923);
			this->pnlModulo3->TabIndex = 0;
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
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::LightCoral;
			this->btnSalir->Cursor = System::Windows::Forms::Cursors::Default;
			this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(18, 64);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(75, 29);
			this->btnSalir->TabIndex = 4;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmModulo3::btnSalir_Click);
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
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmModulo3_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
