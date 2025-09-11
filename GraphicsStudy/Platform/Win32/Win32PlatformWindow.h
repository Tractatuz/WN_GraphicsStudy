#pragma once

#include "WinInclude.h"
#include "Platform/Public/IPlatformWindow.h"
#include "Renderer/Public/ISwapChain.h"

class Win32PlatformWindow : IPlatformWindow
{
public:
	virtual bool Init() override;
	void Update();
	virtual void ShutDown() override;
	void Resize();

	virtual  bool ShouldClose() const override
	{
		return m_shouldClose;
	}

	inline bool ShouldResize() const
	{
		return m_shouldResize;
	}

	inline int GetWidth() const
	{
		return m_width;
	}

	inline int GetHeight() const
	{
		return m_height;
	}

	static constexpr size_t GetFrameCount()
	{
		return 2;
	}

private:
	static LRESULT CALLBACK OnWindowMessage(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
	ATOM m_wndClass = 0;
	HWND m_window = nullptr;
	bool m_shouldClose = false;

	bool m_shouldResize = false;
	UINT m_width = 1280;
	UINT m_height = 720;

// Singleton
public:
	Win32PlatformWindow(const Win32PlatformWindow&) = delete;
	Win32PlatformWindow& operator = (const Win32PlatformWindow&) = delete;

	inline static Win32PlatformWindow& Get()
	{
		static Win32PlatformWindow instance;
		return instance;
	}

private:
	Win32PlatformWindow() = default;

};