#include "Log.hpp"

int main()
{
    Pmu::Log::Init();

    PMU_CORE_WARN("Initialized Log");
    PMU_CORE_INFO("Hello");
}


