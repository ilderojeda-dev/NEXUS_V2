#include "SoundManager.h"

namespace NEXUS_V2 {
	namespace Service {

		SoundManager::SoundManager()
		{
			musicaFondo = gcnew MediaPlayer();
			listaEfectos = gcnew List<MediaPlayer^>();
			sonidoBucle = gcnew MediaPlayer();
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
		void SoundManager::ReproducirSonidoBucle(String^ nombreArchivo, double volumen)
		{
			try {
				// Evitamos recargar si ya está sonando lo mismo (opcional, pero recomendado)
				// Si quieres poder cambiar de sonido (ej: de pasos a correr), quita este if.
				// if (sonidoBucle->Source != nullptr) return; 

				String^ rutaBase = AppDomain::CurrentDomain->BaseDirectory;
				String^ rutaCompleta = Path::Combine(rutaBase, "Resource", nombreArchivo);

				sonidoBucle->Open(gcnew Uri(rutaCompleta));
				sonidoBucle->Volume = volumen;

				// Conectamos el evento para que sea infinito
				sonidoBucle->MediaEnded += gcnew EventHandler(this, &SoundManager::AlTerminarBucle);

				sonidoBucle->Play();
			}
			catch (Exception^ ex) {}
		}

		void SoundManager::DetenerSonidoBucle()
		{
			sonidoBucle->Stop();
			// Opcional: Desconectar el evento si quieres limpiar memoria, 
			// pero para este nivel está bien así.
		}

		void SoundManager::AlTerminarBucle(Object^ sender, EventArgs^ e)
		{
			// ¡Aquí está la magia! Cuando acaba, vuelve a empezar.
			sonidoBucle->Position = TimeSpan::Zero;
			sonidoBucle->Play();
		}

	}
}