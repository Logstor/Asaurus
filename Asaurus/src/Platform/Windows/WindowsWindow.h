#pragma once

#include "Asaurus/Core/Window.h"
#include "Asaurus/Renderer/GraphicsContext.h"

#include "GLFW/glfw3.h"

namespace Asaurus
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		/*! @brief Returns the native window as a void* to be platform
		 *	independent.
		 *	
		 *	@return void* to the native window.
		 */
		inline virtual void* GetNativeWindow() const override { return m_Window; };

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		// Helper
		inline void InitializeGLFWCallbacks();

	private:
		Scope<GraphicsContext> m_Context;
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}
