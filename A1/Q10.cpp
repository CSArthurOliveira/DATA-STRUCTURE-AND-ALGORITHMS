#include <iostream>
#include "Q10.h"

int main()
{
    Q10CircularLinkedList *list = new Q10CircularLinkedList();

    std::cout << "Resposta Q10:" << std::endl;
    list->insertAtBeginning(10);
    list->insertAtBeginning(20);
    list->insertAtBeginning(30);

    std::cout << std::endl;
    list->display();

    list->insertAtEnd(40);
    list->insertAtEnd(50);
    list->insertAtEnd(60);

    std::cout << std::endl;
    list->display();

    list->insertAtBeginning(5);
    list->insertAtEnd(70);

    std::cout << std::endl;
    list->display();
    
    delete list;
    return 0;
}