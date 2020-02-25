/*
ID: 11athom1
PROG: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int dualsquaresdoubled[31626];
int numdssd = 0;
int dualsquares[21047];
int numdss = 0;
int n, m;

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
        if (!binary_search(dualsquares, dualsquares + numdss, a + bmult*b))
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

    for (int p = 0; p <= m; p++)
        for (int q = p; q <= m; q++)
        {
            dualsquaresdoubled[numdssd] = p*p + q*q;
            numdssd++;
        }
    sort(dualsquaresdoubled, dualsquaresdoubled+numdssd);

    int last = -1;
    for (int i = 0; i < numdssd; i++)
    {
        if (dualsquaresdoubled[i] != last)
        {
            dualsquares[numdss] = dualsquaresdoubled[i];
            numdss++;
            last = dualsquaresdoubled[i];
        }
    }

    // cout << "dss finished\n";
    Ariprog temp;

    for (int ai = 0; ai < numdss; ai++)
    {
        // int a = dualsquares[ai];
        // for (int b = 1; b <= (m*m*2 - a) / (n - 1); b++)
        for (int t2i = ai+1; t2i < numdss; t2i++)
        {
            if (ariprog(dualsquares[ai], dualsquares[t2i] - dualsquares[ai]))
            {
                temp.a = dualsquares[ai];
                temp.b = dualsquares[t2i] - dualsquares[ai];
                answers[numanswers] = temp;
                numanswers++;
            }
        }
        // cout << "a finished\n";
    }

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
