#pragma once

namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmModulo1
	/// </summary>
	public ref class FrmModulo1 : public System::Windows::Forms::Form
	{
	public:
		FrmModulo1(void)
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
		~FrmModulo1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlModulo;
	private: System::Windows::Forms::Button^ btnOpcion3;
	private: System::Windows::Forms::Button^ btnOpcion2;


	private: System::Windows::Forms::Button^ btnOpcion1;
	private: System::Windows::Forms::Button^ btnSalir;
	protected:


	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmModulo1::typeid));
			this->pnlModulo = (gcnew System::Windows::Forms::Panel());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->btnOpcion3 = (gcnew System::Windows::Forms::Button());
			this->btnOpcion2 = (gcnew System::Windows::Forms::Button());
			this->btnOpcion1 = (gcnew System::Windows::Forms::Button());
			this->pnlModulo->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlModulo
			// 
			this->pnlModulo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlModulo.BackgroundImage")));
			this->pnlModulo->Controls->Add(this->btnSalir);
			this->pnlModulo->Controls->Add(this->btnOpcion3);
			this->pnlModulo->Controls->Add(this->btnOpcion2);
			this->pnlModulo->Controls->Add(this->btnOpcion1);
			this->pnlModulo->Cursor = System::Windows::Forms::Cursors::Default;
			this->pnlModulo->Location = System::Drawing::Point(-3, -2);
			this->pnlModulo->Name = L"pnlModulo";
			this->pnlModulo->Size = System::Drawing::Size(1241, 831);
			this->pnlModulo->TabIndex = 0;
			this->pnlModulo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmModulo1::pnlModulo_Paint);
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::LightCoral;
			this->btnSalir->Cursor = System::Windows::Forms::Cursors::Default;
			this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(15, 14);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(75, 29);
			this->btnSalir->TabIndex = 3;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmModulo1::btnSalir_Click);
			// 
			// btnOpcion3
			// 
			this->btnOpcion3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)));
			this->btnOpcion3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOpcion3->ForeColor = System::Drawing::Color::Transparent;
			this->btnOpcion3->Location = System::Drawing::Point(787, 683);
			this->btnOpcion3->Name = L"btnOpcion3";
			this->btnOpcion3->Size = System::Drawing::Size(252, 92);
			this->btnOpcion3->TabIndex = 2;
			this->btnOpcion3->Text = L"Conectar rojo → Puerto Alfa\n y negro → Puerto Beta";
			this->btnOpcion3->UseVisualStyleBackColor = false;
			// 
			// btnOpcion2
			// 
			this->btnOpcion2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)));
			this->btnOpcion2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOpcion2->ForeColor = System::Drawing::Color::Transparent;
			this->btnOpcion2->Location = System::Drawing::Point(506, 683);
			this->btnOpcion2->Name = L"btnOpcion2";
			this->btnOpcion2->Size = System::Drawing::Size(252, 92);
			this->btnOpcion2->TabIndex = 1;
			this->btnOpcion2->Text = L"Conectar negro → P2(+)\n y rojo→ P1 (−)";
			this->btnOpcion2->UseVisualStyleBackColor = false;
			// 
			// btnOpcion1
			// 
			this->btnOpcion1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)));
			this->btnOpcion1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOpcion1->ForeColor = System::Drawing::Color::Transparent;
			this->btnOpcion1->Location = System::Drawing::Point(223, 683);
			this->btnOpcion1->Name = L"btnOpcion1";
			this->btnOpcion1->Size = System::Drawing::Size(252, 92);
			this->btnOpcion1->TabIndex = 0;
			this->btnOpcion1->Text = L"Conectar rojo → P2 (+)\n y negro → P1 (−)";
			this->btnOpcion1->UseVisualStyleBackColor = false;
			// 
			// FrmModulo1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1236, 827);
			this->Controls->Add(this->pnlModulo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FrmModulo1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmModulo1";
			this->Load += gcnew System::EventHandler(this, &FrmModulo1::FrmModulo1_Load);
			this->pnlModulo->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmModulo1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void pnlModulo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
