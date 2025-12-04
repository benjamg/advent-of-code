#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

uint64_t find_best(std::string_view str, size_t from, size_t to, uint64_t value, size_t count)
{
	size_t best = from;
	for (size_t i = from + 1; i < to; ++i)
	{
		if (str[i] > str[best])
		{
			best = i;
		}
	}

	value = value * 10 + (str[best] - '0');
	if (count > 1)
	{
		return find_best(str, best + 1, to + 1, value, count - 1);
	}
	return value;
}

int main()
{
	uint64_t total = 0;

	for (std::string line; std::getline(std::cin, line);)
	{
		total += find_best(line, 0, line.length() - 11, 0, 12);
	}

	std::cout << "total: " << total << '\n';
	return EXIT_SUCCESS;
}