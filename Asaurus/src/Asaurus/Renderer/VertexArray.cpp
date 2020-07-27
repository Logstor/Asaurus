#include "aspch.h"
#include "VertexArray.h"
#include "Asaurus/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Asaurus
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::OpenGL:
			{
				return std::make_shared<OpenGLVertexArray>();
			}

			case RendererAPI::API::None:
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
