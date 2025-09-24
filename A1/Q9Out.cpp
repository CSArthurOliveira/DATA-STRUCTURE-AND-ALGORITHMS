#include <iostream>
#include "Q9.h"

int main()
{
    Q9DoubleLinkedList *list = new Q9DoubleLinkedList();

    std::cout << "Resposta Q9:" << std::endl;
    std::cout << std::endl;
    list->insertAtEnd(10);
    list->insertAtEnd(20);
    list->insertAtEnd(30);
    list->insertAtEnd(40);
    list->insertAtEnd(50);

    list->display();
    std::cout << std::endl;

    list->insertAtEnd(40);
    list->insertAtBeggining(40);

    list->insertAtBeggining(5);
    std::cout << std::endl;
    list->display();

    delete list;
    return 0;
}