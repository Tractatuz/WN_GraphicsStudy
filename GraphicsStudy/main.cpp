#include <iostream>

#include <Support/WinInclude.h>
#include <Support/ComPointer.h>
#include <Support/Window.h>

#include <Debug/DXDebugLayer.h>
#include <D3D/DXContext.h>

extern "C" {
	// Setup to use the D3D12Core.dll which is distributed with this.
	// 616 is Agility SDK version.
	// Recommend to check the installed SDK header (D3D12.h) for the latest version number and use it.
	__declspec(dllexport) extern const UINT D3D12SDKVersion = 616;

	// Setup SDK DLL file path. 
	// NuGet package automatically copies the DLLs to a "D3D12" folder next to the .exe file.
	__declspec(dllexport) extern const char* D3D12SDKPath = ".\\D3D12\\";
}

int main()
{
	DXDebugLayer::Get().Init();

	if (DXContext::Get().Init() && DXWindow::Get().Init())
	{
		while (DXWindow::Get().ShouldClose() == false)
		{
			// process pending window message
			DXWindow::Get().Update();

			// handle resizing
			if (DXWindow::Get().ShouldResize())
			{
				DXContext::Get().Flush(DXWindow::GetFrameCount());
				DXWindow::Get().Resize();
			}
			auto* cmdList = DXContext::Get().InitCommandList();
			
			// a lot of setup
			// a draw
			//cmdList->DrawInstanced(3, 3, 3, 3);

			DXContext::Get().ExecuteCommandList();
			// Show me the stuff
			DXWindow::Get().Present();
		}

		// Flushing
		DXContext::Get().Flush(DXWindow::GetFrameCount());

		DXWindow::Get().ShutDown();
		DXContext::Get().ShutDown();
	}
	
	DXDebugLayer::Get().ShutDown();
}