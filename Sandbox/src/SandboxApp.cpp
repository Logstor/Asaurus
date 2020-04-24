#include <Asaurus.h>

#include "imgui/imgui.h"

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

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Asaurus says Welcome!");
		ImGui::End();
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