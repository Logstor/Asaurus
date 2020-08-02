#include "aspch.h"
#include "Asaurus/Renderer/Texture.h"

#include "Asaurus/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"


namespace Asaurus
{
	Ref<Texture2D> Texture2D::Create(const uint32_t width, const uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::OpenGL:
			{
				return CreateRef<OpenGLTexture2D>(width, height);
			}

			case RendererAPI::API::None:
			{
				AS_CORE_ASSERT(false, "RendererAPI::None is not supported: Texture2D::Create");
				return nullptr;
			}

			default:
			{
				AS_CORE_ASSERT(false, "RendererAPI not recognized: Texture2D::Create");
				return nullptr;
			}
		}
	}

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::OpenGL:
			{
				return CreateRef<OpenGLTexture2D>(path);
			}

			case RendererAPI::API::None:
			{
				AS_CORE_ASSERT(false, "RendererAPI::None is not supported: Texture2D::Create");
				return nullptr;
			}

			default:
			{
				AS_CORE_ASSERT(false, "RendererAPI not recognized: Texture2D::Create");
				return nullptr;
			}
		}
	}
}