/*
ID: 11athom1
PROG: barn1
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <algorithm>
// #include <stdlib.h>

using namespace std;

int main()
{
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");

    int m, s, c;
    fin >> m >> s >> c;

    int cows[200];

    for (int i = 0; i < c; i++)
    {
        int cowid;
        fin >> cowid;
        cows[i] = cowid;
    }

    sort(cows, cows+c);

    s -= s - cows[c-1];
    s -= cows[0] - 1;

    int gaps[200];

    for (int i = 0; i < c-1; i++)
    {
        // cout << cows[i+1] << " " << cows[i] << endl;
        gaps[i] = cows[i+1] - cows[i] - 1;
    }

    sort(gaps, gaps+c-1);
    reverse(gaps, gaps+c-1);

    if (c > m)
    {
        for (int i = 0; i < m-1; i++)
        {
            // cout << gaps[i] << endl;
            s -= gaps[i];
        }
    }
    else
    {
        s = c;
    }

    fout << s << endl;

    return 0;
}
