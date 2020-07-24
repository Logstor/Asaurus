#include "aspch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Asaurus
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// Logging pattern Time -> LoggerName -> Message
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// Create Asaurus logger
		s_CoreLogger = spdlog::stdout_color_mt("ASAURUS");
		s_CoreLogger->set_level(spdlog::level::trace);

		// Create Client logger
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}