#pragma once

#include "Window.h"
#include "LayerHandler.h"

namespace Fusion {
	class WindowCloseEvent;

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& Event);

		void PushLayer(Layer* Layer) const;
		void PushOverlay(Layer* Overlay) const;
		void PopLayer(Layer* Layer) const;
		void PopOverlay(Layer* Overlay) const;

	private:
		bool OnWindowCloseEvent(WindowCloseEvent& Event);

	private:
		std::unique_ptr<Window> m_Window;
		std::unique_ptr<LayerHandler> m_LayerHandler;
		bool m_Running;
	};

	Application* CreateApplication();

}

