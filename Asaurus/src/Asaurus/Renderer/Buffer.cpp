#include "aspch.h"
#include "Asaurus/Renderer/Buffer.h"
#include "Asaurus/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Asaurus
{
	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::OpenGL:
			{
				return CreateRef<OpenGLVertexBuffer>(vertices, size);
			}

			case RendererAPI::API::None:
			{
				AS_CORE_ASSERT(false, "RendererAPI::None is not supported: VertexBuffer::Create");
				return nullptr;
			}

			default:
			{
				AS_CORE_ASSERT(false, "RendererAPI not recognized: VertexBuffer::Create");
				return nullptr;
			}
		}
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::OpenGL:
			{
				return CreateRef<OpenGLIndexBuffer>(indices, size);
			}

			case RendererAPI::API::None:
			{
				AS_CORE_ASSERT(false, "RendererAPI::None is not supported: IndexBuffer::Create");
				return nullptr;
			}

			default:
			{
				AS_CORE_ASSERT(false, "RendererAPI not recognized: IndexBuffer::Create");
				return nullptr;
			}
		}
	}
}
