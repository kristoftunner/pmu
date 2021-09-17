#include <gtest/gtest.h>
#include "DataBuffer.hpp"
#include "Base.hpp"
/*
*   Test cases
*       - Test copy
*       - Test move
*       - Test set value
*       - Test overwriting the buffer
*       - Test overindexing the buffer
*       - Copy 
*       
*/

struct chData
{
    unsigned int ch0,ch1,ch2;
};

TEST(DataBuffer, TestSetGetValue)
{
    Pmu::DataBuffer<chData,100> testBuff1;

    struct chData testData1[100];

    for(int i = 0; i < 100; i++)
    {
        testData1[i].ch0 = i;
        testData1[i].ch1 = i;
        testData1[i].ch2 = i;
    }  
    
    for(int i = 0; i < 100; i++)
    {
        testBuff1.SetValue(testData1[i],i);
    }

    for(int i = 0; i < 100; i++)
    {
        EXPECT_EQ(testBuff1.GetValue(i)->ch0,testData1[i].ch0);
        EXPECT_EQ(testBuff1.GetValue(i)->ch1,testData1[i].ch1);
        EXPECT_EQ(testBuff1.GetValue(i)->ch2,testData1[i].ch2);
    }
}

TEST(DataBuffer, TestSetCopyMoveBuffer)
{
    Pmu::DataBuffer<chData,100> testBuff1;

    struct chData testData1[100];

    for(int i = 0; i < 100; i++)
    {
        testData1[i].ch0 = i;
        testData1[i].ch1 = i;
        testData1[i].ch2 = i;
    }  

    //Testing SetBuffer
    testBuff1.SetBuffer(testData1);

    for(int i = 0; i < testBuff1.GetSize(); i++)
    {
        EXPECT_EQ(testBuff1.GetValue(i)->ch0,testData1[i].ch0);
        EXPECT_EQ(testBuff1.GetValue(i)->ch1,testData1[i].ch1);
        EXPECT_EQ(testBuff1.GetValue(i)->ch2,testData1[i].ch2);
    }

    //Test overindexing and overwriting the buffer

    EXPECT_TRUE(testBuff1.GetValue(50));
    EXPECT_FALSE(testBuff1.GetValue(150));

    struct chData testData3 = {1,2,3};
    EXPECT_TRUE(testBuff1.SetValue(testData3,50));
    EXPECT_FALSE(testBuff1.SetValue(testData3,150));

    //Testing copy buffer
    Pmu::SPtr<Pmu::DataBuffer<chData,100>> testBuff2 = std::make_shared<Pmu::DataBuffer<chData,100>>();
    
    struct chData testData2[100];
    for(int i = 0; i < 100; i++)
    {
        testData2[i].ch0 = 2*i;
        testData2[i].ch1 = 2*i;
        testData2[i].ch2 = 2*i;
    }
    
    testBuff2->SetBuffer(testData2);
    ASSERT_TRUE(testBuff1.CopyBuffer(testBuff2));
    for(int i = 0; i < testBuff1.GetSize(); i++)
    {
        EXPECT_EQ(testBuff1.GetValue(i)->ch0,testData2[i].ch0);
        EXPECT_EQ(testBuff1.GetValue(i)->ch1,testData2[i].ch1);
        EXPECT_EQ(testBuff1.GetValue(i)->ch2,testData2[i].ch2);
    }
}