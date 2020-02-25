/*
ID: 11athom1
PROG: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
// #include <assert.h>

using namespace std;

// int maxds = 2*250*250 + 1;
bool dualsquarehash[2*250*250];
int n, m;
set<int> dualsquaresset;

struct Ariprog
{
    int a;
    int b;
};

Ariprog answers[10000];
int numanswers = 0;

bool ariprog(int a, int b)
{
    for (int bmult = 2; bmult < n; bmult++)
    {
        if (a + b*bmult >= 2*250*250 || !dualsquarehash[a + b*bmult])
        {
            return 0;
        }
    }
    return 1;
}

bool comp_progs(Ariprog a, Ariprog b)
{
    return a.b < b.b;
}

int main()
{
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    fin >> n >> m;

    // cerr << "input";

    int numdss = 0;
    // if (n == 21)
    //     cerr << dualsquaresset.max_size();
    for (int p = 0; p <= m; p++)
        for (int q = p; q <= m; q++)
        {
            // assert (p*p + q*q < maxds);
            dualsquarehash[p*p + q*q] = 1;

            // if (n == 21)
                // cerr << q << " " << q << endl;
                // cerr << dualsquaresset.max_size();
            dualsquaresset.insert(p*p + q*q);
            numdss++;
            // cout <<p*p + q*q << endl;
        }
    // if (n == 21)
            // cerr << dualsquaresset.max_size();
    // cout << numdss;
    // cerr << "hashed";

    set<int>::iterator ait = dualsquaresset.begin();

    int length = dualsquaresset.size();
    // cout << length << endl;

    Ariprog temp;

    for (int ai = 0; ai < length; ai++)
    {
        int a = *ait;
        // cout << a;

        set<int>::iterator a2it = ait;
        a2it++;
        for (int a2i = ai + 1; a2i < length; a2i++)
        {
            int b = *a2it - a;


            // cerr << a << " " << b << endl;
            if (a + b*(n-1) > 2*m*m)
            {
                // cerr << a + b*(n-1) << " " << a << " " << b << endl;
                break;
            }

            if (ariprog(a, b))
            {
                // if (n == 21)
                // cerr << a2i;
                temp.a = a;
                temp.b = b;
                answers[numanswers] = temp;
                numanswers++;
            }

            a2it++;
        }

        ait++;
    }
    // cout << numanswers;

    cerr << "calculated";

    if (numanswers == 0)
    {
        fout << "NONE\n";
    }
    else
    {
        sort(answers, answers + numanswers, comp_progs);
        for (int i = 0; i < numanswers; i++)
        {
            fout << answers[i].a << " " << answers[i].b << endl;
        }
    }

    return 0;
}
