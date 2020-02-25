/*
ID: 11athom1
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream fout ("ride.out");
    std::ifstream fin ("ride.in");
    // ofstream fout("ride.out");
    // ifstream fin("ride.in");

    char comet[8];
    char group[8];
    int cometTot = 1;
    int groupTot = 1;

    fin >> comet >> group;

    for (int i; i < 6; i++)
    {
        if (65 <= comet[i] && comet[i] <= 90)
        {
            cometTot *= comet[i] - 64;
        }

        if (65 <= group[i] && group[i] <= 90)
        {
            groupTot *= group[i] - 64;
        }
    }

    fout << ((cometTot % 47 == groupTot % 47) ? "GO\n" : "STAY\n");

    return 0;
}
