#include <iostream>
#include "Q5.h"

int main()
{
	Q5LinkedList *q5 = new Q5LinkedList();

	std::cout << "Resposta Q5:" << std::endl;
	std::cout << std::endl;
	q5->insert(1);
	q5->insert(2);
	q5->insert(3);
	q5->insert(4);
	q5->insert(5);

	q5->display();
	std::cout << std::endl;

	q5->remove(4);

	q5->display();
	std::cout << std::endl;

	q5->clear();
	q5->display();
	delete q5;

	return 0;
}