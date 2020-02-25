/*
ID: 11athom1
PROG: transform
LANG: C++
*/

#include <fstream>
// #include <iostream>#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

void rot(char ans[10][10], char grid[10][10], int n)
{
    // char new[10][10];

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            // 0 0 -> 2 0
            // 1 0 -> 2 1
            // 0 0 <- 0 2
            // 0 1 <- 1 2
            // 0 2 <- 2 2
            // 1 0 <- 0 1
            // 1 1 <- 1 1
            // 1 2 <- 2 1
            ans[n - y - 1][x] = grid[x][y];
        }
    }

    // return new;
}

void flip(char ans[10][10], char grid[10][10], int n)
{
    // char new[10][10]

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            // 0 0 -> 2 0
            // 0 1 -> 2 1
            // 0 2 -> 2 2
            // 1 0 -> 1 0
            // 1 1 -> 1 1
            // 1 2 -> 1 2
            ans[n - x - 1][y] = grid[x][y];
        }
    }

    // return new;
}

bool grideq(char a[10][10], char b[10][10], int n)
{
    // cout << "\n";
    // cout << "\n";
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            // cout << a[x][y] << b[x][y];
            if (a[x][y] != b[x][y])
            {
                return 0;
                // ;
            }
        }
        // cout << "\n";
    }
    return 1;
}


int main()
{
    ifstream fin("transform.in");
    ofstream fout("transform.out");

    int n;
    fin >> n;

    char before[10][10];
    char after[10][10];

    // cout << 1;
    // cout << n;

    for (int y = 0; y < n; y++)
    {
        // cout << 2;
        for (int x = 0; x < n; x++)
        {

            char state;
            fin >> state;
            // cout << state;
            before[x][y] = state;
        }
        // char temp;
        // fin >> temp;
        // cout << "\n";
        fin.ignore(10, '\n');
    }


    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            char state;
            fin >> state;
            // cout << state;
            after[x][y] = state;
        }
        // cout << "\n";
        // char temp;
        fin.ignore(10, '\n');
        // fin >> temp
    }

    char rot1[10][10];
    rot(rot1, before, n);
    char rot2[10][10];
    rot(rot2, rot1, n);
    char rot3[10][10];
    rot(rot3, rot2, n);
    char flip1[10][10];
    flip(flip1, before, n);
    char flip2[10][10];
    rot(flip2, flip1, n);
    char flip3[10][10];
    rot(flip3, flip2, n);
    char flip4[10][10];
    rot(flip4, flip3, n);

    if (grideq(after, rot1, n))
    {
        fout << "1\n";
    }
    else if (grideq(after, rot2, n))
    {
        fout << "2\n";
    }
    else if (grideq(after, rot3, n))
    {
        fout << "3\n";
    }
    else if (grideq(after, flip1, n))
    {
        fout << "4\n";
    }
    else if (grideq(after, flip2, n) || grideq(after, flip3, n) || grideq(after, flip4, n))
    {
        fout << "5\n";
    }
    else if (grideq(after, before, n))
    {
        fout << "6\n";
    }
    else
    {
        fout << "7\n";
    }

    return 0;
}
