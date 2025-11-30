#pragma once

// Declaración anticipada (forward declaration) de FrmInicio para evitar la dependencia circular
namespace NEXUSV2 { ref class FrmInicio; }

namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmYouWinMundoColab
	/// </summary>
	public ref class FrmYouWinMundoColab : public System::Windows::Forms::Form
	{
	public:
		FrmYouWinMundoColab(void)
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
		~FrmYouWinMundoColab()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlYouWin;
	protected:
	private: System::Windows::Forms::Label^ lblTextoWin;
	private: System::Windows::Forms::Button^ btnSalir;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmYouWinMundoColab::typeid));
			this->pnlYouWin = (gcnew System::Windows::Forms::Panel());
			this->lblTextoWin = (gcnew System::Windows::Forms::Label());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->pnlYouWin->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlYouWin
			// 
			this->pnlYouWin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlYouWin.BackgroundImage")));
			this->pnlYouWin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnlYouWin->Controls->Add(this->btnSalir);
			this->pnlYouWin->Controls->Add(this->lblTextoWin);
			this->pnlYouWin->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlYouWin->Location = System::Drawing::Point(0, 0);
			this->pnlYouWin->Name = L"pnlYouWin";
			this->pnlYouWin->Size = System::Drawing::Size(1904, 1041);
			this->pnlYouWin->TabIndex = 0;
			// 
			// lblTextoWin
			// 
			// *** CAMBIO CLAVE AQUÍ: Se establece el color de fondo como transparente. ***
			this->lblTextoWin->BackColor = System::Drawing::Color::Transparent;
			this->lblTextoWin->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblTextoWin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTextoWin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->lblTextoWin->Location = System::Drawing::Point(0, 281);
			this->lblTextoWin->Name = L"lblTextoWin";
			this->lblTextoWin->Size = System::Drawing::Size(562, 468);
			this->lblTextoWin->TabIndex = 0;
			this->lblTextoWin->Text = L"Bien hecho! lograste sobrevivir a esa estampida de meteoritos! Gracias al trabajo"
				L" colaborativo entre tu y R2D2 salieron ilesos! bien hecho piloto, puedes descans"
				L"ar. ";
			// 
			// btnSalir
			// 
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(1571, 876);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(310, 136);
			this->btnSalir->TabIndex = 1;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmYouWinMundoColab::btnSalir_Click);
			// 
			// FrmYouWinMundoColab
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->pnlYouWin);
			this->Name = L"FrmYouWinMundoColab";
			this->Text = L"FrmYouWinMundoColab";
			this->pnlYouWin->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e); 
	};
}