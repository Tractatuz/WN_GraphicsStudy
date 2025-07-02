#include <iostream>

#include <Support/WinInclude.h>
#include <Support/ComPointer.h>

#include <Debug/DXDebugLayer.h>
#include <D3D/DXContext.h>

int main()
{
	/*
	//std::cout << "Hello World";

	
	//ID3D12Device* device;
	//IUnknown* p;
	//p->AddRef();
	//p->QueryInterface(IID_PPV_ARGS(&device));
	//p->Release();
	

	ComPointer<IUnknown> pointer;
	// pointer.QueryInterface()
	pointer.Release();

	POINT pt;
	GetCursorPos(&pt);

	std::cout << "The cursor is x : " << pt.x << " y : " << pt.y;
	*/

	DXDebugLayer::Get().Init();

	//ComPointer<ID3D12Device14>
	//ComPointer<ID3D12Device10> device;

	if (DXContext::Get().Init())
	{

		DXContext::Get().ShutDown();
	}
	

	DXDebugLayer::Get().ShutDown();
}