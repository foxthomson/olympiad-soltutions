// #include "dreaming.h"
#include <stack>
#include <vector>
#include <utility>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

using namespace std;

typedef pair<long long, long long> pii;

// vector<pii> adj[100000];
vector<pii> adj[100000];
bool visited[100000];
long long length[100001];
long long prevnode[100000];

long long travelTime(int N, int M, int L, int A[], int B[], int T[])
{
    for (long long i = 0; i < M; i++)
    {
        adj[A[i]].push_back(make_pair(B[i], T[i]));
        adj[B[i]].push_back(make_pair(A[i], T[i]));
    }

    long long best1 = 0;
    long long best2 = 0;
    long long best3 = 0;
    long long ans = 0;

    for (long long i = 0; i < N; i++)
    {
        if (visited[i]) continue;

        stack<pii> s;
        s.push(make_pair(i, 0));
        long long furthest = i;
        long long bestlength = 0;
        // visited[i] = true;

        while (!s.empty())
        {
            pii curr = s.top();
            s.pop();
            visited[curr.first] = true;

            for(long long j = 0; j < adj[curr.first].size(); j++)
            {
                pii node = adj[curr.first][j];

                if (visited[node.first]) continue;

                s.push(make_pair(node.first, node.second + curr.second));

                if (node.second + curr.second > bestlength)
                {
                    bestlength = node.second + curr.second;
                    furthest = node.first;
                }
            }
        }

        s.push(make_pair(furthest, 0));
        prevnode[furthest] = -1;
        length[furthest] = 0;

        long long newfurthest = furthest;
        long long newbestlength = 0;

        while (!s.empty())
        {
            pii curr = s.top();
            s.pop();
            // visited[curr] = true;

            for(auto node : adj[curr.first])
            {
                if (node.first == prevnode[curr.first]) continue;

                s.push(make_pair(node.first, node.second + curr.second));
                prevnode[node.first] = curr.first;
                length[node.first] = node.second + curr.second;

                if (node.second + curr.second > newbestlength)
                {
                    newbestlength = node.second + curr.second;
                    newfurthest = node.first;
                }
            }
        }


        if (newbestlength > ans)
        {
            ans = newbestlength;
        }
        // cout << ans << " " << newbestlength << " " << furthest << " " << newfurthest << endl;

        long long curr = newfurthest;
        long long back1 = newfurthest;
        // cout << length[curr] << "  " << bestlength << endl;
        while (length[curr] * 2 > newbestlength)
        {
            back1 = curr;
            curr = prevnode[curr];
        }

        // cout << length[back1] << " " << length[curr] << endl;
        long long branchlength = (length[back1] < newbestlength - length[curr]) ? length[back1] : newbestlength - length[curr];
        // cout << branchlength << endl;
        // cout << i << " " << furthest << " " << newfurthest << "  " << newbestlength << " " << curr << endl;
        if (branchlength > best1)
        {
            best3 = best2;
            best2 = best1;
            best1 = branchlength;
        }
        else if (branchlength > best2)
        {
            best3 = best2;
            best2 = branchlength;
        }
        else if (branchlength > best3)
        {
            best3 = branchlength;
        }
        // cout << branchlength << endl;
    }

    // cout << ans << " " << best1 << " " << best2 << " " << best3 << " " << L << endl;
    if (best1 + best2 + L > ans) ans = best1 + best2 + L;
    if (best2 + best3 + 2*L > ans && best3) ans = best2 + best3 + 2*L;

    return ans;
}

static int A[MAX_N];
static int B[MAX_N];
static int T[MAX_N];

int main()
{
	int N, M, L, i;
	int res;

	// FILE *f = fopen("dreaming.in", "r");
	// if (!f)
	// 	fail("Failed to open input file.");

	res = scanf("%d%d%d", &N, &M, &L);
	for (i = 0; i < M; i++)
		res = scanf("%d%d%d", &A[i], &B[i], &T[i]);
	// fclose(f);

	long long answer = travelTime(N, M, L, A, B, T);
	cout << answer << endl;

	return 0;
}
