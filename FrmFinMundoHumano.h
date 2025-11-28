#pragma once

#include <string>      // <<--- IMPORTANTE

using std::string;     // opcional, si quieres simplificar
using std::to_string;  //
namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmFinMundoHumano
	/// </summary>
	public ref class FrmFinMundoHumano : public System::Windows::Forms::Form
	{
	public:
		FrmFinMundoHumano(bool gano, int vidas, int estabilidad, int criterio, int progreso)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;

			construirFinal(gano, vidas, estabilidad, criterio, progreso);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmFinMundoHumano()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::Button^ btnSiguienteNivel;
    private: System::Windows::Forms::Button^ btnSalir;
    private: System::Windows::Forms::Button^ btnVolverInicio;
    private: System::Windows::Forms::Label^ lblTitulo;
    private: System::Windows::Forms::Label^ lblResumen;
    private: System::Windows::Forms::Label^ lblStats;




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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmFinMundoHumano::typeid));
            this->btnSiguienteNivel = (gcnew System::Windows::Forms::Button());
            this->btnSalir = (gcnew System::Windows::Forms::Button());
            this->btnVolverInicio = (gcnew System::Windows::Forms::Button());
            this->lblTitulo = (gcnew System::Windows::Forms::Label());
            this->lblResumen = (gcnew System::Windows::Forms::Label());
            this->lblStats = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // btnSiguienteNivel
            // 
            this->btnSiguienteNivel->Location = System::Drawing::Point(1501, 858);
            this->btnSiguienteNivel->Name = L"btnSiguienteNivel";
            this->btnSiguienteNivel->Size = System::Drawing::Size(186, 102);
            this->btnSiguienteNivel->TabIndex = 0;
            this->btnSiguienteNivel->Text = L"Siguiente nivel";
            this->btnSiguienteNivel->UseVisualStyleBackColor = true;
            this->btnSiguienteNivel->Click += gcnew System::EventHandler(this, &FrmFinMundoHumano::btnSiguienteNivel_Click);
            // 
            // btnSalir
            // 
            this->btnSalir->Location = System::Drawing::Point(981, 908);
            this->btnSalir->Name = L"btnSalir";
            this->btnSalir->Size = System::Drawing::Size(185, 102);
            this->btnSalir->TabIndex = 1;
            this->btnSalir->Text = L"Salir";
            this->btnSalir->UseVisualStyleBackColor = true;
            this->btnSalir->Click += gcnew System::EventHandler(this, &FrmFinMundoHumano::btnSalir_Click);
            // 
            // btnVolverInicio
            // 
            this->btnVolverInicio->Location = System::Drawing::Point(355, 858);
            this->btnVolverInicio->Name = L"btnVolverInicio";
            this->btnVolverInicio->Size = System::Drawing::Size(237, 124);
            this->btnVolverInicio->TabIndex = 2;
            this->btnVolverInicio->Text = L"Volver";
            this->btnVolverInicio->UseVisualStyleBackColor = true;
            this->btnVolverInicio->Click += gcnew System::EventHandler(this, &FrmFinMundoHumano::btnVolverInicio_Click);
            // 
            // lblTitulo
            // 
            this->lblTitulo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
                static_cast<System::Int32>(static_cast<System::Byte>(67)));
            this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
            this->lblTitulo->ForeColor = System::Drawing::Color::Yellow;
            this->lblTitulo->Location = System::Drawing::Point(750, 184);
            this->lblTitulo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lblTitulo->Name = L"lblTitulo";
            this->lblTitulo->Padding = System::Windows::Forms::Padding(8);
            this->lblTitulo->Size = System::Drawing::Size(522, 91);
            this->lblTitulo->TabIndex = 13;
            this->lblTitulo->Visible = false;
            // 
            // lblResumen
            // 
            this->lblResumen->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
                static_cast<System::Int32>(static_cast<System::Byte>(67)));
            this->lblResumen->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
            this->lblResumen->ForeColor = System::Drawing::Color::Yellow;
            this->lblResumen->Location = System::Drawing::Point(418, 340);
            this->lblResumen->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lblResumen->Name = L"lblResumen";
            this->lblResumen->Padding = System::Windows::Forms::Padding(8);
            this->lblResumen->Size = System::Drawing::Size(1220, 249);
            this->lblResumen->TabIndex = 14;
            this->lblResumen->Visible = false;
            // 
            // lblStats
            // 
            this->lblStats->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
                static_cast<System::Int32>(static_cast<System::Byte>(67)));
            this->lblStats->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
            this->lblStats->ForeColor = System::Drawing::Color::Yellow;
            this->lblStats->Location = System::Drawing::Point(750, 618);
            this->lblStats->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lblStats->Name = L"lblStats";
            this->lblStats->Padding = System::Windows::Forms::Padding(8);
            this->lblStats->Size = System::Drawing::Size(601, 270);
            this->lblStats->TabIndex = 15;
            this->lblStats->Visible = false;
            this->lblStats->Click += gcnew System::EventHandler(this, &FrmFinMundoHumano::lblStats_Click);
            // 
            // FrmFinMundoHumano
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(1920, 1080);
            this->Controls->Add(this->lblStats);
            this->Controls->Add(this->lblResumen);
            this->Controls->Add(this->lblTitulo);
            this->Controls->Add(this->btnVolverInicio);
            this->Controls->Add(this->btnSalir);
            this->Controls->Add(this->btnSiguienteNivel);
            this->DoubleBuffered = true;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"FrmFinMundoHumano";
            this->Text = L"FrmFinMundoHumano";
            this->Load += gcnew System::EventHandler(this, &FrmFinMundoHumano::FrmFinMundoHumano_Load);
            this->ResumeLayout(false);

        }
