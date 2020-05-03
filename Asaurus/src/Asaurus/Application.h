#pragma once

#include "Core.h"
#include "Layer/LayerStack.h"
#include "Events/Event.h"
#include "Asaurus/Events/ApplicationEvent.h"
#include "Window.h"
#include "Asaurus/Renderer/Shader.h"
#include "Asaurus/Renderer/Buffer.h"
#include "Asaurus/Renderer/VertexArray.h"

#include "Asaurus/Renderer/OrthoCamera.h"


#include "Asaurus/ImGui/ImGuiLayer.h"

namespace Asaurus
{
	class ASAURUS_API Application
	{
	public:

		Application();

		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		ImGuiLayer* m_ImGuiLayer;
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		static Application* s_Instance;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

		OrthoCamera m_Camera;
	};

	// To be defined in client
	Application* CreateApplication();
}

