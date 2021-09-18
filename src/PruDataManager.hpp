#include <vector>
#include <string>

#include "Base.hpp"
#include "DataBuffer.hpp"

namespace Pmu
{
class PruDataManager
{
private:
    struct chData{
        unsigned int ch0,ch1,ch2;
    };

public:
    PruDataManager();
    ~PruDataManager();

    bool AddInputStream(SPtr<DataBuffer<chData,4000>> fromBuffer);
    bool CreateOutputStreams(int numOfBuffers);
    void SetOutputStreamCount(int count);
    int GetInputStreamCount();
    int GetOutputStreamCount();
    void Tick();
    void ReadFile();

private:

    std::vector<SPtr<Pmu::DataBuffer<chData,4000>>> inputStreams;
    std::vector<SPtr<Pmu::DataBuffer<chData,4000>>> outputStreams;

    std::string inputFileName;
    int inputStreamCount;
    int outputStreamCount;
};
}// namespace Pmu