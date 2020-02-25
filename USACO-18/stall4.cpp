/*
ID: 11athom1
TASK: stall4
LANG: C++
*/

#include <fstream>
#include <queue>
#include <utility>
#include <iostream>

#define INF 99999999
#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

typedef pair<long long, long long> p;

long long cap[500][500];
long long flow[500][500];
long long prevnode[500];
long long flow1[500];
bool visited[500];

int main(int argc, char** argv)
{
    ifstream fin("stall4.in");
    ofstream fout("stall4.out");
    
    int n1, m1;
    fin >> n1 >> m1;
    int m = 2+m1+n1;
    
    for (int i = 0; i < n1; i++)
    {
        int s;
        fin >> s;
        for (int j = 0; j < s; j++)
        {
            int stall;
            fin >> stall;
            cap[i+1][n1+stall] = 1;
        }
        cap[0][i+1] = 1;
    }
    
    for (int i = n1+1; i<m-1; i++)
        cap[i][m-1] = 1;
    
    int totalflow = 0;
    
    int maxflow, maxloc;
    
    while (1)
    {
        
//        for (int x = 0; x < m; x++)
//        {
//            for (int y = 0; y < m; y++)
//                cout << flow[x][y] << " ";
//            cout << endl;
//        }
//        
//        cout << endl;
        
        for (int i = 0; i < m; i++)
        {
            prevnode[i] = -1;
            flow1[i] = 0;
            visited[i] = false;
        }
        flow1[0] = INF;
        
        while (1)
        {
            maxflow = 0;
            maxloc = -1;
            for (int i = 0; i < m; i++)
            {
                if (flow1[i] > maxflow && !visited[i])
                {
                    maxflow = flow1[i];
                    maxloc = i;
                }
            }
            
//            cout << maxloc << endl;
            
            if (maxloc == -1 || maxloc == m-1)
                break;
            
            visited[maxloc] = true;
            
            for (int i = 0; i < m; i++)
            {
//                cout << flow1[i] << " " << maxflow << " " << cap[maxloc][i] << endl;
                if (flow1[i] < MIN(maxflow, cap[maxloc][i]))
                {
//                    cout << " YES\n";
                    prevnode[i] = maxloc;
                    flow1[i] = MIN(maxflow, cap[maxloc][i]);
                }
            }
        }
        
//        cout << maxloc << " " << flow1[m-1] << endl; 
        
        if (maxloc == -1)
            break;
        
        int pathcap = flow1[m-1];
        totalflow += pathcap;
        
        int currnode = m-1;
        while (currnode)
        {
//            cout << currnode << " ";
            int nextnode = prevnode[currnode];
            cap[nextnode][currnode] -= pathcap;
            cap[currnode][nextnode] += pathcap;
            currnode = nextnode;
        }
//        cout << endl;
    }
    
    fout << totalflow << endl;
    
//    while (1)
//    {
////        for (int x = 0; x < m; x++)
////        {
////            for (int y = 0; y < m; y++)
////                cout << flow[x][y] << " ";
////            cout << endl;
////        }
//        
////        cout << endl;
//        bool searched[200];
//        for (int i = 0; i < 200; i++) searched[i] = false;
//        
//        long long prev[200];
//        long long score[200];
//        for (int i = 0; i < 200; i++) score[i] = 0;
//        
//        priority_queue<p> q;
//        p p1(INF, 0);
//        q.push(p1);
//        
//        p p3(0, m-1);
//        q.push(p3);
//        
//        while (1)
//        {
//            p curr = q.top();
//            long long currflow = curr.first;
//            long long currindex = curr.second;
//            q.pop();
//            
////            cout << " " << currindex << " " << currflow << endl;
//            
//            if (currindex == m-1)
//                break;
//            
//            for (int i = 0; i < m; i++)
//            {
//                if (!searched[i] && flow[i][currindex] && (MIN(flow[i][currindex], currflow)) > score[i])
//                {
////                    cout << currindex << " " << i << " " << (MIN(flow[i][currindex], currflow)) << " " << currflow << " " << flow[i][currindex] << endl;
//                    score[i] = MIN(flow[i][currindex], currflow);
////                    cout << "||||||| " << score[i] << " " << i << endl;
//                    prev[i] = currindex;
//                    p p2(MIN(flow[i][currindex], currflow), i);
//                    q.push(p2);
//                }
//            }
//            
//            searched[currindex] = true;
//        }
//        
//        cout << score[m-1] << endl;
//        
//        if (score[m-1] == 0)
//            break;
//        
//        int nodepath = m-1;
//        while (nodepath)
//        {
//            cout << nodepath << " ";
//            flow[nodepath][prev[nodepath]] -= score[m-1];
//            flow[prev[nodepath]][nodepath] += score[m-1];
//            nodepath = prev[nodepath];
//        }
//        cout << endl;
//    }
//    
//    long long ans = 0;
//    for (int i = 0; i < m; i++)
//    {
//        ans += flow[i][m-1];
//    }
//    fout << ans << endl;
    
    
    return 0;
}
