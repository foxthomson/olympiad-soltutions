/*
ID: 11athom1
PROG: numtri
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");

    int r;
    fin >> r;

    int prevrow[1000];
    int currrow[1000];

    fin >> prevrow[0];

    for (int row = 1; row < r; row++)
    {
        for (int column = 0; column <= row; column++)
        {
            // input num
            int curr;
            fin >> curr;

            // handle edges
            if (column == 0)
            {
                // input to currrow
                currrow[0] = curr + prevrow[0];
            }
            else if (column == row)
            {
                // input to currrow
                currrow[column] = curr + prevrow[column - 1];
            }
            else
            {
                // work out max
                int best = ((prevrow[column] > prevrow[column - 1]) ? prevrow[column] : prevrow[column - 1]) + curr;

                // input to currrow
                currrow[column] = best;
            }
        }

        // copy currrow to prevrow
        copy(currrow, currrow + row + 1, prevrow);
    }

    // output max of prevrow
    fout << *max_element(prevrow, prevrow + r) << endl;
}
