#include <iostream>
#include "Q6.h"

int main()
{
    Q6Stack *stack = new Q6Stack();

    std::cout << "Resposta Q6:" << std::endl;
    std::cout << std::endl;
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    stack->display();

    stack->pop();
    stack->display();

    stack->isOnStack(1);
    stack->isOnStack(25);
    std::cout << std::endl;

    stack->clear();
    stack->display();

    delete stack;
    return 0;
}