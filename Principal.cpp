#include "FrmInicio.h"

#include "FrmMundoHumano.h"
#include "FrmModulo1.h"
#include "FrmModulo2.h"
#include "FrmModulo4.h"
using namespace System;
using namespace System::Windows::Forms; [STAThread]

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew  NEXUSV2::FrmInicio());
}

//using namespace System;
//using namespace System::Windows::Forms; [STAThread]
//
//void main()
//{
//	Application::EnableVisualStyles();
//	Application::SetCompatibleTextRenderingDefault(false);
//	Application::Run(gcnew  NEXUSV2::FrmMundoHumano());
//}
