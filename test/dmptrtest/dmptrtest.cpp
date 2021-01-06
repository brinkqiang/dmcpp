#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include "gtest.h"

TEST(dmptrtest_shared_ptr, dmptrtest_shared_ptr)
{
    std::shared_ptr<int> sp1(new int(22));
    std::shared_ptr<int> sp2 = sp1;
    std::cout << "cout: " << sp2.use_count() << std::endl; // 打印引用计数

    std::cout << *sp1 << std::endl;
    std::cout << *sp2 << std::endl;

    sp1.reset();                                            // 显示让引用计数减一
    std::cout << "count: " << sp2.use_count() << std::endl; // 打印引用计数

    std::cout << *sp2 << std::endl; // 22
}

TEST(dmptrtest_unique_ptr, dmptrtest_unique_ptr)
{
    std::unique_ptr<int> up1(new int(11)); // 无法复制的unique_ptr
    //unique_ptr<int> up2 = up1;        // err, 不能通过编译
    std::cout << *up1 << std::endl; // 11

    std::unique_ptr<int> up3 = std::move(up1); // 现在p3是数据的唯一的unique_ptr

    std::cout << *up3 << std::endl; // 11
    //std::cout << *up1 << std::endl;   // err, 运行时错误
    up3.reset(); // 显式释放内存
    up1.reset(); // 不会导致运行时错误
    //std::cout << *up3 << std::endl;   // err, 运行时错误

    std::unique_ptr<int> up4(new int(22)); // 无法复制的unique_ptr
    up4.reset(new int(44));                //"绑定"动态对象
    std::cout << *up4 << std::endl;        // 44

    up4 = nullptr; //显式销毁所指对象，同时智能指针变为空指针。与up4.reset()等价

    std::unique_ptr<int> up5(new int(55));
    int *p = up5.release(); //只是释放控制权，不会释放内存
    std::cout << *p << std::endl;
    //cout << *up5 << endl; // err, 运行时错误
    delete p; //释放堆区资源
}

void check(std::weak_ptr<int> &wp)
{
    std::shared_ptr<int> sp = wp.lock(); // 转换为shared_ptr<int>
    if (sp != nullptr)
    {
        std::cout << "still: " << *sp << std::endl;
    }
    else
    {
        std::cout << "still: "
                  << "pointer is invalid" << std::endl;
    }
}

TEST(dmptrtest_weak_ptr, dmptrtest_weak_ptr)
{
    std::shared_ptr<int> sp1(new int(22));
    std::shared_ptr<int> sp2 = sp1;
    std::weak_ptr<int> wp = sp1; // 指向shared_ptr<int>所指对象

    std::cout << "count: " << wp.use_count() << std::endl; // count: 2
    std::cout << *sp1 << std::endl;                        // 22
    std::cout << *sp2 << std::endl;                        // 22
    check(wp);                                             // still: 22

    sp1.reset();
    std::cout << "count: " << wp.use_count() << std::endl; // count: 1
    std::cout << *sp2 << std::endl;                        // 22
    check(wp);                                             // still: 22

    sp2.reset();
    std::cout << "count: " << wp.use_count() << std::endl; // count: 0
    check(wp);                                             // still: pointer is invalid
}
