/*
ID: 11athom1
PROB: frac1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

// // 1-indexed
// bool frachash[33][33];

using namespace std;

struct frac
{
    int a;
    int b;
};

frac fractions[160*160];
int totfracs = 0;

bool cmpfrac(frac x, frac y)
{
    return x.a*y.b < y.a*x.b;
}

bool simplified(int a, int b)
{
    for (int factor = 2; factor <= a; factor++)
    {
        if (a%factor == 0 && b%factor == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");

    fout << "0/1" << endl;

    int n;
    fin >> n;

    for (int b = 1; b <= n; b++)
    {
        for (int a = 1; a <= b; a++)
        {
            if (simplified(a, b))
            {
                // insert
                // frac temp;
                // temp.a = a;
                // temp.b = b;
                fractions[totfracs].a = a;
                fractions[totfracs].b = b;
                // cout << a << b << endl;
                totfracs++;
            }
        }
    }

    // sort
    sort(fractions, fractions + totfracs, cmpfrac);

    for (int i = 0; i < totfracs; i++)
    {
        fout << fractions[i].a << "/" << fractions[i].b << endl;
    }

    return 0;
}
