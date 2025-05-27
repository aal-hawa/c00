#include "Contact.hpp"

Contact::Contact()
{
	_first_name = "";
	_last_name = "";
	_nickname = "";
	_phone_number = "";
	_darkest_secret = "";	
}

void Contact::edit_Contact(std::string first_name,std::string last_name,std::string nickname,std::string phone_number,std::string darkest_secret)
{
	_first_name = first_name;
	_last_name = last_name;
	_nickname = nickname;
	_phone_number = phone_number;
	_darkest_secret = darkest_secret;
}

void Contact::show_contact_details(int index)
{
	std::string word;
	std::size_t i = 0;
	int spaces = 0;
	std::cout << index;

	for(int index_word = 0; index_word < 3; index_word++)
	{
		std::cout << "|";
		if (index_word == 0)
			word = _first_name;
		else if (index_word == 1)
			word = _last_name;
		else
			word  = _nickname;
		i = word.length();
		spaces = 10 - i;
		for(int s = 0; s < spaces; s++)
			std::cout << " ";
		for(size_t index = 0; index < i; index++)
		{
			if (index == 9 && i > 10)
				word[index] = '.';
			std::cout << word[index];
			if(index == 9)
				break;
		}
	}
	std::cout << std::endl;
}

void Contact::show_contact_all_details()
{
	std::cout << _first_name << " " << _last_name << " " << _nickname << " " << _phone_number << " " << _darkest_secret << std::endl;
}
