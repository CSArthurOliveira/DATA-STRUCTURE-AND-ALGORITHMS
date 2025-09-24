#include <iostream>
#include "Q8.h"

int main()
{

    Q8DoubleLinkedList *list = new Q8DoubleLinkedList();

    std::cout << "Resposta Q8:" << std::endl;
    std::cout << std::endl;
    list->add(10, 0);
    list->add(20, 1);
    list->add(15, 2);
    list->add(5, 3);
    list->add(25, 4);

    list->display();
    std::cout << std::endl;

    list->add(30, 2);
    list->display();
    std::cout << std::endl;

    list->remove(15);
    list->display();
    std::cout << std::endl;

    list->add(90, 2);
    list->display();

    list->isOnList(5);
    std::cout << std::endl;
    delete list;
    
    return 0;
}