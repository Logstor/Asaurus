#pragma once

#include <string>
#include <unordered_map>

#include <glm/glm.hpp>

namespace Asaurus
{
	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		
		virtual void SetInt(const std::string& name, const int value) = 0;
		virtual void SetFloat3(const std::string& name, const glm::vec3& value) = 0;
		virtual void SetFloat4(const std::string& name, const glm::vec4& value) = 0;
		virtual void SetMat4(const std::string& name, const glm::mat4& value) = 0;

		virtual const std::string& GetName() const = 0;

		/// <summary>
		/// For use when a shader has to be created from a asset file. 
		/// It needs to contain both vertex and fragment shader.
		/// </summary>
		/// <param name="path">Path to the asset</param>
		/// <returns>A RendererAPI specific shader</returns>
		static Ref<Shader> Create(const std::string& path);

		/// <summary>
		/// For use when a shader has to be created from a static string.
		/// </summary>
		/// <param name="name">String with the name of the shader</param>
		/// <param name="vertexSrc">String with the vertex shader</param>
		/// <param name="fragmentSrc">String with the fragment shader</param>
		/// <returns>A RendererAPI specific shader</returns>
		static Ref<Shader> Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
	};

	class ShaderLibrary
	{
	public:
		void Add(const Ref<Shader>& shader);
		void Add(const std::string& name, const Ref<Shader>& shader);

		/// <summary>
		/// Loads a shader with the file as name.
		/// </summary>
		/// <param name="filepath">Path to asset</param>
		/// <returns>Ref to the shader</returns>
		Ref<Shader> Load(const std::string& filepath);

		/// <summary>
		/// Loads a shader with the given name as the name.
		/// </summary>
		/// <param name="name">Name of shader</param>
		/// <param name="filepath">Path to asset</param>
		/// <returns>ref to the shader</returns>
		Ref<Shader> Load(const std::string& name, const std::string& filepath);

		/// <summary>
		/// Gets the specified shader from the library.
		/// </summary>
		/// <param name="name">Name of the shader</param>
		/// <returns>Ref to the shader</returns>
		Ref<Shader> Get(const std::string& name);

		/// <summary>
		/// Checks whether the given shader exists in the shader Library.
		/// </summary>
		/// <param name="name">Name of shader</param>
		/// <returns>bool</returns>
		bool Exists(const std::string& name) const;
	private:
		std::unordered_map<std::string, Ref<Shader>> m_Shaders;
	};
}