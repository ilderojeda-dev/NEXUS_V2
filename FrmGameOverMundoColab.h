#pragma once

namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen para FrmGameOverMundoColab
	/// </summary>
	public ref class FrmGameOverMundoColab : public System::Windows::Forms::Form
	{
	public:
		FrmGameOverMundoColab()
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
		~FrmGameOverMundoColab()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnReturnToMenu;
	protected:
	private: System::Windows::Forms::Button^ btnTexto;
	private: System::Windows::Forms::Panel^ panel1;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmGameOverMundoColab::typeid));
			this->btnReturnToMenu = (gcnew System::Windows::Forms::Button());
			this->btnTexto = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnReturnToMenu
			// 
			this->btnReturnToMenu->BackColor = System::Drawing::Color::DarkRed;
			this->btnReturnToMenu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnReturnToMenu.BackgroundImage")));
			this->btnReturnToMenu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnReturnToMenu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReturnToMenu->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReturnToMenu->ForeColor = System::Drawing::Color::White;
			this->btnReturnToMenu->Location = System::Drawing::Point(1567, 884);
			this->btnReturnToMenu->Name = L"btnReturnToMenu";
			this->btnReturnToMenu->Size = System::Drawing::Size(337, 157);
			this->btnReturnToMenu->TabIndex = 1;
			this->btnReturnToMenu->Text = L"VOLVER AL MENÚ";
			this->btnReturnToMenu->UseVisualStyleBackColor = false;
			this->btnReturnToMenu->Click += gcnew System::EventHandler(this, &FrmGameOverMundoColab::btnReturnToMenu_Click);
			// 
			// btnTexto
			// 
			this->btnTexto->BackColor = System::Drawing::Color::DarkRed;
			this->btnTexto->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTexto.BackgroundImage")));
			this->btnTexto->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnTexto->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTexto->Font = (gcnew System::Drawing::Font(L"Consolas", 20, System::Drawing::FontStyle::Bold));
			this->btnTexto->ForeColor = System::Drawing::Color::White;
			this->btnTexto->Location = System::Drawing::Point(711, 624);
			this->btnTexto->Name = L"btnTexto";
			this->btnTexto->Size = System::Drawing::Size(505, 271);
			this->btnTexto->TabIndex = 2;
			this->btnTexto->Text = resources->GetString(L"btnTexto.Text");
			this->btnTexto->UseVisualStyleBackColor = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->btnTexto);
			this->panel1->Controls->Add(this->btnReturnToMenu);
			this->panel1->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1904, 1041);
			this->panel1->TabIndex = 2;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmGameOverMundoColab::panel1_Paint);
			// 
			// FrmGameOverMundoColab
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->panel1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"FrmGameOverMundoColab";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Fin del Juego";
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmGameOverMundoColab::FrmGameOverMundoColab_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnReturnToMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		// 1. Establecer el resultado del diálogo a Abort (indica Derrota/Fallo)
		this->DialogResult = System::Windows::Forms::DialogResult::Abort;
		// 2. Cerrar el formulario.
		this->Close();
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void FrmGameOverMundoColab_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}