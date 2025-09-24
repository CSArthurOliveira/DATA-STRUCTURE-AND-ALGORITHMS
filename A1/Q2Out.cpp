#include <iostream>
#include "Q2.h"

int main()
{
    Q2 *q2 = new Q2();

    std::cout << "Resposta Q2:" << std::endl;
    std::cout << std::endl;
    std::cout << q2->Somatorio(9) << std::endl;
    std::cout << std::endl;
    delete q2;

    return 0;
}