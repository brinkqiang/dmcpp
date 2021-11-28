#include <map>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include <unordered_map>
#include "gtest.h"
#include "dmcast.h"

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

TEST(dmmultimaptest, dmmultimaptest)
{
    std::multimap<int, int> mapData{ {1, 2}, {1, 3}, {3, 4},  {5, 6} };

    auto it = mapData.equal_range(1);

    if (it.first != mapData.end())
    {
        for (auto it2 = it.first; it2 != it.second; ++it2 )
        {
            std::cout << it2->first << " is " << it2->second << std::endl;
        }
    }

    for (int i = 10; i < 100000; i++)
    {
        mapData.insert(std::make_pair(i, i));
    }
}