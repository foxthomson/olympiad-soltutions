/*
ID: 11athom1
PROG: sprime
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("sprime.in");
ofstream fout("sprime.out");

bool is_prime(int check)
{
    // won't be divisable by 2 or 5
    if (check%3 == 0 || check%7 == 0)
    {
        return 0;
    }

    for (int i = 11; i < check; i++)
    {
        if (check%i == 0)
        {
            return 0;
        }

        if (i*i > check)
        {
            break;
        }
    }

    return 1;
}

void solve(int n, int rib)
{
    if (n == 0)
    {
        fout << rib << endl;
    }
    else
    {
        if (is_prime(rib*10 + 1))
        {
            solve(n-1, rib*10 + 1);
        }
        if (is_prime(rib*10 + 3))
        {
            solve(n-1, rib*10 + 3);
        }
        if (is_prime(rib*10 + 7))
        {
            solve(n-1, rib*10 + 7);
        }
        if (is_prime(rib*10 + 9))
        {
            solve(n-1, rib*10 + 9);
        }
    }
}


int main()
{
    int n;
    fin >> n;

    solve(n-1, 2);
    solve(n-1, 3);
    solve(n-1, 5);
    solve(n-1, 7);

    return 0;
}
