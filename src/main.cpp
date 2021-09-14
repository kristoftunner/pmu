#include "Log.hpp"
#include "DataBuffer.hpp"
#include "Base.hpp"

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
    Pmu::SPtr<Pmu::DataBuffer<chData,100>> newBuff2;
    struct chData a[100];
    for(int i = 0; i < 100; i++)
    {
        a[i].ch0 = i;
        a[i].ch1 = i;
        a[i].ch2 = i;
    }
    
    struct chData b[100];
    for(int i = 0; i < 100; i++)
    {
        b[i].ch0 = i*2;
        b[i].ch1 = i*2;
        b[i].ch2 = i*2;
    }

    newBuff.SetBuffer(a);
    newBuff2->SetBuffer(b);
    for(int i = 0; i < 100; i++)
    {
        struct chData temp = *newBuff.GetValue(i);
        std::cout << i << ":" << temp.ch0 << ":" << temp.ch1 << ":" << temp.ch2 << "\n";
    }

    newBuff.CopyBuffer(newBuff2);
    for(int i = 0; i < 100; i++)
    {
        struct chData temp = *newBuff.GetValue(i);
        std::cout << i << ":" << temp.ch0 << ":" << temp.ch1 << ":" << temp.ch2 << "\n";
    }


}


