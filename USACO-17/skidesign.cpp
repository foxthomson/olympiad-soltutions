/*
ID: 11athom1
PROG: skidesign
LANG: C++11
*/

#include <fstream>
#include <iostream>
// #include <stdlib>

using namespace std;

int main()
{
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");

    // input
    int n;
    fin >> n;

    int hills[1000];

    for (int i = 0; i < n; i++)
    {
        int height;
        fin >> height;
        hills[i] = height;
    }

    // main

    int mincost = -1;

    for (int lb = 0; lb <= 83; lb++)
    {
        int ub = lb + 17;

        int cost = 0;

        // iterate though each hill for a selected range
        for (int i = 0; i < n; i++)
        {
            // add cost of changing hill to total
            if (hills[i] < lb)
            {
                cost += (lb-hills[i]) * (lb-hills[i]);
                // cout << hills[i] << " " << i << " " << lb << " "
            }
            else if (hills[i] > ub)
            {
                cost += (hills[i]-ub) * (hills[i]-ub);
            }
        }

        // update mincost
        if (mincost == -1 || cost < mincost)
        {
            // cout << lb << " " << cost << endl;
            mincost = cost;
        }
    }

    // output
    fout << mincost << endl;

    return 0;
}
