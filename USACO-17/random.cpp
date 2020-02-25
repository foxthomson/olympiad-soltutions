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
