#include "D3D12Device.h"

bool D3D12Device::Init()
{
	if (FAILED(CreateDXGIFactory2(0, IID_PPV_ARGS(&m_dxgiFactory))))
	{
		return false;
	}

	if (FAILED(D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_device))))
	{
		return false;
	}

	return true;
}

void D3D12Device::ShutDown()
{
	m_device.Release();
	m_dxgiFactory.Release();
}

void D3D12Device::Flush()
{

}
