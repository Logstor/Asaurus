#pragma once

#ifdef AS_PLATFORM_WINDOWS

extern Asaurus::Application* Asaurus::CreateApplication();

int main(int argc, char** argv)
{
	// Initialize logging
	Asaurus::Log::Init();
	AS_TRACE("TRACE");
	AS_INFO("INFO");
	AS_WARN("WARNING");
	AS_CORE_ERROR("ERROR");
	AS_CRIT("CRITICAL Var={0}", 10);



	auto app = Asaurus::CreateApplication();
	app->Run();
	delete app;
}

#endif