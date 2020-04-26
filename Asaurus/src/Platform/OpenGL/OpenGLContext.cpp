#include "aspch.h"
#include "OpenGLContext.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Asaurus
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
		AS_CORE_ASSERT(m_WindowHandle, "Window Handle is null!");
	}

	void OpenGLContext::Init()
	{
		// Initialize Glad
		glfwMakeContextCurrent(m_WindowHandle);
		int statusGlad = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AS_CORE_ASSERT(statusGlad, "Failed to initialize Glad!");
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}