#pragma once

// Usamos una declaración anticipada (forward declaration) en lugar de incluir el header
// para evitar dependencias circulares.
namespace NEXUSV2 { ref class FrmInicio; }


namespace NEXUSV2 {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmGameOverMundoColab
	/// </summary>
	public ref class FrmGameOverMundoColab : public System::Windows::Forms::Form
	{
	public:
		FrmGameOverMundoColab(void)
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
		~FrmGameOverMundoColab()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlFondo;
	protected:
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Label^ lblTextoGameOver;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmGameOverMundoColab::typeid));
			this->pnlFondo = (gcnew System::Windows::Forms::Panel());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->lblTextoGameOver = (gcnew System::Windows::Forms::Label());
			this->pnlFondo->SuspendLayout();
			this->SuspendLayout();
			this->pnlFondo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlFondo.BackgroundImage")));
			this->pnlFondo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnlFondo->Controls->Add(this->lblTextoGameOver);
			this->pnlFondo->Controls->Add(this->btnSalir);
			this->pnlFondo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlFondo->Location = System::Drawing::Point(0, 0);
			this->pnlFondo->Name = L"pnlFondo";
			this->pnlFondo->Size = System::Drawing::Size(1904, 1041);
			this->pnlFondo->TabIndex = 0;
			this->btnSalir->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(746, 656);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(425, 235);
			this->btnSalir->TabIndex = 0;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmGameOverMundoColab::btnSalir_Click);
			this->lblTextoGameOver->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblTextoGameOver->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTextoGameOver->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lblTextoGameOver->Location = System::Drawing::Point(387, 2);
			this->lblTextoGameOver->Name = L"lblTextoGameOver";
			this->lblTextoGameOver->Size = System::Drawing::Size(1248, 226);
			this->lblTextoGameOver->TabIndex = 2;
			this->lblTextoGameOver->Text = L"Buen intento... para la proxima tal vez necesites un poco mas de ayuda de R2D2..."
				L" lamentablemente esta vez no lograste sobrevivir. Sin embargo, nunca es tarde pa"
				L"ra volver a intentar!";
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->pnlFondo);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Name = L"FrmGameOverMundoColab";
			this->Text = L"FrmGameOverMundoColab";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmGameOverMundoColab::FrmGameOverMundoColab_Load);
			this->pnlFondo->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmGameOverMundoColab_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e);
	
	
};
}
