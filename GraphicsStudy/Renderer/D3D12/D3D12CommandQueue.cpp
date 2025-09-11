#include "D3D12CommandQueue.h"

#include <cstdlib>
#include "D3D12Device.h"

bool D3D12CommandQueue::Init()
{
	D3D12_COMMAND_QUEUE_DESC cmdQueueDesc{};
	cmdQueueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
	cmdQueueDesc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_HIGH;
	cmdQueueDesc.NodeMask = 0;
	cmdQueueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
	
	if (FAILED(D3D12Device::Get().GetDevice()->CreateCommandQueue(&cmdQueueDesc, IID_PPV_ARGS(&m_cmdQueue))))
	{
		return false;
	}
	
	if (FAILED(D3D12Device::Get().GetDevice()->CreateFence(m_fenceValue, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence))))
	{
		return false;
	}

	m_fenceEvent = CreateEvent(nullptr, false, false, nullptr);
	if (!m_fenceEvent)
	{
		return false;
	}

	return true;
}

void D3D12CommandQueue::Shutdown()
{
	if (m_fenceEvent)
	{
		CloseHandle(m_fenceEvent);
	}
	m_cmdQueue.Release();
}

void D3D12CommandQueue::SignalAndWait()
{
	m_cmdQueue->Signal(m_fence, ++m_fenceValue);
	if (SUCCEEDED(m_fence->SetEventOnCompletion(m_fenceValue, m_fenceEvent)))
	{
		if(WaitForSingleObject(m_fenceEvent, 20000) != WAIT_OBJECT_0)
		{
			std::exit(-1);
		}
	}
	else
	{
		std::exit(-99);
	}

	/*while (m_fence->GetCompletedValue() < m_fenceValue)
	{
		SwitchToThread();
	}*/
}