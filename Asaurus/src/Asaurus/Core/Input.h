#pragma once

#include "Asaurus/Core/Core.h"
#include "Asaurus/Core/MouseCodes.h"
#include "Asaurus/Core/KeyCodes.h"

namespace Asaurus
{
	class Input
	{
	public:
		inline static bool IsKeyPressed(KeyCode key) { return s_Instance->IsKeyPressedImpl(key); }

		inline static bool IsMouseButtonPressed(MouseCode button) { return s_Instance->IsMouseButtonPressedImpl(button); }

		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }

		static Scope<Input> Create();
	protected:
		virtual bool IsKeyPressedImpl(KeyCode key) const = 0;
		virtual bool IsMouseButtonPressedImpl(MouseCode button) const = 0;
		virtual std::pair<float, float> GetMousePositionImpl() const = 0;
		virtual float GetMouseXImpl() const = 0;
		virtual float GetMouseYImpl() const = 0;

	private:
		static Scope<Input> s_Instance;
	};
}