#pragma once

#include "Asaurus/Core/Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Asaurus
{
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define AS_CORE_TRACE(...)	::Asaurus::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AS_CORE_INFO(...)	::Asaurus::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AS_CORE_WARN(...)	::Asaurus::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AS_CORE_ERROR(...)	::Asaurus::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AS_CORE_CRIT(...)	::Asaurus::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define AS_TRACE(...)		::Asaurus::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AS_INFO(...)		::Asaurus::Log::GetClientLogger()->info(__VA_ARGS__)
#define AS_WARN(...)		::Asaurus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AS_ERROR(...)		::Asaurus::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_CRIT(...)		::Asaurus::Log::GetClientLogger()->critical(__VA_ARGS__)
