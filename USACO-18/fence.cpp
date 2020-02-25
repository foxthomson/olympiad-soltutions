/*
ID: 11athom1
TASK: fence
LANG: C++
*/

#include <fstream>

using namespace std;

int f;
int connected[500][500];
int path[1500];
int pathlen = 0;
bool odd[500];

void euler(int node)
{
    for (int i = 0; i < 500; i++)
    {
        if (connected[node][i])
        {
            connected[node][i]--;
            connected[i][node]--;
            euler(i);
        }
    }
    path[pathlen] = node;
    pathlen++;
}

int main(int argc, char** argv)
{
    ifstream fin("fence.in");
    ofstream fout("fence.out");
    
    fin >> f;
    
    for (int i = 0; i < f; i++)
    {
        int a, b;
        fin >> a >> b;
        connected[a-1][b-1]++;
        connected[b-1][a-1]++;
        odd[a-1] = !odd[a-1];
        odd[b-1] = !odd[b-1];
    }
    
    bool tour = true;
    
    for (int i = 0; i < 500; i++)
        if (odd[i])
        {
            euler(i);
            tour = false;
            break;
        }
    
    if (tour)
        euler(0);

    for (int i = pathlen-1; i >= 0; i--)
    {
        fout << path[i]+1 << endl;
    }
    
    return 0;
}

