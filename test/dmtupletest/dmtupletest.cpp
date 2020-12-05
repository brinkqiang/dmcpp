
#include <iostream>
#include <tuple>
#include <string>
#include "dmcast.h"
#include "dmformat.h"

int main()
{
	auto t = std::make_tuple(1, 2, "abc", "def", 4.0f);
	fmt::print(dmcast::lexical_cast(t));

	return 0;
}