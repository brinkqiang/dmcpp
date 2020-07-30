// next_permutation example

#include <algorithm>    // std::next_permutation, std::sort
#include <vector>
#include <iostream>
#include "dmformat.h"
#include "dmstrtk.hpp"

typedef std::vector<int> VecData;

int main ()
{
    VecData vec{1, 2,3};

    do
    {
        fmt::print("{}\n", strtk::join(",", vec));
    }
    while (std::next_permutation(vec.begin(), vec.end()));

    fmt::print("{}\n", strtk::join(",", vec));
    return 0;
}