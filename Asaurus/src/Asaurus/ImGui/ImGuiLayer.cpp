#include "aspch.h"
#include "ImGuiLayer.h"
#include "imgui.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "Asaurus/Application.h"

// Temporary
#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Asaurus
{
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{ }

	ImGuiLayer::~ImGuiLayer() {}

	void ImGuiLayer::OnAttach() 
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		// Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array.
		io.KeyMap[ImGuiKey_Tab]			= GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow]	= GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow]	= GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow]		= GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow]	= GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp]		= GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown]	= GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home]		= GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End]			= GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert]		= GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete]		= GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace]	= GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space]	= GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter]	= GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape]	= GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_A]		= GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C]		= GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V]		= GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X]		= GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y]		= GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z]		= GLFW_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach() 
	{

	}

	void ImGuiLayer::OnUpdate()
	{
		// Set DisplaySize
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		// Timing
		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		// Call new frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseMovedEvent>			(AS_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseButtonPressedEvent>	(AS_BIND_EVENT_FN(ImGuiLayer::OnMousePressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>	(AS_BIND_EVENT_FN(ImGuiLayer::OnMouseReleasedEvent));
		dispatcher.Dispatch<MouseScrolledEvent>			(AS_BIND_EVENT_FN(ImGuiLayer::OnMouseScrollEvent));
		dispatcher.Dispatch<KeyPressedEvent>			(AS_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyReleasedEvent>			(AS_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
		dispatcher.Dispatch<KeyTypedEvent>				(AS_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
		dispatcher.Dispatch<WindowResizeEvent>			(AS_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
	}

	bool ImGuiLayer::OnMousePressedEvent(MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;

		// Do not consume the event
		return false;
	}

	bool ImGuiLayer::OnMouseReleasedEvent(MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;

		// Do not consume the event
		return false;
	}

	bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());

		// Do not consume the event
		return false;
	}

	bool ImGuiLayer::OnMouseScrollEvent(MouseScrolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += e.GetXOffset();
		io.MouseWheel += e.GetYOffset();

		// Do not consume the event
		return false;
	}

	bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = true;

		io.KeyCtrl = io.KeysDown[GLFW_KEY_RIGHT_CONTROL] || io.KeysDown[GLFW_KEY_LEFT_CONTROL];
		io.KeyShift = io.KeysDown[GLFW_KEY_RIGHT_SHIFT] || io.KeysDown[GLFW_KEY_LEFT_SHIFT];
		io.KeyAlt = io.KeysDown[GLFW_KEY_RIGHT_ALT] || io.KeysDown[GLFW_KEY_LEFT_ALT];
		io.KeySuper = io.KeysDown[GLFW_KEY_RIGHT_SUPER] || io.KeysDown[GLFW_KEY_LEFT_SUPER];

		// Do not consume the event
		return false;
	}

	bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = false;

		// Do not consume the event
		return false;
	}

	bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();

		int keycode = e.GetKeyCode();
		if (keycode > 0 && keycode < 0x10000)
			io.AddInputCharacter((unsigned short)keycode);

		// Do not consume the event
		return false;
	}

	bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());

		// Do not consume the event
		return false;
	}
}