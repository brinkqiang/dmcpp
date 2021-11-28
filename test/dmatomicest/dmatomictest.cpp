#include <atomic>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include "gtest.h"

TEST(dmatomictest, dmatomictest)
{
    std::atomic_bool ret = true;
    bool bConnected = true;
    if (!ret.compare_exchange_strong(bConnected, false))
    {
        std::cout << ret;
    }

    if (!ret.compare_exchange_strong(bConnected, false))
    {
        std::cout << ret;
    }
}
