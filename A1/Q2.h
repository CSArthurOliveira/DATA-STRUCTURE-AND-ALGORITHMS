class Q2
{
public:
	void Menu()
	{
		int oprt = 0;
		do
		{
			system("cls");
			std::cout << "INFORME A FUNCAO DESEJADA: \n1 - SOMATORIO\n2 - ENCERRAR O PROGRAMA\n\nFUNCAO: ";
			std::cin >> oprt;

			int valor;
			switch (oprt)
			{
			case 1:
				system("cls");
				std::cout << "INFORME UM VALOR: ";
				std::cin >> valor;
				std::cout << "Resposta Q2: " << Somatorio(valor) << std::endl;
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