#include <iostream>
#include "Q3.h"

int main()
{
    Q3 *q3 = new Q3();

    std::cout << "Resposta Q3:" << std::endl;
    std::cout << std::endl;
    std::cout << q3->CalcularProduto(5, 1) << std::endl;
    std::cout << q3->CalcularProduto(5, 5) << std::endl;
    std::cout << std::endl;
    delete q3;

    return 0;
}