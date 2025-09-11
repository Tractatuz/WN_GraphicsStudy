#pragma once

#include "Platform/Public/IPlatformWindow.h"
#include "Renderer/Public/IRenderDevice.h"
#include "Renderer/Public/ISwapChain.h"
#include "Renderer/Public/ICommandQueue.h"

class Application
{
public:
	bool Init();
	bool ShouldClose();
	void Update();
	void Render();
	void Shutdown();

private:
	IPlatformWindow* m_platformWindow;
	IRenderDevice* m_renderDevice;
	ISwapChain* m_swapChain;

	//...

	// Singleton
public:
	Application(const Application&) = delete;
	Application& operator = (const Application&) = delete;

	inline static Application& Get()
	{
		static Application instance;
		return instance;
	}

private:
	Application() = default;
};