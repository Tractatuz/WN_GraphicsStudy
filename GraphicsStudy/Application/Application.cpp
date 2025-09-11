#include "Application.h"

bool Application::Init()
{
	//m_platformWindow = IPlatformWindow::Create(EPlatform::Win32);
	//m_renderDevice = IRenderDevice::Create(ERenderHardwareInterface::D3D12);

	//return true;

	return false;
}

bool Application::ShouldClose()
{
	if (m_platformWindow == nullptr)
	{
		return true;
	}

	return m_platformWindow->ShouldClose();
}

void Application::Update()
{
	// Handle resizing
	if (m_platformWindow->ShouldResize())
	{
		m_renderDevice->Flush();
		m_platformWindow->Resize();
	}
}

void Application::Render()
{

}

void Application::Shutdown()
{

}
