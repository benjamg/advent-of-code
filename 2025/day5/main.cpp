#include <cstdlib>
#include <iostream>
#include <string>
#include <set>

std::ostream &operator<<(std::ostream &os, const std::pair<int64_t, int64_t> &p)
{
	return os << '{' << p.first << ", " << p.second << '}';
}

int main()
{
	std::set<std::pair<int64_t, int64_t>> ranges;
	for (std::string line; std::getline(std::cin, line);)
	{
		if (line.empty())
			break;

		auto start = std::stoll(line.substr(0, line.find("-")));
		auto end = std::stoll(line.substr(line.find("-") + 1));
		auto range = std::make_pair(start, end);

		auto lower = ranges.lower_bound(range);
		if (lower != ranges.begin() && std::prev(lower)->second >= range.first)
		{
			--lower;
		}

		// at end
		if (lower == ranges.end())
		{
			std::cout << line << " inserting at end: " << range << '\n';
			ranges.insert(range);
			continue;
		}

		// totally before lower
		if (lower->first > range.second)
		{
			std::cout << line << " inserting before " << *lower << ": " << range << '\n';
			ranges.insert(range);
			continue;
		}

		// fully contained
		if (lower->first < range.first && lower->second >= range.second)
		{
			std::cout << line << " skipping " << range << " as contained by " << *lower << '\n';
			continue;
		}

		// find overlap end
		auto upper = lower;
		std::cout << line << " Overlapping " << range << '\n';
		while (upper != ranges.end() && upper->first <= range.second)
		{
			std::cout << "  * " << *upper << '\n';
			++upper;
		}

		auto new_start = std::min(lower->first, range.first);
		auto new_end = std::max(range.second, std::prev(upper)->second);
		std::cout << "  - Combined to " << std::make_pair(new_start, new_end) << '\n';
		ranges.erase(lower, upper);
		ranges.emplace(new_start, new_end);
	}

	int fresh = 0;
	for (std::string line; std::getline(std::cin, line);)
	{
		auto value = std::stoll(line);
		auto found = ranges.upper_bound(std::make_pair(value, value));

		if (found != ranges.begin())
		{
			--found;
		}

		if (value >= found->first && value <= found->second)
		{
			++fresh;
		}
	}

	std::cout << "fresh: " << fresh << '\n';

	int64_t total = 0;
	for (const auto &range : ranges)
	{
		total += range.second - range.first + 1;
	}
	std::cout << "\ntotal: " << total << '\n';
}