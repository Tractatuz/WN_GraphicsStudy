#pragma once

#include "Win32Include.h"
#include "Platform/IPlatformWindow.h"

class Win32PlatformWindow : public IPlatformWindow
{
public:
	virtual bool Init() override;
	virtual void Update() override;
	virtual void Shutdown() override;
	virtual void Resize() override;

	virtual bool ShouldClose() const override
	{
		return m_shouldClose;
	}

	virtual bool ShouldResize() const override
	{
		return m_shouldResize;
	}

	virtual uint32_t GetWidth() const override
	{
		return m_width;
	}

	virtual uint32_t GetHeight() const override
	{
		return m_height;
	}

	static constexpr size_t GetFrameCount()
	{
		return 2;
	}

private:
	static LRESULT CALLBACK OnWindowMessage(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);
	
	LRESULT OnWindowMessage(UINT msg, WPARAM wParam, LPARAM lParam);
	void ShowErrorMessage(DWORD errorCode);

private:
	ATOM m_wndClass = 0;
	HWND m_window = nullptr;
	bool m_shouldClose = false;

	bool m_shouldResize = false;
	UINT m_width = 1280;
	UINT m_height = 720;
};