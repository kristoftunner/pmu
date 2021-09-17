#include <iostream>
#include <fstream>
#include <vector>
#include <typeinfo>
#include "Base.hpp"

namespace Pmu
{
struct chData{
    unsigned int ch0,ch1,ch2;
};

template<typename T, size_t S>
class DataBuffer{
public:
    using ValueType = T;

public:
    DataBuffer()
    : type(typeid(ValueType))
    {
        m_Size = 0;
        m_Capacity = S;
        m_Data = new ValueType[m_Capacity];   
    }

    ~DataBuffer()
    {
        delete m_Data;
    }

    bool CopyBuffer(SPtr<DataBuffer> const& fromBuffer)
    {
        if(fromBuffer != nullptr && fromBuffer->m_hasValue &&
            m_Capacity == fromBuffer->m_Capacity)
            //fromBuffer->GetType == type)
        {
            memcpy(m_Data, fromBuffer->m_Data, sizeof(fromBuffer->m_Data[0])*fromBuffer->m_Capacity); 
            return true;
        }
        return false;
    }

    bool MoveBuffer(SPtr<DataBuffer> const& fromBuffer)
    {
        return true;
    }

    bool SetValue(ValueType const& value, size_t index)
    {
        if(index < m_Capacity)
        {
            m_Data[index] = value;
            m_hasValue = true;
            return true;
        }

        return false;
    }

    void SetBuffer(ValueType value[S])
    {
        memcpy(m_Data, value, sizeof(ValueType)*m_Capacity);
        m_hasValue = true;
    }

    ValueType* GetValue(size_t index)
    {
        if(index < m_Capacity && m_hasValue && 
            GetType() == typeid(ValueType))
        {
            return &m_Data[index];
        }
        else
            return nullptr;
    }

    size_t GetSize()
    {
        return m_Capacity;
    } 

    std::type_info const& GetType() const
    {
        if(m_Data != nullptr)
        {
            return type;
        }
        else
        {
            return typeid(void);
        }
    }   
     
private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
    bool m_hasValue = false;
    std::type_info const& type;
};
} //namespace Pmu