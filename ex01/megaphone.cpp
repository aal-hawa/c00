

class megaphone
{
    public:
		static void printFun(std::string str)
		{
			for(size_t i = 0; i < str.length(); i++)
			{
				str[i] = toupper(str[i]);
			}
			std::cout << str; 
		}
};

