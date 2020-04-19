#include "aspch.h"
#include "Application.h"
#include "Asaurus/Events/ApplicationEvent.h"
#include "Asaurus/Log.h"
#include "Window.h"

namespace Asaurus
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}

