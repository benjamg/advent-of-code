#include <cstdlib>
#include <iostream>
#include <string>

bool repeats(std::string_view str, int digits)
{
	if (str.size() % digits != 0)
		return false;

	std::string_view first_part = str.substr(0, digits);
	for (size_t i = digits; i < str.size(); i += digits)
	{
		if (str.substr(i, digits) != first_part)
			return false;
	}
	return true;
}

int main()
{
	int64_t total = 0;

	for (std::string line; std::getline(std::cin, line, ',');)
	{
		int64_t range_start = std::stoll(line.substr(0, line.find('-')));
		int64_t range_end = std::stoll(line.substr(line.find('-') + 1));
		for (int64_t num = range_start; num <= range_end; ++num)
		{
			std::string num_str = std::to_string(num);
			for (int i = 1; i <= num_str.length() / 2; ++i)
			{
				if (repeats(num_str, i))
				{
					total += num;
					break;
				}
			}
		}
	}

	std::cout << "total: " << total << '\n';
	return EXIT_SUCCESS;
}