#pragma once

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
			this->SuspendLayout();
			// 
			// FrmInicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1174, 769);
			this->Name = L"FrmInicio";
			this->Text = L"FrmInicio";
			this->Load += gcnew System::EventHandler(this, &FrmInicio::FrmInicio_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmInicio_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
