/*
ID: 11athom1
PROG: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int answers[20];
int numanswers = 0;
int amax, bmax, cmax;
int as[8000] = {21}, bs[8000] = {21}, cs[8000] = {21};
int pointcount = 0;

// struct Buckets
// {
//
// }

bool pointused(int a, int b, int c)
{
    // check if point has been visited
    if (a == 0)
    {
        for (int i = 0; i < numanswers; i++)
            if (answers[i] == c)
                return 1;
    }
    else
    {
        for (int i = 0; i < pointcount; i++)
            if (as[i] == a && bs[i] == b && cs[i] == c)
                return 1;
    }

    return 0;
}

void solve(int a, int b, int c)
{
    if (a < 0 || b < 0 || c < 0 || a + b + c != cmax)
    {
        cout << a << b << c << endl;
        exit(1);
    }
    if (!pointused(a, b, c))
    {
        // cout << "   " << a << b << c << endl;
        // cout << "{\n";
        // add point to point lists
        as[pointcount] = a;
        bs[pointcount] = b;
        cs[pointcount] = c;
        pointcount++;

        // int diff;

        if (a == 0)
        {
            // cout << "a0{\n";
            answers[numanswers] = c;
            numanswers++;

            // add b to a
            if (b > amax)
            {
                solve(amax, b - amax, c);
            }
            else
            {
                solve(b, 0, c);
            }

            // add c to a
            if (c > amax)
            {
                solve(amax, b, c - amax);
            }
            else
            {
                solve(c, b, 0);
            }

            // add c to b
            solve(0, bmax, cmax - bmax);

            // don't need to add b to c as first case
        }
        else if (c == 0)
        {
            // cout << "c0{\n";
            // b to c
            solve(a, 0, b);

            // a to c
            solve(0, b, a);

            // b to a
            if (b + a > amax)
            {
                // solve(0, a + b, 0);
                solve(amax, a + b - amax, 0);
            }
            else
            {
                solve(a + b, 0, 0);
            }

            // a to b
            if (b + a > bmax)
            {
                // solve(0, a + b, 0);
                solve(a + b - bmax, bmax, 0);
            }
            else
            {
                solve(0, a + b, 0);
            }
        }
        else if (c == cmax)
        {
            // cout << "cmax{\n";
            // c to b
            solve(0, bmax, cmax - (bmax - b));

            // c to a
            solve(amax, 0, cmax - (amax - a));

            // a and b empty
        }
        else if (b == 0)
        {
            // cout << "b0{\n";
            // c to b
            if (c > bmax)
            {
                // cout << "c > bmax ";
                solve(a, bmax, c - bmax);
            }
            else
            {
                // cout << "c <= bmax ";
                solve(a, c, 0);
            }

            // a to b
            if (a > bmax)
            {
                // cout << "a > bmax ";
                solve(a - bmax, bmax, c);
            }
            else
            {
                // cout << "a <= bmax ";
                solve(0, a, c);
            }

            // a to c
            // solve(0, 0, c);

            // c to a
            // cout << "c to a ";
            solve(amax, 0, cmax - amax);
        }
        else if (a == amax)
        {
            // cout << "amax{\n";
            // a to b
            if (amax + b < bmax)
            {
                // cout << amax << bmax << b << a << endl;
                solve(0, amax + b, c);
            }
            else
            {
                solve(amax - (bmax - b), bmax, c);
            }

            // a to c
            // if (amax + c < cmax)
            // {
            //     solve(0, b, amax + c);
            // }
            // else
            // {
            //     solve(amax - (cmax - c), b, cmax);
            // }
            solve(0, b, a + c);

            // b to c
            solve(amax, 0, cmax - amax);

            // c to b
            if (b + c < bmax)
            {
                solve(amax, b + c, 0);
            }
            else
            {
                solve(amax, bmax, c - (bmax - b));
            }
        }
        else if (b == bmax)
        {
            // cout << "bmax{\n";
            // b to c
            solve(a, 0, b + c);

            // b to a
            if (bmax + a < amax)
            {
                solve(bmax + a, 0, c);
            }
            else
            {
                solve(amax, b - (amax - a), c);
            }

            // a to c
            solve(0, b, c + a);

            // c to a
            if (a + c < amax)
            {
                solve(a + c, bmax, 0);
            }
            else
            {
                solve(amax, bmax, c - (amax - a));
            }
        }
        // cout << "}\n";
    }
}

int main()
{
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");

    fin >> amax >> bmax >> cmax;
    // cout << "max: " << amax << bmax << cmax << endl;

    if (amax > cmax)
        amax = cmax;
    if (bmax > cmax)
        bmax = cmax;

    // int a = 0, b = 0, c = cmax;

    solve(0, 0, cmax);

    sort(answers, answers + numanswers);

    for (int i = 0; i < numanswers - 1; i++)
    {
        fout << answers[i] << " ";
    }
    fout << answers[numanswers-1] << endl;

    return 0;
}
