#include "SoundManager.h"

namespace NEXUS_V2 {
	namespace Service {

		SoundManager::SoundManager()
		{
			musicaFondo = gcnew MediaPlayer();
			listaEfectos = gcnew List<MediaPlayer^>();
		}

		void SoundManager::ReproducirMusica(String^ nombreArchivo, double volumen)
		{
			try {
				String^ rutaBase = AppDomain::CurrentDomain->BaseDirectory;
				String^ rutaCompleta = Path::Combine(rutaBase, "Resource", nombreArchivo);

				// --- AGREGAR ESTO PARA PROBAR ---
				if (!System::IO::File::Exists(rutaCompleta)) {
					System::Windows::Forms::MessageBox::Show("NO ENCUENTRO EL ARCHIVO EN:\n" + rutaCompleta);
					return;
				}
				// --------------------------------

				musicaFondo->Open(gcnew Uri(rutaCompleta));
				musicaFondo->Volume = volumen;
				musicaFondo->MediaEnded += gcnew EventHandler(this, &SoundManager::AlTerminarMusica);
				musicaFondo->Play();
			}
			catch (Exception^ ex) {
				System::Windows::Forms::MessageBox::Show("Error: " + ex->Message);
			}
		}

		
		void SoundManager::AlTerminarMusica(Object^ sender, EventArgs^ e)
		{
			musicaFondo->Position = TimeSpan::Zero; 
			musicaFondo->Play();
		}

		void SoundManager::DetenerMusica()
		{
			musicaFondo->Stop();
		}

		void SoundManager::ReproducirEfecto(String^ nombreArchivo, double volumen)
		{
			try {
				String^ rutaBase = AppDomain::CurrentDomain->BaseDirectory;
				String^ rutaCompleta = Path::Combine(rutaBase, "Resource", nombreArchivo);

				MediaPlayer^ efecto = gcnew MediaPlayer();
				efecto->Open(gcnew Uri(rutaCompleta));
				efecto->Volume = volumen;

				efecto->MediaEnded += gcnew EventHandler(this, &SoundManager::AlTerminarEfecto);

				listaEfectos->Add(efecto);
				efecto->Play();
			}
			catch (Exception^ ex) {
				System::Diagnostics::Debug::WriteLine("Error SFX: " + ex->Message);
			}
		}
		void SoundManager::AlTerminarEfecto(Object^ sender, EventArgs^ e)
		{
			MediaPlayer^ reproductorTerminado = (MediaPlayer^)sender;
			reproductorTerminado->Close();

			if (listaEfectos->Contains(reproductorTerminado)) {
				listaEfectos->Remove(reproductorTerminado);
			}
		}
	}
}