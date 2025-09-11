#pragma once

#include "Core/Common.h"

enum class EPlatform
{
	None,
	Win32,
	Max,
};

class IPlatformWindow
{
public:
	virtual ~IPlatformWindow() = default;

	static std::unique_ptr<IPlatformWindow> Create(EPlatform PlatformType);

	virtual bool Init() = 0;
	virtual void Update() = 0;
	virtual void Shutdown() = 0;
	virtual bool ShouldClose() const = 0;
	virtual bool ShouldResize() const = 0;
	virtual void Resize() = 0;

	virtual int GetWidth() const = 0;
	virtual int GetHeight() const = 0;
};