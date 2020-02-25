#include <iostream>
// #include "random.h"
#include <cstdlib>
#include <ctime>

void initRand()
{
    srand(static_cast<unsigned int>(time(0)));
}

int randint(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

// void initRand();
// int randint(int min, int max);

int main()
{
    initRand();

    char inp = 'y';

    do {
        if (inp == 'y')
        {
            std::cout << "Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.\n";

            short num = randint(1, 100);
            // short num = 50;
            short userguess;

            for (short guesses = 1; guesses < 8; guesses++)
            {
                std::cout << "Guess #" << guesses << ": ";
                std::cin >> userguess;
                std::cin.ignore(32767, '\n');

                if (userguess < num)
                {
                    std::cout << "Your guess is too low.\n";
                }
                else if (userguess > num)
                {
                    std::cout << "Your guess is too high.\n";
                }
                else
                {
                    std::cout << "Correct! You win!\n";
                    break;
                }
            }
        }

        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> inp;
        std::cin.ignore(32767, '\n');

    } while (inp != 'n');

    return 0;
}
