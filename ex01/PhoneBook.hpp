#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cctype>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
    public:
		PhoneBook();
		void addFun();
		void searchFun();
	
	private:
		Contact contact[8];
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		int index_contact;
		int separeated_line;
};

#endif