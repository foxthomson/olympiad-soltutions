/*
ID: 11athom1
PROG: combo
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

int rotmod(int n, int m)
{
    if (n <= 0)
    {
        return rotmod(m+n, m);
    }
    if (n >= m + 1)
    {
        return rotmod(n-m, m);
    }
    return n;
}

int main()
{
    ifstream fin("combo.in");
    ofstream fout("combo.out");

    int n;
    fin >> n;

    int a, b, c, d, e, f;
    fin >> a >> b >> c >> d >> e >> f;

    // int tot = 250;



    if (n < 5)
    {
        // max = n*n*n;
        // for (int rotor = 0; rotor < 3; rotor++)
        // {
        //     for (int fkey = 1; fkey <= n+1; fkey++)
        //     {
        //         for (int masteradd = -2; masteradd < 3; masteradd++)
        //         {
        //             if (rotmod(farmer[rotor] + farmeradd, n) == rotmod(master[rotor] + masteradd, n))
        //             {
        //                 overlap[rotor]++;
        //                 break;
        //             }
        //         }
        //     }
        // }
        fout << n*n*n << endl;
    }
    else
    {
        int farmer[3] = {a, b, c};
        int master[3] = {d, e, f};
        int overlap[3] = {0, 0, 0};

        // max = 250;

        for (int rotor = 0; rotor < 3; rotor++)
        {
            for (int farmeradd = -2; farmeradd < 3; farmeradd++)
            {
                for (int masteradd = -2; masteradd < 3; masteradd++)
                {
                    if (rotmod(farmer[rotor] + farmeradd, n) == rotmod(master[rotor] + masteradd, n))
                    {
                        overlap[rotor]++;
                        break;
                    }
                }
            }
        }

        fout << 250 - overlap[0]*overlap[1]*overlap[2] << endl;
    }


    return 0;
}
