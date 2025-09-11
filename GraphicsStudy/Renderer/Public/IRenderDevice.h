#pragma once

class IRenderDevice
{
public:
	virtual ~IRenderDevice() = default;
	
	virtual bool Init() = 0;
	virtual void ShutDown() = 0;
	virtual void Flush() = 0;
};