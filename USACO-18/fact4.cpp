/*
ID: 11athom1
TASK: fact4
LANG: C++
*/

#include <fstream>

using namespace std;

int main(int argc, char** argv) 
{
    ifstream fin("fact4.in");
    ofstream fout("fact4.out");
    
    int n;
    fin >> n;
    
    int ans = 1;
    int twos = 0;
    int fives = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        
        // remove 2s and 5s from j
        while (j%2 == 0) {j/=2; twos++;}
        while (j%5 == 0) {j/=5; fives++;}
        
        // update ans
        ans*=j;
        ans%=10;
    }
    
    // replace 2s
    for (int i = 0; i < twos-fives; i++) {ans*=2; ans%=10;}
    
    fout << ans << endl;
    
    return 0;
}

