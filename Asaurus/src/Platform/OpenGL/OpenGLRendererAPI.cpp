#include "aspch.h"
#include "OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace Asaurus
{
	OpenGLRendererAPI::OpenGLRendererAPI()
	{
	}

	OpenGLRendererAPI::~OpenGLRendererAPI()
	{
	}

	void OpenGLMessageCallback(
		unsigned source,
		unsigned type,
		unsigned id,
		unsigned severity,
		int length,
		const char* message,
		const void* userParam)
	{
		switch (severity)
		{
			case GL_DEBUG_SEVERITY_HIGH:         AS_CORE_CRIT(message);		break;
			case GL_DEBUG_SEVERITY_MEDIUM:       AS_CORE_ERROR(message);	break;
			case GL_DEBUG_SEVERITY_LOW:          AS_CORE_WARN(message);		break;
			case GL_DEBUG_SEVERITY_NOTIFICATION: AS_CORE_TRACE(message);	break;
			default: AS_CORE_ASSERT(false, "Unknown severity level!");
		}
	}

	/// <summary>
	/// Initializes the render.
	///
	/// - Enables blending
	/// -
	/// </summary>
	void OpenGLRendererAPI::Init()
	{
		AS_PROFILE_FUNCTION();

	#ifdef AS_DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);

		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
	#endif

		// Enable blending
		glEnable(GL_BLEND); glEnable(GL_DEPTH_TEST);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void OpenGLRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		glViewport(x, y, width, height);
	}

	void OpenGLRendererAPI::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::DrawIndexed(const Ref<VertexArray>& vertexArray, const uint32_t indexCount)
	{
		// An Error is probably introduced here!
		uint32_t count = indexCount ? vertexArray->GetIndexBuffer()->GetCount() : indexCount;
		
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}