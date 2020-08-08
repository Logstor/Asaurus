#pragma once
#include "Asaurus/Renderer/OrthoCamera.h"
#include "Asaurus/Renderer/Texture.h"

namespace Asaurus
{
	class Renderer2D
	{
	public:
		static void Init();
		static void Shutdown();
		
		static void BeginScene(const OrthoCamera& camera);
		static void EndScene();
		
		// Primitives
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
		
		/// <summary>
		/// Draws a rotated evenly colored Quad on the screen. The rotation needs to be in radians, 
		/// ex. glm::radians(45.0f) will rotate the quad 45 degress.
		/// </summary>
		/// <param name="position"></param>
		/// <param name="size"></param>
		/// <param name="rotation">Radians</param>
		/// <param name="color"></param>
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, const float rotation, const glm::vec4& color);

		/// <summary>
		/// Draws a rotated evenly colored Quad on the screen. The rotation needs to be in radians, 
		/// ex. glm::radians(45.0f) will rotate the quad 45 degress.
		/// </summary>
		/// <param name="position"></param>
		/// <param name="size"></param>
		/// <param name="rotation">Radians</param>
		/// <param name="color"></param>
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, const float rotation, const glm::vec4& color);

		/// <summary>
		/// Draws a rotated texture Quad on the screen. The rotation needs to be in radians, ex. glm::radians(45.0f) will rotate the quad 
		/// 45 degress.
		/// </summary>
		/// <param name="position"></param>
		/// <param name="size"></param>
		/// <param name="rotation">Radians</param>
		/// <param name="color"></param>
		/// <param name="tintColor"></param>
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, const float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));

		/// <summary>
		/// Draws a rotated texture Quad on the screen. The rotation needs to be in radians, ex. glm::radians(45.0f) will rotate the quad 
		/// 45 degress.
		/// </summary>
		/// <param name="position"></param>
		/// <param name="size"></param>
		/// <param name="rotation">Radians</param>
		/// <param name="color"></param>
		/// <param name="tintColor"></param>
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, const float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
	};
}