#include "aspch.h"
#include "VertexArray.h"
#include "Asaurus/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Asaurus
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::OpenGL:
			{
				return new OpenGLVertexArray();
			}

			case RendererAPI::None:
			{
				AS_CORE_ASSERT(false, "RendererAPI::None is not supported: VertexArray::Create");
				return nullptr;
			}

			default:
			{
				AS_CORE_ASSERT(false, "RendererAPI not recognized: VertexArray::Create");
				return nullptr;
			}
		}
	}
}
