#pragma once

namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmFinMundoIA1
	/// </summary>
	public ref class FrmFinMundoIA1 : public System::Windows::Forms::Form
	{
	public:
		FrmFinMundoIA1(bool gano, bool esHistoria, int vidas, int robots, int autonomia, int chips)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//// Esto elimina el pantallazo blanco y el parpadeo
			this->SetStyle(ControlStyles::AllPaintingInWmPaint |
				ControlStyles::UserPaint |
				ControlStyles::DoubleBuffer, true);
			this->UpdateStyles();
			// --------------------------------------------

			this->StartPosition = FormStartPosition::CenterScreen;
			
			// 1. Aplicar el estilo visual (Colores, Fuentes)
			ConfigurarEstiloVisual();

			// 2. Llenar los datos y configurar botones
			construirFinal(gano, esHistoria, vidas, robots, autonomia, chips);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmFinMundoIA1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ lblRobotsEliminados;
	private: System::Windows::Forms::Label^ lblAutonomia;
	private: System::Windows::Forms::Label^ lblChipsRecolectados;

	private: System::Windows::Forms::Button^ btnVolver;
	private: System::Windows::Forms::Button^ btnSiguienteNivel;
		   
	protected:





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Label^ lblT1;
	private: System::Windows::Forms::Label^ lblT2;
	private: System::Windows::Forms::Label^ lblT3;
	private: System::Windows::Forms::Label^ lblT4;

		   bool esHistoria;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmFinMundoIA1::typeid));
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->lblRobotsEliminados = (gcnew System::Windows::Forms::Label());
			this->lblAutonomia = (gcnew System::Windows::Forms::Label());
			this->lblChipsRecolectados = (gcnew System::Windows::Forms::Label());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->btnSiguienteNivel = (gcnew System::Windows::Forms::Button());
			this->lblT1 = (gcnew System::Windows::Forms::Label());
			this->lblT2 = (gcnew System::Windows::Forms::Label());
			this->lblT3 = (gcnew System::Windows::Forms::Label());
			this->lblT4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Location = System::Drawing::Point(625, 238);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(35, 13);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"label1";
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Location = System::Drawing::Point(194, 617);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(35, 13);
			this->lblVidas->TabIndex = 1;
			this->lblVidas->Text = L"label1";
			// 
			// lblRobotsEliminados
			// 
			this->lblRobotsEliminados->AutoSize = true;
			this->lblRobotsEliminados->Location = System::Drawing::Point(579, 617);
			this->lblRobotsEliminados->Name = L"lblRobotsEliminados";
			this->lblRobotsEliminados->Size = System::Drawing::Size(35, 13);
			this->lblRobotsEliminados->TabIndex = 2;
			this->lblRobotsEliminados->Text = L"label2";
			// 
			// lblAutonomia
			// 
			this->lblAutonomia->AutoSize = true;
			this->lblAutonomia->Location = System::Drawing::Point(975, 607);
			this->lblAutonomia->Name = L"lblAutonomia";
			this->lblAutonomia->Size = System::Drawing::Size(56, 13);
			this->lblAutonomia->TabIndex = 3;
			this->lblAutonomia->Text = L"autonomia";
			// 
			// lblChipsRecolectados
			// 
			this->lblChipsRecolectados->AutoSize = true;
			this->lblChipsRecolectados->Location = System::Drawing::Point(1390, 586);
			this->lblChipsRecolectados->Name = L"lblChipsRecolectados";
			this->lblChipsRecolectados->Size = System::Drawing::Size(35, 13);
			this->lblChipsRecolectados->TabIndex = 4;
			this->lblChipsRecolectados->Text = L"label4";
			this->lblChipsRecolectados->Click += gcnew System::EventHandler(this, &FrmFinMundoIA1::lblChipsRecolectados_Click);
			// 
			// btnVolver
			// 
			this->btnVolver->Location = System::Drawing::Point(876, 965);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(120, 64);
			this->btnVolver->TabIndex = 5;
			this->btnVolver->Text = L"button1";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &FrmFinMundoIA1::btnVolver_Click);
			// 
			// btnSiguienteNivel
			// 
			this->btnSiguienteNivel->Location = System::Drawing::Point(1264, 938);
			this->btnSiguienteNivel->Name = L"btnSiguienteNivel";
			this->btnSiguienteNivel->Size = System::Drawing::Size(120, 64);
			this->btnSiguienteNivel->TabIndex = 6;
			this->btnSiguienteNivel->Text = L"button1";
			this->btnSiguienteNivel->UseVisualStyleBackColor = true;
			this->btnSiguienteNivel->Click += gcnew System::EventHandler(this, &FrmFinMundoIA1::btnSiguienteNivel_Click);
			// 
			// lblT1
			// 
			this->lblT1->AutoSize = true;
			this->lblT1->Location = System::Drawing::Point(300, 544);
			this->lblT1->Name = L"lblT1";
			this->lblT1->Size = System::Drawing::Size(35, 13);
			this->lblT1->TabIndex = 7;
			this->lblT1->Text = L"label1";
			// 
			// lblT2
			// 
			this->lblT2->AutoSize = true;
			this->lblT2->Location = System::Drawing::Point(698, 544);
			this->lblT2->Name = L"lblT2";
			this->lblT2->Size = System::Drawing::Size(35, 13);
			this->lblT2->TabIndex = 8;
			this->lblT2->Text = L"label2";
			// 
			// lblT3
			// 
			this->lblT3->AutoSize = true;
			this->lblT3->Location = System::Drawing::Point(1077, 544);
			this->lblT3->Name = L"lblT3";
			this->lblT3->Size = System::Drawing::Size(35, 13);
			this->lblT3->TabIndex = 9;
			this->lblT3->Text = L"label3";
			// 
			// lblT4
			// 
			this->lblT4->AutoSize = true;
			this->lblT4->Location = System::Drawing::Point(1467, 530);
			this->lblT4->Name = L"lblT4";
			this->lblT4->Size = System::Drawing::Size(35, 13);
			this->lblT4->TabIndex = 10;
			this->lblT4->Text = L"label4";
			// 
			// FrmFinMundoIA1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->lblT4);
			this->Controls->Add(this->btnSiguienteNivel);
			this->Controls->Add(this->lblChipsRecolectados);
			this->Controls->Add(this->lblVidas);
			this->Controls->Add(this->lblT3);
			this->Controls->Add(this->lblT1);
			this->Controls->Add(this->lblAutonomia);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->lblRobotsEliminados);
			this->Controls->Add(this->lblT2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FrmFinMundoIA1";
			this->Text = L"FrmFinMundoIA1";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmFinMundoIA1::FrmFinMundoIA1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FrmFinMundoIA1_Load(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private:
		// FUNCIÓN 1: Aplicar Diseño Sci-Fi (Colores Neón)
		void ConfigurarEstiloVisual() {
			// --- DEFINICIÓN DE ESTILOS ---
			System::Drawing::Font^ fuenteTitulo = gcnew System::Drawing::Font("Consolas", 24, FontStyle::Bold);
			System::Drawing::Font^ fuenteDato = gcnew System::Drawing::Font("Segoe UI", 18, FontStyle::Bold);
			System::Drawing::Font^ fuenteEtiqueta = gcnew System::Drawing::Font("Consolas", 10, FontStyle::Regular);
			System::Drawing::Font^ fuenteBoton = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);

			System::Drawing::Color colorNeonCyan = System::Drawing::Color::FromArgb(0, 255, 255);
			System::Drawing::Color colorNeonRosa = System::Drawing::Color::FromArgb(255, 0, 128);
			System::Drawing::Color colorBlanco = System::Drawing::Color::White;
			System::Drawing::Color colorBotonVolver = System::Drawing::Color::FromArgb(200, 20, 20, 20);
			System::Drawing::Color colorBotonSiguiente = System::Drawing::Color::FromArgb(200, 0, 100, 200);

			// --- APLICAR ESTILOS A TÍTULOS ("t") ---
			// Solo cambiamos color, fuente y transparencia. NO tocamos posición.
			EstilizarLabel(lblT1, "VIDAS", fuenteEtiqueta, colorNeonCyan);
			EstilizarLabel(lblT2, "ROBOTS ELIMINADOS", fuenteEtiqueta, colorNeonCyan);
			EstilizarLabel(lblT3, "NIVEL AUTONOMIA", fuenteEtiqueta, colorNeonCyan);
			EstilizarLabel(lblT4, "CHIPS RECOLECTADOS", fuenteEtiqueta, colorNeonCyan);

			// --- APLICAR ESTILOS A DATOS (lbl) ---
			EstilizarLabel(lblVidas, "", fuenteDato, colorBlanco);
			EstilizarLabel(lblRobotsEliminados, "", fuenteDato, colorBlanco);
			EstilizarLabel(lblAutonomia, "", fuenteDato, colorBlanco);
			EstilizarLabel(lblChipsRecolectados, "", fuenteDato, colorBlanco);

			// --- TÍTULO PRINCIPAL ---
			lblTitulo->Font = fuenteTitulo;
			lblTitulo->BackColor = System::Drawing::Color::Transparent;
			lblTitulo->TextAlign = ContentAlignment::MiddleCenter;
			// El color se define en construirFinal según si ganó o perdió

			// --- BOTONES ---
			EstilizarBoton(btnVolver, "VOLVER AL MENU", colorBotonVolver, fuenteBoton);
			EstilizarBoton(btnSiguienteNivel, "SIGUIENTE NIVEL", colorBotonSiguiente, fuenteBoton);
		}

		// Helper SÚPER SIMPLE (Solo apariencia)
		void EstilizarLabel(Label^ lbl, String^ txt, System::Drawing::Font^ f, System::Drawing::Color c) {
			if (txt != "") lbl->Text = txt; // Solo cambia texto si le mandamos uno
			lbl->Font = f;
			lbl->ForeColor = c;
			lbl->BackColor = System::Drawing::Color::Transparent; // Esto es lo importante
			lbl->TextAlign = ContentAlignment::MiddleCenter;
		}

		// Helper para Botones (Solo apariencia)
		void EstilizarBoton(Button^ btn, String^ txt, System::Drawing::Color bg, System::Drawing::Font^ f) {
			btn->Text = txt;
			btn->FlatStyle = FlatStyle::Flat;
			btn->FlatAppearance->BorderSize = 0;
			btn->BackColor = bg;
			btn->ForeColor = System::Drawing::Color::White;
			btn->Font = f;
			btn->Cursor = Cursors::Hand;
		}
		void construirFinal(bool gano, bool esHistoria, int vidas, int robots, int autonomia, int chips) {
			// Llenar los datos
			lblVidas->Text = Convert::ToString(vidas);
			lblRobotsEliminados->Text = Convert::ToString(robots);
			lblAutonomia->Text = Convert::ToString(autonomia) + "%";
			lblChipsRecolectados->Text = Convert::ToString(chips);

			// Definir Título y Color
			if (gano) {
				lblTitulo->Text = "MISION CUMPLIDA";
				lblTitulo->ForeColor = System::Drawing::Color::Lime;
			}
			else {
				lblTitulo->Text = "MISION FALLIDA";
				lblTitulo->ForeColor = System::Drawing::Color::Red;
			}

			// Lógica de Navegación
			btnVolver->Visible = true;

			if (gano && esHistoria) {
				btnSiguienteNivel->Visible = true;
				// Aquí NO movemos nada, se quedan donde tú los pusiste
			}
			else {
				btnSiguienteNivel->Visible = false;
				// OPCIONAL: Solo si quieres centrar el botón volver cuando está solo.
				// Si prefieres que se quede quieto, borra la siguiente línea:
				btnVolver->Left = (this->ClientSize.Width - btnVolver->Width) / 2;
			}
		}
		// EVENTOS DE CLIC
	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}

	private: System::Void btnSiguienteNivel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	
private: System::Void lblChipsRecolectados_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}

