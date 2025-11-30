#pragma once
#include "Mundo.h"
#include "Nave.h"
#include "MundoColabService.h"
#include "PreguntaDialogoServiceMundoColab.h"
#include "FrmGameOverMundoColab.h"
#include "FrmYouWinMundoColab.h"
using namespace System;
namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMundoColab
	/// </summary>
	public ref class FrmMundoColab : public System::Windows::Forms::Form
	{
	public:
		FrmMundoColab(void)
		{
			this->KeyPreview = true; // Habilitar la captura de teclas en el formulario
			InitializeComponent();
			// --- OPTIMIZACIÓN: INICIALIZACIÓN DE BUFFER PERSISTENTE ---
			// 1. Obtener el contexto de buffer.
			bufferContext = BufferedGraphicsManager::Current;
			// 2. Asignar el buffer. Creamos un Graphics object solo AQUI, no en cada Tick.
			buffer = bufferContext->Allocate(this->pnlJuego->CreateGraphics(), this->pnlJuego->ClientRectangle);
			// -----------------------------------------------------------
		
			//TODO: Add the constructor code here
			//
			int altoHUD = pnlHUD->Height;
			mundoColab = new MundoColabService(pnlJuego->Width, pnlJuego->Height - altoHUD + 50, 3);

			char rutaFondo[] = "FondoMundoCOlab.png";
			mundoColab->cargarFondo(rutaFondo);

			char rutaNave[] = "SpriteNave.png";
			mundoColab->CargarSpriteNave(rutaNave, 1, 4);

			char rutaR2D2[] = "R2D2 Sprite.png";
			mundoColab->cargarR2D2(rutaR2D2, 1, 4);

			mundoColab->spawnMeteorito(1); //mantener 1 meteorito si o si (no es necesario)
			mundoColab->spawnEstrella(1); //lo mismo

			teclaPresionadaNave = Direccion::Ninguno;
		}

	protected:

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMundoColab()
		{
			if (components)
			{
				delete components;
			}
			if (mundoColab) {
				delete mundoColab;
			}
			// --- OPTIMIZACIÓN: LIBERAR EL BUFFER PERSISTENTE ---
			if (buffer) {
				delete buffer;
			}
			// ---------------------------------------------------
		}

	private:
		// --- MIEMBROS AÑADIDOS PARA OPTIMIZACIÓN GRÁFICA ---
		BufferedGraphicsContext^ bufferContext;
		BufferedGraphics^ buffer;
		// ---------------------------------------------------
		int tiempoTotal = 0;
		int tiempoDialogo = 0;
		int indiceDialogo = 0;
		int respuestaCorrectaIndex;
		Dialogo* dialogoMostrandose = nullptr;
		MundoColabService* mundoColab;
		Direccion teclaPresionadaNave;

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Panel^ pnlJuego;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ pnlHUD;
	private: System::Windows::Forms::Panel^ pnlTexto;

	private: System::Windows::Forms::Panel^ pnlAliado;
	private: System::Windows::Forms::Panel^ pnlInfo;
	private: System::Windows::Forms::Label^ lblPregunta;



	private: System::Windows::Forms::Label^ lblMensaje;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ lblBalas;
	private: System::Windows::Forms::Label^ lblOp1;
	private: System::Windows::Forms::Label^ lblOp3;
	private: System::Windows::Forms::Label^ lblOp2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ lblDialogo;
	private: System::Windows::Forms::Label^ Mensaje;
	private: System::Windows::Forms::Label^ lblConfianzaR2D2;
	private: System::Windows::Forms::Label^ lblTiempo;












	private: System::ComponentModel::IContainer^ components;

		   /// <summary>
		/// Required designer variable.	
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMundoColab::typeid));
			   this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			   this->pnlJuego = (gcnew System::Windows::Forms::Panel());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->pnlTexto = (gcnew System::Windows::Forms::Panel());
			   this->lblOp3 = (gcnew System::Windows::Forms::Label());
			   this->lblOp2 = (gcnew System::Windows::Forms::Label());
			   this->lblOp1 = (gcnew System::Windows::Forms::Label());
			   this->lblPregunta = (gcnew System::Windows::Forms::Label());
			   this->lblDialogo = (gcnew System::Windows::Forms::Label());
			   this->pnlHUD = (gcnew System::Windows::Forms::Panel());
			   this->pnlInfo = (gcnew System::Windows::Forms::Panel());
			   this->lblConfianzaR2D2 = (gcnew System::Windows::Forms::Label());
			   this->Mensaje = (gcnew System::Windows::Forms::Label());
			   this->lblMensaje = (gcnew System::Windows::Forms::Label());
			   this->lblVidas = (gcnew System::Windows::Forms::Label());
			   this->lblBalas = (gcnew System::Windows::Forms::Label());
			   this->pnlAliado = (gcnew System::Windows::Forms::Panel());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->lblTiempo = (gcnew System::Windows::Forms::Label());
			   this->pnlJuego->SuspendLayout();
			   this->panel1->SuspendLayout();
			   this->pnlTexto->SuspendLayout();
			   this->pnlHUD->SuspendLayout();
			   this->pnlInfo->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // backgroundWorker1
			   // 
			   this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &FrmMundoColab::backgroundWorker1_DoWork);
			   // 
			   // pnlJuego
			   // 
			   this->pnlJuego->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlJuego.BackgroundImage")));
			   this->pnlJuego->Controls->Add(this->panel1);
			   this->pnlJuego->Controls->Add(this->pnlHUD);
			   this->pnlJuego->Location = System::Drawing::Point(0, 0);
			   this->pnlJuego->Name = L"pnlJuego";
			   this->pnlJuego->Size = System::Drawing::Size(1920, 1080);
			   this->pnlJuego->TabIndex = 0;
			   this->pnlJuego->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMundoColab::pnlJuego_Paint);
			   // 
			   // panel1
			   // 
			   this->panel1->AutoSize = true;
			   this->panel1->BackColor = System::Drawing::Color::Black;
			   this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			   this->panel1->Controls->Add(this->pnlTexto);
			   this->panel1->Controls->Add(this->lblDialogo);
			   this->panel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->panel1->Location = System::Drawing::Point(397, 853);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(1023, 230);
			   this->panel1->TabIndex = 4;
			   // 
			   // pnlTexto
			   // 
			   this->pnlTexto->AutoSize = true;
			   this->pnlTexto->BackColor = System::Drawing::Color::Black;
			   this->pnlTexto->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlTexto.BackgroundImage")));
			   this->pnlTexto->Controls->Add(this->lblOp3);
			   this->pnlTexto->Controls->Add(this->lblOp2);
			   this->pnlTexto->Controls->Add(this->lblOp1);
			   this->pnlTexto->Controls->Add(this->lblPregunta);
			   this->pnlTexto->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->pnlTexto->Location = System::Drawing::Point(0, 0);
			   this->pnlTexto->Name = L"pnlTexto";
			   this->pnlTexto->Size = System::Drawing::Size(1020, 227);
			   this->pnlTexto->TabIndex = 1;
			   // 
			   // lblOp3
			   // 
			   this->lblOp3->AutoSize = true;
			   this->lblOp3->Location = System::Drawing::Point(680, 156);
			   this->lblOp3->Name = L"lblOp3";
			   this->lblOp3->Size = System::Drawing::Size(19, 13);
			   this->lblOp3->TabIndex = 3;
			   this->lblOp3->Text = L"3) ";
			   // 
			   // lblOp2
			   // 
			   this->lblOp2->AutoSize = true;
			   this->lblOp2->Location = System::Drawing::Point(397, 156);
			   this->lblOp2->Name = L"lblOp2";
			   this->lblOp2->Size = System::Drawing::Size(19, 13);
			   this->lblOp2->TabIndex = 2;
			   this->lblOp2->Text = L"2) ";
			   // 
			   // lblOp1
			   // 
			   this->lblOp1->AutoSize = true;
			   this->lblOp1->Location = System::Drawing::Point(48, 156);
			   this->lblOp1->Name = L"lblOp1";
			   this->lblOp1->Size = System::Drawing::Size(19, 13);
			   this->lblOp1->TabIndex = 1;
			   this->lblOp1->Text = L"1) ";
			   // 
			   // lblPregunta
			   // 
			   this->lblPregunta->AutoSize = true;
			   this->lblPregunta->Location = System::Drawing::Point(48, 65);
			   this->lblPregunta->Name = L"lblPregunta";
			   this->lblPregunta->Size = System::Drawing::Size(56, 13);
			   this->lblPregunta->TabIndex = 0;
			   this->lblPregunta->Text = L"Pregunta: ";
			   this->lblPregunta->Click += gcnew System::EventHandler(this, &FrmMundoColab::lblDialogo_Click);
			   // 
			   // lblDialogo
			   // 
			   this->lblDialogo->AutoSize = true;
			   this->lblDialogo->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblDialogo->Location = System::Drawing::Point(71, 75);
			   this->lblDialogo->Name = L"lblDialogo";
			   this->lblDialogo->Size = System::Drawing::Size(179, 25);
			   this->lblDialogo->TabIndex = 0;
			   this->lblDialogo->Text = L"Traductor de RD2D: ";
			   // 
			   // pnlHUD
			   // 
			   this->pnlHUD->Controls->Add(this->pnlInfo);
			   this->pnlHUD->Controls->Add(this->pnlAliado);
			   this->pnlHUD->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->pnlHUD->Location = System::Drawing::Point(0, 853);
			   this->pnlHUD->Name = L"pnlHUD";
			   this->pnlHUD->Size = System::Drawing::Size(1920, 227);
			   this->pnlHUD->TabIndex = 0;
			   // 
			   // pnlInfo
			   // 
			   this->pnlInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->pnlInfo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlInfo.BackgroundImage")));
			   this->pnlInfo->Controls->Add(this->lblTiempo);
			   this->pnlInfo->Controls->Add(this->lblConfianzaR2D2);
			   this->pnlInfo->Controls->Add(this->Mensaje);
			   this->pnlInfo->Controls->Add(this->lblMensaje);
			   this->pnlInfo->Controls->Add(this->lblVidas);
			   this->pnlInfo->Controls->Add(this->lblBalas);
			   this->pnlInfo->Dock = System::Windows::Forms::DockStyle::Right;
			   this->pnlInfo->ForeColor = System::Drawing::Color::Yellow;
			   this->pnlInfo->Location = System::Drawing::Point(1414, 0);
			   this->pnlInfo->Name = L"pnlInfo";
			   this->pnlInfo->Size = System::Drawing::Size(506, 227);
			   this->pnlInfo->TabIndex = 2;
			   // 
			   // lblConfianzaR2D2
			   // 
			   this->lblConfianzaR2D2->Location = System::Drawing::Point(55, 156);
			   this->lblConfianzaR2D2->Name = L"lblConfianzaR2D2";
			   this->lblConfianzaR2D2->Size = System::Drawing::Size(167, 13);
			   this->lblConfianzaR2D2->TabIndex = 4;
			   this->lblConfianzaR2D2->Text = L"Confianza con R2D2: ";
			   this->lblConfianzaR2D2->Click += gcnew System::EventHandler(this, &FrmMundoColab::label1_Click);
			   // 
			   // Mensaje
			   // 
			   this->Mensaje->Location = System::Drawing::Point(55, 114);
			   this->Mensaje->Name = L"Mensaje";
			   this->Mensaje->Size = System::Drawing::Size(401, 29);
			   this->Mensaje->TabIndex = 3;
			   this->Mensaje->Text = L"Por cada pregunta respondida correctamente tendrás más chance de recargar más bal"
				   L"as (confianza con R2D2)";
			   // 
			   // lblMensaje
			   // 
			   this->lblMensaje->AutoSize = true;
			   this->lblMensaje->Location = System::Drawing::Point(55, 88);
			   this->lblMensaje->Name = L"lblMensaje";
			   this->lblMensaje->Size = System::Drawing::Size(237, 13);
			   this->lblMensaje->TabIndex = 2;
			   this->lblMensaje->Text = L"Presiona r para recargar cuando no tengas balas";
			   // 
			   // lblVidas
			   // 
			   this->lblVidas->AutoSize = true;
			   this->lblVidas->Location = System::Drawing::Point(55, 55);
			   this->lblVidas->Name = L"lblVidas";
			   this->lblVidas->Size = System::Drawing::Size(39, 13);
			   this->lblVidas->TabIndex = 1;
			   this->lblVidas->Text = L"Vidas: ";
			   // 
			   // lblBalas
			   // 
			   this->lblBalas->AutoSize = true;
			   this->lblBalas->Location = System::Drawing::Point(55, 25);
			   this->lblBalas->Name = L"lblBalas";
			   this->lblBalas->Size = System::Drawing::Size(39, 13);
			   this->lblBalas->TabIndex = 0;
			   this->lblBalas->Text = L"Balas: ";
			   this->lblBalas->Click += gcnew System::EventHandler(this, &FrmMundoColab::lblBalas_Click);
			   // 
			   // pnlAliado
			   // 
			   this->pnlAliado->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->pnlAliado->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlAliado.BackgroundImage")));
			   this->pnlAliado->Dock = System::Windows::Forms::DockStyle::Left;
			   this->pnlAliado->Location = System::Drawing::Point(0, 0);
			   this->pnlAliado->Name = L"pnlAliado";
			   this->pnlAliado->Size = System::Drawing::Size(400, 227);
			   this->pnlAliado->TabIndex = 0;
			   this->pnlAliado->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMundoColab::pnlAliado_Paint);
			   // 
			   // timer1
			   // 
			   this->timer1->Tick += gcnew System::EventHandler(this, &FrmMundoColab::timer1_Tick);
			   // 
			   // lblTiempo
			   // 
			   this->lblTiempo->Location = System::Drawing::Point(273, 30);
			   this->lblTiempo->Name = L"lblTiempo";
			   this->lblTiempo->Size = System::Drawing::Size(119, 30);
			   this->lblTiempo->TabIndex = 5;
			   this->lblTiempo->Text = L"Tiempo restante para sobrevivir: ";
			   // 
			   // FrmMundoColab
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1904, 1041);
			   this->Controls->Add(this->pnlJuego);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Name = L"FrmMundoColab";
			   this->Text = L"FrmMundoColab";
			   this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			   this->Load += gcnew System::EventHandler(this, &FrmMundoColab::FrmMundoColab_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoColab::FrmMundoColab_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoColab::FrmMundoColab_KeyUp);
			   this->pnlJuego->ResumeLayout(false);
			   this->pnlJuego->PerformLayout();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->pnlTexto->ResumeLayout(false);
			   this->pnlTexto->PerformLayout();
			   this->pnlHUD->ResumeLayout(false);
			   this->pnlInfo->ResumeLayout(false);
			   this->pnlInfo->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion

		   // --- FUNCIÓN CLAVE: VERIFICAR ESTADO (VICTORIA/DERROTA) ---
	private: void checkGameStatus() {
		// Usamos el getter de MundoColabService para verificar las vidas y el tiempo

		// 1. Verificar la condición de Victoria: Sobrevivir 500 ticks de tiempoTotal
		if (mundoColab != nullptr && tiempoTotal >= 500) {

			timer1->Enabled = false; // Detener el timer del juego

			// Mostrar el formulario de Victoria
			NEXUSV2::FrmYouWinMundoColab^ winForm = gcnew NEXUSV2::FrmYouWinMundoColab();
			winForm->Show();

			// Ocultar este formulario de juego
			this->Hide();
			return; // Salir, ya se ganó.
		}

		// 2. Verificar la condición de Derrota (Game Over)
		if (mundoColab != nullptr && mundoColab->getVidasNave() <= 0) {

			timer1->Enabled = false; // Detener el timer del juego

			// Creamos una instancia del formulario de Game Over
			NEXUSV2::FrmGameOverMundoColab^ gameOverForm = gcnew NEXUSV2::FrmGameOverMundoColab();

			// Lo mostramos.
			gameOverForm->Show();

			// Ocultar este formulario de juego
			this->Hide();
		}
	}

		   // --- FUNCIÓN CENTRALIZADA PARA ACTUALIZAR EL HUD (Paso 4) ---
	private: void actualizarHUD() {
		// Esta función centraliza todas las actualizaciones de etiquetas
		lblBalas->Text = "Balas: " + mundoColab->getBalasDisponibles().ToString() +
			" / " + mundoColab->getBalasMaximas().ToString();
		lblVidas->Text = "Vidas: " + mundoColab->getVidasNave().ToString();
		lblTiempo->Text = "Tiempo para sobrevivir: " + tiempoTotal.ToString() + " /500";

		// Lógica de mensaje de recarga
		if (mundoColab->getNecesitaRecargar()) {
			lblMensaje->Text = "¡SIN BALAS! Presiona R para recargar";
			lblMensaje->ForeColor = Color::Red;
		}
		else {
			lblMensaje->Text = "Presiona L para disparar (R para recargar)";
			lblMensaje->ForeColor = Color::Yellow; // O el color original que uses
		}

		// Asumiendo que getRespuestasCorrectas() existe en MundoColabService
		// lblConfianzaR2D2->Text = "Confianza con R2D2: " + mundoColab->getRespuestasCorrectas().ToString(); 
	}





		   
	private: System::Void FrmMundoColab_Load(System::Object^ sender, System::EventArgs^ e) {
		timer1->Start();
		pnlTexto->Visible = false;
		pnlTexto->BringToFront();
		actualizarHUD(); // Llamada inicial
	}

		   void FrmMundoColab::mostrarDialogo() {

			   PreguntaDialogoServiceMundoColab* svc = mundoColab->getPreguntaServiceMundoColab();
			   if (svc == nullptr) return;

			   dialogoMostrandose = svc->obtenerDialogo(indiceDialogo);

			   if (dialogoMostrandose != nullptr) {
				   dialogoMostrandose->iniciar(dialogoMostrandose->getTextoCompleto());
				   lblDialogo->Text = ""; // limpiar antes de iniciar
			   }

			   indiceDialogo++;

			   if (indiceDialogo >= svc->getCantidadDialogos())
				   indiceDialogo = 0;
		   }
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	}

		private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

			// Lógica del juego y movimiento
			if (teclaPresionadaNave != Direccion::Ninguno) {
				mundoColab->moverNave(teclaPresionadaNave);
			}
			mundoColab->verificarColisiones(); // ES MUY IMPORTANTE LLAMAR A COLISIONES AQUÍ

			// --- VERIFICACIÓN DE FIN DE JUEGO (CORRECCIÓN) ---
			checkGameStatus();
			// Detenemos la ejecución de la lógica del juego si el timer está desactivado
			if (!timer1->Enabled) return;
			// ---------------------------------------------------

			mundoColab->moverMeteorito();
			mundoColab->moverEstrella();
			mundoColab->moverBalas();

			mundoColab->animarAliado();
			pnlAliado->Invalidate();

			// Lógica de tiempo y diálogo
			tiempoTotal++;
			tiempoDialogo++;
			if (tiempoDialogo >= 50) {
				mostrarDialogo();
				tiempoDialogo = 0;
			}
			if (dialogoMostrandose != nullptr) {

				bool sigue = dialogoMostrandose->actualizar();
				lblDialogo->Text = gcnew String(dialogoMostrandose->getTextoActual().c_str());

				if (!sigue) {
					dialogoMostrandose = nullptr;
				}
			}

			// --- OPTIMIZACIÓN: RENDERIZADO CON BUFFER PERSISTENTE ---
			// 1. Dibujar todo en el buffer
			mundoColab->dibujarTodo(buffer->Graphics);
			// 2. Renderizar el buffer a la pantalla. No se crean ni se borran objetos Graphics.
			buffer->Render();
			// ---------------------------------------------------------

			// Actualizar el HUD
			actualizarHUD();
		}


	private: System::Void FrmMundoColab_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		// ... (lógica de movimiento W, S, A, D)

		if (e->KeyCode == Keys::W) {
			teclaPresionadaNave = Direccion::Arriba;
		}
		if (e->KeyCode == Keys::S) {
			teclaPresionadaNave = Direccion::Abajo;
		}
		if (e->KeyCode == Keys::A) {
			teclaPresionadaNave = Direccion::Izquierda;
		}

		if (e->KeyCode == Keys::D) {
			teclaPresionadaNave = Direccion::Derecha;
		}

		// Disparar
		if (e->KeyCode == Keys::L) {
			mundoColab->disparar();
		}

		// Recargar
		if (e->KeyCode == Keys::R) {
			// Si se necesita recargar y la pregunta no está visible, mostrar pregunta
			if (mundoColab->getNecesitaRecargar() && !pnlTexto->Visible) {
				mostrarPregunta();
			}
		}

		// Respuestas
		if (pnlTexto->Visible) {
			if (e->KeyCode == Keys::D1) procesarRespuesta(0);
			if (e->KeyCode == Keys::D2) procesarRespuesta(1);
			if (e->KeyCode == Keys::D3) procesarRespuesta(2);
		}

	}




	private: System::Void FrmMundoColab_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::W || e->KeyCode == Keys::S ||
			e->KeyCode == Keys::A || e->KeyCode == Keys::D) {
			teclaPresionadaNave = Direccion::Ninguno;
		}
	}

