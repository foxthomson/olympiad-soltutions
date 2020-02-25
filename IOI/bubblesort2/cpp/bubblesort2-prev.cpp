#include "bubblesort2.h"
#include <set>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <utility>

#define TWO19 524288
// #define TWO19 32

using namespace std;

typedef pair<int, int> pii;

int range_thing[TWO19];
bool set_greater[500000][1000]

void reset_thing(int* thing, int size)
{
	for (int i = 0; i < size; i++)
	{
		thing[i] = 0;
	}
}

void inc_thing(int* thing, int size, int index)
{
	thing[0]++;
	int split = size;
	int add = 0;
	for (int off = 1; off < size; off <<= 1)
	{
		split >>= 1;

		if (index < split)
		{
			thing[off+add]++;
			add <<= 1;
		}
		else
		{
			add <<= 1;
			add++;
			index -= split;
		}
	}
}

void dec_thing(int* thing, int size, int index)
{
	thing[0]--;
	int split = size;
	int add = 0;
	for (int off = 1; off < size; off <<= 1)
	{
		split >>= 1;

		if (index < split)
		{
			thing[off+add]--;
			add <<= 1;
		}
		else
		{
			add <<= 1;
			add++;
			index -= split;
		}
	}
}

int get_thing(int* thing, int size, int index)
{
	int ans = 0;

	if (index < 0) return 0;

	int split = size;
	int add = 0;
	for (int off = 1; off < size; off <<= 1)
	{
		split >>= 1;

		if (index < split)
		{
			add <<= 1;
		}
		else
		{
			ans += thing[off+add];
			add <<= 1;
			add++;
			index -= split;
		}
	}

	return ans;
}

std::vector<int> count_scans(std::vector<int> A,std::vector<int> X,std::vector<int> V)
{
	set<int> seen;
	vector<int> distinct;

	// reset_thing(range_thing, );
	// inc_thing(range_thing, 10);
	// inc_thing(range_thing, 3);
	// cout << get_thing(range_thing, 0) << " " << get_thing(range_thing, 5) << " " << get_thing(range_thing, 30) << endl;
	// dec_thing(range_thing, 3);
	// inc_thing(range_thing, 7);
	// cout << get_thing(range_thing, 0) << " " << get_thing(range_thing, 5) << " " << get_thing(range_thing, 30) << endl;

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

	int Q=X.size();
	std::vector<int> answer(Q);

	sort(distinct.begin(), distinct.end());

	// for (auto x : distinct)
	for (int i = 0; i < (distinct.size()-1)/1000; i++)
	{
		int lb = distinct[i*1000];
		int ub = distinct[(i+1)*1000-1 < distinct.size()-1 ? (i+1)*1000-1 : distinct.size()-1];

		map<int, int> back;
		for (int i = lb; i <= ub; i++)
		{
			map[distinct[i]] = i-lb;
		}

		reset_thing(range_thing, TWO19);
		// priority_queue<int> q[1000];
		priority_queue<pii> q;
		bool greater[500000];
		int currlist[500000];
		int maxx = -1;
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				set_greater[i][j] = false;
			}

			greater[i] = A[i] > ub;
			currlist[i] = A[i];
			if (A[i] > ub) inc_thing(range_thing, TWO19, i);
			else if (A[i] >= lb)
			{
				int score = get_thing(i);
				for (int j = 0; j < i; j++)
				{
					score += greater[i];
				}

				q.push(make_pair(scoreu));
				maxx = i;
			}
		}

		int currscore = 0;
		// for (int i = maxx-1; i >= 0; i--)
		// {
		// 	currscore += greater[i];
		// }
		currscore = get_thing(range_thing, TWO19, maxx+1);

		if (!q.empty()) q.pop();

		for (int i = 0; i < Q; i++)
		{
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
					// for (maxx++ ; maxx < X[i]; maxx++)
					// {
					// 	currscore += greater[maxx];
					// }
					q.push(maxx);
					maxx = X[i];
					currscore = get_thing(range_thing, TWO19, maxx);
					// cout << currscore << " " << maxx << endl;
				}
				if (X[i] < maxx)
				{
					q.push(X[i]);
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
			// cout << " " << V[i] << " " << X[i] << " " << maxx << " " << x << " " << currscore << endl;
			// }
			if (V[i] > x)
			{
				if (!greater[X[i]])
				{
					// cout << "!" << endl;
					if (X[i] < maxx)
						currscore++;
					inc_thing(range_thing, TWO19, X[i]);
				}
			}
			else
			{
				if (greater[X[i]])
				{
					if (X[i] < maxx)
						currscore--;
					dec_thing(range_thing, TWO19, X[i]);
					// cout << X[i] << endl;
				}
			}

			if (X[i] == maxx && V[i] != x)
			{
				do
				{
					if (q.empty())
					{
						maxx = -1;
						break;
					}
					maxx = q.top();
					q.pop();
				} while(currlist[maxx] != x);
				currscore = get_thing(range_thing, TWO19, maxx);
				// maxx--;
				// for ( ; maxx >= 0 && currlist[maxx] != x; maxx--)
				// {
				// 	currscore -= greater[maxx];
				// }
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
			// for (int i = 0; i < 11; i++)
			// {
			// 	cout << get_thing(i+1) << " ";
			// }
			// cout << endl;
			// cout << i << " " << currscore << " " << x << " " << maxx << " " << get_thing(maxx) << endl;
		}
		// cout << x << endl << endl;
	}

	// for (int j=0;j<Q;j++) {
	// 	answer[j]=X[j];
	// }
	return answer;
}
