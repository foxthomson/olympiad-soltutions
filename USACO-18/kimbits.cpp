/*
ID: 11athom1
TASK: kimbits
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

//long int posbits[31][31];
long int choose[33][33];
long int sumchoose[33][33];

ifstream fin("kimbits.in");
ofstream fout("kimbits.out");

void ans(unsigned long n, unsigned long l, unsigned long i)
{
    if (l == 0)
        for (int j = 0; j < n; j++) fout << 0;
    else if (n == 1)
    {
        fout << i-1;
    }
    else
    {
//        cout << n << " " << l << " " << i << " " << sumchoose[n-1][l] << endl;
        if (i <= sumchoose[n-1][l])
        {
            fout << 0;
            ans(n-1, l, i);
        }
        else
        {
            fout << 1;
//            cout << n-1 << " " << l-1 << " " << i-sumchoose[n-1][l] << endl;
            ans(n-1, l-1, i-sumchoose[n-1][l]);
        }
    }
}

int main(int argc, char** argv) 
{
    
    unsigned long int n, l, i;
    fin >> n >> l >> i;
//    cout << n << " " << l << " " << i << endl;
    for (int r = 0; r <= 32; r++)
    {
        choose[r][0] = 1;
        sumchoose[r][0] = 1;
    }
    for (int r = 1; r <= 32; r++)
        for (int k = 1; k <= 32; k++)
        {
            choose[r][k] = choose[r-1][k] + choose[r-1][k-1];
            sumchoose[r][k] = sumchoose[r][k-1] + choose[r][k];
        }
    
    ans(n, l, i);
    fout << endl;
    
//    unsigned long int numpos = 0;
//    for (int k = 0; k <= l; k++)
//    {
////        cout << choose[n][k] << " ";
//        numpos += choose[n][k];
//    }
//        
//    bool flip = i > (numpos)/2;
//    if (flip)
//    {
//        i = numpos-i+1;
//        l = n-l;
//    }
////    cout << n << " " << l << " " << i << endl;
//    unsigned long int numfound = 0;
//    unsigned long int curr = 0;
//    unsigned long int currdig = 0;
//    while (numfound < i)
//    {
////        cout << curr << endl;
//        // check if <= l bits
//        if ((currdig <= l && !flip) || (currdig >= l && flip))
//        {
//            numfound++;
////            cout << curr << " " << currdig << endl;
//        }
//        
//        // update vars
//        if (curr%2)
//        {
//            currdig++;
//            unsigned long int check = curr;
//            while (check%2) {check/=2; currdig--;}
//        }
//        else
//        {
//            currdig++;
//        }
//        curr++;
//    }
//    
//    if (flip)
//        for (int j = n-1; j >= 0; j--)
//            fout << 1-(((curr-1) >> j)%2);
//    else
//        for (int j = n-1; j >= 0; j--)
//            fout << (((curr-1) >> j)%2);
//    
//    fout << endl;
    
    return 0;
}

