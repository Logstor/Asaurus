#include "Sandbox2D.h"
#include "imgui/imgui.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{}

void Sandbox2D::OnAttach()
{
	m_SquareVA = Asaurus::VertexArray::Create();

	float squareVertices[5 * 4] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	Asaurus::Ref<Asaurus::VertexBuffer> squareVB;
	squareVB.reset(Asaurus::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
	squareVB->SetLayout({
		{ Asaurus::ShaderDataType::Float3, "a_Position" }
						});
	m_SquareVA->AddVertexBuffer(squareVB);

	uint32_t squareIndicies[6] = { 0, 1, 2, 2, 3, 0 };

	Asaurus::Ref<Asaurus::IndexBuffer> squareIB; squareIB.reset(Asaurus::IndexBuffer::Create(squareIndicies, sizeof(squareIndicies) / sizeof(uint32_t)));
	m_SquareVA->SetIndexBuffer(squareIB);

	m_FlatColorShader = Asaurus::Shader::Create("assets/shaders/FlatColor.glsl");
}

void Sandbox2D::OnDetach() 
{}

void Sandbox2D::OnUpdate(Asaurus::Timestep timestep) 
{
	// Update
	m_CameraController.OnUpdate(timestep);

	// Rendering
	Asaurus::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Asaurus::RenderCommand::Clear();

	Asaurus::Renderer::BeginScene(m_CameraController.GetCamera());

	std::dynamic_pointer_cast<Asaurus::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<Asaurus::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

	Asaurus::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

	Asaurus::Renderer::EndScene();
}
void Sandbox2D::OnImGuiRender() 
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}
void Sandbox2D::OnEvent(Asaurus::Event& event) 
{
	m_CameraController.OnEvent(event);
}