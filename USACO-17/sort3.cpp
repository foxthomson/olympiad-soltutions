/*
ID: 11athom1
PROG: sort3
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int tot1 = 0;
int tot2 = 0;
int tot3 = 0;

int tot2in1 = 0;
int tot3in1 = 0;
int tot1in2 = 0;
int tot3in2 = 0;
int tot1in3 = 0;
int tot2in3 = 0;

int n;

int list[1000];

int main()
{
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");

    fin >> n;
    // cout << n;

    for (int i = 0; i < n; i++)
    {
        int inp;
        fin >> inp;

        switch (inp)
        {
            case 1:
                tot1++;
                // cout << 1;
                break;
            case 2:
                tot2++;
                // cout << 2;
                break;
            case 3:
                tot3++;
                // cout << 3;
                break;
        }

        list[i] = inp;
    }

    for (int i = 0; i < tot1; i++)
    {
        switch (list[i])
        {
            case 2:
                tot2in1++;
                break;
            case 3:
                tot3in1++;
                break;
        }
    }

    for (int i = tot1; i < tot1 + tot2; i++)
    {
        // cout << list[i];
        switch (list[i])
        {
            case 1:
                tot1in2++;
                break;
            case 3:
                tot3in2++;
                break;
        }
    }

    for (int i = tot1 + tot2; i < n; i++)
    {
        switch (list[i])
        {
            case 1:
                tot1in3++;
                break;
            case 2:
                tot2in3++;
                break;
        }
    }

    // cout << endl << tot1 << endl << tot2 << endl << tot3 << endl;
    // cout << tot2in1 << endl;
    // cout << tot3in1 << endl;
    // cout << tot1in2 << endl;
    // cout << tot3in2 << endl;
    // cout << tot1in3 << endl;
    // cout << tot2in3 << endl;

    int ans = 0;

    if (tot2in3 < tot3in2)
    {
        ans += tot2in3;
        tot3in2 -= tot2in3;
        tot2in3 = 0;
    }
    else
    {
        ans += tot3in2;
        tot2in3 -= tot3in2;
        tot3in2 = 0;
    }
    // cout << ans << endl;

    if (tot1in3 < tot3in1)
    {
        ans += tot1in3;
        tot3in1 -= tot1in3;
        tot1in3 = 0;
    }
    else
    {
        ans += tot3in1;
        tot1in3 -= tot3in1;
        tot3in1 = 0;
    }
    // cout << ans << endl;

    if (tot2in1 < tot1in2)
    {
        ans += tot2in1;
        tot1in2 -= tot2in1;
        tot2in1 = 0;
    }
    else
    {
        ans += tot1in2;
        tot2in1 -= tot1in2;
        tot1in2 = 0;
    }
    // cout << ans << endl;

    ans += (tot2in1 + tot3in1) * 2;

    fout << ans << endl;

    return 0;
}
