#include "aspch.h"
#include "WindowsInput.h"

#include "Asaurus/Core/Application.h"
#include <GLFW/glfw3.h>

namespace Asaurus
{
	Scope<Input> Input::s_Instance = CreateScope<WindowsInput>();

	bool WindowsInput::IsKeyPressedImpl(KeyCode key) const
	{
		// We know it's a GLFWwindow
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		// Get the state
		int state = glfwGetKey(window, static_cast<uint32_t>(key));

		// true if it's down in any way
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(MouseCode button) const
	{
		// We know it's a GLFWwindow
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		int state = glfwGetMouseButton(window, static_cast<uint32_t>(button));

		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl() const
	{
		// We know it's a GLFWwindow
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		double x, y;
		glfwGetCursorPos(window, &x, &y);

		return { (float)x, (float)y };
	}

	float WindowsInput::GetMouseXImpl() const
	{
		auto [x, y] = GetMousePositionImpl();
		return x;
	}

	float WindowsInput::GetMouseYImpl() const
	{
		auto [x, y] = GetMousePositionImpl();
		return y;
	}
}