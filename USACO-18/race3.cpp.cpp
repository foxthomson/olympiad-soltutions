/*
ID: 11athom1
TASK: race3
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

bool course[50][50];
//bool ffsearched[50][50];
bool fffound[50][50];
bool fffound2[50][50];
bool firstcomponent[50][50];
int unavoid[50];
int numun = 0;
int unavoid2[50];
int numun2 = 0;

int main(int argc, char** argv)
{
    ifstream fin("race3.in");
    ofstream fout("race3.out");
    
    int n = -1;
    int inp;
    fin >> inp;
    while (inp != -1)
    {
        n++;
        while (inp != -2)
        {
            course[n][inp] = true;
            fin >> inp;
        }
        fin >> inp;
    }
    
//    for (int i = 0; i <= n; i++)
//    {
//        for (int j = 0; j <= n; j++)
//        {
//            cout << course[i][j];
//        }
//        cout << endl;
//    } cout << endl;
    
    for (int i = 1; i < n; i++)
    {
        queue<int> tosearch;
        tosearch.push(0);
        fffound[i][0] = true;
        bool unavoidable = true;
        while (!tosearch.empty())
        {
            int searchme = tosearch.front();
            tosearch.pop();
//            ffsearched[i][searchme];
            for (int j = 0; j <= n; j++)
            {
                if (j == i || fffound[i][j])
                    continue;
                if (course[searchme][j])
                {
                    fffound[i][j] = true;
                    tosearch.push(j);
                    if (j == n)
                    {
//                        cout << "\n" << n << " b"
                        break;
                    }
                }
            }
            if (fffound[i][n])
            {
                unavoidable = false;
                break;
            }
        }
        if (unavoidable)
        {
            unavoid[numun] = i;
            numun++;
        }
    }
    
    fout << numun;
    for (int i = 0; i < numun; i++)
    {
        fout << " " << unavoid[i];
    }
    fout << endl;

    for (int k = 0; k < numun; k++)
    {
        int i = unavoid[k];
        cout << i << endl;
        queue<int> tosearch;
        tosearch.push(i);
        bool unavoidable = true;
        while (!tosearch.empty())
        {
            int searchme = tosearch.front();
            tosearch.pop();
            cout << searchme << " | ";
//            ffsearched[i][searchme];
            for (int j = 0; j <= n; j++)
            {
                if (fffound2[i][j])
                    continue;
                if (course[searchme][j])
                {
                    fffound2[i][j] = true;
                    tosearch.push(j);
                    cout << j << " ";
                    if (fffound[i][j])
                    {
                        cout << endl << j << " breaks " << i << endl;
                        unavoidable = false;
                        break;
                    }
                }
            }
            cout << endl;
            if (!unavoidable)
            {
                break;
            }
        }
        if (unavoidable)// && !course[i][i])
        {
            unavoid2[numun2] = i;
            numun2++;
            
        }
        cout << endl;
    }
    
    fout << numun2;
    for (int i = 0; i < numun2; i++)
    {
        fout << " " << unavoid2[i];
    }
    fout << endl;
    
    return 0;
}

