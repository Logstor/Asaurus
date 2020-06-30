#pragma once

/*
 * For use in client application
 */
#include "Asaurus/Application.h"
#include "Asaurus/Log.h"
#include "Asaurus/Core/Timestep.h"

// ------------ Layering ---------------
#include "Asaurus/Layer/Layer.h"
#include "Asaurus/ImGui/ImGuiLayer.h"

// ------------ IO ---------------------
#include "Asaurus/Input.h"
#include "Asaurus/KeyCodes.h"
#include "Asaurus/MouseButtonCodes.h"
#include "Asaurus/OrthographicCameraController.h"

// ------------ Graphics ---------------
#include "Asaurus/Renderer/Renderer.h"
#include "Asaurus/Renderer/RenderCommand.h"

#include "Asaurus/Renderer/Buffer.h"
#include "Asaurus/Renderer/VertexArray.h"
#include "Asaurus/Renderer/Shader.h"
#include "Asaurus/Renderer/Texture.h"

// ------------ Entry Point ------------
#include "Asaurus/EntryPoint.h"