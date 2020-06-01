#pragma once

namespace Asaurus
{
	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		/// <summary>
		/// For use when a shader has to be created from a asset file. 
		/// It needs to contain both vertex and fragment shader.
		/// </summary>
		/// <param name="path">Path to the asset</param>
		/// <returns>A RendererAPI specific shader</returns>
		static Shader* Create(const std::string& path);

		/// <summary>
		/// For use when a shader has to be created from a static string.
		/// </summary>
		/// <param name="vertexSrc">String with the vertex shader</param>
		/// <param name="fragmentSrc">String with the fragment shader</param>
		/// <returns>A RendererAPI specific shader</returns>
		static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};
}