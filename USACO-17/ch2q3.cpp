#include <iostream>

int main()
{
    double a;
    std::cout << "Enter a: ";
    std::cin >> a;

    double b;
    std::cout << "Enter b: ";
    std::cin >> b;

    char opp;
    std::cout << "Enter opperation: ";
    std::cin >> opp;

    std::cout << a << ' ' << opp << ' ' << b << " = ";

    if (opp == '+')
        std::cout << a + b << std::endl;
    if (opp == '-')
        std::cout << a - b << std::endl;
    if (opp == '*')
        std::cout << a * b << std::endl;
    if (opp == '/')
        std::cout << a / b << std::endl;
}
