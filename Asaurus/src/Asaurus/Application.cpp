#include "aspch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Asaurus
{
	Asaurus::Application::Application()
	{
	}

	Asaurus::Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		AS_TRACE(e);

		std::getchar();
	}
}

