#pragma once

#include "D3D12Include.h"
#include "Renderer/Public/ICommandQueue.h"
#include "Support/ComPointer.h"

class D3D12CommandQueue : ICommandQueue
{
public:
	bool Init();
	void ShutDown();

	void SignalAndWait();
	ID3D12GraphicsCommandList7* InitCommandList();
	void ExecuteCommandList();

	inline void Flush(size_t count)
	{
		for (size_t i = 0; i < count; i++)
		{
			SignalAndWait();
		}
	}

	inline ComPointer<ID3D12CommandQueue>& GetCommandQueue()
	{
		return m_cmdQueue;
	}

private:
	ComPointer<ID3D12CommandQueue> m_cmdQueue;

	ComPointer<ID3D12Fence1> m_fence;
	UINT64 m_fenceValue = 0;
	HANDLE m_fenceEvent = nullptr;

	// Singleton
public:
	D3D12CommandQueue(const D3D12CommandQueue&) = delete;
	D3D12CommandQueue& operator = (const D3D12CommandQueue&) = delete;

	inline static D3D12CommandQueue& Get()
	{
		static D3D12CommandQueue instance;
		return instance;
	}

private:
	D3D12CommandQueue() = default;

};
