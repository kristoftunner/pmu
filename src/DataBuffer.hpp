#include <iostream>
#include <fstream>
#include <vector>

namespace Pmu
{
    struct chData{
        unsigned int ch0,ch1,ch2;
    };

template<size_t S>
    class DataBuffer{
    public:
        DataBuffer();
        ~DataBuffer();

        void ReadBuffer();
        void GetData();
        
        std::vector<int> CopyData();
        

    private:
        std::string m_fName = "";
        int* m_Data = nullptr;
        size_t m_Size = 0;
        size_t m_Capacity = 0;
        std::mutex m_DataMutex;
    };
}