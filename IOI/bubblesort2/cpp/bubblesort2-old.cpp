#include "bubblesort2.h"
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

pii Qs[1000000];
// int numQs

std::vector<int> count_scans(std::vector<int> A,std::vector<int> X,std::vector<int> V)
{
	set<int> seen;
	vector<int> distinct;
	// vector<pii> Qs;

	for (auto x : A)
	{
		if (!seen.count(x))
		{
			seen.insert(x);
			distinct.push_back(x);
		}
	}
	for (auto x : V)
	{
		if (!seen.count(x))
		{
			seen.insert(x);
			distinct.push_back(x);
		}
	}
	for (int i = 0; i < A.size(); i++)
	{
		Qs[i] = make_pair(A[i], i);
	}
	for (int i = 0; i < X.size(); i++)
	{
		Qs[i + A.size()] = make_pair(V[i], X[i]);
	}

	sort(distinct.begin(), distinct.end());
	sort(Qs, Qs + (A.size() + X.size()));

	int Q=X.size();
	std::vector<int> answer(Q);

	int Qsi = 0;
	int currmax = 0;

	for (auto x : distinct)
	{
		for ( ; Qs[Qsi].first == x; Qsi++)
			currmax = Qs[Qsi].second;

		bool greater[500000];
		int currlist[500000];
		int maxx = -1;
		for (int i = 0; i <= currmax; i++)
		{
			greater[i] = A[i] > x;
			currlist[i] = A[i];
			if (A[i] == x) maxx = i;
		}

		int currscore = 0;
		for (int i = maxx-1; i >= 0; i--)
		{
			currscore += greater[i];
		}

		for (int i = 0; i < Q; i++)
		{
			if (X[i] > currmax)
			{
				if (currscore > answer[i])
				{
					answer[i] = currscore;
				}
				continue;
			}
			if (V[i] == x)
			{
				if (X[i] > maxx)
				{
					// int oldx = maxx;
					// maxx = X[i];
					// for (int i = maxx-1; i > oldx; i--)
					// {
					// 	currscore += greater[i];
					// }
					// cout << currscore  << " " << maxx << " -> ";
					for (maxx++ ; maxx < X[i]; maxx++)
					{
						currscore += greater[maxx];
					}
					// cout << currscore << " " << maxx << endl;
				}
			}
			// if (i == 11)
			// {
			// 	for (int i = 0; i < A.size(); i++)
			// 	{
			// 		cout << greater[i] << " ";
			// 	} cout << endl;
			// 	for (int i = 0; i < A.size(); i++)
			// 	{
			// 		cout << currlist[i] << " ";
			// 	}cout << endl;
			// 	 // cout << " " << V[i] << " " << X[i] << " " << maxx << " " << x << " " << currscore << endl;
			// }
			if (V[i] > x)
			{
				if (!greater[X[i]] && X[i] < maxx)
				{
					// cout << "!" << endl;
					currscore++;
				}
			}
			else
			{
				if (greater[X[i]] && X[i] < maxx)
				{
					currscore--;
				}
			}

			if (X[i] == maxx && V[i] != x)
			{
				maxx--;
				for ( ; maxx >= 0 && currlist[maxx] != x; maxx--)
				{
					currscore -= greater[maxx];
				}
			}

			greater[X[i]] = V[i] > x;
			currlist[X[i]] = V[i];

			// if (x == 11){
			// for (int i = 0; i < A.size(); i++)
			// {
			// 	cout << currlist[i] << " ";
			// }cout << endl;}

			if (currscore > answer[i])
			{
				answer[i] = currscore;
			}
			// cout << i << " " << currscore << " " << x << " " << maxx << endl;
		}
	}

	// for (int j=0;j<Q;j++) {
	// 	answer[j]=X[j];
	// }
	return answer;
}
