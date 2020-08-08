#include "aspch.h"
#include "Asaurus/Core/Window.h"

#ifdef AS_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Asaurus
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef AS_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		AS_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}