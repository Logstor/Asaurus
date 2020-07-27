#pragma once

#include "Asaurus.h"

class Sandbox2D : public Asaurus::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate(Asaurus::Timestep timestep) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(Asaurus::Event& event) override;

private:
	Asaurus::OrthographicCameraController m_CameraController;

	// Temporary
	Asaurus::Ref<Asaurus::VertexArray> m_SquareVA;
	Asaurus::Ref<Asaurus::Shader> m_FlatColorShader;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};