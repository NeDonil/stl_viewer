#pragma once

#include <Core\Core.h>

#include <spdlog\spdlog.h>
#include <spdlog\fmt\ostr.h>

namespace Viewer
{
	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static Ref<spdlog::logger> s_Logger;
	};

}

#define CORE_WARNING(...) Log::GetLogger()->warn(__VA_ARGS__)
#define CORE_CRITICAL(...) Log::GetLogger()->critical(__VA_ARGS__)
#define CORE_INFO(...) Log::GetLogger()->info(__VA_ARGS__)
#define CORE_TRACE(...) Log::GetLogger()->trace(__VA_ARGS__)
#define CORE_ERROR(...) Log::GetLogger()->error(__VA_ARGS__)