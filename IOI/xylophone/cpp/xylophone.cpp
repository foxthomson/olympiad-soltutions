#include "xylophone.h"
#include <iostream>
#include <cmath>

#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) < (b) ? (a) : (b)

using namespace std;

static int A[5000];
bool found[5000];
bool paired[5000];

bool searched[5000][5000];
int diff[5000][5000];

int get_diff(int a, int b)
{
	if (searched[MIN(a, b)][MAX(a, b)])
		return diff[MIN(a, b)][MAX(a, b)];
	else
	{
		int d = ask(MIN(a, b), MAX(a, b));
		searched[MIN(a, b)][MAX(a, b)] = true;
		diff[MIN(a, b)][MAX(a, b)] = d;
		return d;
	}
}

void search_bit(int compare_with, int compare_value, bool move_right, bool find_max, int end)
{
	// cout << compare_with << " " << compare_value << " " << move_right << " " << find_max << " " << end << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	if (find_max)
	{
		cout << "find max from " << compare_with << " to " << end << endl;
	}
	else
	{
		cout << "find min from " << compare_with << " to " << end << endl;
	}

	int searchsize = abs(end-compare_with);
	// if (searchsize <= 2) return;
	// if (move_right)
	// {
	// 	bool allfound = true;
	// 	for (int i = compare_with+1; i <= end; i++)
	// 	{
	// 		if (!paired[i])
	// 		{
	// 			allfound = false;
	// 			break;
	// 		}
	// 	}
	// 	if (allfound) return;
	// }
	if (searchsize <= 0) return;
	if (searchsize <= 2)
	{
		if (move_right)
		{
			if (find_max)
			{
				if (!paired[compare_with+1])
				{
					A[compare_with+1] = compare_value + get_diff(compare_with, compare_with+1);
					found[compare_value + get_diff(compare_with, compare_with+1)] = true;
					paired[compare_with] = true;
				}
				if (searchsize == 2 && !paired[compare_with+2])
				{
					if (get_diff(compare_with, compare_with+2) == get_diff(compare_with, compare_with+1))
					{
						A[compare_with+2] = A[compare_with+1] - get_diff(compare_with+1, compare_with+2);
						found[A[compare_with+1] - get_diff(compare_with+1, compare_with+2)] = true;
						A[compare_with+2] = true;
					}
					else
					{
						A[compare_with+2] = A[compare_with] + get_diff(compare_with, compare_with+2);
						found[A[compare_with] + get_diff(compare_with, compare_with+2)] = true;
						A[compare_with+2] = true;
					}
				}
			}
			else
			{
				if (!paired[compare_with+1])
				{
					A[compare_with+1] = compare_value - get_diff(compare_with, compare_with+1);
					found[compare_value - get_diff(compare_with, compare_with+1)] = true;
					paired[compare_with] = true;
				}
				if (searchsize == 2 && !paired[compare_with+2])
				{
					if (get_diff(compare_with, compare_with+2) == get_diff(compare_with, compare_with+1))
					{
						A[compare_with+2] = A[compare_with+1] + get_diff(compare_with+1, compare_with+2);
						found[A[compare_with+1] + get_diff(compare_with+1, compare_with+2)] = true;
						A[compare_with+2] = true;
					}
					else
					{
						A[compare_with+2] = A[compare_with] - get_diff(compare_with, compare_with+2);
						found[A[compare_with] - get_diff(compare_with, compare_with+2)] = true;
						A[compare_with+2] = true;
					}
				}
			}
		}
		else
		{
			if (find_max)
			{
				if (!paired[compare_with-1])
				{
					A[compare_with-1] = compare_value + get_diff(compare_with, compare_with-1);
					found[compare_value + get_diff(compare_with, compare_with-1)] = true;
					paired[compare_with] = true;
				}
				if (searchsize == 2 && !paired[compare_with-2])
				{
					if (get_diff(compare_with, compare_with-2) == get_diff(compare_with, compare_with-1))
					{
						A[compare_with-2] = A[compare_with-1] - get_diff(compare_with-1, compare_with-2);
						found[A[compare_with-1] - get_diff(compare_with-1, compare_with-2)] = true;
						A[compare_with-2] = true;
					}
					else
					{
						A[compare_with-2] = A[compare_with] + get_diff(compare_with, compare_with-2);
						found[A[compare_with] + get_diff(compare_with, compare_with-2)] = true;
						A[compare_with-2] = true;
					}
				}
			}
			else
			{
				if (!paired[compare_with-1])
				{
					A[compare_with-1] = compare_value - get_diff(compare_with, compare_with-1);
					found[compare_value - get_diff(compare_with, compare_with-1)] = true;
					paired[compare_with] = true;
				}
				if (searchsize == 2 && !paired[compare_with-2])
				{
					if (get_diff(compare_with, compare_with-2) == get_diff(compare_with, compare_with-1))
					{
						A[compare_with-2] = A[compare_with-1] + get_diff(compare_with-1, compare_with-2);
						found[A[compare_with-1] + get_diff(compare_with-1, compare_with-2)] = true;
						A[compare_with-2] = true;
					}
					else
					{
						A[compare_with-2] = A[compare_with] - get_diff(compare_with, compare_with-2);
						found[A[compare_with] - get_diff(compare_with, compare_with-2)] = true;
						A[compare_with-2] = true;
					}
				}
			}
		}
		return;
	}

	int maxval = get_diff(compare_with, end);

	int a, b;
	if (move_right)
	{
		a = compare_with+1;
		b = end;
	}
	else
	{
		a = end;
		b = compare_with-1;
	}

	int k;

	while (a <= b)
	{
		k = (a+b)/2;

		if (get_diff(compare_with, k) == maxval)
		{
			if (move_right)
			{
				if (compare_with == k-1 || get_diff(compare_with, k-1) != maxval)
				{
					break;
				}
				else
				{
					b = k;
				}
			}
			else
			{
				if (compare_with == k+1 || get_diff(compare_with, k+1) != maxval)
				{
					break;
				}
				else
				{
					a = k;
				}
			}
		}
		else
		{
			if (move_right)
			{
				a = k;
			}
			else
			{
				b = k;
			}
		}
	}

	if (move_right)
	{
		if (find_max)
		{
			int valk = compare_value + get_diff(compare_with, k);
			A[k] = valk;
			found[valk] = true;
			paired[k] = true;

			int p = k;
			int valp = valk;
			while (!paired[p+1])
			{
				p++;
				bool passed = true;
				for (int add = get_diff(k, p); add > 0; add--)
				{
					if (!found[valp])
					{
						passed = false;
						// break;
					}
					valp--;
				}
				A[p] = valp;
				found[valp] = true;
				paired[p] = true;

				if (!passed)
				{
					search_bit(p-1, A[p-1], true, false, end);
					break;
				}
			}

			p = k;
			valp = valk;
			while (!paired[p-1])
			{
				p--;
				bool passed = true;
				for (int add = get_diff(k, p); add > 0; add--)
				{
					if (!found[valp])
					{
						passed = false;
						// break;
					}
					valp--;
				}
				A[p] = valp;
				found[valp] = true;
				paired[p] = true;

				if (!passed)
				{
					search_bit(p+1, A[p+1], false, false, compare_with+1);
					break;
				}
			}
		}
		else
		{
			int valk = compare_value - get_diff(compare_with, k);
			A[k] = valk;
			found[valk] = true;
			paired[k] = true;

			int p = k;
			int valp = valk;
			while (!paired[p+1])
			{
				p++;
				bool passed = true;
				for (int add = get_diff(k, p); add > 0; add--)
				{
					if (!found[valp])
					{
						passed = false;
						// break;
					}
					valp++;
				}
				A[p] = valp;
				found[valp] = true;
				paired[p] = true;

				if (!passed)
				{
					search_bit(p-1, A[p-1], true, true, end);
					break;
				}
			}

			p = k;
			valp = valk;
			while (!paired[p-1])
			{
				p--;
				bool passed = true;
				for (int add = get_diff(k, p); add > 0; add--)
				{
					if (!found[valp])
					{
						passed = false;
						// break;
					}
					valp++;
				}
				A[p] = valp;
				found[valp] = true;
				paired[p] = true;

				if (!passed)
				{
					search_bit(p+1, A[p+1], false, true, compare_with+1);
					break;
				}
			}
		}
	}
	else
	{
		if (find_max)
		{
			int valk = compare_value + get_diff(compare_with, k);
			A[k] = valk;
			found[valk] = true;
			paired[k] = true;

			int p = k;
			int valp = valk;
			while (!paired[p+1])
			{
				p++;
				bool passed = true;
				for (int add = get_diff(k, p); add > 0; add--)
				{
					if (!found[valp])
					{
						passed = false;
						// break;
					}
					valp--;
				}
				A[p] = valp;
				found[valp] = true;
				paired[p] = true;

				if (!passed)
				{
					search_bit(p-1, A[p-1], true, false, compare_with-1);
					break;
				}
			}

			p = k;
			valp = valk;
			while (!paired[p-1])
			{
				p--;
				bool passed = true;
				for (int add = get_diff(k, p); add > 0; add--)
				{
					if (!found[valp])
					{
						passed = false;
						// break;
					}
					valp--;
				}
				A[p] = valp;
				found[valp] = true;
				paired[p] = true;

				if (!passed)
				{
					search_bit(p+1, A[p+1], false, false, end);
					break;
				}
			}
		}
		else
		{
			int valk = compare_value - get_diff(compare_with, k);
			A[k] = valk;
			found[valk] = true;
			paired[k] = true;

			int p = k;
			int valp = valk;
			while (!paired[p+1])
			{
				p++;
				bool passed = true;
				for (int add = get_diff(k, p); add > 0; add--)
				{
					if (!found[valp])
					{
						passed = false;
						// break;
					}
					valp++;
				}
				A[p] = valp;
				found[valp] = true;
				paired[p] = true;

				if (!passed)
				{
					search_bit(p-1, A[p-1], true, true, compare_with-1);
					break;
				}
			}

			p = k;
			valp = valk;
			while (!paired[p-1])
			{
				p--;
				bool passed = true;
				for (int add = get_diff(k, p); add > 0; add--)
				{
					if (!found[valp])
					{
						passed = false;
						// break;
					}
					valp++;
				}
				A[p] = valp;
				found[valp] = true;
				paired[p] = true;

				if (!passed)
				{
					search_bit(p+1, A[p+1], false, true, end);
					break;
				}
			}
		}
	}
}

