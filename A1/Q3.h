class Q3
{
public:
	Q3()
	{
	}
	~Q3()
	{
	}

	int CalcularProduto(int a, int b)
	{
		if (b == 1)
			return a;
		else
		{
			return a + CalcularProduto(a,b - 1);
		}
	}
};
