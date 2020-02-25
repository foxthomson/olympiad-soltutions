/*
ID: 11athom1
PROG: subset
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

long long save[391][40];

long long solve(int n, int k)
{
    if (n < 0 || k < 0)
    {
        return 0;
    }
    if (n == 0 && k == 0)
    {
        return 1;
    }
    if (save[n][k] == -1)
    {
        long long ans = solve(n, k-1) + solve(n-k, k-1);
        save[n][k] = ans;
        return ans;
    }
    return save[n][k];
}

int main()
{
    ifstream fin("subset.in");
    ofstream fout("subset.out");

    for (int i = 0; i < 391; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            save[i][j] = -1;
        }
    }

    int n;
    fin >> n;

    if ((n*n + n)/2 % 2 == 0)
    {
        fout << solve((n*n + n)/4, n)/2 << endl;
    }
    else
    {
        fout << "0\n";
    }

    return 0;
}
