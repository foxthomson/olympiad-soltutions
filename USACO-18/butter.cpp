/*
ID: 11athom1
TASK: butter
LANG: C++11
*/

#include <fstream>
#include <utility>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int cows[500];
int bestdist[800][800];
bool searched[800][800];
int scores[800];

int numnodes[800];
int adj[800][800];
int length[800][800];

//bool comp(pair<int, int> a, pair<int, int> b)
//{
//    return a.first > b.first;
//}
auto comp = [](pair<int, int> a, pair<int, int> b) {return a.first > b.first;};

priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(comp)> q(comp);

int main(int argc, char** argv) 
{
    ifstream fin("butter.in");
    ofstream fout("butter.out");
    
    int n, p, c;
    fin >> n >> p >> c;
    
    for (int i = 0; i < n; i++)
    {
        fin >> cows[i];
    }
    
    for (int i = 0; i < c; i++)
    {
        int a, b, l;
        fin >> a >> b >> l;
        adj[a-1][numnodes[a-1]] = b-1;
        adj[b-1][numnodes[b-1]] = a-1;
        length[a-1][numnodes[a-1]] = l;
        length[b-1][numnodes[b-1]] = l;
        numnodes[a-1]++;
        numnodes[b-1]++;
    }
    
    int bestscore = 0;
    
    for (int center = 0; center < p; center++)
    {
        // empty queue
        while (!q.empty())
            q.pop();
        
        pair<int, int> first(0, center);
        q.push(first);
        bestdist[center][center] = 0;
        
        for (int i = 0; i < p; i++)
        {
            // get next to search
            int curr;
            do
            {
                curr = q.top().second;
                q.pop();
            } while (searched[center][curr]);
            
            searched[center][curr] = true;
            
            for (int j = 0; j < numnodes[curr]; j++)
            {
                int connect = adj[curr][j];
                int len = length[curr][j];
                if (!searched[center][connect])
                {
                    if (!bestdist[center][connect] || bestdist[center][connect] > bestdist[center][curr] + len)
                    {
                        bestdist[center][connect] = bestdist[center][curr] + len;
                        pair<int, int> pushpair(bestdist[center][connect], connect);
                        q.push(pushpair);
                    }
                }
            }
        }
            
        for (int i = 0; i < n; i++)
        {
            scores[center] += bestdist[center][cows[i]-1];
        }

        if (!bestscore || scores[center]<bestscore)
        {
            bestscore = scores[center];
        }
    }
    fout << bestscore << endl;
//    for (int i = 0; i < p; i++)
//    {
//        for (int j = 0; j < p; j++)
//        {
//            cout << bestdist[i][j] << " ";
//        }
//        cout << endl;
//    }
    
//    
//    int bestscore = 0;
//    
//    for (int center = 0; center < p; center++)
//    {
//        int curr = center;
//        for (int i = 0; i < p; i++)
//        {
//            searched[center][curr] = true;
//            int best, nextnode;
//            int found = false;
//            for (int j = 0; j < p; j++)
//            {
//                if (!searched[center][j])
//                if (adj[curr][j])
//                {
//                    if (bestdist[center][j] && bestdist[center][j] < adj[curr][j] + bestdist[center][curr])
//                    {
//                        bestdist[center][j] = adj[curr][j] + bestdist[center][curr];
//                    }
//                    if (!found || bestdist[center][j] > best)
//                    {
//                        best = bestdist[center][j];
//                        nextnode = j;
//                        found = true;
//                    }
//                }
//            }
//            curr = nextnode;
//        }
//        
//        for (int i = 0; i < n; i++)
//        {
//            scores[center] += bestdist[center][cows[i]-1];
//        }
//        
//        if (!bestscore || scores[center]>bestscore)
//        {
//            bestscore = scores[center];
//        }
//    }
//    
//    fout << bestscore << endl;
    
    return 0;
}

