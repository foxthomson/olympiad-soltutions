#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector<int> connected[1000];

int main(int argc, char const *argv[])
{
    ifstream graph(argv[1]);
    ifstream additions(argv[2]);

    int n, k, w0;
    graph >> n >> k >> w0;
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        graph >> a >> b;
        connected[a].push_back(b);
        connected[b].push_back(a);
    }

    int n2 = k;
    // additions >> n2;
    for (int i = 0; i < n2; i++)
    {
        int a, b;
        additions >> a >> b;
        connected[a].push_back(b);
        connected[b].push_back(a);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        bool visited[1000];
        for (int j = 0; j < n; j++)
            visited[j] = false;

        queue<int> nodes;
        queue<int> dists;
        nodes.push(i);
        nodes.push(0);
        visited[i] = true;

        while (!nodes.empty())
        {
            int node = nodes.front();
            int d = dists.front();
            nodes.pop();
            dists.pop();
            ans += d;

            for (auto b : connected[node])
            {
                if (!visited[b])
                {
                    visited[b] = true;
                    nodes.push(b);
                    dists.push(d+1);
                }
            }
        }
    }

    cout << ans/2 << " " << 1 - ((double) ans/2)/((double) w0) << endl;

    return 0;
}
