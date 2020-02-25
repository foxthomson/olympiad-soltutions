/*
ID: 11athom1
PROG: ariprog
LANG: C++
*/

#include <fstream>
// #include <iostre\zam>
#include <algorithm>

using namespace std;

// bool issquare(int a)
// {
//     // quick find if sqrt is int
//     int odd = 1;
//     // int count = 1;
//     while (a > 0)
//     {
//         // count++;
//         a -= odd;
//         odd += 2;
//     }
//     return (a == 0);
// }

struct Prog
{
    int a;
    int b;
};

int comp_progs(Prog a, Prog b)
{
    return a.b < b.b;
}

int main()
{
    // cout << 1;
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    int n, m;
    fin >> n >> m;

    int max = 2*m*m; // the maximum number in a progression
    // int maxb = max/(n-1); // the maximum b posible
    // int maxa = max - (n-1);

    int numprogs = 0;
    Prog progs[10000];

    int dss[31626];
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
    // cout << numdss;
    int *enddss = dss + numdss;
    sort(dss, enddss);


    // interates though each a and b
    for (int a = 0; a <= max - (n-1); a++)
    {
        // cout << a << " " << b << ":\n";

        // check if a is a dual square (optimization)
        // bool adualsquare = 0;
        // for (int p = 0; p <= a; p++)
        // {
        //     // q must be square, q = term - p*p
        //     // cout << " " << term << " = " << p*p << " + " << term - p*p << endl;
        //     if (issquare(a - p*p) && a - p*p <= m*m && p*p <= m*m)
        //     {
        //         adualsquare = 1;
        //         break;
        //     }
        // }
        if (!binary_search(dss, enddss, a))
        {
            continue;
        }

        // int maxb = (max - a) / (n - 1);

        for (int b = 1; b <= (max - a) / (n - 1); b++)
        {
            bool ariprog = 1; // is a valid solution
            int maxa = max - b*(n-1);

            // iterates though each term
            // cout << a << " " << b << endl;
            for (int bmult = 1; bmult < n; bmult++)
            {
                // bool dualsquare = 0;
                // int term = a + b*bmult;

                // each posible p
                // cout << a << " + " << b << " * " << bmult << " = " << term;
                // for (int p = 0; p <= term; p++)
                // {
                //     // q must be square, q = term - p*p
                //     // cout << "\n " << term << " = " << p*p << " + " << term - p*p;
                //     if (issquare(term - p*p) && term - p*p <= m*m && p*p <= m*m)
                //     // if (binary_search(dss, dss+numdss, p*p + q*q))
                //     {
                //         dualsquare = 1;
                //         break;
                //     }
                //     if (term - p*p < 0)
                //     {
                //         break;
                //     }
                // }

                // not valid
                if (!binary_search(dss, enddss, a + b*bmult))
                {
                    ariprog = 0;
                    // cout << " not valid";
                    break;
                }
                // cout << endl;
            }

            // valid
            if (ariprog)
            {
                // none = 0;
                Prog newprog;
                newprog.a = a;
                newprog.b = b;
                progs[numprogs] = newprog;
                numprogs++;
                // cout << a << " " << b << endl;
            }
        }
    }

    // cout << issquare(0) << issquare(1) << issquare(4) << issquare(5) << issquare(25) << issquare(88) << endl;
    if (numprogs == 0)
    {
        fout << "NONE\n";
    }
    else
    {
        sort(progs, progs + numprogs, comp_progs);
        for (int i = 0; i < numprogs; i++)
        {
            fout << progs[i].a << " " << progs[i].b << endl;
        }
    }

    return 0;
}
