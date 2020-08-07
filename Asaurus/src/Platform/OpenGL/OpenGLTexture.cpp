#include "aspch.h"
#include "OpenGLTexture.h"

#include <stb_image.h>
#include <glad/glad.h>

namespace Asaurus
{
	OpenGLTexture2D::OpenGLTexture2D(const uint32_t width, const uint32_t height)
		:m_Width(width), m_Height(height)
	{
		AS_PROFILE_FUNCTION();

		// Determine format
		m_InternalFormat = GL_RGB8, m_DataFormat = GL_RGBA;
		
		// Create Storage for Texture and upload
		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, m_InternalFormat, m_Width, m_Height);

		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}

	OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
		:m_Path(path)
	{
		AS_PROFILE_FUNCTION();

		// stbi loads from top to bottom, and OpenGL draws the opposite. Therefore:
		stbi_set_flip_vertically_on_load(1);

		int width, height, channels;
		stbi_uc* data = nullptr;
		{
			AS_PROFILE_SCOPE("stbi_load - OpenGLTexture2D::OpenGLTexture2D(const std::string& path)");
			data = stbi_load(path.c_str(), &width, &height, &channels, 0);
		}

		AS_CORE_ASSERT(data, "Failed to load image!");

		// Determine format
		GLenum internalFormat = 0, dataFormat = 0;
		switch (channels)
		{
			case 3:
				internalFormat = GL_RGB8;
				dataFormat = GL_RGB;
				break;

			case 4:
				internalFormat = GL_RGBA8;
				dataFormat = GL_RGBA;
				break;

			default:
				AS_CORE_WARN("Couldn't specify format for Texture {0}, with {1} channels", path, channels);
				break;
		}
		AS_CORE_ASSERT(internalFormat & dataFormat, "{0} Format not supported!");

		// Set properties
		m_Width = width;
		m_Height = height;
		m_InternalFormat = internalFormat;
		m_DataFormat = dataFormat;

		// Create Storage for Texture and upload
		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, internalFormat, m_Width, m_Height);

		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, dataFormat, GL_UNSIGNED_BYTE, data);

		// Free data
		stbi_image_free(data);
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		AS_PROFILE_FUNCTION();

		glDeleteTextures(1, &m_RendererID);
	}

	void OpenGLTexture2D::SetData(void* data, size_t size)
	{
		AS_PROFILE_FUNCTION();

		// Debug code
	#ifdef AS_DEBUG
		uint32_t bytesPerPixel = m_DataFormat == GL_RGBA ? 4 : 3;
		uint32_t actualSize = m_Width * m_Height * bytesPerPixel;
		AS_CORE_ASSERT(size == actualSize, "Call to SetData failed - size argument needs to match actualsize");
	#endif

		// Set data
		glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, m_DataFormat, GL_UNSIGNED_BYTE, data);
	}

	void OpenGLTexture2D::Bind(uint32_t slot) const
	{
		AS_PROFILE_FUNCTION();

		glBindTextureUnit(slot, m_RendererID);
	}
}