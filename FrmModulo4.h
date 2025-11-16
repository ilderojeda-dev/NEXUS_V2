#pragma once

namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmModulo4
	/// </summary>
	public ref class FrmModulo4 : public System::Windows::Forms::Form
	{
	public:
		FrmModulo4(void)
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
		~FrmModulo4()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlModulo4;
	private: System::Windows::Forms::Button^ btnOpcionA;
	private: System::Windows::Forms::Button^ btnOpcionC;
	private: System::Windows::Forms::Button^ btnOpcionB;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmModulo4::typeid));
			this->pnlModulo4 = (gcnew System::Windows::Forms::Panel());
			this->btnOpcionC = (gcnew System::Windows::Forms::Button());
			this->btnOpcionB = (gcnew System::Windows::Forms::Button());
			this->btnOpcionA = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->pnlModulo4->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlModulo4
			// 
			this->pnlModulo4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlModulo4.BackgroundImage")));
			this->pnlModulo4->Controls->Add(this->btnSalir);
			this->pnlModulo4->Controls->Add(this->btnOpcionC);
			this->pnlModulo4->Controls->Add(this->btnOpcionB);
			this->pnlModulo4->Controls->Add(this->btnOpcionA);
			this->pnlModulo4->Location = System::Drawing::Point(0, -4);
			this->pnlModulo4->Name = L"pnlModulo4";
			this->pnlModulo4->Size = System::Drawing::Size(1252, 815);
			this->pnlModulo4->TabIndex = 0;
			// 
			// btnOpcionC
			// 
			this->btnOpcionC->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)));
			this->btnOpcionC->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnOpcionC->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOpcionC->Location = System::Drawing::Point(825, 569);
			this->btnOpcionC->Name = L"btnOpcionC";
			this->btnOpcionC->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->btnOpcionC->Size = System::Drawing::Size(128, 66);
			this->btnOpcionC->TabIndex = 2;
			this->btnOpcionC->Text = L"C";
			this->btnOpcionC->UseVisualStyleBackColor = false;
			// 
			// btnOpcionB
			// 
			this->btnOpcionB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)));
			this->btnOpcionB->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnOpcionB->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOpcionB->Location = System::Drawing::Point(558, 569);
			this->btnOpcionB->Name = L"btnOpcionB";
			this->btnOpcionB->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->btnOpcionB->Size = System::Drawing::Size(128, 66);
			this->btnOpcionB->TabIndex = 1;
			this->btnOpcionB->Text = L"B";
			this->btnOpcionB->UseVisualStyleBackColor = false;
			// 
			// btnOpcionA
			// 
			this->btnOpcionA->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)));
			this->btnOpcionA->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnOpcionA->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOpcionA->Location = System::Drawing::Point(312, 569);
			this->btnOpcionA->Name = L"btnOpcionA";
			this->btnOpcionA->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->btnOpcionA->Size = System::Drawing::Size(128, 66);
			this->btnOpcionA->TabIndex = 0;
			this->btnOpcionA->Text = L"A";
			this->btnOpcionA->UseVisualStyleBackColor = false;
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::LightCoral;
			this->btnSalir->Cursor = System::Windows::Forms::Cursors::Default;
			this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(25, 31);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(75, 29);
			this->btnSalir->TabIndex = 4;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmModulo4::btnSalir_Click);
			// 
			// FrmModulo4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1251, 808);
			this->Controls->Add(this->pnlModulo4);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FrmModulo4";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmModulo4";
			this->Load += gcnew System::EventHandler(this, &FrmModulo4::FrmModulo4_Load);
			this->pnlModulo4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmModulo4_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
