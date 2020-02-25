/*
ID: 11athom1
TASK: concom
LANG: C++
*/

#include <fstream>

using namespace std;

int own[100][100];
bool control[100][100];

int main(int argc, char** argv) 
{
    ifstream fin("concom.in");
    ofstream fout("concom.out");
    
    int n;
    fin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int j, k, p;
        fin >> j >> k >> p;
        own[j-1][k-1] = p;
        if (p > 50)
        {
            control[j-1][k-1] = true;
        }
    }
    
    for (int i = 0; i < 100; i++)
        for (int a = 0; a < 100; a++)
        {
            int numsub = 1;
            int sub[100];
            sub[0] = a;
            
            // Get those owed by a
            for (int b = 0; b < 100; b++)
                if (control[a][b])
                {
                    sub[numsub] = b;
                    numsub++;
                }
            
            // for each company get percent owed by subs
            for (int b = 0; b < 100; b++)
            {
                if (a==b || control[a][b])
                {
                    continue;
                }
                
                int owned = 0;
                for (int j = 0; j < numsub; j++)
                    owned += own[sub[j]][b];
                
                if (owned > 50)
                {
                    control[a][b] = true;
                }
            }
        }
    
    for (int a = 0; a < 100; a++)
        for (int b = 0; b < 100; b++)
            if (control[a][b] && a != b)
            {
                fout << a+1 << " " << b+1 << endl;
            }
    
    return 0;
}

