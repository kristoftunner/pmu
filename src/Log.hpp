#pragma once
#include "Base.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

/*namespace Pmu
{*/
    class Log
    {
    private:
        static Ref<spdlog::logger> s_CoreLogger;
    public:
        static void Init();
        
        static Ref<spdlog::logger>& GetCoreLogger(){return s_CoreLogger;}
        
    };
//}


//Log macros
#define PMU_CORE_TRACE(...)     ::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PMU_CORE_INFO(...)      ::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PMU_CORE_WARN(...)      ::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PMU_CORE_ERROR(...)     ::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PMU_CORE_CRITICAL(...)  ::Log::GetCoreLogger()->critical(__VA_ARGS__)