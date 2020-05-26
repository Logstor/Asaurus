#include "aspch.h"
#include "Asaurus/Renderer/Texture.h"

#include "Asaurus/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"


namespace Asaurus
{
	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::OpenGL:
			{
				return std::make_shared<OpenGLTexture2D>(path);
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