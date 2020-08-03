#include "aspch.h"
#include "RendererAPI.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Asaurus
{
	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
			case RendererAPI::API::None:    AS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLRendererAPI>();
		}

		AS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}