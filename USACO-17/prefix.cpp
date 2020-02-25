/*
ID: 11athom1
PROG: prefix
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

// stores indexes which work and needs to be checked
queue<int> checkindex;
int numqueued = 0;

// stores points which have been queued
bool queued[2000000];

// keeps track of the largest index reached
int best = 0;

// stores seq to find prefix
string seq;

// stores primitaves
string prim[200];
int numprim = 0;

// stores indexes of primitaves begining with a letter
int primbyfirst[26][200];
int numprimbyfirst[26];
// letter - 'A'

// stores length of primitives
int lenprim[200];

int main()
{
    // init
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");

    // input
    string inp;
    while (1)
    {
        fin >> inp;
        if (inp == ".")
        {
            break;
        }
        // cout << inp << endl;

        // add to prim
        prim[numprim] = inp;

        // add to primbyfirst
        primbyfirst[inp[0] - 'A'][numprimbyfirst[inp[0] - 'A']] = numprim;
        numprimbyfirst[inp[0] - 'A']++;

        // add to lenprim
        lenprim[numprim] = inp.length();

        // cout << numprim << endl;

        numprim++;
    }

    // cout << numprim << endl;

    // inp seq
    fin >> seq;
    while (!fin.eof())
    {
        string temp;
        fin >> temp;
        seq += temp;
    }

    // cout << queued[0] << queued[19999] << queued[200000] << queued[100] << queued[10];
    queued[0] = 1;
    checkindex.push(0);
    numqueued++;

    while (numqueued > 0)
    {
        int consider = checkindex.front();
        checkindex.pop();
        numqueued--;
        // cerr << consider << endl;

        int first = seq[consider] - 'A';
        // cout << first << seq[consider] << endl;
        // cout << seq;
        for (int i = 0; i < numprimbyfirst[first]; i++)
        {
            // cout << prim[primbyfirst[first][i]] << primbyfirst[first][i] << endl;

            // check if fits

            // check if prefixing
            bool works = 1;
            for (int add = 1; add < lenprim[primbyfirst[first][i]]; add++)
            {
                if (seq[consider + add] != prim[primbyfirst[first][i]][add])
                {
                    works = 0;
                    break;
                }
            }

            if (works && !queued[consider + lenprim[primbyfirst[first][i]]])
            {
                // check if best
                if (consider + lenprim[primbyfirst[first][i]] > best)
                {
                    best = consider + lenprim[primbyfirst[first][i]];
                }

                queued[consider + lenprim[primbyfirst[first][i]]] = 1;
                checkindex.push(consider + lenprim[primbyfirst[first][i]]);
                numqueued++;
            }
        }
    }

    // output
    fout << best << endl;
    cout << best << endl;

    return 0;
}
