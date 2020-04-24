#include <Asaurus.h>

class ExampleLayer : public Asaurus::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		if (Asaurus::Input::IsKeyPressed(AS_KEY_TAB))
			AS_TRACE("Tab key pressed!");
	}

	void OnEvent(Asaurus::Event& event) override
	{
		// AS_TRACE("{0}", event);
	}
};

class Sandbox : public Asaurus::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Asaurus::ImGuiLayer());
	}

	~Sandbox()
	{}
};

Asaurus::Application* Asaurus::CreateApplication()
{
	return new Sandbox();
}