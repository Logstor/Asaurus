#include "aspch.h"
#include "Shader.h"
#include "Asaurus/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include <glad/glad.h>

namespace Asaurus
{
	Ref<Shader> Shader::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::OpenGL: { return CreateRef<OpenGLShader>(path); }
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

	Ref<Shader> Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::OpenGL: { return CreateRef<OpenGLShader>(name, vertexSrc, fragmentSrc); }
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

	/////////////// ShaderLibrary /////////////// 

	void ShaderLibrary::Add(const std::string& name, const Ref<Shader>& shader)
	{
		// Check that we don't have the shader in the map already
		AS_CORE_ASSERT(!Exists(name), "Shader already exists!");

		m_Shaders[name] = shader;
	}

	void ShaderLibrary::Add(const Ref<Shader>& shader)
	{
		auto& name = shader->GetName();

		Add(name, shader);
	}


	Ref<Shader> ShaderLibrary::Load(const std::string& filepath)
	{
		auto shader = Shader::Create(filepath);

		Add(shader);

		return shader;
	}

	Ref<Shader> ShaderLibrary::Load(const std::string& name, const std::string& filepath)
	{
		auto shader = Shader::Create(filepath);

		Add(name, shader);

		return shader;
	}

	Ref<Shader> ShaderLibrary::Get(const std::string& name)
	{
		// Make sure it exists
		AS_CORE_ASSERT(Exists(name), "Shader not found!");
		return m_Shaders[name];
	}
	bool ShaderLibrary::Exists(const std::string& name) const
	{
		return m_Shaders.find(name) != m_Shaders.end();
	}
}