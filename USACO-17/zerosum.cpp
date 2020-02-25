/*
ID: 11athom1
PROG: zerosum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream fout("zerosum.out");

void output(int n, int curr, int prev, int currsum, string opperations, bool lastpos)
{
    if (curr == n + 1)
    {
        // reached the end
        if (currsum == 0)
        {
            // ans works
            for (int i = 0; i < n-1; i++)
            {
                fout << i + 1 << opperations[i];
            }
            fout << n << endl;
        }
    }
    else
    {
        // cout << curr << prev << endl;

        // blanks
        output(n, curr + 1, prev*10 + (lastpos ? curr : -curr), currsum - prev + (prev*10 + (lastpos ? curr : -curr)), opperations + ' ', lastpos);

        // +
        output(n, curr + 1, curr, currsum + curr, opperations + '+', 1);

        // -
        output(n, curr + 1, -curr, currsum - curr, opperations + '-', 0);
    }
}

int main()
{
    ifstream fin("zerosum.in");

    int n;
    fin >> n;

    output(n, 2, 1, 1, "", 1);

    return 0;
}
