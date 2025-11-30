#pragma once

namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmFinMundoIA
	/// </summary>
	public ref class FrmFinMundoIA : public System::Windows::Forms::Form
	{
	public:
		FrmFinMundoIA(bool victoria, int vidas, int robotsEliminados, int autonomia, int chipsRecolectados)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			juegoGanado = victoria;
			this->actualizarResultados(vidas, robotsEliminados, autonomia, chipsRecolectados);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmFinMundoIA()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblRecursoRecolectado;
	protected:
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ lblRobotsEliminados;
	private: System::Windows::Forms::Label^ lblAutonomia;
	private: System::Windows::Forms::Label^ lblResultado;

	protected:




	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		bool juegoGanado;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmFinMundoIA::typeid));
			this->lblRecursoRecolectado = (gcnew System::Windows::Forms::Label());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->lblRobotsEliminados = (gcnew System::Windows::Forms::Label());
			this->lblAutonomia = (gcnew System::Windows::Forms::Label());
			this->lblResultado = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblRecursoRecolectado
			// 
			this->lblRecursoRecolectado->AutoSize = true;
			this->lblRecursoRecolectado->BackColor = System::Drawing::Color::Transparent;
			this->lblRecursoRecolectado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRecursoRecolectado->ForeColor = System::Drawing::Color::Yellow;
			this->lblRecursoRecolectado->Location = System::Drawing::Point(1108, 585);
			this->lblRecursoRecolectado->Name = L"lblRecursoRecolectado";
			this->lblRecursoRecolectado->Size = System::Drawing::Size(484, 55);
			this->lblRecursoRecolectado->TabIndex = 0;
			this->lblRecursoRecolectado->Text = L"Chips Recolectados:";
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->BackColor = System::Drawing::Color::Transparent;
			this->lblVidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVidas->ForeColor = System::Drawing::Color::Yellow;
			this->lblVidas->Location = System::Drawing::Point(62, 269);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(163, 55);
			this->lblVidas->TabIndex = 1;
			this->lblVidas->Text = L"Vidas:";
			this->lblVidas->Click += gcnew System::EventHandler(this, &FrmFinMundoIA::lblVidas_Click);
			// 
			// lblRobotsEliminados
			// 
			this->lblRobotsEliminados->AutoSize = true;
			this->lblRobotsEliminados->BackColor = System::Drawing::Color::Transparent;
			this->lblRobotsEliminados->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRobotsEliminados->ForeColor = System::Drawing::Color::Yellow;
			this->lblRobotsEliminados->Location = System::Drawing::Point(62, 585);
			this->lblRobotsEliminados->Name = L"lblRobotsEliminados";
			this->lblRobotsEliminados->Size = System::Drawing::Size(455, 55);
			this->lblRobotsEliminados->TabIndex = 2;
			this->lblRobotsEliminados->Text = L"Robots Eliminados:";
			// 
			// lblAutonomia
			// 
			this->lblAutonomia->AutoSize = true;
			this->lblAutonomia->BackColor = System::Drawing::Color::Transparent;
			this->lblAutonomia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAutonomia->ForeColor = System::Drawing::Color::Yellow;
			this->lblAutonomia->Location = System::Drawing::Point(1108, 269);
			this->lblAutonomia->Name = L"lblAutonomia";
			this->lblAutonomia->Size = System::Drawing::Size(481, 55);
			this->lblAutonomia->TabIndex = 3;
			this->lblAutonomia->Text = L"Nivel de autonomía: ";
			this->lblAutonomia->Click += gcnew System::EventHandler(this, &FrmFinMundoIA::lblAutonomia_Click);
			// 
			// lblResultado
			// 
			this->lblResultado->AutoSize = true;
			this->lblResultado->BackColor = System::Drawing::Color::Transparent;
			this->lblResultado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblResultado->ForeColor = System::Drawing::Color::Yellow;
			this->lblResultado->Location = System::Drawing::Point(652, 104);
			this->lblResultado->Name = L"lblResultado";
			this->lblResultado->Size = System::Drawing::Size(250, 55);
			this->lblResultado->TabIndex = 4;
			this->lblResultado->Text = L"Resultado";
			this->lblResultado->Click += gcnew System::EventHandler(this, &FrmFinMundoIA::lblResultado_Click);
			// 
			// FrmFinMundoIA
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1888, 1002);
			this->Controls->Add(this->lblResultado);
			this->Controls->Add(this->lblAutonomia);
			this->Controls->Add(this->lblRobotsEliminados);
			this->Controls->Add(this->lblVidas);
			this->Controls->Add(this->lblRecursoRecolectado);
			this->Name = L"FrmFinMundoIA";
			this->Text = L"FrmFinMundoIA";
			this->Load += gcnew System::EventHandler(this, &FrmFinMundoIA::FrmFinMundoIA_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void lblVidas_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void FrmFinMundoIA_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblResultado_Click(System::Object^ sender, System::EventArgs^ e) {
}
	private: void actualizarResultados(int vidas, int robotsEliminados, int autonomia, int chipsRecolectados) {
		lblVidas->Text = "Vidas: " + vidas;
		lblRobotsEliminados->Text = "Robots Eliminados: " + robotsEliminados;
		lblAutonomia->Text = "Nivel de autonomía: " + autonomia + " %";
		lblRecursoRecolectado->Text = "Chips Recolectados: " + chipsRecolectados;
		if (juegoGanado) {
			lblResultado->Text = "¡Victoria!";
		}
		else {
			lblResultado->Text = "Derrota";
		}
	}
private: System::Void lblAutonomia_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
