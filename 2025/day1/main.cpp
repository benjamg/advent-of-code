#include <cstdlib>
#include <iostream>
#include <string>

int main()
{
	int dial = 50;
	int pass = 0;
	int clicks = 0;

	for (std::string line; std::getline(std::cin, line);)
	{
		if (line.empty())
			continue;

		int value = std::stoi(line.substr(1));
		int loops = value / 100;
		int delta = value % 100;

		int old_dial = dial;
		dial += (line[0] == 'L') ? -delta : delta;

		bool wrapped = (dial < 0 || dial >= 100);
		dial = ((dial % 100) + 100) % 100;

		if (wrapped && old_dial != 0 && dial != 0)
		{
			++clicks;
		}

		if (dial == 0 && old_dial != 0)
		{
			++clicks;
			++pass;
		}
		else if (dial == 0)
		{
			++pass;
		}

		clicks += loops;
	}

	std::cout << "Passcode is " << pass << '\n';
	std::cout << "0x434C49434B is " << clicks << '\n';
	return EXIT_SUCCESS;
}