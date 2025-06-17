
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index_contact = 0;
	separeated_line = 0;
}

 void PhoneBook::addFun()
 {
	std::string line = "";
	std::string out_put = "first name";
	std::cout << "enter the first name" << std::endl;
	separeated_line = 0;
	 while (separeated_line < 5)
	 {
		if (!std::getline(std::cin, line))
			break;
		if (line == "")
			std::cout << "can not enter empty data" << std::endl;
		else if (separeated_line == 0)
		{
			first_name = line;
			out_put = "last name";
		}
		else if (separeated_line == 1)
		{
			last_name = line;
			out_put = "nickname";

		}
		else if (separeated_line == 2)
		{
			nickname = line;
			out_put = "phone number";

		}
		else if (separeated_line == 3)
		{
			phone_number = line;
			out_put = "darkest secret";

		}
		else if (separeated_line == 4)
		{
			darkest_secret = line;
			out_put = "";
			
		}
		if (out_put != "")
			std::cout << "enter the " << out_put << std::endl;
		if (line != "")
			separeated_line++;

	 }
	contact[index_contact % 8].edit_Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	index_contact++;
 }

 void PhoneBook::searchFun()
 {
	std::string line = "";
	for (size_t i = 0; i < 8; i++)
	{
		contact[i].show_contact_details(i + 1);
	}
	while (1)
	{
		std::cout << "enter valid index" << std::endl;
		if (!std::getline(std::cin, line))
			return;
		if (line.length() == 1 && line[0] >= '1' && line[0] <= '8')
			break;
	}
	contact[line[0] - 1 - '0'].show_contact_all_details();
 }
