/*
ID: 11athom1
TASK: contact
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

int numocc[13][50000];
int currnum[13];
int output[200000];
int outdig[200000];

int main(int argc, char** argv) 
{
    ifstream fin("contact.in");
    ofstream fout("contact.out");
    
    int a, b, n;
    fin >> a >> b >> n;
    
    int i = 0;
    for (char d; fin >> d; i++)
    {
        
//        cout << (d-'0') << " " << i << " ";
        for (int len = a; len <= b; len++)
        {
            currnum[len] = ((currnum[len]-(currnum[len]/(1<<(len-1)))*(1<<(len-1)))<<1) + (d-'0');
//            cout << currnum[len] << " ";
            if (len-1 <= i)
            {
                numocc[len][currnum[len]]++;
            }
        }
//        cout << endl;
    }
    
    int maxocc, occmax;
    int nextmax = 200001;
    
    for (int j = 0; j < n; j++)
    {
        maxocc = nextmax;
        nextmax = 0;
        occmax = 0;
    
        for (int k = a; k <= b; k++)
        {
//            cout << k << " " << (1<<k) << endl;
            for (int m = 0; m < (1<<k); m++)
            {
                if (numocc[k][m]  < maxocc)
                {
                    if (numocc[k][m] > nextmax)
                    {
                        nextmax = numocc[k][m];
                        occmax = 0;
                    }
                    if (numocc[k][m] == nextmax)
                    {
                        output[occmax] = m;
                        outdig[occmax] = k;
                        occmax++;
                    }
                }
            }
        }
            
        if (!nextmax)
            break;
        fout << nextmax;
//        cout << nextmax << " | ";
        for (int k = 0; k < occmax; k++)
        {
            if (k%6 == 0)
                fout << endl;
//            else if (k!=(occmax-1))
            else    
                fout << " ";
            
//            cout << output[k] << "," << k << " ";
            
            for (int m = outdig[k]-1; m >= 0; m--)
            {
                fout << (output[k] >> m);
                output[k] %= (1<<m);
            }
        }
        fout << endl;
//        cout << endl;
    }
    
    return 0;
}

