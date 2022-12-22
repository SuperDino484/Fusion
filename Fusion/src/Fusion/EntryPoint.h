#pragma once

#ifdef FN_PLATFORM_WINDOWS

extern Fusion::Application* Fusion::CreateApplication();

int main(int argc, char** argv)
{
	Fusion::Log::Init();
	FN_CORE_INFO("Launching application");
	const auto app = Fusion::CreateApplication();
	app->Run();
	FN_CORE_INFO("Closing application");
	delete app;
}

#endif