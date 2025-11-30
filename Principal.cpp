#include "FrmInicio.h"

#include "FrmMundoHumano.h"
#include "FrmModulo1.h"
#include "FrmModulo2.h"
#include "FrmModulo3.h"	

#include "FrmMundoColab.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew NEXUSV2::FrmInicio());
}