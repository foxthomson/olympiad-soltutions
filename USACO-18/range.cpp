/*
ID: 11athom1
TASK: range
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

bool squares[250][250];
bool newsquares[250][250];

int main(int argc, char** argv) 
{
    ifstream fin("range.in");
    ofstream fout("range.out");
    
    int n;
    fin >> n;
    
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
        char c;
        fin >> c;
        squares[i][j] = c-'0';
    }
    
    int size = 1;
    while (1)
    {
        // find 2x2
        int count = 0;
        n--; size++;
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (squares[i][j] && squares[i][j+1] && squares[i+1][j] && squares[i+1][j+1])
            {
//                cout << size << " " << i << " " << j << endl;
                count++;
                newsquares[i][j] = 1;
            }
            else newsquares[i][j] = 0;
        }
        
        if (count)
            fout << size << " " << count << endl;
        else
            break;
        
        // copy newsqrs to sqrs
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            squares[i][j] = newsquares[i][j];
        }
    }
    
    return 0;
}

