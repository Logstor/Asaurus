#pragma once

#include <memory>

// Platform detection using predefined macros
#ifdef _WIN32
	/* Windows x64/x86 */
	#ifdef _WIN64
		/* Windows x64  */
		#define AS_PLATFORM_WINDOWS

	#else
		/* Windows x86 */
		#error "x86 Builds are not supported!"
	#endif
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
	/* TARGET_OS_MAC exists on all the platforms
	 * so we must check all of them (in this order)
	 * to ensure that we're running on MAC
	 * and not some other Apple platform */
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator is not supported!"

	#elif TARGET_OS_IPHONE == 1
		#define AS_PLATFORM_IOS
		#error "IOS is not supported!"

	#elif TARGET_OS_MAC == 1
		#define AS_PLATFORM_MACOS
		#error "MacOS is not supported!"

	#else
		#error "Unknown Apple platform!"
	#endif
/* We also have to check __ANDROID__ before __linux__
 * since android is based on the linux kernel
 * it has __linux__ defined */
#elif defined(__ANDROID__)
	#define AS_PLATFORM_ANDROID
	#error "Android is not supported!"

#elif defined(__linux__)
	#define AS_PLATFORM_LINUX
	#error "Linux is not supported!"

#else
	/* Unknown compiler/platform */
	#error "Unknown platform!"
#endif // End of platform detection

#ifdef AS_DEBUG
	#define AS_ENABLE_ASSERTS
#endif

//////////// Profiling ////////////
#define AS_PROFILE 1

#if AS_PROFILE
	// Resolve which function signature macro will be used. Note that this only
	// is resolved when the (pre)compiler starts, so the syntax highlighting
	// could mark the wrong one in your editor!
	#if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) || (defined(__ICC) && (__ICC >= 600)) || defined(__ghs__)
		#define AS_FUNC_SIG __PRETTY_FUNCTION__
	#elif defined(__DMC__) && (__DMC__ >= 0x810)
		#define AS_FUNC_SIG __PRETTY_FUNCTION__
	#elif defined(__FUNCSIG__)
		#define AS_FUNC_SIG __FUNCSIG__
	#elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) || (defined(__IBMCPP__) && (__IBMCPP__ >= 500))
		#define AS_FUNC_SIG __FUNCTION__
	#elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)
		#define AS_FUNC_SIG __FUNC__
	#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
		#define AS_FUNC_SIG __func__
	#elif defined(__cplusplus) && (__cplusplus >= 201103)
		#define AS_FUNC_SIG __func__
	#else
		#define AS_FUNC_SIG "HZ_FUNC_SIG unknown!"
	#endif

	#define AS_PROFILE_BEGIN_SESSION(name, filepath) ::Asaurus::Instrumentor::Get().BeginSession(name, filepath)
	#define AS_PROFILE_END_SESSION() ::Asaurus::Instrumentor::Get().EndSession()
	#define AS_PROFILE_SCOPE(name) ::Asaurus::InstrumentationTimer timer##__LINE__(name)
	#define AS_PROFILE_FUNCTION() AS_PROFILE_SCOPE(AS_FUNC_SIG)
#else
	#define AS_PROFILE_BEGIN_SESSION(name, filepath)
	#define AS_PROFILE_END_SESSION()
	#define AS_PROFILE_SCOPE(name)
	#define AS_PROFILE_FUNCTION()
#endif
////////////////////////////////////

#ifdef AS_ENABLE_ASSERTS
	#define AS_ASSERT(x, ...) { if(!(x)) { AS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AS_CORE_ASSERT(x, ...) { if(!(x)) { AS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AS_ASSERT(x, ...)
	#define AS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define AS_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

// Asaurus Pointer types
namespace Asaurus
{
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
	
	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}