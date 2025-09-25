#include <iostream>

class Q1
{

public:
	void Menu()
	{
		int oprt = 0;
		do
		{
			system("cls");
			std::cout << "INFORME A FUNCAO DESEJADA: \n1 - (F1)\n2 - (F2)\n3 - (F3)\n4 - ENCERRAR\n\nFUNCAO: ";
			std::cin >> oprt;

			int valor;
			switch (oprt)
			{
			case 1:
				system("cls");
				std::cout << "INFORME UM VALOR PARA (F1): ";
				std::cin >> valor;
				std::cout << "Resposta Q1F1: " << F1(valor) << std::endl;
				system("pause");
				break;
			case 2:
				system("cls");
				std::cout << "INFORME UM VALOR PARA (F2): ";
				std::cin >> valor;
				std::cout << "Resposta Q1F2: " << F2(valor) << std::endl;
				system("pause");
				break;
			case 3:
				system("cls");
				std::cout << "INFORME UM VALOR PARA (F3): ";
				std::cin >> valor;
				std::cout << "Resposta Q1F3: ";
				F3(valor);
				system("pause");
				break;
			case 4:
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