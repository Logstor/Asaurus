#include "aspch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Asaurus
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}