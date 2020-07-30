#pragma once
#include "Asaurus/Renderer/Shader.h"
#include "glm/glm.hpp"

//TODO: Has to replaced by including glad correctly!
typedef unsigned int GLenum;

namespace Asaurus
{
	/// <summary>
	/// Shader class for OpenGL.
	/// </summary>
	class OpenGLShader : public Shader
	{
	public:
		/// <summary>
		/// Creates an OpenGLShader from a shader asset file.
		/// The file has to contain both vertex and fragment shader.
		/// </summary>
		/// <param name="path">Path to asset</param>
		/// <returns>An OpenGLShader instance</returns>
		OpenGLShader(const std::string& path);
		OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader() override;

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void SetInt(const std::string& name, const int value) override;
		virtual void SetFloat3(const std::string& name, const glm::vec3& value) override;
		virtual void SetFloat4(const std::string& name, const glm::vec4& value) override;
		virtual void SetMat4(const std::string& name, const glm::mat4& value) override;

		virtual const std::string& GetName() const override { return m_Name; }

		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
		void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);

		void UploadUniformFloat4(const std::string& name, const glm::vec4& color);
		void UploadUniformFloat3(const std::string& name, const glm::vec3& color);
		void UploadUniformFloat2(const std::string& name, const glm::vec2& color);
		void UploadUniformFloat(const std::string& name, const float color);

		void UploadUniformInt(const std::string& name, const int color);

	private:
		std::string ReadFile(const std::string& filepath);
		std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
		void Compile(const std::unordered_map<GLenum, std::string>& shaderSources);

	private:
		uint32_t m_RendererID;
		std::string m_Name;
	};
}

