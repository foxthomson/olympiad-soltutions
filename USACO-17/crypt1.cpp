/*
ID: 11athom1
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
// #include <sstream>

using namespace std;

bool in_array(int array[10], int size, int search)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == search)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");

    int setsize;
    fin >> setsize;

    // input set of digits
    int set[10];
    for (int i = 0; i < setsize; i++)
    {
        int digit;
        fin >> digit;
        // cout << digit << endl;
        set[i] = digit;
    }

    sort(set, set + setsize);

    int total = 0;

    //   a b c
    //     d e
    // -------
    //   f g h
    // i j k
    // -------
    // l m n o
    for (int ai = 0; ai < setsize; ai++)
    {
    int a = set[ai];
    for (int bi = 0; bi < setsize; bi++)
    {
    int b = set[bi];
    for (int ci = 0; ci < setsize; ci++)
    {
    int c = set[ci];
    for (int di = 0; di < setsize; di++)
    {
    int d = set[di];
    for (int ei = 0; ei < setsize; ei++)
    {
    int e = set[ei];
        // a=2;
        // b=2;
        // c=2;
        // d=2;
        // e=2;

        int fgh = (100*a + 10*b + c) * e;
        int ijk = (100*a + 10*b + c) * d;
        int lmno = fgh + 10*ijk;

        if (fgh >= 1000 || ijk >= 1000 || lmno >= 10000)
        {
            continue;
        }

        int h = fgh%10;
        int g = (fgh%100 - h)/10;
        int f = fgh/100;
        int k = ijk%10;
        int j = (ijk%100 - k)/10;
        int i = ijk/100;
        int o = lmno%10;
        int n = (lmno%100 - o)/10;
        int m = (lmno%1000 - o - 10*n)/100;
        int l = lmno/1000;

        int digits[10] = {f,g,h,i,j,k,l,m,n,o};

        bool solution = 1;

        for (int loop = 0; loop < 10; loop++)
        {
            // cout << digits[loop];
            if (!in_array(set, setsize, digits[loop]))
            {
                solution = 0;
                break;
            }
        }

        // cout<<" "<<a<<b<<c<<"\n  "<<d<<e<<"\n "<<f<<g<<h<<"\n"<<i<<j<<k<<"\n"<<l<<m<<n<<o<<"\n\n";
        if (solution)
        {
            total++;
        }
    }
    }
    }
    }
    }



    // for (int ai = 0; ai < setsize; ai++)
    // {
    //     int a = set[ai];
    //     // cout << ai;
    //     for (int di = 0; di < setsize; di++)
    //     {
    //         int d = set[di];
    //         // if (a*d > 10)
    //         // {
    //         //     // cout << a << d;
    //         //     break;
    //         // }
    //
    //         for (int ei = 0; ei < setsize; ei++)
    //         {
    //             int e = set[ei];
    //             // if (a*e > 10)
    //             // {
    //             //     // cout << a << e;
    //             //     continue;
    //             // }
    //
    //             for (int ci = 0; ci < setsize; ci++)
    //             {
    //                 int c = set[ci];
    //                 // ce - 10s = ce/10
    //                 // ce - 1s = ce%10
    //                 int h = (c*e)%10;
    //                 int g = (c*e)/10; // needs to be added to
    //                 int k = (c*d)%10;
    //                 int j = (c*d)/10; // needs to be added to
    //
    //                 // cout << "hi\n";
    //                 if (!in_array(set, setsize, h) || !in_array(set, setsize, k))
    //                 {
    //                     // cout << h << k << endl;
    //                     continue;
    //                 }
    //
    //                 for (int bi = 0; bi < setsize; bi++)
    //                 {
    //                     int b = set[bi];
    //                     // ce - 10s = ce/10
    //                     // ce - 1s = ce%10
    //                     //
    //                     int ans = (100*a + 10*b + c) * (10*d + e);
    //                     // cout <<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<ans<<endl;
    //                     if (ans >= 10000)
    //                     {
    //                         break;
    //                     }
    //                     // cout << "hii\n";
    //                     g += b*e;
    //                     j += b*d;
    //                     int f = g/10 + (a*e)%10;
    //                     int i = j/10 + (a*d)%10;
    //                     g %= 10;
    //                     j %= 10;
    //
    //                     if (f >= 10 || i >= 10)
    //                     {
    //                         break;
    //                     }
    //
    //                     int l = ans/1000;
    //                     int m = (ans%1000)/100;
    //                     int n = (ans%100)/10;
    //                     int o = (ans%10);
    //
    //                     int pos[8] = {g, j, f, i, l, m, n, o};
    //                     // cout <<l<<" "<<m<<" "<<n<<" "<<o<<" "<<ans<<endl;
    //                     bool broken = 0;
    //                     for (int loop = 0; loop < 8; loop++)
    //                     {
    //                         // cout << pos[i] << endl;
    //                         if (!in_array(set, setsize, pos[loop]))
    //                         {
    //                             broken = 1;
    //                             break;
    //                         }
    //                     }
    //                     if (!broken)
    //                     {
    //                         cout <<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<" "<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<m<<" "<<n<<" "<<o<<endl;
    //                         total++;
    //                     }
    //
    //                     // int g = (b*e)/10;
    //                     // int j += (b*d)%10;
    //                     // int j = (b*d)/10; // needs to be added to
    //
    //                     // if (!in_array(set, setsize, h) || !in_array(set, setsize, h))
    //                     // {
    //                     //     break;
    //                     // }
    //
    //
    //                 }
    //             }
    //         }
    //     }
    // }

    fout << total << endl;

    return 0;
}
