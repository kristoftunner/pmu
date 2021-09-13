#include <vector>
#include <iostream>

#include "Base.hpp"
#include "DataBuffer.hpp"

namespace Pmu
{

DataBuffer::DataBuffer()
{
    m_Size = 0;
    m_Capacity = S;
    m_Data = new T[m_Capacity];
}

DataBuffer::~DataBuffer()
{
    delete m_Data;
}

DataBuffer::SetValue()
{

}

DataBuffer::MoveBuffer()
{

}

DataBuffer::CopyData()
{

}
} //namespace Pmu