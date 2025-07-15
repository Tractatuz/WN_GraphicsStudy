#pragma once

#include <Support/WinInclude.h>
#include <Support/ComPointer.h>

class DXWindow
{
public:
	bool Init();
	void ShutDown();

private:
	static LRESULT CALLBACK OnWindowMessage(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
	ATOM m_wndClass = 0;


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