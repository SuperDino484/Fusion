#include "fnpch.h"
#include "Layer.h"


namespace Fusion
{
	Layer::Layer(const std::string& Name, bool Enabled):
		m_Name(Name), m_Enabled(Enabled)
	{
	}

	Layer::~Layer()
	{
		OnShutdown();
	}

	void Layer::OnEvent(Event& Event)
	{
	}

	void Layer::OnAwake()
	{
	}

	void Layer::OnStart()
	{
	}

	void Layer::OnUpdate(float DeltaTime)
	{
	}

	void Layer::OnEnd()
	{
	}

	void Layer::OnShutdown()
	{
	}
}
