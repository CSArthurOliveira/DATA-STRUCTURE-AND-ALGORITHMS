#include <iostream>

struct Node
{
	int info;
	Node *next;
};

class Q5LinkedList
{
private:
	Node *head;
	int listSize;

	void clear()
	{
		while (head != nullptr)
		{
			Node *current = head;
			head = head->next;
			delete current;
		}
		listSize = 0;
	}

	void insert(int value)
	{
		if (head == nullptr)
		{
			head = new Node();
			head->info = value;
			head->next = nullptr;
		}
		else
		{
			Node *current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = new Node();
			current->next->info = value;
			current->next->next = nullptr;
		}
		listSize++;
	}

	void remove(int value)
	{
		if (head == nullptr && listSize == 0)
		{
			std::cout << "Lista Vazia" << std::endl;
		}
		else if (head->info == value)
		{
			Node *selected = head;
			head = head->next;
			delete selected;
			listSize--;
		}
		else
		{
			Node *runner = head;
			while (runner->next != nullptr && runner->next->info != value)
			{
				runner = runner->next;
			}

			if (runner->next == nullptr)
			{
				std::cout << "Valor Inexistente" << std::endl;
			}else{
							Node *selected = runner->next;
							runner->next = runner->next->next;
							delete selected;
							listSize--;
			}
		}
	}

	void display()
	{
		if (head == nullptr && listSize == 0)
		{
			std::cout << "Lista Vazia" << std::endl;
		}
		else
		{
			Node *current = head;
			int i = 0;
			while (current != nullptr)
			{
				std::cout << "Valor no indice " << i << ": " << current->info << "; ";
				i++;
				current = current->next;
			}
			std::cout << std::endl;
		}
	};

	void isOnList(int value)
	{
		if (head == nullptr && listSize == 0)
		{
			std::cout << "Lista Vazia" << std::endl;
		}
		else
		{
			Node *current = head;
			int i = 0;
			while (current != nullptr && current->info != value)
			{
				i++;
				current = current->next;
			}

			if (current == nullptr)
			{
				std::cout << "Valor Inexistente" << std::endl;
			}
			else
			{
				std::cout << "Valor encontrado na posicao: " << i << std::endl;
			}
		}
	}

	bool isEmpty()
	{
		return head == nullptr;
	}

public:
	Q5LinkedList()
	{
		head = nullptr;
		listSize = 0;
	}

	~Q5LinkedList()
	{
		clear();
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
					std::cout << "\nValor removido com sucesso!" << std::endl;
				}
				system("pause");
				break;
			case 3:
				system("cls");
				if(!isEmpty())
				{
					std::cout << "INFORME O VALOR QUE DESEJA VERIFICAR: ";
					std::cin >> toVerify;
					isOnList(toVerify);
				}else{
					std::cout << "Lista Vazia" << std::endl;
				};
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