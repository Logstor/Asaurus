#pragma once

#include "Asaurus/Renderer/OrthoCamera.h"
#include "Asaurus/Core/Timestep.h"

#include "Asaurus/Events/ApplicationEvent.h"
#include "Asaurus/Events/MouseEvent.h"

namespace Asaurus
{
	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectRatio, bool rotation = false);

		void OnUpdate(Timestep ts);
		void OnEvent(Event& e);

		OrthoCamera& GetCamera() { return m_Camera; }
		const OrthoCamera& GetCamera() const { return m_Camera; }

	private:
		bool OnMouseScolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);

	private:
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		OrthoCamera m_Camera;

		bool m_Rotation;
		float m_CameraRotation = 0.0f;
		float m_CameraTranslationSpeed = 5.0f, m_CameraRotationSpeed = 180.0f;
		glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
	};

}

