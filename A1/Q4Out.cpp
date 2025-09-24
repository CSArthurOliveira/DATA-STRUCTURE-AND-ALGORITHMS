#include <iostream>
#include "Q4.h"

int main()
{
	Q4LinkedList *q4 = new Q4LinkedList();

	std::cout << "Resposta Q4:" << std::endl;
	std::cout << std::endl;
	q4->insert(1);
	q4->insert(2);
	q4->insert(3);
	q4->insert(4);
	q4->insert(5);

	q4->display(q4->head);
	std::cout << std::endl;

	std::cout << std::endl;
	q4->isOnList(q4->head, 4);
	std::cout << std::endl;

	q4->remove(q4->head, 4);

	q4->display(q4->head);
	std::cout << std::endl;
	std::cout << std::endl;

	q4->isOnList(q4->head,5);
	std::cout << std::endl;

	q4->remove(q4->head,1);

	q4->display(q4->head);
	std::cout << std::endl;
	delete q4;
	
	return 0;
}