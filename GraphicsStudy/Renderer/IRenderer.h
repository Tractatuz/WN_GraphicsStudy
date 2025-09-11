#pragma once

#include "Core/Common.h"

enum class ERenderHardwareInterface
{
	None,
	D3D12,
	Max,
};

class IRenderer
{
public:
	static std::unique_ptr<IRenderer> Create(ERenderHardwareInterface RHIType);
	virtual ~IRenderer() = default;

	virtual bool Init() = 0;
	virtual void Shutdown() = 0;
	virtual void Render() = 0;
	virtual void Flush() = 0;
};