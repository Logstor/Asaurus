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
		AS_PROFILE_FUNCTION();

		// Initialize Glad
		glfwMakeContextCurrent(m_WindowHandle);
		int statusGlad = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AS_CORE_ASSERT(statusGlad, "Failed to initialize Glad!");

		AS_CORE_INFO("OpenGL Info:");
		AS_CORE_INFO("    Vendor:   {0}", glGetString(GL_VENDOR));
		AS_CORE_INFO("    Renderer: {0}", glGetString(GL_RENDERER));
		AS_CORE_INFO("    Version:  {0}", glGetString(GL_VERSION));

		// Version check
	#ifdef AS_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		AS_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Asaurus requires atleast OpenGL version 4.5!");
	#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		AS_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}
}