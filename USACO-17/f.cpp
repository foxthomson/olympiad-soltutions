// #include <stdafx.h> // Visual Studio users need to uncomment this line
#include <iostream> // for std::cout and std::endl
#include "add.h"

// Definition of function doPrint()
void doPrint() // doPrint() is the called function in this example
{
    std::cout << "In doPrint()" << std::endl;
}

void print(int x)
{
    std::cout << x << std::endl;
}

// int add(int x, int y);

// Definition of function main()
int main()
{
    std::cout << "Starting main()" << std::endl;
    doPrint(); // Interrupt main() by making a function call to doPrint().  main() is the caller.
    std::cout << "Ending main()" << std::endl;

    print(add(5, 7));

    return 0;
}
