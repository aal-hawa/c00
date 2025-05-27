#include <iostream>
#include <cctype>
#include <string>

class Contact
{
	public:
		Contact();
		void edit_Contact(std::string first_name,std::string last_name,std::string nickname,std::string phone_number,std::string darkest_secret);
		void show_contact_details(int index);
		void show_contact_all_details();

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
};

