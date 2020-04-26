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

		AS_CORE_INFO("OpenGL Info:");
		AS_CORE_INFO("    Vendor:   {0}", glGetString(GL_VENDOR));
		AS_CORE_INFO("    Renderer: {0}", glGetString(GL_RENDERER));
		AS_CORE_INFO("    Version:  {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}