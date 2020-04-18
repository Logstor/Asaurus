#pragma once

#ifdef AS_PLATFORM_WINDOWS

extern Asaurus::Application* Asaurus::CreateApplication();

int main(int argc, char** argv)
{
	printf("Asaurus Engine\n");
	auto app = Asaurus::CreateApplication();
	app->Run();
	delete app;
}

#endif