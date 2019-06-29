
#include <iostream>
#include <tuple>
#include <string>

auto f() {
    return std::make_tuple(1, 2.3, "456");
}

int main() {
    auto[x, y, z] = f();
    std::cout << x << ", " << y << ", " << z << std::endl;
    return 0;
}