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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}