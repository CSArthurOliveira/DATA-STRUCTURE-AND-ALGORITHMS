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
		}else if (head->info == value)
		{
			Node *selected = head;
			head = head->next;
			delete selected;
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
			}

			Node *selected = runner->next;
			runner->next = runner->next->next;
			delete selected;
		}

		listSize--;
	}

	void display()
	{
		if (head == nullptr && listSize == 0)
		{
			std::cout << "Lista Vazia" << std::endl;
		}else{
			Node *current = head;
			int i = 0;
			while (current != nullptr)
			{
				std::cout << "Elemento: " << i << ": " << current->info << " ";
				i++;
				current = current->next;
			}
			std::cout << std::endl;
		}

	};

	int displaySize()
	{
		return listSize;
	};
};