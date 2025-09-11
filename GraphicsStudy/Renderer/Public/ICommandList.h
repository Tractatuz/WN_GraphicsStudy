#pragma once

class ICommandList
{
public:
	virtual ~ICommandList() = default;

	virtual bool Init() = 0;
	virtual void ShutDown() = 0;
};