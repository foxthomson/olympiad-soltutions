/*
ID: 11athom1
PROG: subset
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int n, totto;

int ripple(int addto, int lessthan)
{
    // finds the number of pairs that add to addto and are less than lessthan
    if (addto % 2)
    {
        int mid = addto / 2;
        int lower = mid - 1;
        int upper = lessthan - mid - 1;
        if (upper < 0 || lower < 0)
        {
            return 0;
        }
        else
        {
            return (lower < upper) ? lower : upper;
        }
    }
    else
    {
        int midminushalf = addto / 2;
        int lower = midminushalf;
        int upper = lessthan - midminushalf - 1;
        if (upper < 0 || lower < 0)
        {
            return 0;
        }
        else
        {
            return (lower < upper) ? lower : upper;
        }
    }
}

int dfs(int currsum, int newint)
{
    if (totto - currsum - newint <= 2)
    {
        // cannot ripple if diff is less than 3
        return 0;
    }
    else
    {
        int ans = ripple(totto - currsum - newint, newint);
        for (int search = newint - 1; search > 0; search--)
        {
            ans += dfs(currsum+newint, search);
        }
        return ans;
    }
}

int main()
{
    ifstream fin("subset.in");
    ofstream fout("subset.out");

    fin >> n;

    if (((n*n + n) / 2) % 2 == 0)
    {
        totto = (n*n + n) / 4;

        cout << dfs(0, n);
    }
    else
    {
        fout << 0 << endl;
    }

    return 0;
}
