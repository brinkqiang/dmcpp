#include <map>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>

int main()
{
    {
        std::map<int, int> mapData{ {1, 2},  {3, 4},  {5, 6} };

        auto it = mapData.find(1);

        for (int i = 10; i < 100000; i++)
        {
            mapData.insert(std::make_pair(i, i));
        }

        std::cout << it->second << std::endl;
    }
    {
        std::unordered_map<int, int> mapData{ {1, 2},  {3, 4},  {5, 6} };

        auto it = mapData.find(1);

        for (int i = 10; i < 100000; i++)
        {
            mapData.insert(std::make_pair(i, i));
        }

        std::cout << it->second << std::endl;
    }

    return 0;
}