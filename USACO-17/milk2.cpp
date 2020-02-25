/*
ID: 11athom1
PROG: milk2
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    int n;
    fin >> n;

    int groups = n;

    int schedule[5000][2];

    int maxmilk = 0;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        //    <     >
        fin >> start;
        fin >> end;

        cout << end << start << "\n";

        for (int j = 0; j < i; j++)
        {
            // cout << i-j << "\n";
            int start2 = schedule[j][0];
            int end2 = schedule[j][1];
            //    [     ]

            if (start <= end2 && start >= start2)
            {
                // [  <  ]
                if (end <= end2)
                {
                    // [  <  >  ]
                    schedule[j][0] = -1;
                    schedule[j][1] = -1;
                    start = start2;
                    end = end2;
                    groups--;
                    // <        >
                }
                else
                {
                    // [  <  ]  >
                    schedule[j][0] = -1;
                    schedule[j][1] = -1;
                    start = start2;
                    groups--;
                    // <        >
                }
            }
            else if (start < end2)
            {
                // <   [   ]
                if (end < start2)
                {
                    // <  >  [  ]
                    ;
                }
                else if (end <= end2)
                {
                    // <  [  >  ]
                    schedule[j][0] = -1;
                    schedule[j][1] = -1;
                    end = end2;
                    groups--;
                    // <        >
                }
                else
                {
                    // <  [  ]  >
                    schedule[j][0] = -1;
                    schedule[j][1] = -1;
                    groups--;
                    // <        >
                }
            }
            // else
            // {
            //     // [   ]  <
            // }

            // schedule[i][0] =

            // if (start >= schedule[j][1])
            // {
            //     start = schedule[j][0];
            //     schedule[j][0] = -1;
            //     schedule[j][1] = -1;
            //     groups--;
            // }
            // if (end >= schedule[j][0])
            // {
            //     end = schedule[j][1];
            //     schedule[j][0] = -1;
            //     schedule[j][1] = -1;
            //     groups--;
            // }
        }

        schedule[i][0] = start;
        schedule[i][1] = end;

        // cout << i;

        if (end - start > maxmilk)
        {
            maxmilk = end - start;
        }
        // cout << end << start << maxmilk << "\n";
    }

    int maxnomilk = 0;

    for (int i = 0; i < n; i++)
    {
        int start = schedule[i][0];
        int end = schedule[i][1];

        if (start != -1)
        {
            bool uninit = 1;
            int min = 0;
            for (int j = 0; j < n; j++)
            {
                int start2 = schedule[j][0];
                int end2 = schedule[j][1];

                if (start2 != -1 && i != j)
                {
                    if (uninit && end < start2)
                    {
                        uninit = 0;
                        min = start2 - end;
                    }
                    else if (end < start2 && start2 - end < min)
                    {
                        min = start2 - end;
                    }
                }
            }

            if (min > maxnomilk)
            {
                maxnomilk = min;
            }
        }
    }

    fout << maxmilk << " " << maxnomilk << "\n";

    return 0;
}
