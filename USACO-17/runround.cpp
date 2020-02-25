/*
ID: 11athom1
PROG: runround
LANG: C++
*/

// #include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string int2string(long conv)
{
    stringstream sstream;
    sstream << conv;
    // string ans;
    // sstream >> ans;
    return sstream.str();
}

int char2int(char conv)
{
    // switch (conv)
    // {
    //     case ('0'): return 0;
    //     case ('1'): return 1;
    //     case ('2'): return 2;
    //     case ('3'): return 3;
    //     case ('4'): return 4;
    //     case ('5'): return 5;
    //     case ('6'): return 6;
    //     case ('7'): return 7;
    //     case ('8'): return 8;
    //     case ('9'): return 9;
    // }
    // return 0;
    return conv - '0';
}

bool runround(string num)
{
    // check for pairs and zeros
    int len = num.length();
    bool used[10] = {1,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < len; i++)
    {
        int asint = char2int(num[i]);
        if (used[asint])
        {
            return 0;
        }
        used[asint] = 1;
    }

    int inpath[10] = {0,0,0,0,0,0,0,0,0,0};
    int currindex = 0;
    for (int i = 0; i < len; i++)
    {
        currindex += char2int(num[currindex]);
        currindex %= len;

        if (inpath[currindex])
        {
            return 0;
        }
        inpath[currindex] = 1;
    }
    return (currindex == 0);
}

int main()
{
    ifstream fin("runround.in");
    ofstream fout("runround.out");

    long m;
    fin >> m;

    m++;

    string mstr = int2string(m);
    int add = 1;
    for (int i = mstr.length() - 1; i >= 0; i--)
    {
        if (mstr[i] == '0')
        {
            m += add;
        }
        add *= 10;
    }

    // notfound = 1;
    while (!runround(int2string(m)))
    {
        m++;
        // if ()
        // {
        //     break;
        // }
    }
    fout << m << endl;

    // cout << int2string(1000).length();

    return 0;
}
