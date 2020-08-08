#pragma once

#include "Asaurus/Core/Input.h"

namespace Asaurus
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(KeyCode key) const override;

		virtual bool IsMouseButtonPressedImpl(MouseCode button) const override;
		virtual std::pair<float, float> GetMousePositionImpl() const override;
		virtual float GetMouseXImpl() const override;
		virtual float GetMouseYImpl() const override;
	};
}