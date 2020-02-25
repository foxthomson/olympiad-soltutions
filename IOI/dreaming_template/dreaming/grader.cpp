#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "dreaming.h"

using namespace std;

#define fail(s, x...) do { \
		fprintf(stderr, s "\n", ## x); \
		exit(1); \
	} while(0)

#define MAX_N 100000

static int A[MAX_N];
static int B[MAX_N];
static int T[MAX_N];


int main(int argc, char *argv[]) {
	int N, M, L, i;
	int res;

	// FILE *f = fopen("dreaming.in", "r");
	FILE *f = fopen(argv[1], "r");
	if (!f)
		fail("Failed to open input file.");

	// cout << argv[2] << endl;

	ifstream fin(argv[2]);
	int correct;
	fin >> correct;

	res = fscanf(f, "%d%d%d", &N, &M, &L);
	for (i = 0; i < M; i++)
		res = fscanf(f, "%d%d%d", &A[i], &B[i], &T[i]);
	fclose(f);

	int answer = travelTime(N, M, L, A, B, T);
	if (answer == correct) cout << "AC   " << argv[1] << endl;
	else cout << "FAIL " << argv[1] << " " << answer << " " << correct << endl;
	// printf("%d\n", answer);

	return 0;
}
