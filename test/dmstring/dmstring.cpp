
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <type_traits>
#include "gtest.h"
template<typename... Args>
inline void append(std::string& s, Args&&... args)
{
    ((s += std::forward<Args>(args), s += ", "), ...);
}

//template<typename... Args>
//void print(Args... Args){
//    std::initializer_list<int>{(std::cout << args << std::endl, 0)...};
//}

//c++17 unary fold
template<typename... Args>
void print(Args... args) {
    ((std::cout << args << std::endl), ...);
}
//
////c++17 binary fold
//template<typename ...Args>void print(Args&&... args) {
//    (std::cout << ... << args) << '\n';
//}

TEST(dmstring, dmstring)
{
    std::string s;    
    append(s, "1", "2", "3");
    print("1", "2", "3");
}