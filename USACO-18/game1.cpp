/*
ID: 11athom1
TASK: game1
LANG: C++
*/

#include <fstream>
#include <iostream>

#define MIN(x, y) (x) > (y) ? (y) : (x)
#define MAX(x, y) (x) < (y) ? (y) : (x)

using namespace std;

int board[100];
int a[100];
//int newa[100];
int b[100];
//int newb[100];

int main(int argc, char** argv) 
{
    ifstream fin("game1.in");
    ofstream fout("game1.out");
    
    int n;
    fin >> n;
    
    for (int i = 0; i < n; i++)
    {
        fin >> board[i];
        a[i] = board[i];
    }
    
    for (int i = n-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
//            cout << a[j] << " " << b[j] << endl;
            if (a[j] > a[j+1])
            {
                b[j] = a[j+1];
                a[j] = b[j+1] + board[j];
            }
            else
            {
                int newb = a[j];
                a[j] = b[j] + board[n-i+j];
                b[j] = newb;
            }
            
        }
    }
    
    fout << a[0] << " " << b[0] << endl;
    
    return 0;
}

