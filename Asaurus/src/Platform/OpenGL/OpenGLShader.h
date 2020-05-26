#pragma once
#include "Asaurus/Renderer/Shader.h"
#include "glm/glm.hpp"

namespace Asaurus
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader() override;

		virtual void Bind() const override;
		virtual void Unbind() const override;

		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
		void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);

		void UploadUniformFloat4(const std::string& name, const glm::vec4& color);
		void UploadUniformFloat3(const std::string& name, const glm::vec3& color);
		void UploadUniformFloat2(const std::string& name, const glm::vec2& color);
		void UploadUniformFloat(const std::string& name, const float color);

		void UploadUniformInt(const std::string& name, const int color);
	private:
		uint32_t m_RendererID;
	};
}

