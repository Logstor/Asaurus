#include "aspch.h"
#include "OpenGLTexture.h"

#include "stb_image.h"
#include "glad/glad.h"

namespace Asaurus
{
	OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
		:m_Path(path)
	{
		// stbi loads from top to bottom, and OpenGL draws the opposite. Therefore:
		stbi_set_flip_vertically_on_load(1);

		int width, height, channels;
		stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
		AS_CORE_ASSERT(data, "Failed to load image!");

		m_Width = width;
		m_Height = height;

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

		// Create Storage for Texture and upload
		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, internalFormat, m_Width, m_Height);

		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, dataFormat, GL_UNSIGNED_BYTE, data);

		// Free data
		stbi_image_free(data);
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &m_RendererID);
	}

	void OpenGLTexture2D::Bind(uint32_t slot) const
	{
		glBindTextureUnit(slot, m_RendererID);
	}
}