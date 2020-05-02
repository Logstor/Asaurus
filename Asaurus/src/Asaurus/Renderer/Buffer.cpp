#include "aspch.h"
#include "Buffer.h"
#include "Asaurus/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Asaurus
{
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::OpenGL:
			{
				return new OpenGLVertexBuffer(vertices, size);
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

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::OpenGL:
			{
				return new OpenGLIndexBuffer(indices, size);
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
