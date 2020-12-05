
#include <iostream>
#include <tuple>
#include <string>
#include "dmcast.h"
#include "dmformat.h"

template<typename... T>
std::string csv(std::tuple<T...>& t)
{
	std::string strData;
	std::apply([&](auto&& ... args) { ((strData += (strData.empty() ? "" : ","), strData += dmcast::lexical_cast(args)), ...); }, t);
	return strData;
}

int main()
{
	auto t = std::make_tuple(1, 2, "abc", "def", 4.0f);
	fmt::print(csv(t));

	return 0;
}