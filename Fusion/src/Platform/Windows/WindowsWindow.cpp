#include "fnpch.h"
#include "WindowsWindow.h"

#include "Fusion/Log.h"
#include "Fusion/Core.h"
#include "Fusion/Events/ApplicationEvent.h"

namespace Fusion
{

	Window* Window::Create(const WindowData& Data)
	{
		return new WindowsWindow(Data);
	}

	WindowsWindow::WindowsWindow(const WindowData& Data)
	{
		Init(Data);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVsync(const bool Enabled)
	{
		glfwSwapInterval(Enabled ? 1 : 0);
		m_WindowData.Vsync = Enabled;
	}

	bool WindowsWindow::IsVsync() const
	{
		return m_WindowData.Vsync;
	}

	void WindowsWindow::Init(const WindowData& Data)
	{
		m_WindowData.Title = Data.Title;
		m_WindowData.Width = Data.Width;
		m_WindowData.Height = Data.Height;

		if(!s_GLFWInitialized)
		{
			int success = glfwInit();
			FN_CORE_ASSERT(success, "Could not initialize glfw. Code {0}", success);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(Data.Width, Data.Height, Data.Title.c_str(), NULL, NULL);
		FN_CORE_ASSERT(m_Window, "Could not initialize window");

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_WindowData);
		SetVsync(true);

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* Window, int Width, int Height)
		{
			const WindowsWindowData& UserData = *static_cast<WindowsWindowData*>(glfwGetWindowUserPointer(Window));
			WindowResizeEvent Event(Width, Height);
			UserData.EventCallback(Event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* Window)
		{
			const WindowsWindowData& UserData = *static_cast<WindowsWindowData*>(glfwGetWindowUserPointer(Window));
			WindowCloseEvent Event;
			UserData.EventCallback(Event);
		});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}
}
