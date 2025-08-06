#pragma once

#include <Support/WinInclude.h>
#include <Support/ComPointer.h>
#include <D3D/DXContext.h>

class DXWindow
{
public:
	bool Init();
	void Update();
	void Present();
	void ShutDown();
	void Resize();

	inline bool ShouldClose() const
	{
		return m_shouldClose;
	}

	inline bool ShouldResize() const
	{
		return m_shouldResize;
	}

	inline UINT GetWidth() const
	{
		return m_width;
	}

	inline UINT GetHeight() const
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

	ComPointer<IDXGISwapChain4> m_swapChain;

// Singleton
public:
	DXWindow(const DXWindow&) = delete;
	DXWindow& operator = (const DXWindow&) = delete;

	inline static DXWindow& Get()
	{
		static DXWindow instance;
		return instance;
	}

private:
	DXWindow() = default;

};