#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, int> pli;

vector<int> connected[1000];
int back[1000][1000];
int deg[1000];
// vector<int> numnodes[1000];
int numnodes[1000][1000];
int counted[1000];
int edgesdone[1000];
long long score[1000][1000];
long long sumscore[1000];
int edgesdone2[1000];
bool visited[1000];
bool examine[1000];
int intree[1000];
int treesize = 0;
bool avoid[1000];
bool conntest[1000][1000];
vector<int> leaves;

void ff(int start)
{
    treesize = 0;
    for (int i = 0; i < 1000; i++)
        examine[i] = false;
    queue<int> q;
    q.push(start);
    examine[start] = true;
    intree[treesize] = start;
    treesize++;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int conn : connected[node])
        {
            if (!avoid[conn] && !examine[conn])
            {
                examine[conn] = true;
                q.push(conn);
                intree[treesize] = conn;
                treesize++;
            }
        }
    }
}

pli searchtree()
{
    for (int i = 0; i < 20; i++)
        // cout << examine[i] << " ";
    // cout << endl;
    if (treesize <= 1) return make_pair(-1, -1);

    for (int i = 0; i < treesize; i++)
    {
        int node = intree[i];

        deg[node] = 0;

        // cout << node << endl << " ";
        for (int conn : connected[node])
        {
            if (examine[conn]) deg[node]++;
            // if (examine[conn]) cout << conn << " ";
        }
        // cout << endl;

        for (int j = 0; j < 1000; j++)
        {
            numnodes[node][j] = 0;
            score[node][j] = 0;
        }
        counted[node] = 0;
        edgesdone[node] = 0;
        sumscore[node] = 0;
        edgesdone2[node] = 0;
        visited[node] = 0;
    }

    queue<int> q;

    for (int i = 0; i < treesize; i++)
    {
        if (deg[i] == 1)
        {
            leaves.push_back(i);
            int j = 0;
            int b = connected[i][0];
            while (!examine[b])
            {
                j++;
                b = connected[i][j];
            }
            // numnodes[b][back[b][i]] = 1;
            numnodes[i][b] = 1;
            numnodes[b][i] = treesize-1;
            edgesdone[i]++;
            counted[i] += treesize-1;
            edgesdone[b]++;
            counted[b] += 1;

            if (edgesdone[b] == deg[b]-1)
            {
                q.push(b);
            }
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // cout << node << endl;

        if (edgesdone[node] < deg[node])
            for (int conn : connected[node])
                if (!numnodes[conn][node])
                    numnodes[conn][node] = treesize-1 - counted[node];

        edgesdone[node] = deg[node];
        counted[node] = treesize-1;

        for (int conn : connected[node])
        {
            if (!examine[conn]) continue;
            if (numnodes[node][conn]) continue;

            numnodes[node][conn] = treesize - numnodes[conn][node];
            counted[conn] += treesize - numnodes[conn][node];
            edgesdone[conn]++;

            if (edgesdone[conn] == deg[conn]-1)
                q.push(conn);
        }
    }

    // for (int a = 0; a < n; a++)
    // {
    //     for (int b = 0; b < n; b++)
    //     {
    //         cout << numnodes[a][b] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < treesize; i++)
    {
        if (deg[intree[i]] == 1)
        {
            // cout << "leaf: " << intree[i] << endl;
            int j = 0;
            int b = connected[intree[i]][0];
            while (!examine[b])
            {
                j++;
                b = connected[intree[i]][j];
            }            // numnodes[b][back[b][intree[i]]] = 1;
            score[intree[i]][b] = 1;
            // numnodes[b][intree[i]] = n-1;
            // edgesdone[intree[i]]++;
            // counted[intree[i]] += n-1;
            edgesdone2[b]++;
            sumscore[b] += 1;

            // if (b == 2) cout << "Node 2 deg = " << deg[b] << endl;
            if (edgesdone2[b] >= deg[b]-1)
            {
                q.push(b);
            }
        }
    }

    long long minscore = -1;
    int ans = -1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (visited[node]) continue;
        // cout << "!" << node << endl;

        if (deg[node] == 1) continue;

        if (edgesdone2[node] < deg[node])
        {
            // cout << node << " " << edgesdone2[node] << " " << deg[node] << endl;
            for (int conn : connected[node])
            {
                if (!examine[conn]) continue;
                if (!score[conn][node])
                {
                    // if (score[node][conn]) break;

                    score[node][conn] = sumscore[node] + numnodes[node][conn];
                    sumscore[conn] += sumscore[node] + numnodes[node][conn];
                    edgesdone2[conn]++;

                    if (edgesdone2[conn] >= deg[conn]-1)
                        q.push(conn);

                    break;
                }
            }
        }
        else
        {
            // cout << " " << node << endl;
            for (int conn : connected[node])
            {
                if (!examine[conn]) continue;
                // cout << node << " " << conn << " " << score[node][conn] << endl;

                if (score[node][conn]) continue;

                score[node][conn] = sumscore[node] - score[conn][node] + numnodes[node][conn];
                sumscore[conn] += sumscore[node] - score[conn][node] + numnodes[node][conn];
                edgesdone2[conn]++;

                if (edgesdone2[conn] >= deg[conn]-1)
                    q.push(conn);
            }
            visited[node] = true;

            if (sumscore[node] < minscore || minscore < 0)
            {
                minscore = sumscore[node];
                ans = node;
                // cout << ">>>>>" << node << endl;
            }
        }
    }

    // cout << ">>>>> " << minscore << " " << ans << endl;

    return make_pair(minscore, ans);
}

