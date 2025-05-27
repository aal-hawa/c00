#include "PhoneBook.hpp"

int main(int ac, char **arv)
{
	std::string add = "ADD";
	std::string search = "SEARCH";
	std::string exit = "EXIT";
	std::string line;
	PhoneBook m;
	int i;

	i = 1;
	if (ac == 1)
	{
		while (1)
		{
			std::cout << "Please enter: ADD, SEARCH, or EXIT" << std::endl;

			std::getline(std::cin, line);
			if (line == add)
				m.addFun();
			else if (line == search)
				m.searchFun();
			else if (line  == exit)
				break;
			if (arv[i + 1])
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "ERROR: You have more argumants" <<std::endl;
	}
	return (0);
}