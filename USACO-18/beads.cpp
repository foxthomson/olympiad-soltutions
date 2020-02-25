/*
ID: 11athom1
TASK: beads
LANG: C++
*/

#include <fstream>

#define MIN(a, b) a<b ? a : b
#define MAX(a, b) a>b ? a : b
#define MOD(a, b) a%b<0 ? a%b + b : a%b

using namespace std;

int main(int argc, char** argv) 
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    
    int n;
    fin >> n;
    
    char beads[350];
    for (int i = 0; i < n; i++)
    {
        fin >> beads[i];
    }
    
    int best = 0;
    for (int i = 0; i < n; i++)
    {
        int score = 0;
        
        char currcol = 'w';
        int pointer = i;
        
        while (score < n)
        {
            if (currcol == 'w')
                currcol = beads[pointer];
            else
            {
                if (beads[pointer] != 'w' && beads[pointer] != currcol)
                    break;
            }
            
            score++;
            pointer++;
            pointer %= n;
        }
        
        currcol = 'w';
        pointer = MOD(i-1, n);
        
        while (score < n)
        {
            if (currcol == 'w')
                currcol = beads[pointer];
            else
                if (beads[pointer] != 'w' && beads[pointer] != currcol)
                    break;
            
            score++;
            pointer = MOD(pointer-1, n);
        }
        
        best = MAX(best, score);
    }
    
    fout << best << endl;
    
    return 0;
}

