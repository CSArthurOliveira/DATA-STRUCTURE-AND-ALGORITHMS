#include <iostream>
#include "Q7.h"

int main()
{
    Q7Queue *queue = new Q7Queue();
    queue->Menu();
    delete queue;
    return 0;
}