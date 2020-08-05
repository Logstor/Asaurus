#pragma once

#include "Asaurus/Core/Core.h"

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
	AS_CRIT("CRITICAL");


	// Create client application and run
	AS_PROFILE_BEGIN_SESSION("Startup", "AsaurusProfile-Startup.json");
	auto app = Asaurus::CreateApplication();
	AS_PROFILE_END_SESSION();

	AS_PROFILE_BEGIN_SESSION("Runtime", "AsaurusProfile-Runtime.json");
	app->Run();
	AS_PROFILE_END_SESSION();

	AS_PROFILE_BEGIN_SESSION("Shutdown", "AsaurusProfile-Shutdown.json");
	delete app;
	AS_PROFILE_END_SESSION();
}

#endif