#include "pch.h"
#include "DataGenerator.h"
#include <random>
#include <sstream>
using namespace std;
namespace Algorithm_Benchmark_Tool::DataAnalytics
{
    wstring DataGenerator::GenerateRandomArrayString(int length)
    {
        if (length <= 0) return L"";

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, 10000);

        wstringstream wss;
        for (int i = 0; i < length; ++i)
        {
            wss << distrib(gen);
            if (i < length - 1)
            {
                wss << L", ";
            }
        }
        return wss.str();
    }
}