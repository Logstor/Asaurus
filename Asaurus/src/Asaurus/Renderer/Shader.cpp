#include "aspch.h"
#include "Shader.h"
#include "Asaurus/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include <glad/glad.h>

namespace Asaurus
{
	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::OpenGL: { return new OpenGLShader(vertexSrc, fragmentSrc); }
			case RendererAPI::None: 
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
}