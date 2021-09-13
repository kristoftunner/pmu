#include <iostream>
#include <fstream>
#include <vector>

#include "Base.hpp"

namespace Pmu
{
    struct chData{
        unsigned int ch0,ch1,ch2;
    };

template<typename T, size_t S>
    class DataBuffer{
    public:
        DataBuffer();
        ~DataBuffer();

        bool CopyBuffer();
        bool MoveBuffer();
        void SetValue();
        T* GetValue(); 

        std::type_info const& GetType() const;        

    private:
        int* m_Data = nullptr;
        size_t m_Size = 0;
        size_t m_Capacity = 0;
        bool m_hasValue = false;
    };
}