#include "gtest.h"
#include <chrono>
#include <map>
#include <stdint.h>

TEST(dmchronotest, dmchronotest)
{
    std::map<uint64_t, uint64_t> mapChrono;
    for (size_t i = 0; i < 100000; i++)
    {
        auto tp = std::chrono::high_resolution_clock::now();
        auto nano = tp.time_since_epoch().count();

        mapChrono[nano]++;

        ASSERT_TRUE(mapChrono[nano] == 1);
    }
}

TEST(dmchronotest2, dmchronotest2)
{
    double total = 0;

    for (int i=1; i <= 6; i++)
    {
        total += ((i*2-1) / exp2(i-1));
    }
    std::cout << total << std::endl;
}