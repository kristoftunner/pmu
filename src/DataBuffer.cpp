#include <vector>
#include <iostream>
#include <memory>

#include "Base.hpp"
#include "DataBuffer.hpp"

namespace Pmu
{

DataBuffer::DataBuffer()
{
    m_Size = 0;
    m_Capacity = S;
    m_Data = new ValueType[m_Capacity];
    type = typeid(ValueType);
}

DataBuffer::~DataBuffer()
{
    delete m_Data;
}

bool DataBuffer::MoveBuffer(SPtr<DataBuffer> const& fromBuffer)
{
    return true;   
}

bool DataBuffer::CopyBuffer(SPtr<DataBuffer> const& fromBuffer)
{
    if(fromBuffer != nullptr && fromBuffer->m_hasValue &&
       m_Capacity == fromBuffer->m_Capacity)
    {
        memcpy(m_Data, fromBuffer->m_Data, sizeof(fromBuffer->getType())*fromBuffer->m_Capacity); 
        return true;
    }
    return false;
}

std::type_info const& DataBuffer::GetType() const
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
} //namespace Pmu