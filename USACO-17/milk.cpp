/*
ID: 11athom1
PROG: milk
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("milk.in");
    ofstream fout("milk.out");

    int n, m;
    fin >> n >> m;

    int cost[5000], capacity[5000];

    for (int i = 0; i < m; i++)
    {
        int a, b;
        fin >> a >> b;
        cost[i] = a;
        capacity[i] = b;
    }

    int totcost = 0;

    while (n > 0)
    {
        int min = 1000;
        int minpoint = 0;
        for (int i = 0; i < m; i++)
        {
            if (capacity[i] > 0)
            {
                if (cost[i] < min)
                {
                    min = cost[i];
                    minpoint = i;
                }
            }
        }


        if (capacity[minpoint] > n)
        {
            totcost += n * cost[minpoint];
            n = 0;
        }
        else
        {
            totcost += capacity[minpoint] * cost[minpoint];
            // cout << minpoint << capacity[minpoint] * cost[minpoint] << endl;
            n -= capacity[minpoint];
            capacity[minpoint] = 0;
        }
    }

    fout << totcost << endl;

    return 0;
}
