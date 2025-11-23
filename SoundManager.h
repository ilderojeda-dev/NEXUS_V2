#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Windows::Media;

namespace NEXUS_V2 {
	namespace Service {

		public ref class SoundManager
		{
		private:
			MediaPlayer^ musicaFondo;
			List<MediaPlayer^>^ listaEfectos;
			MediaPlayer^ sonidoBucle;
			void AlTerminarMusica(Object^ sender, EventArgs^ e);
			void AlTerminarEfecto(Object^ sender, EventArgs^ e);
			void AlTerminarBucle(Object^ sender, EventArgs^ e);

		public:
			SoundManager();
			void ReproducirMusica(String^ nombreArchivo, double volumen);
			void DetenerMusica();
			void ReproducirEfecto(String^ nombreArchivo, double volumen);
			void ReproducirSonidoBucle(String^ nombreArchivo, double volumen);
			void DetenerSonidoBucle();

		};
	}
}