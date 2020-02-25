#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

typedef pair<long long, int> plli;

vector<int> adj[100000];
vector<long long> len[100000];
long long best[100000];
long long worst[100000];
bool searched[100000];

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++)
	{
		long long a, b, l;
		cin >> a >> b >> l;
		adj[a].push_back(b);
		adj[b].push_back(a);
		len[a].push_back(l);
		len[b].push_back(l);
	}
	
	for (int i = 0; i < n; i++)
	{
		best[i] = -1;
		worst[i] = -1;
	}
	
	priority_queue<plli, vector<plli>, greater<plli> > q;
	
	for (int i = 0; i < k; i++)
	{
		int p;
		cin >> p;
		best[p] = 0;
		worst[p] = 0;
		plli topush;
		topush.first = 0;
		topush.second = p;
		q.push(topush);
	}
	
	while (!q.empty())
	{
		plli popped = q.top();
		long long w = popped.first;
		int p = popped.second;
		q.pop();
		if (searched[p]) continue;
		//cout << w << " " << p << endl;
		
		if (!p) {cout << w << endl; break; }
		
		searched[p] = true;
		
		for (int j = 0; j < adj[p].size(); j++)
		{
			if (!searched[adj[p][j]])
			{
				//cout << adj[p][j] << " " << best[adj[p][j]] << " " << worst[adj[p][j]] << " " << len[p][j] << endl;
				if (best[adj[p][j]] == -1 || (best[adj[p][j]] > w + len[p][j] && w + len[p][j] <= 1000000000))
				{
					worst[adj[p][j]] = best[adj[p][j]];
					best[adj[p][j]] = w + len[p][j];
					if (worst[adj[p][j]] != -1)
					{
						plli topush;
						topush.first = worst[adj[p][j]];
						topush.second = adj[p][j];
						q.push(topush);
					}
				}
				else if (worst[adj[p][j]] == -1 || (worst[adj[p][j]] > w + len[p][j] && w + len[p][j] <= 1000000000))
				{
					worst[adj[p][j]] = w + len[p][j];
					plli topush;
					topush.first = worst[adj[p][j]];
					topush.second = adj[p][j];
					q.push(topush);
				}
			}
		}
	}
			
	return 0;
}
