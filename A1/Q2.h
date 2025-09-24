class Q2
{
public:
	Q2()
	{
	}

	~Q2()
	{
	}

	int Somatorio(int number)
	{
		if (number % 2 != 0)
		{
			number--;
		}

		if (number == 0)
		{
			return number;
		}
		else
		{
			return number + Somatorio(number - 2);
		}
	}
};