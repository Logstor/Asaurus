#pragma once

#include "Asaurus/Renderer/RenderCommand.h"
#include "Asaurus/Renderer/OrthoCamera.h"
#include "Asaurus/Renderer/Shader.h"
#include <glm/glm.hpp>

namespace Asaurus
{
	/// <summary>
	/// Renderer for 3D rendering.
	/// </summary>
	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();
		static void OnWindowResize(uint32_t width, uint32_t height);

		static void BeginScene(OrthoCamera& camera);
		static void EndScene();

		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		static inline RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		struct SceneData
		{
			glm::mat4 m_ViewProjectionMatrix;
		};

		static Scope<SceneData> s_SceneData;
	};
}

