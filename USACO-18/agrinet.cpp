/*
ID: 11athom1
TASK: agrinet
LANG: C++
*/

#include <fstream>

using namespace std;

int dists[100][100];
int distfromtree[100];
bool intree[100];

int main(int argc, char** argv) 
{
    ifstream fin("agrinet.in");
    ofstream fout("agrinet.out");
    
    int n;
    fin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> dists[i][j];
    
    int nointree = 1;
    intree[0] = true;
    int lastin = 0;
    int cost = 0;
    
    while (nointree < n)
    {
        int best = 0;
        int nextnode;

        for (int i = 0; i < n; i++)
        {
            if (!intree[i])
            {
                if (!distfromtree[i] || distfromtree[i] > dists[lastin][i])
                    distfromtree[i] = dists[lastin][i];
                
                if (!best || best > distfromtree[i])
                {
                    best = distfromtree[i];
                    nextnode = i;
                }
            }
        }
        
        nointree++;
        intree[nextnode] = true;
        cost += best;
        lastin = nextnode;
    }
    
    fout << cost << endl;
    
    return 0;
}