int main(int argc, char const *argv[])
{
    ifstream graph(argv[1]);
    ofstream additions(argv[2]);

    int n, k, w0;
    graph >> n >> k >> w0;
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        graph >> a >> b;
        back[a][b] = connected[a].size(); // back[a][connected[a][i]] = i
        back[b][a] = connected[b].size();
        connected[a].push_back(b);
        connected[b].push_back(a);
        conntest[a][b] = true;
        conntest[b][a] = true;
        // numnodes[a].push_back(0);
        // numnodes[b].push_back(0);
        deg[a]++;
        deg[b]++;
    }

    priority_queue<pli> mainqueue;

    ff(0);
    pli first = searchtree();
    // cout << leaves.size() << endl;
    for (int i = 0; i < k; i++)
    {
        if (conntest[first.second][leaves[i]])
        {
            k++;
            continue;
        }
        additions << first.second << " " << leaves[i] << endl;
    }
    // mainqueue.push(first);
    // int lastnode = first.second;
    // avoid[lastnode] = true;
    // for (int conn : connected[lastnode])
    // {
    //     // cout << conn << endl;
    //     if (avoid[conn]) continue;
    //     ff(conn);
    //     pli addtoq = searchtree();
    //     // cout << addtoq.first << " " << addtoq.second << endl;
    //     if (addtoq.second != -1)
    //         mainqueue.push(addtoq);
    // }
    //
    // for (int i = 0; i < k; i++)
    // {
    //     int node = mainqueue.top().second;
    //     // cout << mainqueue.top().first << endl;
    //     // additions << lastnode << endl;
    //     // cout << node
    //     mainqueue.pop();
    //     avoid[node] = true;
    //     for (int conn : connected[node])
    //     {
    //         if (avoid[conn]) continue;
    //         ff(conn);
    //         pli addtoq = searchtree();
    //         // cout << addtoq.first << " " << addtoq.second << endl;
    //         if (addtoq.second != -1)
    //             mainqueue.push(addtoq);
    //     }
    //     if (conntest[lastnode][node])
    //         i--;
    //     else
    //     {
    //         additions << lastnode << " " << node << endl;
    //         // lastnode = node;
    //     }
    // }
    // cout << searchtree() << endl;


    // queue<int> q;
    //
    // for (int i = 0; i < n; i++)
    // {
    //     if (deg[i] == 1)
    //     {
    //         int b = connected[i][0];
    //         // numnodes[b][back[b][i]] = 1;
    //         numnodes[i][b] = 1;
    //         numnodes[b][i] = n-1;
    //         edgesdone[i]++;
    //         counted[i] += n-1;
    //         edgesdone[b]++;
    //         counted[b] += 1;
    //
    //         if (edgesdone[b] == deg[b]-1)
    //         {
    //             q.push(b);
    //         }
    //     }
    // }
    //
    // while (!q.empty())
    // {
    //     int node = q.front();
    //     q.pop();
    //
    //     // cout << node << endl;
    //
    //     if (edgesdone[node] < deg[node])
    //         for (int conn : connected[node])
    //             if (!numnodes[conn][node])
    //                 numnodes[conn][node] = n-1 - counted[node];
    //
    //     edgesdone[node] = deg[node];
    //     counted[node] = n-1;
    //
    //     for (int conn : connected[node])
    //     {
    //         if (numnodes[node][conn]) continue;
    //
    //         numnodes[node][conn] = n - numnodes[conn][node];
    //         counted[conn] += n - numnodes[conn][node];
    //         edgesdone[conn]++;
    //
    //         if (edgesdone[conn] == deg[conn]-1)
    //             q.push(conn);
    //     }
    // }
    //
    // // for (int a = 0; a < n; a++)
    // // {
    // //     for (int b = 0; b < n; b++)
    // //     {
    // //         cout << numnodes[a][b] << " ";
    // //     }
    // //     cout << endl;
    // // }
    //
    // for (int i = 0; i < n; i++)
    // {
    //     if (deg[i] == 1)
    //     {
    //         int b = connected[i][0];
    //         // numnodes[b][back[b][i]] = 1;
    //         score[i][b] = 1;
    //         // numnodes[b][i] = n-1;
    //         // edgesdone[i]++;
    //         // counted[i] += n-1;
    //         edgesdone2[b]++;
    //         sumscore[b] += 1;
    //
    //         if (edgesdone2[b] >= deg[b]-1)
    //         {
    //             q.push(b);
    //         }
    //     }
    // }
    //
    // while (!q.empty())
    // {
    //     int node = q.front();
    //     q.pop();
    //     if (visited[node]) continue;
    //
    //     if (deg[node] == 1) continue;
    //
    //     if (edgesdone2[node] < deg[node])
    //     {
    //         // cout << node << " " << edgesdone2[node] << " " << deg[node] << endl;
    //         for (int conn : connected[node])
    //             if (!score[conn][node])
    //             {
    //                 // if (score[node][conn]) break;
    //
    //                 score[node][conn] = sumscore[node] + numnodes[node][conn];
    //                 sumscore[conn] += sumscore[node] + numnodes[node][conn];
    //                 edgesdone2[conn]++;
    //
    //                 if (edgesdone2[conn] >= deg[conn]-1)
    //                     q.push(conn);
    //
    //                 break;
    //             }
    //     }
    //     else
    //     {
    //         // cout << " " << node << endl;
    //         for (int conn : connected[node])
    //         {
    //             // cout << node << " " << conn << " " << score[node][conn] << endl;
    //
    //             if (score[node][conn]) continue;
    //
    //             score[node][conn] = sumscore[node] - score[conn][node] + numnodes[node][conn];
    //             sumscore[conn] += sumscore[node] - score[conn][node] + numnodes[node][conn];
    //             edgesdone2[conn]++;
    //
    //             if (edgesdone2[conn] >= deg[conn]-1)
    //                 q.push(conn);
    //         }
    //         visited[node] = true;
    //     }
    // }

        // for (int conn : connected[node])
        // {
        //     if (numnodes[node][conn]) continue;
        //
        //     numnodes[node][conn] = n - numnodes[conn][node];
        //     counted[conn] += n - numnodes[conn][node];
        //     edgesdone[conn]++;
        //
        //     if (edgesdone[conn] >= deg[conn]-1)
        //         q.push(conn);
        // }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << sumscore[i] << " ";
    // }
    // cout << endl;

    // for (int a = 0; a < n; a++)
    // {
    //     for (int b = 0; b < n; b++)
    //     {
    //         cout << score[a][b] << "\t";
    //     }
    //     cout << endl;
    // }

    // long long ans = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     bool visited[1000];
    //     for (int j = 0; j < n; j++)
    //         visited[j] = false;
    //
    //     queue<int> nodes;
    //     queue<int> dists;
    //     nodes.push(i);
    //     nodes.push(0);
    //     visited[i] = true;
    //
    //     while (!nodes.empty())
    //     {
    //         int node = nodes.front();
    //         int d = dists.front();
    //         nodes.pop();
    //         dists.pop();
    //         ans += d;
    //
    //         for (auto b : connected[node])
    //         {
    //             if (!visited[b])
    //             {
    //                 visited[b] = true;
    //                 nodes.push(b);
    //                 dists.push(d+1);
    //             }
    //         }
    //     }
    // }
    //
    // cout << ans << " " << 1 - ((double) ans)/((double) w0) << endl;

    return 0;
}
