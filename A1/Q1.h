#include <iostream>

class Q1
{

public:

	int F1(int number)
	{
		if (number == 0)
			return 1;
		else
			return (number * F1(number - 1));
	}

	int F2(int number)
	{
		if (number == 0)
			return (1);
		if (number == 1)
			return (1);
		else
			return (F2(number - 1) + 2 * F2(number - 2));
	}

	void F3(int number)
	{
		if (number == 0)
			std::cout << "ZERO!" << std::endl;
		else
		{
			std::cout << number;
			std::cout << number;
			F3(number - 1);
		};
	}
};