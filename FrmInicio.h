#pragma once
#include "FrmMundoIA.h"
namespace NEXUSV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmInicio
	/// </summary>
	public ref class FrmInicio : public System::Windows::Forms::Form
	{
	public:
		FrmInicio(void)
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
		~FrmInicio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ brnMundoIA;
	protected:

	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

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
			this->brnMundoIA = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// brnMundoIA
			// 
			this->brnMundoIA->Location = System::Drawing::Point(389, 360);
			this->brnMundoIA->Name = L"brnMundoIA";
			this->brnMundoIA->Size = System::Drawing::Size(75, 23);
			this->brnMundoIA->TabIndex = 0;
			this->brnMundoIA->Text = L"MUNDO IA";
			this->brnMundoIA->UseVisualStyleBackColor = true;
			this->brnMundoIA->Click += gcnew System::EventHandler(this, &FrmInicio::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(544, 360);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(701, 360);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// FrmInicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1174, 769);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->brnMundoIA);
			this->Name = L"FrmInicio";
			this->Text = L"FrmInicio";
			this->Load += gcnew System::EventHandler(this, &FrmInicio::FrmInicio_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmInicio_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		FrmMundoIA^ frmMundoIA = gcnew FrmMundoIA();
		frmMundoIA->Show();
	}
	};
}
