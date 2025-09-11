#pragma once

#include "Renderer/IRenderer.h"

class D3D12Renderer : public IRenderer
{
public:
	virtual bool Init() override;

	virtual void Shutdown() override;

	virtual void Render() override;

	virtual void Flush() override;
};