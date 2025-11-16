#pragma once

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
		FrmModulo2(void)
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmModulo2::typeid));
			this->pnlModulo2 = (gcnew System::Windows::Forms::Panel());
			this->btnOpcion4 = (gcnew System::Windows::Forms::Button());
			this->btnOpcion3 = (gcnew System::Windows::Forms::Button());
			this->btnOpcion2 = (gcnew System::Windows::Forms::Button());
			this->btnOpcion1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->pnlModulo2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlModulo2
			// 
			this->pnlModulo2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlModulo2.BackgroundImage")));
			this->pnlModulo2->Controls->Add(this->btnSalir);
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
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::LightCoral;
			this->btnSalir->Cursor = System::Windows::Forms::Cursors::Default;
			this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(35, 23);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(75, 29);
			this->btnSalir->TabIndex = 4;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmModulo2::btnSalir_Click);
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
};
}
