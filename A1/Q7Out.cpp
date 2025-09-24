#include <iostream>
#include "Q7.h"

int main()
{
    Q7Queue *queue = new Q7Queue();

    std::cout << "Resposta Q7:" << std::endl;
    std::cout << std::endl;
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);

    queue->display();
    queue->dequeue();
    queue->display();
    std::cout << std::endl;

    queue->isOnQueue(4);

    queue->clear();
    queue->display();

    queue->isOnQueue(4);
    delete queue;
    return 0;
}