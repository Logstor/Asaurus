#include <Asaurus.h>

class Sandbox : public Asaurus::Application
{
public:
	Sandbox()
	{}

	~Sandbox()
	{}
};

Asaurus::Application* Asaurus::CreateApplication()
{
	return new Sandbox();
}