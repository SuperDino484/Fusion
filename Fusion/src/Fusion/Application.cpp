#include "fnpch.h"
#include "Application.h"

#include "GLFW/glfw3.h"

namespace Fusion
{

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create(WindowData("Fusion Editor")));
		m_Running = true;
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while(m_Running)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.3f, 0.5f, 0.8f, 1.0f);
			m_Window->OnUpdate();
		}
	}

}