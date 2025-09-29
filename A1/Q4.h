#include <iostream>

struct Node
{
	int data;
	int index;
	Node *next;
};

class Q4LinkedList
{
private:
	Node *head;
	int listSize = 0;

	void insert(int value)
	{
		if (head == nullptr)
		{
			head = new Node();
			head->data = value;
			head->index = 0;
			head->next = nullptr;
		}
		else
		{
			Node *current = head;
			int steps = 1;
			while (current->next != nullptr)
			{
				current = current->next;
				steps++;
			}
			current->next = new Node();
			current->next->data = value;
			current->next->index = steps;
			current->next->next = nullptr;
		}

		listSize++;
	}

	void remove(int target)
	{

		if (remover(head, target))
		{
			std::cout << "\nValor removido com sucesso!" << std::endl;
		}
		else
		{
			std::cout << "\nFalha ao remover o valor!" << std::endl;
		};
	}

	bool remover(Node *&start, int target)
	{
		if (start == nullptr)
		{
			return false;
		}

		if (start->data == target)
		{
			Node *selected = start;

			start = start->next;

			if (start != nullptr)
				reorganizer(start);

			delete selected;
			listSize--;
			return true;
		}

		return remover(start->next, target);
	}

	void reorganizer(Node *start)
	{

		Node *current = start;
		while (current != nullptr)
		{
			current->index--;
			current = current->next;
		}
	}

	void display()
	{
		displaying(head);
		std::cout << std::endl;
	}

	void displaying(Node *start)
	{
		if (start != nullptr)
		{
			std::cout << "Valor no indice " << start->index << ": " << start->data << ";  ";
			displaying(start->next);
		}
		else if (head == nullptr)
		{
			std::cout << "\nLista vazia!" << std::endl;
		}
	}

	void isOnList(int target)
	{
		int position = exists(head, target);

		if (position < 0)
		{
			std::cout << "\nValor nao encontrado!" << std::endl;
		}
		else
		{
			std::cout << "\nValor encontrado no indice: " << position << std::endl;
		}
	}

	int exists(Node *start, int target)
	{
		if (start == nullptr)
		{
			return -1;
		}
		else
		{
			if (start->data == target)
			{
				return start->index;
			}
			else
			{
				return exists(start->next, target);
			}
		}
	}

	bool isEmpty()
	{
		return head == nullptr;
	}

public:
	Q4LinkedList()
	{
		head = nullptr;
		listSize = 0;
	}

	~Q4LinkedList()
	{
		Node *current = head;
		while (current != nullptr)
		{
			Node *next = current->next;
			delete current;
			current = next;
		}
	}

	void Menu()
	{
		int oprt;
		int toInsert, toVerify, toRemove;
		do
		{
			system("cls");
			std::cout << "INFORME A OPERACAO: \n1 - INSERIR\n2 - REMOVER\n3 - VERIFICAR\n4 - MOSTRAR\n5 - ENCERRAR O PROGRAMA\n\nOPERACAO: ";
			std::cin >> oprt;

			switch (oprt)
			{
			case 1:
				system("cls");
				std::cout << "INFORME O VALOR QUE DESEJA INSERIR: ";
				std::cin >> toInsert;
				insert(toInsert);
				std::cout << "\nValor inserido com sucesso! " << std::endl;
				system("pause");
				break;
			case 2:
				system("cls");
				display();
				std::cout << std::endl;
				if (!isEmpty())
				{
					std::cout << "INFORME O VALOR QUE DESEJA REMOVER: ";
					std::cin >> toRemove;
					remove(toRemove);
				}
				system("pause");
				break;
			case 3:
				system("cls");
				if (!isEmpty())
				{
					std::cout << "INFORME O VALOR QUE DESEJA VERIFICAR: ";
					std::cin >> toVerify;
					isOnList(toVerify);
				}
				else
				{
					std::cout << "\nLista vazia!\n\n"
							  << std::endl;
				}
				system("pause");
				break;
			case 4:
				system("cls");
				display();
				std::cout << std::endl;
				system("pause");
				break;
			case 5:
				std::cout << "PROGRAMA ENCERRADO!" << std::endl;
				break;
			default:
				std::cout << "OPERACAO INVALIDA!" << std::endl;
				system("pause");
				break;
			}
		} while (oprt != 5);
	}
};