#pragma once

#include "D3D12Include.h"
#include "Core/ComPointer.h"

class D3D12Device
{
public:
	bool Init();
	void Shutdown();
	void Flush();

	inline ComPointer<IDXGIFactory7>& GetFactory()
	{
		return m_dxgiFactory;
	}

	inline ComPointer<ID3D12Device10>& GetDevice()
	{
		return m_device;
	}

private:
	ComPointer<IDXGIFactory7> m_dxgiFactory;
	ComPointer<ID3D12Device10> m_device;

	// Singleton
public:
	D3D12Device(const D3D12Device&) = delete;
	D3D12Device& operator = (const D3D12Device&) = delete;

	inline static D3D12Device& Get()
	{
		static D3D12Device instance;
		return instance;
	}

private:
	D3D12Device() = default;
};
