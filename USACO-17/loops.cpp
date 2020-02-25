#include <iostream>

int main()
{
    {
        // a-z
        char letter = 'a';
        while (letter <= 'z')
        {
            std::cout << letter << ' ';
            letter++;
        }

        std::cout << "\n\n";
    }
    {
        // 54321-1
        short i = 5;
        while (i > 0)
        {
            short j = 5;
            while (j >= i)
            {
                std::cout << j << " ";
                j--;
            }
            std::cout << '\n';
            i--;
        }

        std::cout << '\n';
    }
    {
        // 54321-1
        short i = 1;
        while (i <= 5)
        {
            short j = 5;
            while (j > 0)
            {
                std::cout << static_cast<char>(j <= i ? j + 48 : ' ') << " ";
                j--;
            }
            std::cout << '\n';
            i++;
        }

        std::cout << '\n';
    }
}