private: System::Void pnlJuego_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	// En un juego con Timer y Render(), este evento Paint se usa como fallback
	// o para redibujar elementos estáticos.
	// Si usas buffer->Render() en el Tick, esta función es menos crítica.
	if (mundoColab != nullptr) {
		mundoColab->dibujarTodo(e->Graphics);
	}

}


	   void FrmMundoColab::mostrarPregunta() {
		   // Obtener puntero a la pregunta actual desde el servicio del mundo
		   PreguntaDialogoServiceMundoColab* svc = mundoColab->getPreguntaServiceMundoColab();
		   if (svc == nullptr) return;

		   Pregunta* p = svc->obtenerPreguntaActual(); // usa el método que tu service tiene
		   if (p == nullptr) return;

		   // getTextoPregunta() devuelve char*
		   char* texto = p->getTextoPregunta();
		   auto opciones = p->getOpciones(); // vector<char*>&

		   lblPregunta->Text = gcnew String(texto);

		   // Comprueba que haya al menos 3 opciones
		   if (opciones.size() >= 1) lblOp1->Text = gcnew String(opciones[0]);
		   else lblOp1->Text = "1) ";

		   if (opciones.size() >= 2) lblOp2->Text = gcnew String(opciones[1]);
		   else lblOp2->Text = "2) ";

		   if (opciones.size() >= 3) lblOp3->Text = gcnew String(opciones[2]);
		   else lblOp3->Text = "3) ";

		   // índice de respuesta correcta según tu clase Pregunta
		   respuestaCorrectaIndex = p->getRespuestaCorrecta();
		   pnlTexto->BackColor = System::Drawing::Color::FromArgb(180, 0, 0, 0);
		   // Mostrar panel de pregunta (asegúrate de que pnlPregunta exista en el diseñador)
		   pnlTexto->BringToFront();
		   pnlTexto->Visible = true;

		   // Pausar el juego
		   timer1->Enabled = false;
	   }


	   void FrmMundoColab::procesarRespuesta(int seleccionada) {

		   bool correcta = (seleccionada == respuestaCorrectaIndex);

		   mundoColab->procesarRecargaPorRespuesta(correcta);

		   lblConfianzaR2D2->Text = "Confianza con R2D2: " + mundoColab->getRespuestasCorrectas().ToString(); //nivel de confianza por respuesta correcta
		   // Ocultamos y limpiamos
		   pnlTexto->Visible = false;

		   lblPregunta->Text = "";
		   lblOp1->Text = "";
		   lblOp2->Text = "";
		   lblOp3->Text = "";

		   // Reanudar juego
		   timer1->Enabled = true;

		   // Pasar a siguiente pregunta
		   PreguntaDialogoServiceMundoColab* svc = mundoColab->getPreguntaServiceMundoColab();
		   if (svc) svc->avanzarSiguientePregunta();
	   }





		   //---------------------------------------------------------------------------------//
		   //PANELES

	private: System::Void pnlAliado_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (mundoColab != nullptr)mundoColab->dibujarAliadoR2D2(e->Graphics);

	}
	private: System::Void lblDialogo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lblBalas_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		   private: System::Void btnOp1_Click(System::Object^ sender, System::EventArgs^ e) {
			   procesarRespuesta(0);
		   }
private: System::Void btnOp2_Click(System::Object^ sender, System::EventArgs^ e) {
	procesarRespuesta(1);
}
private: System::Void btnOp3_Click(System::Object^ sender, System::EventArgs^ e) {
	procesarRespuesta(2);
}


private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

}
};
	}
