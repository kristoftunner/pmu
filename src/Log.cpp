#include "Base.hpp"
#include "Log.hpp"

#include <memory> 
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "spdlog/sinks/rotating_file_sink.h"
namespace Pmu
{
    SPtr<spdlog::logger> Log::s_CoreLogger;

    void Log::Init()
    {
        std::vector<spdlog::sink_ptr> logSinks;

        logSinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        logSinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Pmu.log",true));

        logSinks[0]->set_pattern("%^[%T] %n: %v%$");
		logSinks[1]->set_pattern("[%T] [%l] %n: %v");

        s_CoreLogger = std::make_shared<spdlog::logger>("Pmu",begin(logSinks),end(logSinks));

        spdlog::register_logger(s_CoreLogger);
        s_CoreLogger->set_level(spdlog::level::trace);
        s_CoreLogger->flush_on(spdlog::level::trace);

    }
}