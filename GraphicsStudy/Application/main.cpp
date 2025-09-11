//#include <iostream>

#include "Application.h"

int main()
{
	if (Application::Get().Init())
	{
		while (Application::Get().ShouldClose() == false)
		{
			Application::Get().Update();
			Application::Get().Render();
		}
	}

	Application::Get().Shutdown();

	return 0;
}