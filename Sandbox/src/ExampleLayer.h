#pragma once

#include "Asaurus.h"

class ExampleLayer : public Asaurus::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Asaurus::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Asaurus::Event & e) override;

private:
	Asaurus::ShaderLibrary m_ShaderLibrary;
	Asaurus::Ref<Asaurus::Shader> m_Shader;
	Asaurus::Ref<Asaurus::VertexArray> m_VertexArray;

	Asaurus::Ref<Asaurus::Shader> m_FlatColorShader;
	Asaurus::Ref<Asaurus::VertexArray> m_SquareVA;

	Asaurus::Ref<Asaurus::Texture2D> m_Texture, m_ChernoLogoTexture;
	uint32_t slot = 0;

	Asaurus::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};