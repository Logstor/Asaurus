#include "aspch.h"
#include "Platform/Windows/WindowsWindow.h"
#include "Platform/OpenGL/OpenGLContext.h"
#include "Asaurus/Events/ApplicationEvent.h"
#include "Asaurus/Events/KeyEvent.h"
#include "Asaurus/Events/MouseEvent.h"
#include "Asaurus/Renderer/Renderer.h"
#include "Asaurus/Core/Input.h"

namespace Asaurus
{

	static uint8_t s_GLFWWindowCount = 0;

	static void GLFWErrorCallback(int error, const char* desc)
	{
		AS_CORE_ERROR("GLFW Error! ({0}): {1}", error, desc);
	}

	Scope<Window> Window::Create(const WindowProps& props)
	{
		return CreateScope<WindowsWindow>(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		AS_PROFILE_FUNCTION();

		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		AS_PROFILE_FUNCTION();

		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		AS_PROFILE_FUNCTION();

		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;


		AS_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		// Initialize GLFW if this is the first Window
		if (s_GLFWWindowCount == 0)
		{
			AS_PROFILE_SCOPE("GLFW - Init");

			AS_CORE_INFO("Initializing GLFW");
			int success = glfwInit();
			AS_CORE_ASSERT(success, "Could not intialize GLFW!");

			glfwSetErrorCallback(GLFWErrorCallback);
		}

		// Create GLFW window
		{
			AS_PROFILE_SCOPE("GLFW - CreateWindow");

		#if defined(AS_DEBUG)
			if (Renderer::GetAPI() == RendererAPI::API::OpenGL)
				glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
		#endif

			m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
			++s_GLFWWindowCount;
		}

		// Create Rendering context
		m_Context = CreateScope<OpenGLContext>(m_Window);
		m_Context->Init();

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// Set GLFW callbacks
		InitializeGLFWCallbacks();
	}


	void WindowsWindow::Shutdown()
	{
		AS_PROFILE_FUNCTION();

		glfwDestroyWindow(m_Window);

		// No more Windows -> Terminate
		if (--s_GLFWWindowCount == 0)
		{
			AS_CORE_INFO("Terminating GLFW");
			glfwTerminate();
		}
	}

	void WindowsWindow::OnUpdate()
	{
		AS_PROFILE_FUNCTION();

		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		AS_PROFILE_FUNCTION();

		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	////////////////// Helpers //////////////////
	inline void WindowsWindow::InitializeGLFWCallbacks()
	{
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent e(static_cast<KeyCode>(key), 0);
						data.EventCallback(e);
						break;
					}

					case GLFW_REPEAT:
					{
						KeyPressedEvent e(static_cast<KeyCode>(key), 1);
						data.EventCallback(e);
						break;
					}

					case GLFW_RELEASE:
					{
						KeyReleasedEvent e(static_cast<KeyCode>(key));
						data.EventCallback(e);
						break;
					}

					default:
					{
						AS_CORE_WARN("Key action wasn't recognized: {0}", action);
						break;
					}
				}
			});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				KeyTypedEvent e(static_cast<KeyCode>(keycode));
				data.EventCallback(e);
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent e(static_cast<MouseCode>(button));
						data.EventCallback(e);
						break;
					}

					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent e(static_cast<MouseCode>(button));
						data.EventCallback(e);
						break;
					}

					default:
					{
						AS_CORE_WARN("Mouse action wasn't recognized: {0}", action);
						break;
					}
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent e((float)xOffset, (float)yOffset);
				data.EventCallback(e);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent e((float)xPos, (float)yPos);
				data.EventCallback(e);
			});
	}
}