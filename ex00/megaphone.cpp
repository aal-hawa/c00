#include <iostream>

class Megaphone
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
	Megaphone megaphone;
	int i;

	i = 1;
	if (ac != 1)
	{
		while (arv[i])
			megaphone.printFun(arv[i++]);
		std::cout << std::endl;
	}
	else {
		megaphone.printFun("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
		std::cout << std::endl;
	}
	return (0);
}