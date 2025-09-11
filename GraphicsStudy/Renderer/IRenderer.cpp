#include "IRenderer.h"

#include "Renderer/D3D12/D3D12Renderer.h"

std::unique_ptr<IRenderer> IRenderer::Create(ERenderHardwareInterface RHIType)
{
	switch (RHIType)
	{
	case ERenderHardwareInterface::D3D12:
		return std::make_unique<D3D12Renderer>();
	case ERenderHardwareInterface::None:
	case ERenderHardwareInterface::Max:
	default:
		break;
	}
    return nullptr;
}
