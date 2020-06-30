#pragma once

#include <glm/glm.hpp>

namespace Asaurus
{
	class OrthoCamera
	{
	public:
		OrthoCamera(float left, float right, float bottom, float top);
		~OrthoCamera();
		
		void SetProjection(float left, float right, float bottom, float top);

		void SetPosition(const glm::vec3& position) { m_Position = position; RecalculateViewMatrix(); }
		void SetRotation(float rotation) { m_Rotation = rotation; RecalculateViewMatrix(); }

		const glm::vec3& GetPosition() const { return m_Position; }
		const float GetRotation() const { return m_Rotation; }


		const glm::mat4& GetProjectionMatrix() const { return m_Projection; }
		const glm::mat4& GetViewMatrix() const { return m_View; }
		const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjection; }
	private:
		void RecalculateViewMatrix();

	private:
		glm::mat4 m_Projection;
		glm::mat4 m_View;
		glm::mat4 m_ViewProjection;

		glm::vec3 m_Position = {0.0f, 0.0f, 0.0f};
		float m_Rotation = 0.0f;
	};
}