#pragma once

#include "D3D12Include.h"
#include "Renderer/Public/IRenderDevice.h"
#include "Support/ComPointer.h"

class D3D12Device : IRenderDevice
{
public:
	virtual bool Init() override;
	virtual void ShutDown() override;
	virtual void Flush() override;

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
