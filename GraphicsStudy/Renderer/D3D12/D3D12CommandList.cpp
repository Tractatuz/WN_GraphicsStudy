#include "D3D12CommandList.h"

#include "D3D12Device.h"

bool D3D12CommandList::Init()
{
	if (FAILED(D3D12Device::Get().GetDevice()->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_cmdAllocator))))
	{
		return false;
	}

	if (FAILED(D3D12Device::Get().GetDevice()->CreateCommandList1(0, D3D12_COMMAND_LIST_TYPE_DIRECT, D3D12_COMMAND_LIST_FLAG_NONE, IID_PPV_ARGS(&m_cmdList))))
	{
		return false;
	}

	return true;
}

void D3D12CommandList::Shutdown()
{
	m_cmdList.Release();
	m_cmdAllocator.Release();
}

ID3D12GraphicsCommandList7* D3D12CommandList::InitCommandList()
{
	m_cmdAllocator->Reset();
	m_cmdList->Reset(m_cmdAllocator, nullptr);
	return m_cmdList;
}

void D3D12CommandList::ExecuteCommandList()
{
	if (SUCCEEDED(m_cmdList->Close()))
	{
		ID3D12CommandList* lists[] = { m_cmdList };
		//m_cmdQueue->ExecuteCommandLists(1, lists);
		//SignalAndWait();
	}
}
