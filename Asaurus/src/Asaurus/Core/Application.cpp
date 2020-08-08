#include "aspch.h"
#include "Asaurus/Core/Application.h"
#include "Asaurus/Core/Log.h"
#include "Asaurus/Renderer/Renderer.h"

//REMOVE
#include "GLFW/glfw3.h"
#include "Asaurus/Renderer/Shader.h"

namespace Asaurus
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		AS_PROFILE_FUNCTION();

		AS_CORE_ASSERT(!s_Instance, "Application already exist!");
		s_Instance = this;

		m_Window = Window::Create();
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		// Initialize Renderer
		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application() 
	{
		Renderer::Shutdown();
	}

	void Application::PushLayer(Layer* layer) 
	{ 
		AS_PROFILE_FUNCTION();

		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer) 
	{ 
		AS_PROFILE_FUNCTION();

		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		AS_PROFILE_FUNCTION();

		// Create Dispatcher and Dispatch
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));

		for (auto it = m_LayerStack.rend(); it != m_LayerStack.rbegin(); ++it)
		{
			(*it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::Run()
	{
		AS_PROFILE_FUNCTION();

		float time;
		Timestep timestep;

		while (m_Running)
		{
			AS_PROFILE_SCOPE("RunLoop");

			time = (float)glfwGetTime(); // Platform::GetTime()
			timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			// Only render and update if the window isn't minimized
			if (!m_Minimized)
			{
				{
					AS_PROFILE_SCOPE("Update Layers");

					for (Layer* layer : m_LayerStack)
						layer->OnUpdate(timestep);
				}

				m_ImGuiLayer->Begin();
				{
					AS_PROFILE_SCOPE("LayerStack OnImGuiRender");

					for (Layer* layer : m_LayerStack)
						layer->OnImGuiRender();
				}
				m_ImGuiLayer->End();
			}

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		AS_PROFILE_FUNCTION();

		if (!e.GetWidth() || !e.GetHeight())
		{
			m_Minimized = true;
			return false;
		}

		// Make sure minimized is false
		m_Minimized = false;

		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		// Don't consume the event
		return false;
	}
}

