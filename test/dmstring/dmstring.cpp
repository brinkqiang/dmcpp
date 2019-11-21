
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <type_traits>

template<typename... Args>
inline void append(std::string& s, Args&&... args)
{
    ((s += std::forward<Args>(args), s += ", "), ...);
}

int main() {
    std::string s;    
    append(s, "1", "2", "3");

    return 0;
}