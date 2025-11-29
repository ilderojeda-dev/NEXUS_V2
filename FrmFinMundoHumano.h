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
		FrmFinMundoHumano(bool gano, bool esHistoria, int vidas, int estabilidad, int criterio, int progreso)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
            ConfigurarEstiloVisual();           // 👈 aplicar diseño
            construirFinal(gano, esHistoria, vidas, estabilidad, criterio, progreso);
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
            this->btnVolverInicio = (gcnew System::Windows::Forms::Button());
            this->lblTitulo = (gcnew System::Windows::Forms::Label());
            this->lblResumen = (gcnew System::Windows::Forms::Label());
            this->lblStats = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // btnSiguienteNivel
            // 
            this->btnSiguienteNivel->Location = System::Drawing::Point(1430, 897);
            this->btnSiguienteNivel->Name = L"btnSiguienteNivel";
            this->btnSiguienteNivel->Size = System::Drawing::Size(186, 102);
            this->btnSiguienteNivel->TabIndex = 0;
            this->btnSiguienteNivel->Text = L"Siguiente nivel";
            this->btnSiguienteNivel->UseVisualStyleBackColor = true;
            this->btnSiguienteNivel->Visible = false;
            this->btnSiguienteNivel->Click += gcnew System::EventHandler(this, &FrmFinMundoHumano::btnSiguienteNivel_Click);
            // 
            // btnVolverInicio
            // 
            this->btnVolverInicio->Location = System::Drawing::Point(812, 875);
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
            this->lblTitulo->Location = System::Drawing::Point(705, 184);
            this->lblTitulo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lblTitulo->Name = L"lblTitulo";
            this->lblTitulo->Padding = System::Windows::Forms::Padding(8);
            this->lblTitulo->Size = System::Drawing::Size(522, 91);
            this->lblTitulo->TabIndex = 13;
            this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            this->lblTitulo->Visible = false;
            // 
            // lblResumen
            // 
            this->lblResumen->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
                static_cast<System::Int32>(static_cast<System::Byte>(67)));
            this->lblResumen->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
            this->lblResumen->ForeColor = System::Drawing::Color::Yellow;
            this->lblResumen->Location = System::Drawing::Point(418, 302);
            this->lblResumen->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lblResumen->Name = L"lblResumen";
            this->lblResumen->Padding = System::Windows::Forms::Padding(8);
            this->lblResumen->Size = System::Drawing::Size(1220, 312);
            this->lblResumen->TabIndex = 14;
            this->lblResumen->Visible = false;
            // 
            // lblStats
            // 
            this->lblStats->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
                static_cast<System::Int32>(static_cast<System::Byte>(67)));
            this->lblStats->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
            this->lblStats->ForeColor = System::Drawing::Color::Yellow;
            this->lblStats->Location = System::Drawing::Point(704, 630);
            this->lblStats->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lblStats->Name = L"lblStats";
            this->lblStats->Padding = System::Windows::Forms::Padding(8);
            this->lblStats->Size = System::Drawing::Size(601, 216);
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
        void construirFinal(bool gano, bool esHistoria, int vidas, int estabilidad, int criterio, int progreso)
        {
            string titulo;
            string textoEstado;
            string textoCriterio;
            string textoStats;

            // ------------------------------
            // A. Criterio humano (segun gano/perdio)
            // ------------------------------
            if (!gano) {
                // PERDIO LA MISION
                if (criterio < 40) {
                    textoCriterio =
                        "Criterio humano: BAJO (" + std::to_string(criterio) + "%)\n"
                        "Empezaste con un 100% de criterio, pero muchas decisiones sin analizar fueron\n"
                        "agotando ese margen.\n"
                        "En esta simulacion confiaste mas en el impulso que en anticipar consecuencias.\n"
                        "La proxima vez, intenta detenerte un momento antes de decidir que reparar o por donde avanzar.\n";
                }
                else if (criterio <= 70) {
                    textoCriterio =
                        "Criterio humano: MEDIO (" + std::to_string(criterio) + "%)\n"
                        "Hubo buenos momentos de analisis, pero en instantes clave volviste a moverte sin suficiente\n"
                        "reflexion.\n"
                        "Con un poco mas de cuestionamiento y priorizacion, esta mision podia haber llegado a buen final.\n";
                }
                else {
                    textoCriterio =
                        "Criterio humano: ALTO (" + std::to_string(criterio) + "%)\n"
                        "En papel mantuviste un alto nivel de criterio, pero no lo aplicaste en todas tus decisiones.\n"
                        "Fallaste la mision por acciones concretas: arriesgarte sin proteccion o dejar modulos sin cerrar.\n"
                        "El numero alto te recuerda que el criterio sirve solo si se usa a tiempo.\n";
                }
            }
            else {
                // GANO LA MISION
                if (criterio < 40) {
                    textoCriterio =
                        "Criterio humano: BAJO (" + std::to_string(criterio) + "%)\n"
                        "Lograste completar la mision, pero con un criterio muy desgastado.\n"
                        "Salvaste la nave a costa de muchos intentos y decisiones poco analizadas.\n"
                        "Piensa como podrias llegar al mismo resultado usando menos prueba y mas evaluacion previa.\n";
                }
                else if (criterio <= 70) {
                    textoCriterio =
                        "Criterio humano: MEDIO (" + std::to_string(criterio) + "%)\n"
                        "Combinaste buenos momentos de analisis con otros mas impulsivos.\n"
                        "La mision se completo, pero aun hay espacio para mejorar como ordenas prioridades y riesgos.\n"
                        "Si ajustas un poco la forma en que evalúas cada opcion, la proxima vez podras resolver con mas calma.\n";
                }
                else {
                    textoCriterio =
                        "Criterio humano: ALTO (" + std::to_string(criterio) + "%)\n"
                        "Cerraste la mision conservando casi todo tu criterio inicial.\n"
                        "Tus decisiones mostraron un uso consciente de la informacion disponible,\n"
                        "priorizando, evaluando riesgos y usando la nave como herramienta, no como piloto automatico.\n"
                        "Este es el tipo de criterio que queremos ver fuera del simulador.\n";
                }
            }

            // -----------------------------
            // B. Estado final (gano / perdio)
            // -----------------------------
            if (!gano) {
                titulo = "Mision fallida";

                if (estabilidad <= 0) {
                    textoEstado =
                        "La nave perdio estabilidad critica.\n\n"
                        "Las decisiones que postergaron problemas importantes terminaron acumulandose.\n"
                        "En sistemas complejos, ignorar una alerta a tiempo puede hacer caer todo lo demas.\n";
                }
                else if (vidas <= 0) {
                    textoEstado =
                        "Has agotado tus oportunidades.\n\n"
                        "Te acercaste al peligro sin la proteccion adecuada en momentos clave.\n"
                        "La prisa sin criterio puede ser tan peligrosa como quedarse quieto.\n";
                }
                else {
                    textoEstado =
                        "La mision quedo incompleta.\n\n"
                        "Algunos modulos nunca llegaron a estabilizarse.\n"
                        "En una proxima simulacion, piensa que reparar primero y que riesgo estas dispuesto a asumir.\n";
                }

                // Botones para DERROTA
                btnSiguienteNivel->Visible = false;
                btnVolverInicio->Visible = true;
            }
            else {
                titulo = "Mision completada";

                textoEstado =
                    "Has estabilizado los modulos criticos de la nave y evitado el colapso del sistema.\n\n"
                    "Cada decision que tomaste fue ajustando poco a poco el equilibrio del sistema.\n"
                    "Mas que 'responder bien', usaste el criterio humano para ordenar prioridades y\n"
                    "asumir la responsabilidad de tus elecciones.\n";

                // Botones para VICTORIA
                btnVolverInicio->Visible = true;
                if (esHistoria) {
                    btnSiguienteNivel->Visible = true;
                }
            }

            // -----------------------------
            // C. Stats numericos
            // -----------------------------
            textoStats =
                "RESUMEN DE LA MISION\n\n"
                "Estabilidad final de la nave: " + std::to_string(estabilidad) + "%\n"
                "Indice de criterio humano:    " + std::to_string(criterio) + "%\n"
                "Progreso de la mision:        " + std::to_string(progreso) + "%\n"
                "Vidas restantes:              " + std::to_string(vidas) + "\n";

            // Pasar a labels .NET
            lblTitulo->Text = gcnew System::String(titulo.c_str());
            lblResumen->Text = gcnew System::String((textoEstado + "\n" + textoCriterio).c_str());
            lblStats->Text = gcnew System::String(textoStats.c_str());

            lblTitulo->Visible = true;
            lblResumen->Visible = true;
            lblStats->Visible = true;
        }
        void ConfigurarEstiloVisual()
        {
            // Color de paneles: azul oscuro semitransparente que combine con el fondo
            System::Drawing::Color panelColor =
                System::Drawing::Color::FromArgb(210, 4, 35, 71);  // A,R,G,B

            System::Drawing::Color textoPrincipal =
                System::Drawing::Color::FromArgb(255, 255, 230, 140); // amarillo suave
            System::Drawing::Color textoSecundario =
                System::Drawing::Color::FromArgb(255, 220, 230, 255); // casi blanco

            // --------- Titulo ----------
            lblTitulo->BackColor = panelColor;
            lblTitulo->ForeColor = textoPrincipal;
            lblTitulo->Font = gcnew System::Drawing::Font(
                "Segoe UI Semibold", 24.0f, System::Drawing::FontStyle::Bold);
            lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            lblTitulo->AutoSize = false;              // para que respete el tamaño del rectángulo
            // si quieres estirarlo un poco mas:
            // lblTitulo->Width = 600;

            // --------- Resumen ----------
            lblResumen->BackColor = panelColor;
            lblResumen->ForeColor = textoSecundario;
            lblResumen->Font = gcnew System::Drawing::Font(
                "Segoe UI", 14.0f, System::Drawing::FontStyle::Regular);
            lblResumen->TextAlign = System::Drawing::ContentAlignment::TopLeft;

            // --------- Stats ----------
            lblStats->BackColor = panelColor;
            lblStats->ForeColor = textoSecundario;
            lblStats->Font = gcnew System::Drawing::Font(
                "Segoe UI", 16.0f, System::Drawing::FontStyle::Regular);
            lblStats->TextAlign = System::Drawing::ContentAlignment::TopLeft;

            // --------- Botones ----------
            cli::array<System::Windows::Forms::Button^>^ botones =
                gcnew cli::array<System::Windows::Forms::Button^>(2) {
                btnVolverInicio, btnSiguienteNivel
            };

            for each (System::Windows::Forms::Button ^ b in botones) {
                b->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
                b->FlatAppearance->BorderSize = 0;
                b->BackColor = System::Drawing::Color::FromArgb(255, 255, 204, 0); // amarillo
                b->ForeColor = System::Drawing::Color::FromArgb(255, 35, 20, 40);  // vino oscuro
                b->Font = gcnew System::Drawing::Font(
                    "Segoe UI", 14.0f, System::Drawing::FontStyle::Bold);
                b->Cursor = System::Windows::Forms::Cursors::Hand;
            }

            // Opcional: darle un pequeño sombreado al formulario
            this->DoubleBuffered = true;
        }


	private: System::Void FrmFinMundoHumano_Load(System::Object^ sender, System::EventArgs^ e) {
	}
    private: System::Void btnVolverInicio_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel; // volver al inicio de la app
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
