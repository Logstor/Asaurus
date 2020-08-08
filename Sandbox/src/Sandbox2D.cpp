#include "Sandbox2D.h"
#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{}

void Sandbox2D::OnAttach()
{
	AS_PROFILE_FUNCTION();

	m_CheckerboardTexture = Asaurus::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach() 
{
	AS_PROFILE_FUNCTION();

}

void Sandbox2D::OnUpdate(Asaurus::Timestep timestep) 
{
	AS_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(timestep);

	// Rendering
	{
		AS_PROFILE_SCOPE("Renderer Prep");
		Asaurus::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Asaurus::RenderCommand::Clear();
	}

	{
		AS_PROFILE_SCOPE("Renderer Draw");

		Asaurus::Renderer2D::BeginScene(m_CameraController.GetCamera());

		Asaurus::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
		Asaurus::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Asaurus::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f, glm::vec4(1.0f, 0.9f, 0.9f, 1.0f));

		Asaurus::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender() 
{
	AS_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Asaurus::Event& event) 
{
	m_CameraController.OnEvent(event);
}