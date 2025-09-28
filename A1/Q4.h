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
			std::cout << "Elemento removido com sucesso!" << std::endl;
		}
		else
		{
			std::cout << "Falha ao remover elemento!" << std::endl;
		};
	}

	bool remover(Node *&start, int target)
	{
		if (start == nullptr)
		{
			return false;
		}
		else if (head->data == target)
		{
			Node *selected = head;
			head = head->next;
			reorganizer(selected->next);
			delete selected;
			listSize--;
			return true;
		}

		else if (start->data == target)
		{
			Node *selected = start;
			start = start->next;
			reorganizer(selected->next);
			delete selected;
			listSize--;
			return true;
		}

		return remover(start->next, target);
	}

	void reorganizer(Node *start)
	{
		Node *current = start;
		int i = start->index;
		while (current != nullptr)
		{
			current->index = i - 1;
			current = current->next;
			i++;
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
			std::cout << "Elemento no indice " << start->index << ": " << start->data << ";  ";
			displaying(start->next);
		}
		else if (head == nullptr)
		{
			std::cout << "Lista vazia!" << std::endl;
		}
	}

	void isOnList(int target)
	{
		int position = exists(head, target);

		if (position < 0)
		{
			std::cout << "Elemento inexistente!" << std::endl;
		}
		else
		{
			std::cout << "Elemento encontrado no indice: " << position << std::endl;
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
				std::cout << "ELEMENTO INSERIDO COM SUCESSO: " << std::endl;
				system("pause");
				break;
			case 2:
				system("cls");
				display();
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
				std::cout << "INFORME O VALOR QUE DESEJA VERIFICAR: ";
				std::cin >> toVerify;
				isOnList(toVerify);
				system("pause");
				break;
			case 4:
				system("cls");
				display();
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