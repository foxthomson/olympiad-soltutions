/*
ID: 11athom1
PROG: preface
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int numI = 0;
int numV = 0;
int numX = 0;
int numL = 0;
int numC = 0;
int numD = 0;
int numM = 0;

int addnum(int n)
{
    // units
    switch (n%10)
    {
        case (1):
            numI += 1;
            break;
        case (2):
            numI += 2;
            break;
        case (3):
            numI += 3;
            break;
        case (4):
            numI += 1;
            numV += 1;
            break;
        case (5):
            numV += 1;
            break;
        case (6):
            numI += 1;
            numV += 1;
            break;
        case (7):
            numI += 2;
            numV += 1;
            break;
        case (8):
            numI += 3;
            numV += 1;
            break;
        case (9):
            numI += 1;
            numX += 1;
            break;
    }

    // tens
    switch ((n/10)%10)
    {
        case (1):
            numX += 1;
            break;
        case (2):
            numX += 2;
            break;
        case (3):
            numX += 3;
            break;
        case (4):
            numX += 1;
            numL += 1;
            break;
        case (5):
            numL += 1;
            break;
        case (6):
            numX += 1;
            numL += 1;
            break;
        case (7):
            numX += 2;
            numL += 1;
            break;
        case (8):
            numX += 3;
            numL += 1;
            break;
        case (9):
            numX += 1;
            numC += 1;
            break;
    }

    // hundreds
    switch ((n/100)%10)
    {
        case (1):
            numC += 1;
            break;
        case (2):
            numC += 2;
            break;
        case (3):
            numC += 3;
            break;
        case (4):
            numC += 1;
            numD += 1;
            break;
        case (5):
            numD += 1;
            break;
        case (6):
            numC += 1;
            numD += 1;
            break;
        case (7):
            numC += 2;
            numD += 1;
            break;
        case (8):
            numC += 3;
            numD += 1;
            break;
        case (9):
            numC += 1;
            numM += 1;
            break;
    }

    // thousands
    switch ((n/1000)%10)
    {
        case (1):
            numM += 1;
            break;
        case (2):
            numM += 2;
            break;
        case (3):
            numM += 3;
            break;
    }
}

int main()
{
    // init
    ifstream fin("preface.in");
    ofstream fout("preface.out");

    // inp
    int n;
    fin >> n;

    // itterate for all values
    for (int i = 1; i <= n; i++)
    {
        addnum(i);
    }

    // output
    fout << "I " << numI << endl;
    if (numM == 0)
    {
        if (numD == 0)
        {
            if (numC == 0)
            {
                if (numL == 0)
                {
                    if (numX == 0)
                    {
                        if (numV == 0)
                        {
                            ;
                        }
                        else
                        {
                            fout << "V " << numV << endl;
                        }
                    }
                    else
                    {
                        fout << "V " << numV << endl
                             << "X " << numX << endl;
                    }
                }
                else
                {
                    fout << "V " << numV << endl
                         << "X " << numX << endl
                         << "L " << numL << endl;
                }
            }
            else
            {
                fout << "V " << numV << endl
                     << "X " << numX << endl
                     << "L " << numL << endl
                     << "C " << numC << endl;
            }
        }
        else
        {
            fout << "V " << numV << endl
                 << "X " << numX << endl
                 << "L " << numL << endl
                 << "C " << numC << endl
                 << "D " << numD << endl;
        }
    }
    else
    {
        fout << "V " << numV << endl
             << "X " << numX << endl
             << "L " << numL << endl
             << "C " << numC << endl
             << "D " << numD << endl
             << "M " << numM << endl;
    }

    // addnum(1234);
    // fout << numI << numV << numX << numL << numC << numD << numM << endl;

    return 0;
}
