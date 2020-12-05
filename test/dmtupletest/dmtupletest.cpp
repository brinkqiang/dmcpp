
#include <iostream>
#include <tuple>
#include <string>
#include "dmcast.h"

template<int index, typename... T>
struct print_tuple {
	void operator() (std::tuple<T...>& t) {
		std::cout << get<index>(t) << " ";
		print_tuple<index - 1, T...>{}(t);
	}
};

template<typename... T>
struct print_tuple<0, T...> {
	void operator() (std::tuple<T...>& t) {
		std::cout << get<0>(t) << " ";
	}
};

template<typename... T>
void print(std::tuple<T...>& t) {
	const auto size = std::tuple_size<std::tuple<T...>>::value;
	print_tuple<size - 1, T...>{}(t);
}

template<typename... T>
std::string csv(std::tuple<T...>& t)
{
	std::string strData;
	std::apply([&strData](auto&& ... args) { ((strData += (strData.empty() ? "" : ","), strData += dmcast::lexical_cast(args)), ...); }, t);
	return strData;
}

int main()
{
	auto t = std::make_tuple(1, 2, "abc", "def", 4.0f);
	auto s = csv(t);

	std::cout << s << " ";

	return 0;
}