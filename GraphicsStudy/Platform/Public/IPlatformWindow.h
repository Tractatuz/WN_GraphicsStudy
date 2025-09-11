#pragma once

class IPlatformWindow
{
public:
	virtual ~IPlatformWindow() = default;

	virtual bool Init() = 0;
	virtual void ShutDown() = 0;
	virtual bool ShouldClose() const = 0;
	virtual bool ShouldResize() const = 0;
	virtual void Resize() = 0;

	virtual int GetWidth() const = 0;
	virtual int GetHeight() const = 0;
};