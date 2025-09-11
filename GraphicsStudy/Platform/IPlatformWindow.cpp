#include "IPlatformWindow.h"

#include "Platform/Win32/Win32PlatformWindow.h"

std::unique_ptr<IPlatformWindow> IPlatformWindow::Create(EPlatform PlatformType)
{
	switch (PlatformType)
	{
	case EPlatform::Win32:
		return std::make_unique<Win32PlatformWindow>();
	case EPlatform::None:
	case EPlatform::Max:
	default:
		break;
	}
	return nullptr;
}
