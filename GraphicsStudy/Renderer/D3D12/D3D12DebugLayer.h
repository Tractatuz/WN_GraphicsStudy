#pragma once

#include "D3D12Include.h"
#include "Core/ComPointer.h"

class D3D12DebugLayer
{
public:
	bool Init();
	void Shutdown();

private:
#ifdef _DEBUG
	ComPointer<ID3D12Debug6> m_d3d12Debug;
	ComPointer<IDXGIDebug1> m_dxgiDebug;
#endif


// Singleton
public:
	D3D12DebugLayer(const D3D12DebugLayer&) = delete;
	D3D12DebugLayer& operator = (const D3D12DebugLayer&) = delete;

	inline static D3D12DebugLayer& Get()
	{
		static D3D12DebugLayer instance;
		return instance;
	}

private:
	D3D12DebugLayer() = default;
};
