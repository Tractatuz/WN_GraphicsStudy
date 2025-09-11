#include <cstdint>

extern "C" {
	// Setup to use the D3D12Core.dll which is distributed with this.
	// 616 is Agility SDK version.
	// Recommend to check the installed SDK header (D3D12.h) for the latest version number and use it.
	__declspec(dllexport) extern const uint32_t D3D12SDKVersion = 616;

	// Setup SDK DLL file path. 
	// NuGet package automatically copies the DLLs to a "D3D12" folder next to the .exe file.
	__declspec(dllexport) extern const char* D3D12SDKPath = ".\\D3D12\\";
}