#include "IndexedMesh.h"
#include "Loader.h"
#include "Saver.h"
#include <Windows.h>

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PWSTR pCmdLine, _In_ int) {
	try {

		int size = 0;
		PWSTR* args = CommandLineToArgvW(GetCommandLine(), &size);
		if (size < 2) {
			MessageBoxA(NULL, "Open your .txt with thie .exe to convert. The result will locate inside the .txt directory", NULL, NULL);
		}
		else {
			std::wstring path{ args[1] };
			std::wstring extentionName{ L".im" };
			Loader l{ path };
			IndexedMesh im{ l };
			Saver s{ path , extentionName };
			auto binary = im.Binary();
			s.Save(binary);
		}

	}
	catch (const std::exception& e) {
		MessageBoxA(NULL, e.what(), NULL, NULL);
	}
}