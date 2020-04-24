#pragma once

#include "Asaurus/Core.h"
#include "Asaurus/Layer/Layer.h"
#include "Asaurus/Events/MouseEvent.h"
#include "Asaurus/Events/KeyEvent.h"
#include "Asaurus/Events/ApplicationEvent.h"

namespace Asaurus
{
	class ASAURUS_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		bool OnMousePressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrollEvent(MouseScrolledEvent& e);

		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);

		bool OnWindowResizeEvent(WindowResizeEvent& e);

	private:
		float m_Time = 0.0f;
	};
}