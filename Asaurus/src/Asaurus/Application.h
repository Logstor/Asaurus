#pragma once

#include "Core.h"

namespace Asaurus
{
	class ASAURUS_API Application
	{
	public:

		Application();

		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}

