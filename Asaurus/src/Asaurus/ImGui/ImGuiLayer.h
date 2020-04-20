#pragma once

#include "Asaurus/Core.h"
#include "Asaurus/Layer.h"

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
		float m_Time = 0.0f;
	};
}