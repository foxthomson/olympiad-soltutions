#include "decoder.h"
#include "decoderlib.h"
#include <utility>
#include <algorithm>
#include <iterator>

using namespace std;

// typedef tuple<int, int, int, int> tup;
typedef pair<int, int> pit;

int make2(int a, int b, int c, int d)
{
    return (a<<9) + (b<<6) + (c<<3) + d;
}

void decode(int N, int L, int X[])
{
//   int i, b;
//   for(i=0; i<L; i++)
//   {
//     b = X[i];
//     output(b);
//   }
  
    pit codes[400];
    int numcodes = 0;
    
    for (int a = 0; a < 8; a++)
    for (int b = 0; b < 8; b++)
    for (int c = 0; c < 8; c++)
    for (int d = 0; d < 8; d++)
    {
        if (a+b+c+d <= 7)
        {
            codes[numcodes] = make_pair(a+b+c+d, make2(a, b, c, d));
            numcodes++;
        }
    }
    
    sort(codes, codes+numcodes);
    
//     int ans[64];
    int numbird[64][4];
    
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j < 4; j++)
            numbird[i][j] = 0;
    }
    
    for (int i = 0; i < L; i++)
    {
        numbird[X[i] >> 2][X[i]&3]++;
    }
    
    for (int i = 0; i < N; i++)
    {
        output(distance(codes, find(codes, codes + numcodes, make_pair(numbird[i][0]+numbird[i][1]+numbird[i][2]+numbird[i][3], make2(numbird[i][0],numbird[i][1],numbird[i][2],numbird[i][3])))));
    }
}
