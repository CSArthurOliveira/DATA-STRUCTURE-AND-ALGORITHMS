class Q3
{
public:
	
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
