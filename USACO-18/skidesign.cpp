/*
ID: 11athom1
TASK: skidesign
LANG: C++
*/

#include <fstream>
#include <iostream>

#define min(a, b) (a>b?b:a)
#define square(a) ((a)*(a))

using namespace std;

int main(int argc, char** argv) 
{
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
    
    // inp
    int n;
    fin >> n;
    
    int hills[1000];
    for (int i = 0; i < n; i++)
        fin >> hills[i];
    
    
    bool first = true;
    long long best = 0;
    for (int i = 0; i < 83; i++)
    {
        // Get cost of making everything >=i <=i+17
        long long score = 0;
        for (int j = 0; j < n; j++)
        {
            if (hills[j] < i)
                score += square(i-hills[j]);
            else if (hills[j] > i+17)
                score += square(hills[j]-i-17);
         
//        cout << score << endl;
        }
        
        if (first)
        {
            best = score;
            first = false;
        }
        else
            best = min(best, score);
    }
    
    fout << best << endl;
    
    return 0;
}

