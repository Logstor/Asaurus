#pragma once

#ifdef AS_PLATFORM_WINDOWS

	#ifdef AS_BUILD_DLL
		#define ASAURUS_API __declspec(dllexport)
	#else
		#define ASAURUS_API __declspec(dllimport)
	#endif // AS_BUILD_DLL

#else
	#error Asaurus only supports Windows!

#endif

#define BIT(x) (1 << x)