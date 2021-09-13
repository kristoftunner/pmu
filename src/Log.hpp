#pragma once
#include "Base.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Pmu
{
    class Log
    {
    private:
        static SPtr<spdlog::logger> s_CoreLogger;
    public:
        static void Init();
        
        static SPtr<spdlog::logger>& GetCoreLogger(){return s_CoreLogger;}
        
    };
}


//Log macros
#define PMU_CORE_TRACE(...)     ::Pmu::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PMU_CORE_INFO(...)      ::Pmu::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PMU_CORE_WARN(...)      ::Pmu::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PMU_CORE_ERROR(...)     ::Pmu::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PMU_CORE_CRITICAL(...)  ::Pmu::Log::GetCoreLogger()->critical(__VA_ARGS__)