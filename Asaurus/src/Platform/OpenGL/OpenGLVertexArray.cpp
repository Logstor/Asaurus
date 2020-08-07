#include "aspch.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"
#include <glad/glad.h>

namespace Asaurus
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
			case Asaurus::ShaderDataType::None:
			{
				AS_CORE_ASSERT(false, "ShaderDataType was None!");
				return 0;
			}
			case Asaurus::ShaderDataType::Float:
				return GL_FLOAT;
			case Asaurus::ShaderDataType::Float2:
				return GL_FLOAT;
			case Asaurus::ShaderDataType::Float3:
				return GL_FLOAT;
			case Asaurus::ShaderDataType::Float4:
				return GL_FLOAT;
			case Asaurus::ShaderDataType::Mat3:
				return GL_FLOAT;
			case Asaurus::ShaderDataType::Mat4:
				return GL_FLOAT;
			case Asaurus::ShaderDataType::Int:
				return GL_INT;
			case Asaurus::ShaderDataType::int2:
				return GL_INT;
			case Asaurus::ShaderDataType::Int3:
				return GL_INT;
			case Asaurus::ShaderDataType::Int4:
				return GL_INT;
			case Asaurus::ShaderDataType::Bool:
				return GL_BOOL;
			default:
			{
				AS_CORE_ASSERT(false, "Unknown ShaderDataType!");
				return 0;
			}
		}
	}


	OpenGLVertexArray::OpenGLVertexArray()
	{
		AS_PROFILE_FUNCTION();

		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		AS_PROFILE_FUNCTION();

		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		AS_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		AS_PROFILE_FUNCTION();

		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& buffer)
	{
		AS_PROFILE_FUNCTION();

		AS_CORE_ASSERT(buffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(m_RendererID);
		buffer->Bind();

		const auto& layout = buffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(m_VertexBufferIndex);

			glVertexAttribPointer(m_VertexBufferIndex,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);

			m_VertexBufferIndex++;
		}

		m_VertexBuffers.push_back(buffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& buffer)
	{
		AS_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
		buffer->Bind();

		m_IndexBuffer = buffer;
	}
}