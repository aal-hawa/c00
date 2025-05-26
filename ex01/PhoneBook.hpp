
#include "Phone.h"

class PhoneBook
{
	//first name, last name, nickname, phone number, and darkest secret
	
    public:
		void addFun(std::string line);
		void searchFun(std::string line);
		void exitFun();
		void replace_contacts();
	
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		int ligth_contact;
};

