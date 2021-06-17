
#include <iostream>
#include <tuple>
#include <string>
#include "dmcast.h"
#include "dmformat.h"
#include "gtest.h"

TEST(dmtupletest, dmtupletest)
{
    auto t = std::make_tuple(1, 2, "abc", "def", 4.0f);
    fmt::print(dmcast::lexical_cast(t));

    int a[5] = {1,2,3,4,5};
    fmt::print(dmcast::lexical_cast(a));
}