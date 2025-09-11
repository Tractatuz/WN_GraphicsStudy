#pragma once

class ICommandQueue
{
public:
	virtual ~ICommandQueue() = default;

	virtual bool Init() = 0;
	virtual void ShutDown() = 0;
};