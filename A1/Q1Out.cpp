#include <iostream>
#include "Q1.h"

int main()
{
	Q1 *q1 = new Q1();

	std::cout << "Resposta Q1F1:" << std::endl;
	std::cout << std::endl;

	std::cout << q1->F1(0) << std::endl;
	std::cout << q1->F1(1) << std::endl;
	std::cout << q1->F1(5) << std::endl;
	std::cout << std::endl;

	std::cout << "Resposta Q1F2:" << std::endl;
	std::cout << std::endl;

	std::cout << q1->F2(0) << std::endl;
	std::cout << q1->F2(1) << std::endl;
	std::cout << q1->F2(5) << std::endl;
	std::cout << std::endl;

	std::cout << "Resposta Q1F3:" << std::endl;
	std::cout << std::endl;

	q1->F3(0);
	q1->F3(1);
	q1->F3(5);
	std::cout << std::endl;
	delete q1;

	return 0;
}