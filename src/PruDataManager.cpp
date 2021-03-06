#include "Base.hpp"
#include "PruDataManager.hpp"
#include "Log.hpp"
#include <vector>
#include <mutex>
#include <thread>
#include <condition_variable>

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

    bool PruDataManager::CreateOutputStreams(int numOfBuffers)
    {
        SPtr<DataBuffer<chData,4000>> bufferData = std::make_shared<DataBuffer<chData,4000>>();
        outputStreams.push_back(bufferData);
        return true;
    }

    void PruDataManager::ReadFile()
    {
        
    }
    
    void PruDataManager::Run()
    {
        _thread = std::thread( &PruDataManager::Tick, this );
    }

    void PruDataManager::Stop()
    {
        if(_thread.joinable())
            _thread.join();
    }
    void PruDataManager::Tick()
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
        PMU_CORE_INFO("Ticking");
        while(true)
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(1s);
            std::unique_lock<std::mutex> lock(_dataBuffMutex);
            
            struct chData data[4000];
            for(int i = 0; i < 4000; i++)
            {
                data[i].ch0 = i;
                data[i].ch1 = i;
                data[i].ch2 = i;
            }
            PMU_CORE_INFO("Setting buffer");
            outputStreams[0]->SetBuffer(data);
            _dataReady.notify_all();
        }
    }

} // namespace Pru
