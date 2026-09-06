#include "../include/array.hpp"
#include <iostream>


int main() 
{
    array<int> hello(10);
    std::cout << "All is gone correctly" <<std::endl;

    hello[0] = 10;

    hello.print(0);

    return 0;
}
