#include "PhoneBook.hpp"

int main(int ac, char **arv)
{
	std::string add = "ADD";
	std::string search = "SEARCH";
	std::string exit = "EXIT";
	std::string line = "";
	PhoneBook phoneBook;
	int i;
	(void)arv;
	i = 1;
	if (ac == 1)
	{
		while (1)
		{
			std::cout << "Please enter: ADD, SEARCH, or EXIT" << std::endl;

			if (!std::getline(std::cin, line))
				break;
			if (line == add)
				phoneBook.addFun();
			else if (line == search)
				phoneBook.searchFun();
			else if (line  == exit)
				break;
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "ERROR: You have more argumants" <<std::endl;
	}
	return (0);
}