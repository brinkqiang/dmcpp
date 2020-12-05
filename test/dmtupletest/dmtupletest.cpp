
#include <iostream>
#include <tuple>
#include <string>

template<int index, typename... Ts>
struct print_tuple {
	void operator() (std::tuple<Ts...>& t) {
		std::cout << get<index>(t) << " ";
		print_tuple<index - 1, Ts...>{}(t);
	}
};

template<typename... Ts>
struct print_tuple<0, Ts...> {
	void operator() (std::tuple<Ts...>& t) {
		std::cout << get<0>(t) << " ";
	}
};

template<typename... Ts>
void print(std::tuple<Ts...>& t) {
	const auto size = std::tuple_size<std::tuple<Ts...>>::value;
	print_tuple<size - 1, Ts...>{}(t);
}

int main()
{
	auto t = std::make_tuple(1, 2, "abc", "def", 4.0f);
	print(t);

    auto [x, y, z] = std::make_tuple(1, 2.3, "456");
    std::cout << x << ", " << y << ", " << z << std::endl;
    return 0;
}