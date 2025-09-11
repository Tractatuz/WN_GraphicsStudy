#pragma once

#include "Core/Common.h"
#include "Platform/IPlatformWindow.h"
#include "Renderer/IRenderer.h"

class Application
{
public:
	bool Init();
	bool ShouldClose();
	void Update();
	void Render();
	void Shutdown();

private:
	std::unique_ptr<IPlatformWindow> m_platformWindow;
	std::unique_ptr<IRenderer> m_renderer;

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