void detect_pitch(int N)
{

	int searchsize = N;
	if (searchsize == 2)
	{
		answer(0, 0);
		answer(1, 1);
		return;
	}

	int maxval = N-1;

	int compare_with = 0;

	int a, b;
	// if (move_right)
	// {
	// 	a = compare_with+1;
	// 	b = end;
	// }
	// else
	// {
	// 	a = end;
	// 	b = compare_with-1;
	// }
	a = 1;
	b = N-1;

	int k;

	while (a <= b)
	{
		k = (a+b)/2;

		if (get_diff(compare_with, k) == maxval)
		{
			if (compare_with == k-1 || get_diff(compare_with, k-1) != maxval)
			{
				break;
			}
			else
			{
				b = k;
			}
		}
		else
		{
			a = k;
		}
	}

	int valk = N-1;
	A[k] = valk;
	found[valk] = true;
	paired[k] = true;

	int p = k;
	int valp = valk;
	while (!paired[p+1])
	{
		p++;
		bool passed = true;
		for (int add = get_diff(k, p); add > 0; add--)
		{
			if (!found[valp])
			{
				passed = false;
				// break;
			}
			valp--;
		}
		A[p] = valp;
		found[valp] = true;
		paired[p] = true;

		if (!passed)
		{
			search_bit(p-1, A[p-1], true, false, N-1);
			break;
		}
	}

	p = k;
	valp = valk;
	while (!paired[p-1])
	{
		p--;
		bool passed = true;
		for (int add = get_diff(k, p); add > 0; add--)
		{
			if (!found[valp])
			{
				passed = false;
				// break;
			}
			valp--;
		}
		A[p] = valp;
		found[valp] = true;
		paired[p] = true;

		if (!passed)
		{
			search_bit(p+1, A[p+1], false, false, 0);
			break;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << i << " " << A[i] << endl;
		// answer(i, A[i]);
	}

	// int maxdiff = 0;
	// int maxkey = 0;
	// for (int i = 1; i < N; i++)
	// {
	// 	int d = ask(0, i);
	// 	if (d > maxdiff)
	// 	{
	// 		maxdiff = d;
	// 		maxkey = i;
	// 	}
	// }
	//
	// int ans[5000];
	// for (int i = 0; i < N; i++)
	// {
	// 	ans[i] = 0;
	// }
	//
	// bool larger = false;
	//
	// for (int i = 0; i < N; i++)
	// {
	// 	if (i == maxkey)
	// 		continue;
	//
	// 	int d = ask(MIN(i, maxkey), MAX(i, maxkey));
	// 	ans[i] = d;
	//
	// 	if (d == N-1)
	// 	{
	// 		larger = i < maxkey;
	// 	}
	// }
	//
	// if (larger)
	// {
	// 	for (int i = 0; i < N; i++)
	// 	{
	// 		cout << i << " " << N-1 - ans[i] << endl;
	// 		answer(i, N-1 - ans[i]);
	// 	}
	// }
	// else
	// {
	// 	for (int i = 0; i < N; i++)
	// 	{
	// 		cout << i << " " << ans[i] << endl;
	// 		answer(i, ans[i]);
	// 	}
	// }

	// int value = ask(0, N - 1);
	//
	// for(int i = 0; i < N; i++) {
	// 	answer(i, i);
	// }

}
