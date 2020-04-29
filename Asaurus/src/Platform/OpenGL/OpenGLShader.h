#pragma once
#include "Asaurus/Renderer/Shader.h"

namespace Asaurus
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader() override;

		virtual void Bind() const override;
		virtual void Unbind() const override;

		
	private:
		uint32_t m_RendererID;
	};
}

