#include <Fusion.h>

class PrototypeLayer : public Fusion::Layer
{
public:
	PrototypeLayer():
		Layer("PrototypeLayer")
	{
	}
	~PrototypeLayer() override
	{
		
	}

	void OnEvent(Fusion::Event& Event) override
	{
		FN_INFO("{0}", Event.ToString());
	}

	void OnAwake() override { FN_INFO("OnAwake"); }
	void OnStart() override { FN_INFO("OnStart"); }
	void OnEnd() override { FN_INFO("OnEnd"); }
	void OnShutdown() override { FN_INFO("OnShutdown"); }
};

class Sandbox : public Fusion::Application
{
public:
	Sandbox()
	{
		PushLayer(new PrototypeLayer());
	}

	~Sandbox() override
	{

	}
};

Fusion::Application* Fusion::CreateApplication()
{
	return new Sandbox();
}
