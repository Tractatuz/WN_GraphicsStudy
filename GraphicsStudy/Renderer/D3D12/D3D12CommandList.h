#pragma once

#include "D3D12Include.h"
#include "Core/ComPointer.h"

class D3D12CommandList
{
public:
	bool Init();
	void Shutdown();

	ID3D12GraphicsCommandList7* InitCommandList();
	void ExecuteCommandList();

private:
	ComPointer<ID3D12CommandAllocator> m_cmdAllocator;
	ComPointer<ID3D12GraphicsCommandList7> m_cmdList;

	// Singleton
public:
	D3D12CommandList(const D3D12CommandList&) = delete;
	D3D12CommandList& operator = (const D3D12CommandList&) = delete;

	inline static D3D12CommandList& Get()
	{
		static D3D12CommandList instance;
		return instance;
	}

private:
	D3D12CommandList() = default;

};
