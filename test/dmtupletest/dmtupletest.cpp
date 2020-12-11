
#include <iostream>
#include <tuple>
#include <string>
#include "dmcast.h"
#include "dmformat.h"

template <typename T>
std::string stl_tostring(std::tuple<T...>& t)
{
	std::string strData;
	std::apply([&](auto&& ... args) { ((strData += (strData.empty() ? "" : ","), strData += lexical_cast(args)), ...); }, t);
	return strData;
}

int main()
{
	auto t = std::make_tuple(1, 2, "abc", "def", 4.0f);
	fmt::print(stl_tostring(t));
	return 0;
}