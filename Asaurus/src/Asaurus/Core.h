#pragma once

#ifdef AS_PLATFORM_WINDOWS
#if AS_DYNAMIC_LINK
	#ifdef AS_BUILD_DLL
		#define ASAURUS_API __declspec(dllexport)
	#else
		#define ASAURUS_API __declspec(dllimport)
	#endif // AS_BUILD_DLL
#else
	#define ASAURUS_API
#endif

#else
	#error Asaurus only supports Windows!

#endif

#ifdef AS_ENABLE_ASSERTS
	#define AS_ASSERT(x, ...) { if(!(x)) { AS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AS_CORE_ASSERT(x, ...) { if(!(x)) { AS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AS_ASSERT(x, ...)
	#define AS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define AS_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)