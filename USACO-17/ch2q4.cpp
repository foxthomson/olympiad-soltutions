#include <iostream>
#include "constants.h"

double distanceFallen(int t)
{
    return constants::g * t * t / 2;
}

void outputHeight(double s, int t)
{
    double distance = s - distanceFallen(t);

    std::cout << "At " << t << " seconds, the ball is ";

    if (distance > 0)
        std::cout << distance << "m above the ground" << std::endl;
    else
        std::cout << "on the ground" << std::endl;
}

int main()
{
    double s;
    std::cout << "Input initial height: ";
    std::cin >> s;

    outputHeight(s, 0);
    outputHeight(s, 1);
    outputHeight(s, 2);
    outputHeight(s, 3);
    outputHeight(s, 4);
    outputHeight(s, 5);
}
