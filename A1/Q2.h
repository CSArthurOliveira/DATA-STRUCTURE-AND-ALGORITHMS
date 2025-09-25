class Q2
{
public:
	
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