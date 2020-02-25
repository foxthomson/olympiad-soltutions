/*
ID: 11athom1
PROG: wormhole
LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct wormhole
{
    long long x;
    long long y;
};

struct simplewh
{
    bool exists;
    bool visited;
    int pairnum;
};

// bool in

bool compwh(wormhole a, wormhole b)
{
    return a.y < b.y;
}

bool loop(simplewh wormholes[12][12])
{
    bool visited[12][12] = {0};

    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            if (!visited[i][j] && wormholes[i][j].visited)
            {
                int curr_i = i, curr_j = j;
                bool loop;
                do {
                    curr_j++;
                    visited[curr_i][curr_j] = 1;
                    if (curr_j <= 12 || !wormholes[curr_i][curr_j].exists || !wormholes[curr_i][curr_j].visited)
                    {
                        loop = 0;
                        break;
                    }
                    int pairnum = -wormholes[curr_i][curr_j].pairnum;
                    for (int i2 = 0; i2 < 12; i2++)
                    {
                        for (int j2 = 0; j2 < 12; j2++)
                        {
                            if (wormholes[i2][j2].pairnum == pairnum)
                            {
                                curr_i = i2;
                                curr_j = j2;
                                break;
                            }
                        }
                    }
                    // if (!curr_j.exists || !curr_j.visited)
                    // {
                    //
                    // }
                } while(!(curr_i == i && curr_j == j));

                if (curr_i == i && curr_j == j)
                {
                    return 1;
                }
            }
    return 0;
}

int notpairings(simplewh wormholes[12][12], int pairsleft)
{
    if (pairsleft == 0)
    {
        return 1;
    }
    // bool visited
    
}

int main()
{
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");

    int n;
    fin >> n;

    wormhole wormholes[12];

    for (int i = 0; i < n; i++)
    {
        long long x, y;
        fin >> x >> y;
        wormholes[i].x = x;
        wormholes[i].y = y;
    }

    sort(wormholes, wormholes+n, compwh);

    simplewh numrow[12][12] = {{{0, 0, 0}}};

    long long curr_y = -1;
    int curr_j = 0;
    int curr_i = -1;

    for (int i = 0; i < n; i++)
    {
        if (wormholes[i].y == curr_y)
        {
            numrow[curr_i][curr_j].exists = 1;
            curr_j++;
        }
        else
        {
            curr_i++;
            curr_j = 0;
            curr_y = wormholes[i].y;
            numrow[curr_i][curr_j].exists = 1;
        }
    }

    return 0;
}
