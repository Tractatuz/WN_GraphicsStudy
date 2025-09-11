#pragma once

class ISwapChain
{
public:
	virtual ~ISwapChain() = default;

	virtual bool Init() = 0;
	virtual void Shutdown() = 0;
};