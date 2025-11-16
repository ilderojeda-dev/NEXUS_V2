#include "FrmInicio.h"
#include "FrmMundoColab.h"
using namespace System;
using namespace System::Windows::Forms; [STAThread]

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew  NEXUSV2::FrmMundoColab());

}