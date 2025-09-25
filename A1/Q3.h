class Q3
{
public:
	void Menu()
	{
		int oprt;
		int x, y;
		do
		{
			system("cls");
			std::cout << "INFORME A FUNCAO DESEJADA: \n1 - CALCULAR PRODUTO\n2 - ENCERRAR O PROGRAMA\n\nFUNCAO: ";
			std::cin >> oprt;
			switch (oprt)
			{
			case 1:
				system("cls");
				std::cout << "INFORME DOIS VALORES: " << std::endl;
				std::cin >> x;
				std::cin >> y;
				std::cout << "Resposta Q3: " << CalcularProduto(x, y) << std::endl;
				system("pause");
				break;
			case 2:
				std::cout << "ENCERRANDO O PROGRAMA..." << std::endl;
				oprt = 4;
				break;
			default:
				system("cls");
				std::cout << "OPCAO INVALIDA!" << std::endl;
				system("pause");
				break;
			}
		} while (oprt != 4);
	}

private:
	int CalcularProduto(int a, int b)
	{
		if (b == 1)
			return a;
		else
		{
			return a + CalcularProduto(a, b - 1);
		}
	}
};
