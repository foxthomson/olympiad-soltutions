/*
ID: 11athom1
TASK: fence9
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
    ifstream fin("fence9.in");
    ofstream fout("fence9.out");
    
    int m, n, p;
    fin >> m >> n >> p;
    
    long long ans = 0;
    if (p > m)
        for (int x = 1; x < n; x++)
        {
            ans += p - ((p-m)*x)/n - 1;
            ans -= (m * x) / n;
//            cout << p - ((p-m)*x)/n - 1 << " " << (m * x) / n << endl;
        }
    else
        for (int x = 1; x < n; x++)
        {
            ans += p + ((m-p)*x)/n;
            ans -= (m*x)/n;
            if (((m-p)*x)%n == 0)
                ans -= 1;
        }
    
    fout << ans << endl;
    
    return 0;
}

