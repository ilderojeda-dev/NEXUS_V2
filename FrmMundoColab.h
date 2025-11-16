#pragma once
#include "Mundo.h"
#include "Nave.h"
#include "MundoColabService.h"
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

			//
			//TODO: Add the constructor code here
			//
			mundoColab = new MundoColabService(pnlJuego->Width, pnlJuego->Height, 3);

			char rutaFondo[] = "FondoMundoCOlab.png";
			mundoColab->cargarFondo(rutaFondo);

			char rutaNave[] = "SpriteNave.png";
			mundoColab->CargarSpriteNave(rutaNave, 1, 4);

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
		}

	private:
		MundoColabService* mundoColab;
		Direccion teclaPresionadaNave;

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Panel^ pnlJuego;
	private: System::Windows::Forms::Timer^ timer1;


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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &FrmMundoColab::backgroundWorker1_DoWork);
			// 
			// pnlJuego
			// 
			this->pnlJuego->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlJuego.BackgroundImage")));
			this->pnlJuego->Location = System::Drawing::Point(0, 0);
			this->pnlJuego->Name = L"pnlJuego";
			this->pnlJuego->Size = System::Drawing::Size(1920, 1080);
			this->pnlJuego->TabIndex = 0;
			this->pnlJuego->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMundoColab::pnlJuego_Paint);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMundoColab::timer1_Tick);
			// 
			// FrmMundoColab
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->pnlJuego);
			this->Name = L"FrmMundoColab";
			this->Text = L"FrmMundoColab";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmMundoColab::FrmMundoColab_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoColab::FrmMundoColab_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoColab::FrmMundoColab_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmMundoColab_Load(System::Object^ sender, System::EventArgs^ e) {
		timer1->Start();
		
		

		
	}
	private: System::Void pnlJuego_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (mundoColab == nullptr) {
			mundoColab = new MundoColabService(pnlJuego->Width, pnlJuego->Height, 3);
		}
		mundoColab->dibujarTodo(e->Graphics);

	}
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		if (teclaPresionadaNave != Direccion::Ninguno) {
			mundoColab->moverNave(teclaPresionadaNave);
		}

		//Reenderizado
		Graphics^ canvas = pnlJuego->CreateGraphics();

		BufferedGraphicsContext^ espacio_buffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio_buffer->Allocate(canvas, pnlJuego->ClientRectangle);

		mundoColab->dibujarTodo(buffer->Graphics);
		buffer->Render (canvas);

		delete buffer;
		delete canvas;
	}
	private: System::Void FrmMundoColab_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	

		if (e->KeyCode == Keys::W) {
			teclaPresionadaNave = Direccion::Arriba;
		}
	if (e->KeyCode == Keys::S){
		teclaPresionadaNave = Direccion::Abajo;
	}
	if (e->KeyCode == Keys::A){
		teclaPresionadaNave = Direccion::Izquierda;
	}

	if (e->KeyCode == Keys::D){
		teclaPresionadaNave = Direccion::Derecha;
	}

	}
	private: System::Void FrmMundoColab_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::W || e->KeyCode == Keys::S ||
			e->KeyCode == Keys::A || e->KeyCode == Keys::D) {
			teclaPresionadaNave = Direccion::Ninguno;
		}
	}
};
}
