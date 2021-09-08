#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#define CHANNELS 3 
#define DEAFULT_NR_ROWS 1024

namespace Pmu
{
    struct chData
    {
        unsigned int ch0,ch1,ch2;
    };

    std::ostream& operator<<(std::ostream& stream, const chData& data)
    {
        stream << data.ch0 << "," << data.ch1 << "," << data.ch2 << std::endl;
        return stream;
    }

    class dataBuffer
    {
        public:
            unsigned int rows = 0;
            unsigned int cols = 3;
            std::vector<chData> data;
            
            dataBuffer(std::string fName);
            void readData(std::string fName);
    };

    dataBuffer::dataBuffer(std::string fName)
    {
        std::ifstream input(fName, std::ios::binary);
        input.seekg(0,input.end);
        int length = input.tellg();
        input.seekg(0,input.beg);
        rows = length/(4*cols);
        std::cout << "There is " << rows << " rows of data" << std::endl;
        input.close();   
    }

    void dataBuffer::readData(std::string fName)
    {
        std::ifstream input( fName, std::ios::binary );
        input.seekg(0, input.end);
        int length = input.tellg();
        input.seekg(0,input.beg);
        std::cout << length << std::endl;
        data.reserve(32);
        input.read((char *)&data[0],length);
        for(auto i = 0; i < rows; i++)
        {
            std::cout << "row:" << i  << " " << data[i] << std::endl; 
        }    
        input.close();
    }
}