#pragma endregion
	private:
        void construirFinal(bool gano, int vidas, int estabilidad, int criterio, int progreso)
        {
            std::string titulo;
            std::string textoEstado;
            std::string textoCriterio;
            std::string textoStats;

            // --- Texto sobre el criterio humano (SIEMPRE aparece) ---
            if (criterio < 40) {
                textoCriterio =
                    "Criterio humano: BAJO (" + std::to_string(criterio) + "%)\n"
                    "Tus decisiones se apoyaron poco en el analisis y la evaluacion de consecuencias.\n"
                    "Actuaste mas por impulso o prueba y error que por pensamiento critico.\n";
            }
            else if (criterio <= 70) {
                textoCriterio =
                    "Criterio humano: MEDIO (" + std::to_string(criterio) + "%)\n"
                    "Mostraste momentos de buen analisis, pero tambien decisiones apresuradas.\n"
                    "Hay equilibrio, pero aun puedes cuestionar y priorizar mejor.\n";
            }
            else {
                textoCriterio =
                    "Criterio humano: ALTO (" + std::to_string(criterio) + "%)\n"
                    "Tus decisiones mostraron un uso consciente de la informacion, evaluando riesgos\n"
                    "y alternativas antes de actuar. Usaste el sistema como herramienta, no como sustituto.\n";
            }

            // --- Estado final (gano / perdio) ---
            if (!gano) {
                titulo = "Mision fallida";

                if (estabilidad <= 0) {
                    textoEstado =
                        "La nave perdio su estabilidad.\n\n"
                        "Las decisiones no alcanzaron para mantener el sistema en pie. "
                        "En un entorno critico, dejar problemas sin priorizar a tiempo tiene un costo.\n";
                }
                else if (vidas <= 0) {
                    textoEstado =
                        "Has agotado tus oportunidades.\n\n"
                        "Te expusiste al peligro sin la proteccion adecuada en momentos clave. "
                        "La prisa, sin criterio, puede ser tan peligrosa como no actuar.\n";
                }
                else {
                    textoEstado =
                        "No lograste completar la mision en este intento.\n\n"
                        "Quedaron modulos sin estabilizar. La proxima vez, "
                        "piensa que reparar primero y que riesgos estas dispuesto a asumir.\n";
                }

                // Botones para DERROTA
                btnSiguienteNivel->Visible = false;
                btnSalir->Visible = false;
                btnVolverInicio->Visible = true;
            }
            else {
                titulo = "Mision completada";

                textoEstado =
                    "Has estabilizado los modulos criticos de la nave y evitado el colapso del sistema.\n\n"
                    "Mas alla de 'responder bien', tus decisiones muestran como el criterio humano puede\n"
                    "ordenar prioridades, usar recursos y asumir consecuencias en un entorno complejo.\n";

                // Botones para VICTORIA
                btnVolverInicio->Visible = false;
                btnSalir->Visible = true;
                btnSiguienteNivel->Visible = true;
            }

            // --- Stats numéricos ---
            textoStats =
                "Estabilidad final de la nave: " + std::to_string(estabilidad) + "%\n"
                "Indice de criterio humano:     " + std::to_string(criterio) + "%\n"
                "Progreso de la mision:         " + std::to_string(progreso) + "%\n"
                "Vidas restantes:               " + std::to_string(vidas) + "\n";

            // Pasar a labels .NET
            lblTitulo->Text = gcnew System::String(titulo.c_str());
            lblResumen->Text = gcnew System::String((textoEstado + "\n\n" + textoCriterio).c_str());
            lblStats->Text = gcnew System::String(textoStats.c_str());

            // Asegúrate de que se vean
            lblTitulo->Visible = true;
            lblResumen->Visible = true;
            lblStats->Visible = true;
        }

	private: System::Void FrmFinMundoHumano_Load(System::Object^ sender, System::EventArgs^ e) {
	}
    private: System::Void btnVolverInicio_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel; // volver al inicio de la app
        this->Close();
    }
private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
    this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
    this->Close();
}
private: System::Void btnSiguienteNivel_Click(System::Object^ sender, System::EventArgs^ e) {
    this->DialogResult = System::Windows::Forms::DialogResult::OK; // seguir al siguiente nivel 

    this->Close();
}
private: System::Void lblStats_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
