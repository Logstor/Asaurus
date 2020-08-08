#pragma once

/*
 * For use in client application
 */
#include "Asaurus/Core/Core.h"
#include "Asaurus/Core/Application.h"
#include "Asaurus/Core/Log.h"
#include "Asaurus/Core/Timestep.h"

// ------------ Layering ---------------
#include "Asaurus/Core/Layer/Layer.h"
#include "Asaurus/ImGui/ImGuiLayer.h"

// ------------ IO ---------------------
#include "Asaurus/Core/Input.h"
#include "Asaurus/Core/KeyCodes.h"
#include "Asaurus/Core/MouseCodes.h"
#include "Asaurus/Renderer/OrthographicCameraController.h"

// ------------ Graphics ---------------
#include "Asaurus/Renderer/Renderer.h"
#include "Asaurus/Renderer/Renderer2D.h"
#include "Asaurus/Renderer/RenderCommand.h"

#include "Asaurus/Renderer/Buffer.h"
#include "Asaurus/Renderer/VertexArray.h"
#include "Asaurus/Renderer/Shader.h"
#include "Asaurus/Renderer/Texture.h"
