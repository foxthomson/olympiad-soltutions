/*
ID: 11athom1
PROG: beads
LANG: C++
*/

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int partmod(int a, int b)
{
    if (a < b && a >= 0)
    {
        return a;
    }
    else if (a < 0)
    {
        return a + b;
    }
    else
    {
        return a % b;
    }
}

int main()
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");

    int len;
    fin >> len;

    string beads;
    fin >> beads;

    int max = 0;

    for (int i = 0; i < len; i++)
    {
        int count = 1;

        char colour = beads[i];

        while (count < len)
        {
            if (colour == 'w')
            {
                colour = beads[partmod(i+count, len)];
            }
            else if (colour != beads[partmod(i+count, len)] && beads[partmod(i+count, len)] != 'w')
            {
                break;
            }
            count++;
        }

        int count2 = 1;

        colour = beads[partmod(i-1, len)];

        while (count2 < len)
        {
            if (colour == 'w')
            {
                colour = beads[partmod(i-count2-1, len)];
            }
            else if (colour != beads[partmod(i-count2-1, len)] && beads[partmod(i-count2-1, len)] != 'w')
            {
                break;
            }
            count2++;
        }
        // cout << count << count2 << "\n";

        if (count + count2 > max)
        {
            max = count + count2;
        }
    }

    fout << ((max < len) ? max : len) << "\n";

    return 0;
}
