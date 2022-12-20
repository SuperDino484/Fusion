#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Fusion {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

// Core logging macros
#define FN_CORE_TRACE(...)		::Fusion::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FN_CORE_INFO(...)		::Fusion::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FN_CORE_WARN(...)		::Fusion::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FN_CORE_ERROR(...)		::Fusion::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FN_CORE_CRITICAL(...)	::Fusion::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client logging macros
#define FN_TRACE(...)			::Fusion::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FN_INFO(...)			::Fusion::Log::GetClientLogger()->info(__VA_ARGS__)
#define FN_WARN(...)			::Fusion::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FN_ERROR(...)			::Fusion::Log::GetClientLogger()->error(__VA_ARGS__)
#define FN_CRITICAL(...)		::Fusion::Log::GetClientLogger()->critical(__VA_ARGS__)
