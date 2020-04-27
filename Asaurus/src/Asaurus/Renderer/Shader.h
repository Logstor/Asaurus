#pragma once

#include <string>

namespace Asaurus
{
	class Shader
	{
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentsource);
		~Shader();

		void Bind() const;
		void Unbind() const;

	private:
		uint32_t m_RendererID;
	};
}