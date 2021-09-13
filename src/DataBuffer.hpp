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

        bool CopyBuffer();
        bool GetData();
        void SetValue();
        std::vector<int> CopyData();

        std::type_info const& GetType() const;        

    private:
        int* m_Data = nullptr;
        size_t m_Size = 0;
        size_t m_Capacity = 0;
    };
}