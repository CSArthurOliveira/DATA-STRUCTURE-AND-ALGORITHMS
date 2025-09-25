#include <iostream>
#include "Q3.h"

int main()
{
    Q3 *q3 = new Q3();
    q3->Menu();
    
    delete q3;
    return 0;
}