#include "encoder.h"
#include "encoderlib.h"
#include <utility>
#include <algorithm>

using namespace std;

// typedef tuple<int, int, int, int> tup;
typedef pair<int, int> pit;

int make(int a, int b, int c, int d)
{
    return (a<<9) + (b<<6) + (c<<3) + d;
}

int get0(int inp)
{    
    return inp >> 9;
}
int get1(int inp)
{    
    return (inp >> 6)&7;
}
int get2(int inp)
{    
    return (inp >> 3)&7;
}
int get3(int inp)
{    
    return (inp)&7;
}


void encode(int N, int M[])
{
  //int i;
  //for(i=0; i<N; i++)
  //  send(M[i]);
    
    pit codes[400];
    int numcodes = 0;
    
    for (int a = 0; a < 8; a++)
    for (int b = 0; b < 8; b++)
    for (int c = 0; c < 8; c++)
    for (int d = 0; d < 8; d++)
    {
        if (a+b+c+d <= 7)
        {
            codes[numcodes] = make_pair(a+b+c+d, make(a, b, c, d));
            numcodes++;
        }
    }
    
    sort(codes, codes+numcodes);
    
    for (int i = 0; i < N; i++)
    {
        int adr = i << 2;
        
        for (int j = 0; j < get0(codes[M[i]].second); j++)
            send(adr);
        for (int j = 0; j < get1(codes[M[i]].second); j++)
            send(adr+1);
        for (int j = 0; j < get2(codes[M[i]].second); j++)
            send(adr+2);
        for (int j = 0; j < get3(codes[M[i]].second); j++)
            send(adr+3);
    }
}
