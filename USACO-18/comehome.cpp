/*
ID: 11athom1
TASK: comehome
LANG: C++
*/

#include <fstream>
//#include <iostream>

#define INF 100000

using namespace std;

int adj[1000][1000];
int dist[1000];
bool visited[1000];

int main(int argc, char** argv) 
{
    ifstream fin("comehome.in");
    ofstream fout("comehome.out");

    // input
    int p;
    fin >> p;
    
    for (int i = 0; i < p; i++)
    {
        char c1; char c2; int d;
        fin >> c1 >> c2 >> d;
        if (adj[c1][c2] == 0 || adj[c1][c2] > d)
            adj[c1][c2] = adj[c2][c1] = d;
//        cout << adj[c1][c2];
    }
    
    for (int i = 0; i < 1000; i++)
        dist[i] = INF;
    
//    dist['?'] = INF;
    
    char curr = 'Z';
    dist[curr] = 0;
    visited[curr] = true;
    while (1)
    {
        char nextpoint = '?';
        for (int i = 'a'; i <= 'z'; i++)
        {
            if (!visited[i])
            {
//                cout << curr << i << adj[curr][i] << endl;
                if (adj[curr][i] && dist[i] > dist[curr] + adj[curr][i])
                    dist[i] = dist[curr]+adj[curr][i];
                
                if (dist[i]<dist[nextpoint])
                    nextpoint = i;
            }
        }
        for (int i = 'A'; i <= 'Z'; i++)
        {
            if (!visited[i])
            {
                if (adj[curr][i] && dist[i] > dist[curr] + adj[curr][i])
                    dist[i] = dist[curr]+adj[curr][i];
                
                if (dist[i]<dist[nextpoint])
                    nextpoint = i;
            }
        }
        
        curr = nextpoint;
        if ('A' <= curr && curr < 'Z')
        {
            fout << curr << " " << dist[curr] << endl;
            break;
        }
        visited[curr] = true;
    }
    
    return 0;
}

