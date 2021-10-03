#include "Base.hpp"
#include "PruDataManager.hpp"

int main()
{
    Pmu::PruDataManager mg;

    
    mg.CreateOutputStreams(1);

    mg.Run();
}