/*
ID: 11athom1
PROG: money
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

// long long ans = 0;

int v, n;

int coins[25];

long long answers[10000][25];

int dp_ans(int make, int limit)
{
    // cout << make << endl;
    if (make == 0)
    {
        // base case
        return 1;
    }

    if (answers[make][limit] != -1)
    {
        // answer already solved
        return answers[make];
    }

    long long ans = 0;

    // check each coin value
    for (int i = 0; i < limit; i++)
    {
        if (make - coins[i] >= 0)
        {
            // valid coin
            ans += dp_ans(make - coins[i]);
        }
    }

    answers[make] = ans;
    return ans;
}

int main()
{
    ifstream fin("money.in");
    ofstream fout("money.out");

    fin >> v >> n;

    // inp
    for (int i = 0; i < v; i++)
    {
        fin >> coins[i];
    }

    // set answers to -1
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            answers[i][j] = -1;
        }
    }

    cout << dp_ans(n, v) << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << answers[i] << endl;
    // }

    return 0;
}
