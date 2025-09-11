#include "Application.h"
#include "Platform/IPlatformWindow.h"
#include "Renderer/IRenderer.h"

bool Application::Init()
{
	m_platformWindow = IPlatformWindow::Create(EPlatform::Win32);
	if (m_platformWindow == nullptr || m_platformWindow->Init() == false)
	{
		return false;
	}

	m_renderer = IRenderer::Create(ERenderHardwareInterface::D3D12);
	if (m_renderer == nullptr || m_renderer->Init() == false)
	{
		return false;
	}

	return true;
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
	m_platformWindow->Update();

	// Handle resizing
	if (m_platformWindow->ShouldResize())
	{
		m_renderer->Flush();
		m_platformWindow->Resize();
	}
}

void Application::Render()
{

}

void Application::Shutdown()
{

}
