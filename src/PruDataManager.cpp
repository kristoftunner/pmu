#include "Base.hpp"
#include "PruDataManager.hpp"

#include <vector>


namespace Pmu
{
    PruDataManager::PruDataManager()
    {
        inputStreamCount = 0;
        outputStreamCount = 0;
    }

    PruDataManager::~PruDataManager()
    {

    }

    void PruDataManager::SetOutputStreamCount(int count)
    {
        outputStreamCount = count;
    }

    int PruDataManager::GetInputStreamCount()
    {
        return inputStreamCount;
    }

    int PruDataManager::GetOutputStreamCount()
    {
        return outputStreamCount;
    }

    bool PruDataManager::AddInputStream(SPtr<DataBuffer<chData,4000>> fromBuffer)
    {
        inputStreams.push_back(fromBuffer);    
        inputStreamCount++;    
        return true;
    }

    bool PruDataManager::CreateOutputStreams(int numOfBuffers,size_t bufferSize)
    {
        SPtr<DataBuffer<chData,bufferSize>> bufferData = std::make_shared<DataBuffer<chData,bufferSize>>();
        outputStreams.push_back(bufferData);
        return true;
    }

    void PruDataManager::ReadFile()
    {
        
    }

    bool Tick()
    {
        // read data to buffer
        /*std::ifstream input(inputFileName, std::ios::binary);
        input.seekg(0,input.end);
        int length = input.tellg();
        input.seekg(0, input.beg);

        size_t bufferSize = outputStreams[0]->GetSize();
        struct chData data[bufferSize];
        input.read((char *)&data[0], length);
        input.close();*/

        struct chData data[4000];
        for(int i = 0; i < 4000; i++)
        {
            data[i].ch0 = i;
            data[i].ch1 = i;
            data[i].ch2 = i;
        }
        outputStreams[0]->SetBuffer(data);

        return true;
    }
} // namespace Pru
