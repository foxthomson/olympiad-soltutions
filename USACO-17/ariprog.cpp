/*
ID: 11athom1
PROG: ariprog
LANG: C++
*/

#include <fstream>
// #include <iostream>
#include 

using namespace std;

bool issquare(int a)
{
    // quick find if sqrt is int
    int odd = 1;
    // int count = 1;
    while (a > 0)
    {
        // count++;
        a -= odd;
        odd += 2;
    }
    return (a == 0);
}

int main()
{
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    int n, m;
    fin >> n >> m;

    int max = 2*m*m; // the maximum number in a progression
    int maxb = max/(n-1); // the maximum b posible

    bool none = 1;


    int dss[10000];
    int numdss = 0;
    for (int p = 0; p <= m; p++)
    {
        for (int q = 0; q <= p; q++)
        {
            // if (!binary_search(dss, dss+numdss, p*p + q*q))
            // {
            //
            // }
            dss[numdss] = p*p + q*q;
            numdss++;
        }
    }
    sort(dss, dss+numdss);

    // interates though each a and b
    for (int b = 1; b <= maxb; b++)
    {
        int maxa = max - b*(n-1);
        for (int a = 0; a <= maxa; a++)
        {
            bool ariprog = 1; // is a valid solution
            // cout << a << " " << b << ":\n";

            // check if a is a dual square (optimization)
            bool adualsquare = 0;
            for (int p = 0; p <= a; p++)
            {
                // q must be square, q = term - p*p
                // cout << " " << term << " = " << p*p << " + " << term - p*p << endl;
                if (issquare(a - p*p) && a - p*p <= m*m && p*p <= m*m)
                {
                    adualsquare = 1;
                    break;
                }
            }
            if (!adualsquare)
            {
                continue;
            }

            // iterates though each term
            for (int bmult = 1; bmult < n; bmult++)
            {
                bool dualsquare = 0;
                int term = a + b*bmult;

                // each posible p
                for (int p = 0; p <= term; p++)
                {
                    // q must be square, q = term - p*p
                    // cout << " " << term << " = " << p*p << " + " << term - p*p << endl;
                    if (issquare(term - p*p) && term - p*p <= m*m && p*p <= m*m)
                    {
                        dualsquare = 1;
                        break;
                    }
                }

                // not valid
                if (!dualsquare)
                {
                    ariprog = 0;
                    // cout << "not valid";
                    break;
                }
            }
            // cout << endl;

            // valid
            if (ariprog)
            {
                none = 0;
                fout << a << " " << b << endl;
            }
        }
    }

    // cout << issquare(0) << issquare(1) << issquare(4) << issquare(5) << issquare(25) << issquare(88) << endl;
    if (none)
    {
        fout << "NONE\n";
    }

    return 0;
}
