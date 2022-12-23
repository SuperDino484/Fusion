#include "fnpch.h"
#include "LayerHandler.h"


namespace Fusion
{
	LayerHandler::LayerHandler() :
		m_LayerInsertIndex(0) {}

	LayerHandler::~LayerHandler()
	{
		Shutdown();
	}

	void LayerHandler::PushLayer(Layer* Layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, Layer);
		m_LayerInsertIndex++;
	}

	void LayerHandler::PushOverlay(Layer* Overlay)
	{
		m_Layers.emplace_back(Overlay);
	}

	void LayerHandler::PopLayer(Layer* Layer)
	{
		auto iter = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, Layer);
		if(iter != m_Layers.begin() + m_LayerInsertIndex)
		{
			delete Layer;
			m_Layers.erase(iter);
		}
	}

	void LayerHandler::PopOverlay(Layer* Overlay)
	{
		auto iter = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), Overlay);
		if (iter != m_Layers.end())
		{
			delete Overlay;
			m_Layers.erase(iter);
		}
	}

	void LayerHandler::Shutdown()
	{
		for(const auto Layer : m_Layers)
		{
			delete Layer;
		}
		m_Layers.clear();
	}
}
