#pragma once

#include "fnpch.h"
#include "Fusion/Window.h"

#include "GLFW/glfw3.h"

namespace Fusion
{

	class WindowsWindow : public Window
	{
		struct WindowsWindowData
		{
			std::string Title;
			uint16_t Width;
			uint16_t Height;
			bool Vsync;

			EventCallbackFn EventCallback;
		};
	public:
		inline static bool s_GLFWInitialized = false;

		explicit WindowsWindow(const WindowData& Data);
		~WindowsWindow() override;
		void OnUpdate() override;

		[[nodiscard]] uint16_t GetWidth() const override { return m_WindowData.Width; }
		[[nodiscard]] uint16_t GetHeight() const override { return m_WindowData.Height; }

		void SetEventCallbackFunction(const EventCallbackFn& Callback) override { m_WindowData.EventCallback = Callback; }

		void SetVsync(const bool Enabled) override;
		[[nodiscard]] bool IsVsync() const override;

	private:
		virtual void Init(const WindowData& Data);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		WindowsWindowData m_WindowData;
	};

}

