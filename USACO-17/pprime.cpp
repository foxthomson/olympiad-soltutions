/*
ID: 11athom1
PROG: pprime
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
// #include <algorithm>

#define SEIVE_SIZE 100000000

using namespace std;

long long seive[SEIVE_SIZE / 64 / 2 + 1];

bool pal(int check)
{
    stringstream sstream;
    sstream << check;
    // string clear;
    // sstream >> clear;
    string scheck = sstream.str();
    string reversedcheck = string(scheck.rbegin(), scheck.rend());
    // cout << scheck.length() << endl;
    // copy(scheck.rbegin(), scheck.rend(), reversedcheck.begin());
    // reverse(reversedcheck.begin(), reversedcheck.begin() + scheck.length() - 1);
    // cout << reversedcheck << "=" << scheck << endl;
    return reversedcheck.compare(scheck) == 0;
}

// void get_primes()
// {
//     ;
// }

bool get_bool(int point)
{
    point = point / 2;
    int index = point/64;
    long long mask = 1;
    for (int i = 0; i < point - index*64; i++)
    {
        mask *= 2;
    }
    // cout << point << " " << index << " " << mask << endl;
    return mask & seive[index];
}

void set_bool(int point)
{
    point = point / 2;
    int index = point/64;
    long long mask = 1;
    for (int i = 0; i < point - index*64; i++)
    {
        mask *= 2;
    }
    seive[index] &= ~mask;
}

int main()
{
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");

    cout << SEIVE_SIZE / 64 + 1;

    // cout << pal(10001) << pal(1234554321) << pal(1) << pal(123);

    int upper, lower;
    fin >> lower >> upper;
    if (lower % 2 == 0)
    {
        lower++;
    }
    // cout << lower << upper;

    cerr << "input" << endl;

    // set array to 1s
    seive[2] = 1;
    for (int i = 0; i < SEIVE_SIZE/64/2 + 1; i++)
    {
        // int index = i/32;
        // int mask = 1;
        // for (int j = 0; j < i - index*32; j++)
        // {
        //
        // }
        seive[i] = 0xFFFFFFFFFFFFFFFF;
        // cout << i;
    }

    cerr << "set" << endl;
    cout << get_bool(101);

    // find sqrt of max
    int odds = 1;
    int sqrt = 0;
    int maxpart = upper;

    while (maxpart > 0)
    {
        maxpart -= odds;
        sqrt++;
        odds += 2;
        // cout << maxpart << sqrt << odds;
    }

    cerr << "sqrt" << endl;
    // cout << sqrt;

    // find primes
    for (int prime = 3; prime <= sqrt; prime+=2)
    {
        if (get_bool(prime))
        {
            // cout << prime << endl;
            int pos = 3*prime;
            while (pos < upper)
            {
                // cout << " " << pos << endl;
                set_bool(pos);
                pos += 2*prime;
            }
        }
    }
    cerr << "primes" << endl;

    for (int i = lower; i <= upper; i+=2)
    {
        // cout << get_bool(i) << i << endl;
        if (get_bool(i) && pal(i))
        {
            fout << i << endl;
        }
    }
    cerr << "ans" << endl;

    return 0;
}
