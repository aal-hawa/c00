#include <iostream>
#include <cctype>
#include <string>

class megaphone
{
    public:
		void printFun(std::string str)
		{
			for(size_t i = 0; i < str.length(); i++)
			{
				str[i] = toupper(str[i]);
			}
			std::cout << str; 
		}
};

int main(int ac, char **arv)
{
	megaphone m;
	int i;

	i = 1;
	if (ac != 1)
	{
		while (arv[i])
		{
			m.printFun(arv[i++]);
			if (arv[i])
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	else {
		m.printFun("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
		std::cout << std::endl;
	}
	return (0);
}