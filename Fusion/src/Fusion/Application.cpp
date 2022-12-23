#include "fnpch.h"
#include "Application.h"

#include <ranges>

#include "GLFW/glfw3.h"
#include "Core.h"
#include "Log.h"
#include "Events/ApplicationEvent.h"

namespace Fusion
{

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create(WindowData("Fusion Editor")));
		m_Window->SetEventCallbackFunction(BIND_EVENT_FN(Application::OnEvent));

		m_LayerHandler = std::make_unique<LayerHandler>();

		m_Running = true;
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		// Needs to be at the very top
		for (auto& it : *m_LayerHandler)
			it->OnAwake();


		// Can be somewhere in the middle, but OnAwake must be called first
		for (auto& it : *m_LayerHandler)
			it->OnStart();

		while(m_Running)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.3f, 0.5f, 0.8f, 1.0f);

			for (auto& it : *m_LayerHandler)
			{
				// TODO: Pass in actual DeltaTime instead of 0.0f
				it->OnUpdate(0.0f);
			}

			m_Window->OnUpdate();
		}
		// Needs to be at the end of this while loop
		for (auto& it : *m_LayerHandler)
			it->OnEnd();


		// Needs to be at the very bottom
		for (auto& it : *m_LayerHandler)
			it->OnShutdown();
	}

	void Application::OnEvent(Event& Event)
	{
		for (auto& it : std::ranges::reverse_view(*m_LayerHandler))
		{
			if (Event.IsHandled())
				break;
			it->OnEvent(Event);
		}

		EventDispatcher Dispatcher(Event);
		Dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowCloseEvent));
	}

	void Application::PushLayer(Layer* Layer) const
	{
		m_LayerHandler->PushLayer(Layer);
	}

	void Application::PushOverlay(Layer* Overlay) const
	{
		m_LayerHandler->PushOverlay(Overlay);
	}

	void Application::PopLayer(Layer* Layer) const
	{
		m_LayerHandler->PopLayer(Layer);
	}

	void Application::PopOverlay(Layer* Overlay) const
	{
		m_LayerHandler->PopOverlay(Overlay);
	}

	bool Application::OnWindowCloseEvent(WindowCloseEvent& Event)
	{
		m_Running = false;
		return true;
	}
}
