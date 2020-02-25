/*
ID: 11athom1
PROG: subset
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int n, half;

int dfs(int prev, int add)
{
    // cout << add << "{" << endl;
    int sum = prev + add;
    if (sum == half)
    {
        // cout << "/\n";
        return 1;
    }
    if (sum > half)
    {
        // cout << "x\n";
        return 0;
    }

    int ans = 0;
    for (int search = add + 1; search <= n; search++)
    {
        ans += dfs(sum, search);
    }

    // cout << add << "}" << endl;

    return ans;
}

int main()
{
    ifstream fin("subset.in");
    ofstream fout("subset.out");

    // while (1)
    // {
    fin >> n;

    // half triangle number (sum of natual numbers)
    // half = (n*n + n) / 4;

    // fout << dfs(0, 1) << endl;
    if (((n*n + n) / 2) % 2 == 0)
    {
        half = (n*n + n) / 4;

        cout << dfs(0, 1)<< endl;
    }
    else
    {
        fout << 0 << endl;
    }
    // }
    return 0;
}
