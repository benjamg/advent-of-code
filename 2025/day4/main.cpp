#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

int moverolls(std::vector<std::string> &grid)
{
	int moved = 0;
	for (auto y = 0; y < grid.size(); ++y)
	{
		for (auto x = 0; x < grid[y].size(); ++x)
		{
			auto adj = 0;

			if (grid[y][x] == '@')
			{
				if (y > 0 && x > 0 && grid[y - 1][x - 1] == '@')
					++adj;
				if (y > 0 && grid[y - 1][x] == '@')
					++adj;
				if (y > 0 && x + 1 < grid[y].size() && grid[y - 1][x + 1] == '@')
					++adj;

				if (x > 0 && grid[y][x - 1] == '@')
					++adj;
				if (x + 1 < grid[y].size() && grid[y][x + 1] == '@')
					++adj;

				if (y + 1 < grid.size() && x > 0 && grid[y + 1][x - 1] == '@')
					++adj;
				if (y + 1 < grid.size() && grid[y + 1][x] == '@')
					++adj;
				if (y + 1 < grid.size() && x + 1 < grid[y].size() && grid[y + 1][x + 1] == '@')
					++adj;

				if (adj < 4)
				{
					++moved;
					grid[y][x] = '.';
				}
			}
		}
	}
	return moved;
}

int main()
{
	int total = 0;

	std::vector<std::string> grid;
	for (std::string line; std::getline(std::cin, line);)
	{
		grid.push_back(line);
	}

	auto moved = 0;
	do
	{
		moved = moverolls(grid);
		total += moved;
	} while (moved > 0);

	std::cout << "total: " << total << '\n';
	return EXIT_SUCCESS;
}