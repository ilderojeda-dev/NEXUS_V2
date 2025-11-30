#pragma once

namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen para FrmYouWinMundoColab
	/// </summary>
	public ref class FrmYouWinMundoColab : public System::Windows::Forms::Form
	{
	public:
		FrmYouWinMundoColab(void)
		{
			InitializeComponent();
			//
			// TODO: Agregar código del constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~FrmYouWinMundoColab()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnContinue;
	private: System::Windows::Forms::Panel^ pnlImagen;
	private: System::Windows::Forms::Label^ lblTexto;

	private:
		/// <summary>
		/// Variable de diseñador requerida.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Código generado por el Diseñador de Windows Forms
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede
		/// modificar el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmYouWinMundoColab::typeid));
			this->btnContinue = (gcnew System::Windows::Forms::Button());
			this->pnlImagen = (gcnew System::Windows::Forms::Panel());
			this->lblTexto = (gcnew System::Windows::Forms::Label());
			this->pnlImagen->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnContinue
			// 
			this->btnContinue->BackColor = System::Drawing::Color::Teal;
			this->btnContinue->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnContinue.BackgroundImage")));
			this->btnContinue->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnContinue->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnContinue->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnContinue->ForeColor = System::Drawing::Color::White;
			this->btnContinue->Location = System::Drawing::Point(1631, 859);
			this->btnContinue->Name = L"btnContinue";
			this->btnContinue->Size = System::Drawing::Size(273, 182);
			this->btnContinue->TabIndex = 1;
			this->btnContinue->Text = L"CONTINUAR / MENÚ";
			this->btnContinue->UseVisualStyleBackColor = false;
			this->btnContinue->Click += gcnew System::EventHandler(this, &FrmYouWinMundoColab::btnContinue_Click);
			// 
			// pnlImagen
			// 
			this->pnlImagen->BackColor = System::Drawing::Color::White;
			this->pnlImagen->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlImagen.BackgroundImage")));
			this->pnlImagen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnlImagen->Controls->Add(this->lblTexto);
			this->pnlImagen->Controls->Add(this->btnContinue);
			this->pnlImagen->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlImagen->Location = System::Drawing::Point(0, 0);
			this->pnlImagen->Name = L"pnlImagen";
			this->pnlImagen->Size = System::Drawing::Size(1904, 1041);
			this->pnlImagen->TabIndex = 2;
			// 
			// lblTexto
			// 
			this->lblTexto->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold));
			this->lblTexto->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lblTexto->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblTexto.Image")));
			this->lblTexto->Location = System::Drawing::Point(807, 354);
			this->lblTexto->Name = L"lblTexto";
			this->lblTexto->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->lblTexto->Size = System::Drawing::Size(295, 191);
			this->lblTexto->TabIndex = 2;
			this->lblTexto->Text = L"Felicidades piloto! haz logrado sobrevivir a esta aventura, claro que no lo podri"
				L"an haber hecho uno sin el otro... me refiero a R2D2 y a ti. Gran trabajo en equi"
				L"po! eso si es una colaboracion.";
			this->lblTexto->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// FrmYouWinMundoColab
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->pnlImagen);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FrmYouWinMundoColab";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Victoria";
			this->pnlImagen->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnContinue_Click(System::Object^ sender, System::EventArgs^ e) {
		// 1. Establecer el resultado del diálogo a OK (indica Victoria/Éxito)
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		// 2. Cerrar el formulario.
		this->Close();
	}
	};
}