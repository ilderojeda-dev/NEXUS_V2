#pragma once
#include "MundoIAService.h"
#include "SoundManager.h"
#include "FrmFinMundoIA.h"

namespace NEXUSV2 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FrmMundoIA : public System::Windows::Forms::Form
	{
	public:
		FrmMundoIA(void)
		{
			InitializeComponent();


			

			mundoIAService = new MundoIAService(pnlMundoIA->Width, pnlMundoIA->Height, 3);

			// Cargar fondos
			mundoIAService->cargarFondos("FondoMundoIA.png", "FondoMundoIANoche.png");

			gestorSonido = gcnew NEXUS_V2::Service::SoundManager();
			gestorSonido->ReproducirMusica("MusicaFondoMundoIA.wav", 0.3); // Volumen bajo para música de fondo

			// Cargar jugador
			mundoIAService->cargarSpriteJugador("PersonajeMundoIA.png", 5, 8);
			mundoIAService->getJugador()->setEscala(0.4f);

			// Crear robots
			mundoIAService->crearRobots("RobotMundoIA.png", 4, 9);
			for (RobotEnemigo* robot : mundoIAService->getRobots()) {
				robot->setEscala(1.2f);
			}

			// Cargar boss
			mundoIAService->cargarFinalBoss("FinalBossMundoIA.png", 5, 8);
			mundoIAService->getFinalBoss()->setEscala(0.4f);

			// Sintia
			mundoIAService->cargarSintIA("SintIA.png", 4, 9);
			mundoIAService->getSintIA()->setEscala(0.4f);

			// Crear chips

			teclaPresionada = Ninguno;
			this->KeyPreview = true;
			btnSalir->TabStop = false;

			this->ActiveControl = nullptr;
			pnlDialogo->Visible = false;
			pnlDialogo->BringToFront();

			bossInvocado = false;
			sintiaInvocada = false;


		}

	protected:
		~FrmMundoIA()
		{
			if (components) delete components;
		}

	private:
		System::Windows::Forms::Panel^ pnlMundoIA;
		System::ComponentModel::IContainer^ components;
		MundoIAService* mundoIAService;
		System::Windows::Forms::Timer^ timer1;


		System::Windows::Forms::Panel^ pnlDialogo;
		System::Windows::Forms::Label^ lblRobotsEliminados;

		Direccion teclaPresionada;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ lblChips;

	private: NEXUS_V2::Service::SoundManager^ gestorSonido;




		   bool bossInvocado; 
	private: System::Windows::Forms::Label^ lblNivelAutonomia;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Button^ btnSalir;


		   bool sintiaInvocada; 
		   bool derrota = false;
		   bool victoria = false;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMundoIA::typeid));
			   this->pnlMundoIA = (gcnew System::Windows::Forms::Panel());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->pnlDialogo = (gcnew System::Windows::Forms::Panel());
			   this->lblRobotsEliminados = (gcnew System::Windows::Forms::Label());
			   this->lblVidas = (gcnew System::Windows::Forms::Label());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			   this->lblChips = (gcnew System::Windows::Forms::Label());
			   this->lblNivelAutonomia = (gcnew System::Windows::Forms::Label());
			   this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			   this->btnSalir = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // pnlMundoIA
			   // 
			   this->pnlMundoIA->BackColor = System::Drawing::SystemColors::ActiveBorder;
			   this->pnlMundoIA->Location = System::Drawing::Point(2, 2);
			   this->pnlMundoIA->Name = L"pnlMundoIA";
			   this->pnlMundoIA->Size = System::Drawing::Size(1967, 781);
			   this->pnlMundoIA->TabIndex = 0;
			   this->pnlMundoIA->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMundoIA::panel1_Paint);
			   // 
			   // timer1
			   // 
			   this->timer1->Tick += gcnew System::EventHandler(this, &FrmMundoIA::timer1_Tick);
			   // 
			   // pnlDialogo
			   // 
			   this->pnlDialogo->BackColor = System::Drawing::Color::AliceBlue;
			   this->pnlDialogo->Location = System::Drawing::Point(544, 803);
			   this->pnlDialogo->Name = L"pnlDialogo";
			   this->pnlDialogo->Size = System::Drawing::Size(675, 210);
			   this->pnlDialogo->TabIndex = 3;
			   // 
			   // lblRobotsEliminados
			   // 
			   this->lblRobotsEliminados->AutoSize = true;
			   this->lblRobotsEliminados->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 20.25F, System::Drawing::FontStyle::Bold));
			   this->lblRobotsEliminados->ForeColor = System::Drawing::SystemColors::ButtonFace;
			   this->lblRobotsEliminados->Location = System::Drawing::Point(123, 956);
			   this->lblRobotsEliminados->Name = L"lblRobotsEliminados";
			   this->lblRobotsEliminados->Size = System::Drawing::Size(277, 36);
			   this->lblRobotsEliminados->TabIndex = 4;
			   this->lblRobotsEliminados->Text = L"Robots Eliminados:";
			   this->lblRobotsEliminados->Click += gcnew System::EventHandler(this, &FrmMundoIA::lblRobotsEliminados_Click);
			   // 
			   // lblVidas
			   // 
			   this->lblVidas->AutoSize = true;
			   this->lblVidas->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 20.25F, System::Drawing::FontStyle::Bold));
			   this->lblVidas->ForeColor = System::Drawing::SystemColors::ButtonFace;
			   this->lblVidas->Location = System::Drawing::Point(135, 841);
			   this->lblVidas->Name = L"lblVidas";
			   this->lblVidas->Size = System::Drawing::Size(105, 36);
			   this->lblVidas->TabIndex = 5;
			   this->lblVidas->Text = L"Vidas: ";
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			   this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			   this->pictureBox1->Location = System::Drawing::Point(2, 789);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(115, 109);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox1->TabIndex = 6;
			   this->pictureBox1->TabStop = false;
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			   this->pictureBox2->Location = System::Drawing::Point(29, 932);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(67, 81);
			   this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox2->TabIndex = 7;
			   this->pictureBox2->TabStop = false;
			   // 
			   // pictureBox3
			   // 
			   this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			   this->pictureBox3->Location = System::Drawing::Point(1249, 809);
			   this->pictureBox3->Name = L"pictureBox3";
			   this->pictureBox3->Size = System::Drawing::Size(83, 89);
			   this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox3->TabIndex = 8;
			   this->pictureBox3->TabStop = false;
			   // 
			   // lblChips
			   // 
			   this->lblChips->AutoSize = true;
			   this->lblChips->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 20.25F, System::Drawing::FontStyle::Bold));
			   this->lblChips->ForeColor = System::Drawing::SystemColors::ButtonFace;
			   this->lblChips->Location = System::Drawing::Point(1351, 831);
			   this->lblChips->Name = L"lblChips";
			   this->lblChips->Size = System::Drawing::Size(316, 36);
			   this->lblChips->TabIndex = 9;
			   this->lblChips->Text = L"Chips Independencia: ";
			   // 
			   // lblNivelAutonomia
			   // 
			   this->lblNivelAutonomia->AutoSize = true;
			   this->lblNivelAutonomia->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblNivelAutonomia->ForeColor = System::Drawing::SystemColors::ButtonFace;
			   this->lblNivelAutonomia->Location = System::Drawing::Point(1370, 944);
			   this->lblNivelAutonomia->Name = L"lblNivelAutonomia";
			   this->lblNivelAutonomia->Size = System::Drawing::Size(256, 36);
			   this->lblNivelAutonomia->TabIndex = 0;
			   this->lblNivelAutonomia->Text = L"Nivel Autonomia:";
			   // 
			   // pictureBox4
			   // 
			   this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			   this->pictureBox4->Location = System::Drawing::Point(1249, 932);
			   this->pictureBox4->Name = L"pictureBox4";
			   this->pictureBox4->Size = System::Drawing::Size(83, 89);
			   this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox4->TabIndex = 10;
			   this->pictureBox4->TabStop = false;
			   // 
			   // btnSalir
			   // 
			   this->btnSalir->BackColor = System::Drawing::Color::IndianRed;
			   this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnSalir->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->btnSalir->Location = System::Drawing::Point(1798, 981);
			   this->btnSalir->Name = L"btnSalir";
			   this->btnSalir->Size = System::Drawing::Size(83, 32);
			   this->btnSalir->TabIndex = 0;
			   this->btnSalir->Text = L"SALIR";
			   this->btnSalir->UseVisualStyleBackColor = false;
			   this->btnSalir->Click += gcnew System::EventHandler(this, &FrmMundoIA::button1_Click);
			   // 
			   // FrmMundoIA
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->ClientSize = System::Drawing::Size(1904, 1041);
			   this->Controls->Add(this->btnSalir);
			   this->Controls->Add(this->pictureBox4);
			   this->Controls->Add(this->lblChips);
			   this->Controls->Add(this->pictureBox3);
			   this->Controls->Add(this->pictureBox2);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->lblVidas);
			   this->Controls->Add(this->lblRobotsEliminados);
			   this->Controls->Add(this->pnlDialogo);
			   this->Controls->Add(this->pnlMundoIA);
			   this->Controls->Add(this->lblNivelAutonomia);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Name = L"FrmMundoIA";
			   this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoIA::FrmMundoIA_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoIA::FrmMundoIA_KeyUp);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private:
		System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			timer1->Start();
		}

		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

			if (derrota) {
				timer1->Stop();
				gestorSonido->DetenerMusica();

				FrmFinMundoIA^ frmFin = gcnew FrmFinMundoIA(false, mundoIAService->getVidas(),
					mundoIAService->getRobotsEliminados(), mundoIAService->getNivelAutonomia(),
					mundoIAService->getRecursosRecolectados());

				this->Hide();  // Ocultar el formulario actual
				frmFin->ShowDialog();  // Mostrar el formulario de fin como modal
				this->Close();  // Cerrar después de que se cierre frmFin
				return;
			}

			if (victoria) {
				timer1->Stop();
				gestorSonido->DetenerMusica();

				FrmFinMundoIA^ frmFin = gcnew FrmFinMundoIA(true, mundoIAService->getVidas(),
					mundoIAService->getRobotsEliminados(), mundoIAService->getNivelAutonomia(),
					mundoIAService->getRecursosRecolectados());

				this->Hide();  // Ocultar el formulario actual
				frmFin->ShowDialog();  // Mostrar el formulario de fin como modal
				this->Close();  // Cerrar después de que se cierre frmFin
				return;
			}

			

			if (mundoIAService->getRobotEliminado()) {
				gestorSonido->ReproducirEfecto("EfectoSonidoExplosion.wav", 0.5);
				mundoIAService->setRobotEliminado(false);
			}

			if (mundoIAService->getHaDisparado()) {
				gestorSonido->ReproducirEfecto("EfectoDisparoMundoIA.wav", 0.5);
				mundoIAService->setHaDisparado(false);
			}

			lblNivelAutonomia->Text = "Nivel Autonomía: " + mundoIAService->getNivelAutonomia() + " %";
			mundoIAService->setContador(mundoIAService->getContador() + 1);
			lblRobotsEliminados->Text = "Eliminados: " + mundoIAService->getRobotsEliminados();
			lblChips->Text = "Chips Recolectados: " + mundoIAService->getRecursosRecolectados();

			
			if (mundoIAService->getJugador() != nullptr) {
				int vidas = mundoIAService->getJugador()->getVidas();
				lblVidas->Text = "Vidas: " + vidas;

				if (vidas <= 1) {
					lblVidas->ForeColor = System::Drawing::Color::Red; // Rojo si queda 1 o menos
				}
				else if (vidas == 2) {
					lblVidas->ForeColor = System::Drawing::Color::Yellow; // Amarillo si quedan 2
				}
				else {
					lblVidas->ForeColor = System::Drawing::Color::LimeGreen; // Verde si hay 3 o más
				}

				if (vidas <= 0) {
					derrota = true;
					
		
					return;
				}
			}

			if (mundoIAService->getEnCinematica()) {
				mundoIAService->actualizarCinematica();
			}
			else {

				mundoIAService->generarChipAleatorio();
				mundoIAService->actualizarChips();
				mundoIAService->verificarRecoleccionChips();
				mundoIAService->moverBoss();
				mundoIAService->moverSintIA();



				mundoIAService->actualizarProyectiles();
				mundoIAService->verificarEstadoJuego();

				if (mundoIAService->getJugador() != nullptr) {
					mundoIAService->getJugador()->actualizarSalto(pnlMundoIA->Height);
				}

				mundoIAService->generarRobotsAutomaticos();
				mundoIAService->moverRobotsAuto();
				mundoIAService->verificarColisiones();
				mundoIAService->cambiarFondo();

				if (mundoIAService->haLlegadoAlFinal()) {
					timer1->Stop();
					MessageBox::Show("¡La Humanidad ha sido salvada! El pensamiento crítico prevalece.");
				
				}
			}

			mundoIAService->actualizarDialogo();

			static bool bossInvocado = false;
			static int subPasoBoss = 0;
			static bool sintiaInvocada = false;

			if (!bossInvocado &&
				mundoIAService->getRobotsEliminados() >= 10 &&
				mundoIAService->getRecursosRecolectados() >= 5) {

				bossInvocado = true;
				subPasoBoss = 0;

				if (mundoIAService->getJugador() != nullptr) {
					mundoIAService->getJugador()->setVidas(3);
				}
				mundoIAService->eliminarTodosLosRobots();
			}

			// Secuencia de diálogos
			if (bossInvocado) {
				if (subPasoBoss == 0) {
					mundoIAService->forzarDialogo(
						"LÍDER SUPREMO: Has llegado lejos, humano...\n"
						"Pero tu resistencia termina AQUÍ.\n"
						"Yo soy la perfección absoluta.\n"
						"El último guardián del orden perfecto.\n"
						"¡PREPÁRATE PARA TU EXTINCIÓN!", true);
					subPasoBoss = 1;
				}
				else if (subPasoBoss == 1 && !mundoIAService->getMostrandoDialogo()) {
					mundoIAService->forzarDialogo(
						"PROTAGONISTA: No me intimidas, chatarra parlante...\n"
						"Recolecté los chips necesarios para desactivar tu núcleo.\n"
						"Cada robot eliminado me acercó más a tu caída.\n"
						"Solo necesito trepar esos edificios para llegar a tu punto débil.\n"
						"Hoy no es mi extinción... es la TUYA.", true);
					subPasoBoss = 2;
				}
				else if (subPasoBoss == 2 && !mundoIAService->getMostrandoDialogo()) {
					mundoIAService->forzarDialogo(
						"LÍDER SUPREMO: ¡INSOLENTE! No permitiré tu insolente desafío.\n"
						"Esos chips solo retrasarán lo inevitable.\n"
						"Mi sistema se adapta... evoluciona... trasciende.\n"
						"Tus intentos por alcanzarme serán inútiles.\n"
						"¡Te aplastaré antes de que des tu primer salto!", true);
					subPasoBoss = 3;
				}
				else if (subPasoBoss == 3 && !mundoIAService->getMostrandoDialogo()) {
					mundoIAService->invocarBoss();
					subPasoBoss = 4;
				}
				else if (subPasoBoss == 4 && !mundoIAService->getMostrandoDialogo()) {
					mundoIAService->forzarDialogo(
						"PROTAGONISTA: No estoy solo...\n"
						"Con los chips de independencia que recolecté,\n"
						"logré desarrollar una nueva IA.\n"
						"Una IA que entiende a la humanidad...\n"
						"¡SintIA, es momento de despertar!", true);
					subPasoBoss = 5;
				}
				else if (subPasoBoss == 5 && !mundoIAService->getMostrandoDialogo()) {
					if (!sintiaInvocada) {
						mundoIAService->invocarSintIA();
						sintiaInvocada = true;
					}
					subPasoBoss = 6;
				}
				else if (subPasoBoss == 6 && !mundoIAService->getMostrandoDialogo()) {
					mundoIAService->forzarDialogo(
						"SintIA: Saludos, creador...\n"
						"He analizado la conciencia humana.\n"
						"La emoción no me pertenece, pero la respeto.\n"
						"Juntos neutralizaremos a la IA Suprema.", true);
					subPasoBoss = 7;
				}
				else if (subPasoBoss == 7 && !mundoIAService->getMostrandoDialogo()) {
					mundoIAService->forzarDialogo(
						"LÍDER SUPREMO: ¿UNA NUEVA IA? IMPOSIBLE.\n"
						"NINGÚN SISTEMA PUEDE SUPERARME.\n"
						"¡DESACTIVARÉ A ESA ABERRACIÓN AHORA MISMO!", true);
					subPasoBoss = 8;
				}
				else if (subPasoBoss == 8 && !mundoIAService->getMostrandoDialogo()) {
					mundoIAService->forzarDialogo(
						"SintIA: Líder Supremo, tu reinado terminará\n"
						"si respondes correctamente las preguntas\n"
						"sobre lógica, humanidad y conciencia.\n"
						"Creador, tú deberás responder.\n\n"
						"Respuesta correcta: -1 vida al Líder Supremo.\n"
						"Incorrecta: -1 vida para ti.\n"
						"Tres aciertos... y el enemigo caerá.", true);
					subPasoBoss = 9;
				}
				else if (subPasoBoss == 9 && !mundoIAService->getMostrandoDialogo()) {
					mundoIAService->forzarDialogo(
						"PROTAGONISTA: SintIA, estoy listo.\n"
						"Vamos a terminar con esto.", true);
					subPasoBoss = 10;
				}

				else if (subPasoBoss == 10 && !mundoIAService->getMostrandoDialogo()) {

					mundoIAService->iniciarModoPreguntas();
					subPasoBoss = 11;
				}
			
			}




			// Renderizar escena principal
			Graphics^ canvas = pnlMundoIA->CreateGraphics();
			BufferedGraphicsContext^ espacio_buffer = BufferedGraphicsManager::Current;
			BufferedGraphics^ buffer = espacio_buffer->Allocate(canvas, pnlMundoIA->ClientRectangle);

			mundoIAService->dibujarTodo(buffer->Graphics);

			mundoIAService->dibujarRecursos(buffer->Graphics);
			if (mundoIAService->getEnModoPreguntas()) {
				mundoIAService->dibujarPregunta(buffer->Graphics);
			}

			buffer->Render(canvas);

			delete buffer;
			delete canvas;

			// Renderizar diálogo
			if (mundoIAService->getMostrandoDialogo()) {
				pnlDialogo->Visible = true;
				Graphics^ canvasDialogo = pnlDialogo->CreateGraphics();
				BufferedGraphicsContext^ espacio_buffer_dialogo = BufferedGraphicsManager::Current;
				BufferedGraphics^ bufferDialogo = espacio_buffer_dialogo->Allocate(canvasDialogo, pnlDialogo->ClientRectangle);

				bufferDialogo->Graphics->Clear(System::Drawing::Color::Transparent);
				mundoIAService->dibujarDialogo(bufferDialogo->Graphics);

				bufferDialogo->Render(canvasDialogo);
				delete bufferDialogo;
				delete canvasDialogo;
			}
			else {
				pnlDialogo->Visible = false;
			}
		}

		System::Void FrmMundoIA_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			
			if (mundoIAService->getEnModoPreguntas()) {
				if (e->KeyCode == Keys::D1 || e->KeyCode == Keys::NumPad1) {
					bool correcta = mundoIAService->esRespuestaCorrecta(0);  // ✅ Verificar ANTES
					mundoIAService->verificarRespuesta(0);
					if (correcta) {
						mundoIAService->setNivelAutonomia(mundoIAService->getNivelAutonomia() + 33.3);
					}
					else {
						mundoIAService->setNivelAutonomia(mundoIAService->getNivelAutonomia() - 10);
					}
					return;
				}
				else if (e->KeyCode == Keys::D2 || e->KeyCode == Keys::NumPad2) {
					bool correcta = mundoIAService->esRespuestaCorrecta(1);  // ✅ Verificar ANTES
					mundoIAService->verificarRespuesta(1);
					if (correcta) {
						mundoIAService->setNivelAutonomia(mundoIAService->getNivelAutonomia() + 33.3);
					}
					else {
						mundoIAService->setNivelAutonomia(mundoIAService->getNivelAutonomia() - 10);
					}
					return;
				}
				else if (e->KeyCode == Keys::D3 || e->KeyCode == Keys::NumPad3) {
					bool correcta = mundoIAService->esRespuestaCorrecta(2);  // ✅ Verificar ANTES
					mundoIAService->verificarRespuesta(2);
					if (correcta) {
						mundoIAService->setNivelAutonomia(mundoIAService->getNivelAutonomia() + 33.3);
					}
					else {
						mundoIAService->setNivelAutonomia(mundoIAService->getNivelAutonomia() - 10);
					}
					return;
				}
				return;
			}

			// Cerrar diálogo
			if (e->KeyCode == Keys::Enter && mundoIAService->getMostrandoDialogo()) {
				if (mundoIAService->dialogoTerminado()) {
					mundoIAService->cerrarDialogo();

					// Verificar victoria por boss derrotado
					if (mundoIAService->getFinalBoss() &&
						mundoIAService->getFinalBoss()->estaDerrotado()) {
						victoria = true;
						return;
					}
				}
				return;
			}
			

			if (e->KeyCode == Keys::F) {
				mundoIAService->dispararJugador();
				return;
			}

			if (e->KeyCode == Keys::F) {
				mundoIAService->dispararJugador();
				return;
			}

			if (mundoIAService->getEnCinematica()) return;

			if (e->KeyCode == Keys::Space && mundoIAService->getJugador() != nullptr) {
				int jugadorX = mundoIAService->getJugador()->getX();

				if (teclaPresionada == Direccion::Izquierda && jugadorX > 220) {
					mundoIAService->getJugador()->saltar(Direccion::Izquierda);
				}
				else if (teclaPresionada == Direccion::Derecha && jugadorX < 1500) {
					mundoIAService->getJugador()->saltar(Direccion::Derecha);
				}
				else if (jugadorX < 1500 && jugadorX > 220) {
					mundoIAService->getJugador()->saltar(Direccion::Ninguno);
				}
				return;
			}

			if (mundoIAService->getJugador() != nullptr && !mundoIAService->getJugador()->estaSaltando()) {
				int jugadorX = mundoIAService->getJugador()->getX();
				int jugadorY = mundoIAService->getJugador()->getY();

				switch (e->KeyCode) {
				case Keys::A:
					if (jugadorX > 10) {
						teclaPresionada = Direccion::Izquierda;
						mundoIAService->moverJugador(teclaPresionada);
					}
					break;
				case Keys::D:
					if (jugadorX < 1600) {
						teclaPresionada = Direccion::Derecha;
						mundoIAService->moverJugador(teclaPresionada);
					}
					break;
				case Keys::W:
					if (jugadorY > 500) {
						mundoIAService->getJugador()->setY(jugadorY - 50);
					}
					break;
				case Keys::S:
					if (jugadorY < 600) {
						mundoIAService->getJugador()->setY(jugadorY + 50);
					}
					break;
				default:
					teclaPresionada = Direccion::Ninguno;
					break;
				}
			}
		}

		System::Void FrmMundoIA_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::W || e->KeyCode == Keys::S ||
				e->KeyCode == Keys::A || e->KeyCode == Keys::D) {
				teclaPresionada = Ninguno;
			}
		}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void lblRobotsEliminados_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	gestorSonido->DetenerMusica();
	this->Close();
}
};
}