#include "Base.hpp"
#include "PruDataManager.hpp"

int main()
{
    Pmu::PruDataManager signalGen;
    
    Pmu::Log::Init();
    
    signalGen.CreateOutputStreams(1);

    signalGen.Run();
    signalGen.Stop();
}