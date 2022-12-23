#pragma once

#include "fnpch.h"
#include "Layer.h"

namespace Fusion
{

	class LayerHandler
	{
	public:
		LayerHandler();
		~LayerHandler();

		void PushLayer(Layer* Layer);
		void PushOverlay(Layer* Overlay);

		void PopLayer(Layer* Layer);
		void PopOverlay(Layer* Overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

		std::vector<Layer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
		std::vector<Layer*>::reverse_iterator rend() { return m_Layers.rend(); }
	private:
		void Shutdown();

	private:
		std::vector<Layer*> m_Layers;
		uint16_t m_LayerInsertIndex;
	};

}

