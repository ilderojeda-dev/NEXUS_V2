#include "FrmGameOverMundoColab.h"
#include "FrmInicio.h"             

using namespace NEXUSV2;
using namespace System;
using namespace System::Windows::Forms;

// Implementación de la función btnSalir_Click
System::Void FrmGameOverMundoColab::btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
	// 1. Ocultar el formulario de Game Over
	this->Hide();

	// 2. Crear y mostrar una nueva instancia del menú principal
	// La definición completa de FrmInicio está disponible gracias al #include de arriba.
	NEXUSV2::FrmInicio^ menuPrincipal = gcnew NEXUSV2::FrmInicio();

	// Mostrar el menú principal
	menuPrincipal->Show();

	// 3. Cerrar el formulario actual de Game Over
	this->Close();
}