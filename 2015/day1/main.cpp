#include <cstdlib>
#include <iostream>
#include <string>

int main()
{
	char ch;
	int floor = 0;
	int pos = 0;
	bool found = false;

	while (std::cin)
	{
		std::cin.get(ch);
		if (std::cin.eof())
			break;

		if (ch == '(')
			++floor;
		else if (ch == ')')
			--floor;

		++pos;
		if (floor < 0 && !found)
		{
			std::cout << "floor " << floor << " at pos " << pos << '\n';
			found = true;
		}
	}
	std::cout << "final floor: " << floor << '\n';
	return EXIT_SUCCESS;
}