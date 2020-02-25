/*
ID: 11athom1
PROG: pprime
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

// #define SEIVE_SIZE 100000000

using namespace std;

// long long seive[SEIVE_SIZE / 64 / 2 + 1];

// bool pal(int check)
// {
//     stringstream sstream;
//     sstream << check;
//     // string clear;
//     // sstream >> clear;
//     string scheck = sstream.str();
//     string reversedcheck = string(scheck.rbegin(), scheck.rend());
//     // cout << scheck.length() << endl;
//     // copy(scheck.rbegin(), scheck.rend(), reversedcheck.begin());
//     // reverse(reversedcheck.begin(), reversedcheck.begin() + scheck.length() - 1);
//     // cout << reversedcheck << "=" << scheck << endl;
//     return reversedcheck.compare(scheck) == 0;
// }

int to_pal(int half)
{
    stringstream sshalf;
    sshalf << half;
    string shalf = sshalf.str();
    string reversedhalf = string(shalf.rbegin(), shalf.rend());

    istringstream buffer(shalf + reversedhalf);
    int ans;
    buffer >> ans;
    return ans;
}

int to_pal_mid(int half, int mid)
{
    stringstream sshalf;
    sshalf << half;
    string shalf = sshalf.str();
    string reversedhalf = string(shalf.rbegin(), shalf.rend());

    stringstream ssmid;
    ssmid << mid;
    string smid = ssmid.str();

    // cout << (shalf + smid) << endl;

    istringstream buffer(shalf + smid + reversedhalf);
    int ans;
    buffer >> ans;
    return ans;
}

// void get_primes()
// {
//     ;
// }

// bool get_bool(int point)
// {
//     point = point / 2;
//     int index = point/64;
//     long long mask = 1;
//     for (int i = 0; i < point - index*64; i++)
//     {
//         mask *= 2;
//     }
//     // cout << point << " " << index << " " << mask << endl;
//     return mask & seive[index];
// }
//
// void set_bool(int point)
// {
//     point = point / 2;
//     int index = point/64;
//     long long mask = 1;
//     for (int i = 0; i < point - index*64; i++)
//     {
//         mask *= 2;
//     }
//     seive[index] &= ~mask;
// }

bool prime(int check)
{
    if (check%2 == 0)
    {
        return 0;
    }

    for (int i = 3; i < 10000; i+=2)
    {
        if (check % i == 0)
        {
            return 0;
        }
        if (i*i > check)
        {
            break;
        }
    }
    return 1;
}

int answers[800];
int numanswers = 0;

int main()
{
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");

    // cout << SEIVE_SIZE / 64 + 1;

    // cout << pal(10001) << pal(1234554321) << pal(1) << pal(123);

    int upper, lower;
    fin >> lower >> upper;
    if (lower % 2 == 0)
    {
        lower++;
    }

    // cout << prime(100) << prime(101) << prime(121) << prime(99999999);
    // cout << to_pal_mid(10, 5);

    int tot = 0;

    for (int pal = 5; pal < 10; pal+=2)
    {
        if (lower <= pal && upper >= pal && prime(pal))
        {
            // cout << pal << endl;
            fout << pal << endl;
            // tot++;
        }
    }

    for (int start = 1; start < 9999; start++)
    {
        int repeat = to_pal(start);
        if (lower <= repeat && upper >= repeat && prime(repeat))
        {
            // fout << repeat << endl;
            // cout << repeat << endl;
            answers[numanswers] = repeat;
            numanswers++;
            tot++;
        }

        for (int mid = 0; mid < 10; mid++)
        {
            repeat = to_pal_mid(start, mid);
            // cout << repeat << (lower <= repeat && upper >= repeat) << prime(repeat) << endl;
            if (lower <= repeat && upper >= repeat && prime(repeat))
            {
                // cout << repeat << endl;
                // fout << repeat << endl;
                answers[numanswers] = repeat;
                numanswers++;
                tot++;
            }
        }
    }

    // cout << tot;

    sort(answers, answers + numanswers);

    for (int i = 0; i < numanswers; i++)
    {
        fout << answers[i] << endl;
    }

    // cout << lower << upper;

    // cerr << "input" << endl;

    // // set array to 1s
    // seive[2] = 1;
    // for (int i = 0; i < SEIVE_SIZE/64/2 + 1; i++)
    // {
    //     // int index = i/32;
    //     // int mask = 1;
    //     // for (int j = 0; j < i - index*32; j++)
    //     // {
    //     //
    //     // }
    //     seive[i] = 0xFFFFFFFFFFFFFFFF;
    //     // cout << i;
    // }



    // cerr << "set" << endl;
    // cout << get_bool(101);
    //
    // // find sqrt of max
    // int odds = 1;
    // int sqrt = 0;
    // int maxpart = upper;
    //
    // while (maxpart > 0)
    // {
    //     maxpart -= odds;
    //     sqrt++;
    //     odds += 2;
    //     // cout << maxpart << sqrt << odds;
    // }
    //
    // cerr << "sqrt" << endl;
    // // cout << sqrt;
    //
    // // find primes
    // for (int prime = 3; prime <= sqrt; prime+=2)
    // {
    //     if (get_bool(prime))
    //     {
    //         // cout << prime << endl;
    //         int pos = 3*prime;
    //         while (pos < upper)
    //         {
    //             // cout << " " << pos << endl;
    //             set_bool(pos);
    //             pos += 2*prime;
    //         }
    //     }
    // }
    // cerr << "primes" << endl;
    //
    // for (int i = lower; i <= upper; i+=2)
    // {
    //     // cout << get_bool(i) << i << endl;
    //     if (get_bool(i) && pal(i))
    //     {
    //         fout << i << endl;
    //     }
    // }
    // cerr << "ans" << endl;
    //
    // for (int p = lower; p <= upper; p += 2)
    // {
    //     if (pal(p) && prime(p))
    //     {
    //         fout << p << endl;
    //     }
    // }

    return 0;
}
