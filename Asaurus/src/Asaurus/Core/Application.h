#pragma once

#include "Asaurus/Core/Core.h"
#include "Asaurus/Core/Layer/LayerStack.h"
#include "Asaurus/Events/Event.h"
#include "Asaurus/Events/ApplicationEvent.h"
#include "Asaurus/Core/Window.h"
#include "Asaurus/Core/Timestep.h"

#include "Asaurus/Renderer/OrthoCamera.h"


#include "Asaurus/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Asaurus
{
	class Application
	{
	public:

		Application();

		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		LayerStack m_LayerStack;
		float m_LastFrameTime;

		static Application* s_Instance;
		friend int ::main(int argc, char** argv);

		bool m_Minimized	= false;
		bool m_Running		= true;
	};

	// To be defined in client
	Application* CreateApplication();
}

