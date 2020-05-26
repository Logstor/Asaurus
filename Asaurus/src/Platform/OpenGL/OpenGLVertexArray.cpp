#include "aspch.h"
#include "OpenGLVertexArray.h"
#include <glad/glad.h>

namespace Asaurus
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
			case Asaurus::ShaderDataType::None:
				break;
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
		glCreateVertexArrays(1, &m_RendererID);

	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& buffer)
	{
		AS_CORE_ASSERT(buffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(m_RendererID);
		buffer->Bind();

		const auto& layout = buffer->GetLayout();
		uint32_t index = 0;
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);

			glVertexAttribPointer(index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);

			index++;
		}

		m_VertexBuffers.push_back(buffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& buffer)
	{
		glBindVertexArray(m_RendererID);
		buffer->Bind();

		m_IndexBuffer = buffer;
	}
}