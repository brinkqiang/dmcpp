#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include "gtest.h"

TEST(dmptrtest, dmptrtest)
{
    std::shared_ptr<int> sp1(new int(22));
    std::shared_ptr<int> sp2 = sp1;
    std::cout << "cout: " << sp2.use_count() << std::endl; // 打印引用计数

    std::cout << *sp1 << std::endl;
    std::cout << *sp2 << std::endl;

    sp1.reset(); // 显示让引用计数减一
    std::cout << "count: " << sp2.use_count() << std::endl; // 打印引用计数

    std::cout << *sp2 << std::endl; // 22
}

