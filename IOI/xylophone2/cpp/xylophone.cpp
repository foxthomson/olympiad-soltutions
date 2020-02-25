#include "xylophone.h"
#include <iostream>

using namespace std;

static int A[5000];

int pairs[5000];
int triples[5000];
bool up[5000];
int relvalues[5000];

void detect_pitch(int N)
{

	// int value = ask(0, N - 1);

	// for(int i = 0; i < N; i++) {
	// 	answer(i, i);
	// }

	for (int i = 0; i < N-2; i++)
	{
		pairs[i] = ask(i, i+1);
		triples[i] = ask(i, i+2);
		// cout << pairs[i] << " " << triples[i] << endl;
	}
	pairs[N-2] = ask(N-2, N-1);

	up[0] = true;

	for (int i = 1; i < N-1; i++)
	{
		if (pairs[i-1] + pairs[i] == triples[i-1])
		{
			up[i] = up[i-1];
		}
		else
		{
			up[i] = !up[i-1];
		}
	}

	int max = 0;
	int maxi = 0;
	int min = 0;
	int mini = 0;

	for (int i = 1; i < N; i++)
	{
		if (up[i-1])
		{
			relvalues[i] = relvalues[i-1] + pairs[i-1];
		}
		else
		{
			relvalues[i] = relvalues[i-1] - pairs[i-1];
		}

		if (relvalues[i] > max)
		{
			maxi = i;
			max = relvalues[i];
		}
		if (relvalues[i] < min)
		{
			mini = i;
			min = relvalues[i];
		}
	}

	// cout << mini << " " << maxi << endl;
	// cout << min << " " << max << endl;
	for (int i = 0; i < N; i++)
	{
		if (maxi > mini)
		{
			// cout << i << " " << relvalues[i] - min << endl;
			answer(i, relvalues[i] - min);
		}
		else
		{
			// cout << i << " " << max - relvalues[i] << endl;
			answer(i, max - relvalues[i]);
		}
	}

}
