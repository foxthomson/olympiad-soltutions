/*
ID: 11athom1
LANG: C++
TASK: nuggets
*/

#include <fstream>
#include <queue>
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int numnuggs;
int nuggnumbers[10];
int smallestnugg = 0;
priority_queue<int, vector<int>, greater<int> > nuggqueue;
int nuggstreak = 0;
int prevnugg = 0;
int best;
int gcdnuggs;

int main(int argc, char** argv)
{
    ifstream fin("nuggets.in");
    ofstream fout("nuggets.out");
    
    fin >> numnuggs;
    
    for (int i = 0; i < numnuggs; i++)
    {
        fin >> nuggnumbers[i];
        
        if (smallestnugg == 0 || nuggnumbers[i] < smallestnugg)
            smallestnugg = nuggnumbers[i];
        
        nuggqueue.push(nuggnumbers[i]);
        
        if (i == 0)
            gcdnuggs = nuggnumbers[i];
        else
            gcdnuggs = gcd(gcdnuggs, nuggnumbers[i]);
    }
    
    if (gcdnuggs != 1 || smallestnugg == 1)
    {
        fout << 0 << endl;
        return 0;
    }
    
    best = smallestnugg - 1;
    
    while (1)
    {
        int currnugg = nuggqueue.top();
        while (currnugg == nuggqueue.top())
            nuggqueue.pop();
        
        // check if extends the streak
        if (prevnugg + 1 == currnugg)
        {
            nuggstreak++;
            if (nuggstreak == smallestnugg)
            {
                fout << best << endl;
                return 0;
            }
        }
        else
        {
            best = currnugg - 1;
            nuggstreak = 1;
        }
        
        for (int i = 0; i < numnuggs; i++)
        {
            nuggqueue.push(currnugg + nuggnumbers[i]);
        }
        
        prevnugg = currnugg;
    }
    
    return 0;
}

