#include <Asaurus.h>
#include <Asaurus/Core/EntryPoint.h>

#include "Platform/OpenGL/OpenGLShader.h"
#include "Sandbox2D.h"

#include "imgui/imgui.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class ExampleLayer : public Asaurus::Layer
{
public:
	ExampleLayer()
		: Asaurus::Layer("Example"), m_CameraController(1280.0f / 720.0f)
	{
		// Draw Triangle
		m_VertexArray = Asaurus::VertexArray::Create();

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.5f, 0.2, 0.1f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.5f, 0.2, 1.0f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.5f, 1.0, 0.1f, 1.0f
		};

		Asaurus::Ref<Asaurus::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Asaurus::VertexBuffer::Create(vertices, sizeof(vertices)));

		Asaurus::BufferLayout layout = {
			{ Asaurus::ShaderDataType::Float3, "a_Position" },
			{ Asaurus::ShaderDataType::Float4, "a_Color" }
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indicies[3] = { 0, 1, 2 };

		Asaurus::Ref<Asaurus::IndexBuffer> indexBuffer;
		indexBuffer.reset(Asaurus::IndexBuffer::Create(indicies, sizeof(indicies) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA = Asaurus::VertexArray::Create();

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
		};

		Asaurus::Ref<Asaurus::VertexBuffer> squareVB;
		squareVB.reset(Asaurus::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Asaurus::ShaderDataType::Float3, "a_Position" },
			{ Asaurus::ShaderDataType::Float2, "a_TexCoord" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndicies[6] = { 0, 1, 2, 2, 3, 0 };

		Asaurus::Ref<Asaurus::IndexBuffer> squareIB; squareIB.reset(Asaurus::IndexBuffer::Create(squareIndicies, sizeof(squareIndicies) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}

		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}

		)";

		m_Shader = Asaurus::Shader::Create("VertexPosColorTriangle", vertexSrc, fragmentSrc);

		std::string flatColorShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}

		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0);
			}

		)";

		m_FlatColorShader = Asaurus::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_Texture = Asaurus::Texture2D::Create("assets/textures/Checkerboard.png");
		m_ChernoLogoTexture = Asaurus::Texture2D::Create("assets/textures/ChernoLogo.png");
		std::dynamic_pointer_cast<Asaurus::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<Asaurus::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", slot);
	}

	virtual void OnUpdate(Asaurus::Timestep ts) override
	{ 
		// Update
		m_CameraController.OnUpdate(ts);

		// Rendering
		Asaurus::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Asaurus::RenderCommand::Clear();

		Asaurus::Renderer::BeginScene(m_CameraController.GetCamera());

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Asaurus::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Asaurus::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;

				Asaurus::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		auto textureShader = m_ShaderLibrary.Get("Texture");

		m_Texture->Bind(slot);
		Asaurus::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		m_ChernoLogoTexture->Bind(slot);
		Asaurus::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));


		// Triangle
		//Asaurus::Renderer::Submit(m_Shader, m_VertexArray);

		Asaurus::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	virtual void OnEvent(Asaurus::Event& event) override
	{
		m_CameraController.OnEvent(event);
	}

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

class Sandbox : public Asaurus::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{}
};

Asaurus::Application* Asaurus::CreateApplication()
{
	return new Sandbox();
}