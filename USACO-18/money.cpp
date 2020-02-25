/*
ID: 11athom1
TASK: money
LANG: C++
*/

#include <fstream>
#include <algorithm>
//#include <iostream>

using namespace std;

int coins[25];
long long calculated[25][10000];
bool iscalc[25][10000];

long long calculatecoins(int upto, int amount)
{
//    cout << upto << " " << amount << endl;
    
    if (amount == 0)
    {
        // base case 2
        return 1;
    }
    
    if (upto == 0)
    {
        // base case
//        cout << coins[0]%amount << endl;
        return (amount%coins[0] == 0);
    }
    
    if (iscalc[upto][amount])
    {
        return calculated[upto][amount];
    }
    
    long long ans = 0;
    for (int mult = 0; mult <= (amount/coins[upto]); mult++)
    {
        ans += calculatecoins(upto-1, amount-(mult*coins[upto]));
    }
//    cout << upto << " " << amount << " " << ans << endl;
    
    iscalc[upto][amount] = true;
    calculated[upto][amount] = ans;
    
    return ans;
}

int main(int argc, char** argv) 
{
    ifstream fin("money.in");
    ofstream fout("money.out");
    
    // input (v and n switched
    int n;
    int v;
    fin >> n >> v;
    
    for (int i = 0; i < n; i++)
    {
        fin >> coins[i];
    }
    sort(coins, coins+n);
    
    fout << calculatecoins(n-1, v) << endl;
    
    return 0;
}

