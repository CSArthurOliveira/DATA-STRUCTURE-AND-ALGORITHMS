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
	
	void remove(int target){
		remover(head,target);
	}	

	void display(){
		displayer(head);
	}

	void isOnList(int target){
		verify(head,target);
	}
	
	private:
	
	void reindex(Node* start){
		Node* current = start;
		int i = start->index;
		while (current != nullptr){
			current->index = i - 1;
			current = current->next;
			i++;
		}
	}

	void remover(Node *start, int value)
	{
		if (start == nullptr && listSize == 0)
			std::cout << "Lista vazia!" << std::endl;
	
		else if(head->data == value){
			Node *remove = head;
			head = head->next;
			reindex(remove->next);
			delete remove;
		}
		else if (start->next->data == value)
		{
			Node *remove = start->next;
			start->next = start->next->next;
			reindex(remove);
			delete remove;
		}
		else
		{
			remover(start->next, value);
		}
	
		listSize--;
	}
	
	void displayer(Node *start)
	{
		if (start != nullptr){
			std::cout << "Elemento no indice " << start->index << ": " << start->data << ",  ";
			displayer(start->next);
		}
		else if(head == nullptr)
		{
			std::cout << "Lista vazia!" << std::endl;
		}
	}
	
	void verify(Node *start, int value)
	{
		if (start->data == value)
			std::cout << "Elemento " << value << " encontrado no indice: " << start->index << std::endl;
		else
			verify(start->next, value);
	};
};