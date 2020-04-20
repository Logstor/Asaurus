#include <Asaurus.h>

class ExampleLayer : public Asaurus::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		AS_INFO("ExampleLayer:: Update");
	}

	void OnEvent(Asaurus::Event& event) override
	{
		AS_TRACE("{0}", event);
	}
};

class Sandbox : public Asaurus::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{}
};

Asaurus::Application* Asaurus::CreateApplication()
{
	return new Sandbox();
}