#include <map>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include <unordered_map>
#include "gtest.h"

TEST(dmmaptest, dmmaptest)
{
    std::map<int, int> mapData{ {1, 2},  {3, 4},  {5, 6} };

    auto it = mapData.find(1);

    for (int i = 10; i < 100000; i++)
    {
        mapData.insert(std::make_pair(i, i));
    }

    std::cout << it->second << std::endl;
}

TEST(dmunordered_maptest, dmunordered_maptest)
{
    std::unordered_map<int, int> mapData{ {1, 2},  {3, 4},  {5, 6} };

    auto it = mapData.find(1);

    for (int i = 10; i < 100000; i++)
    {
        mapData.insert(std::make_pair(i, i));
    }

    std::cout << it->second << std::endl;
}