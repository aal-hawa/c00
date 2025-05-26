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
			if (arv[i + 1])
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