#include <iostream>
#include <cmath>
#include "artclass.h"

using namespace std;

float normdot(int x, int y, int z)
{
    float mult = sqrt(x*x + y*y + z*z) * sqrt(3);
    return (float)(x+y+z) / mult;
}

int style(int H, int W, int R[500][500], int G[500][500], int B[500][500])
{
    float totgrey = 0;
    for (int x = 0; x < W; x++)
    for (int y = 0; y < H; y++)
    {
        totgrey += normdot(R[x][y], G[x][y], B[x][y]);
    }
    totgrey /= float(H*W);
    cout << totgrey << endl;
}
