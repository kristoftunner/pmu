#include "Log.hpp"
#include "DataBuffer.hpp"

struct chData
{
    unsigned int ch0,ch1,ch2;
};

int main()
{
    Pmu::Log::Init();

    PMU_CORE_WARN("Initialized Log");
    PMU_CORE_INFO("Hello");

    Pmu::DataBuffer<chData,100> newBuff;

    struct chData a[100];
    for(int i = 0; i < 100; i++)
    {
        a[i].ch0 = i;
        a[i].ch1 = i;
        a[i].ch2 = i;
    }

    newBuff.SetBuffer(a);

    for(int i = 0; i < 100; i++)
    {
        struct chData temp = *newBuff.GetValue(i);
        std::cout << i << ":" << temp.ch0 << ":" << temp.ch1 << ":" << temp.ch2 << "\n";
    }
}


