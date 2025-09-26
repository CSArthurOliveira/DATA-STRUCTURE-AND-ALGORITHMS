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

	void display()
	{
		displaying(head);
	}

	void displaying(Node *start)
	{
		if (start != nullptr)
		{
			std::cout << "Elemento no indice " << start->index << ": " << start->data << ",  ";
			displaying(start->next);
		}
		else if (head == nullptr)
		{
			std::cout << "Lista vazia!" << std::endl;
		}
	}

	void reIndex(Node *start)
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
		do
		{
			system("cls");
			std::cout << "INFORME A OPERACAO: \n1 - INSERIR\n2 - REMOVER\n3 - VERIFICAR\n4 - MOSTRAR\n5 - ENCERRAR O PROGRAMA\n\nOPERACAO: ";
			std::cin >> oprt;
		} while (oprt != 5);
	}
};