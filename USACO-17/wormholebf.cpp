/*
ID: 11athom1
PROG: wormhole
LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct Wormhole
{
    long long x;
    long long y;
};

struct Simple
{
    bool exists{0};
    bool linked{0};
    int link_a;
    int link_b;
};

bool looped(Simple wormholes[12][12])
{
    bool visited[12][12] = {0};

    // iterate for each WH
    for (int a = 0; a < 12; a++)
    {
        for (int b = 0; b < 12; b++)
        {
            // check viable
            if (!visited[a][b] && wormholes[a][b].exists && wormholes[a][b].linked)
            {
                int cow_a = a;
                int cow_b = b;

                // move cow until she escapes or returns to (a, b)
                while (1)
                {
                    // cout << "  (" << cow_a << "," << cow_b << ")(" << a << "," << b << ")" << endl;
                    cow_b++;

                    // catch overflow
                    if (cow_b >= 12)
                    {
                        break;
                    }

                    // visited[cow_a][cow_b] = 1; only visited if walking out of, not into

                    Simple enter = wormholes[cow_a][cow_b];

                    // check if wormhole linked
                    if (!enter.exists || !enter.linked)
                    {
                        // cout << "->(" << cow_a << "," << cow_b << ")\n";
                        break;
                    }

                    // teleport
                    cow_a = enter.link_a;
                    cow_b = enter.link_b;
                    // cout << "->(" << cow_a << "," << cow_b << ")\n";
                    visited[cow_a][cow_b] = 1;

                    // check for returning to start
                    if (cow_a == a && cow_b == b)
                    {
                        // cout << "exit 1" << endl;
                        return 1;
                    }
                }
                // cout << endl;
            }
        }
    }
    // no loop
    // cout << "exit 0" << endl;
    return 0;
}

int noloop(int n, Simple wormholes[12][12])
{
    // for (int a = 0; )

    // base case
    if (n == 0)
    {
        return 1;
    }

    // search for first unlinked WH
    int link1_a = -1;
    int link1_b = -1;

    for (int a = 0; a < 12; a++)
    {
        for (int b = 0; b < 12; b++)
        {
            if (wormholes[a][b].exists && !wormholes[a][b].linked)
            {
                link1_a = a;
                link1_b = b;
                break;
            }
        }
        if (link1_a != -1)
        {
            break;
        }
    }

    // set link flag
    wormholes[link1_a][link1_b].linked = 1;

    // number of pairings with no loops
    int ans = 0;

    // Try linking to the other unlinked WHs
    for (int link2_a = 0; link2_a < 12; link2_a++) // can start from link1 as the rest are linked
    {
        for (int link2_b = 0; link2_b < 12; link2_b++)
        {
            // check if unlinked
            // cout << n << ":" << ans << endl;
            if (wormholes[link2_a][link2_b].exists && !wormholes[link2_a][link2_b].linked)
            {
                // link
                wormholes[link2_a][link2_b].linked = 1;
                wormholes[link2_a][link2_b].link_a = link1_a;
                wormholes[link2_a][link2_b].link_b = link1_b;
                wormholes[link1_a][link1_b].link_a = link2_a;
                wormholes[link1_a][link1_b].link_b = link2_b;
                // cout << "l1a " << link1_a << " l1b " << link1_b << " l2a " << link2_a << " l2b " << link2_b << endl;

                // Check if no loop created
                if (!looped(wormholes))
                {
                    // Add pairings with no loop to current answer
                    ans += noloop(n-2, wormholes);
                }

                // unlink
                wormholes[link2_a][link2_b].linked = 0;
            }
        }
    }

    // remove link flag
    wormholes[link1_a][link1_b].linked = 0;

    return ans;
}

int main()
{
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");

    // input
    int n;
    fin >> n;

    // cout << n << endl;

    Wormhole locations[12];

    for (int i = 0; i < n; i++)
    {
        long long x, y;
        fin >> x >> y;
        locations[i].x = x;
        locations[i].y = y;
    }

    // simplify locations

    sort(locations, locations + n, [&](Wormhole wh1, Wormhole wh2){return wh1.y<wh2.y;});

    //               a   b
    Simple wormholes[12][12];

    int ypoint = -1;
    int apoint = -1;
    int bpoint;

    for (int i = 0; i < n; i++)
    {
        // cout << locations[i].x << locations[i].y << endl;
        if (locations[i].y != ypoint)
        {
            ypoint = locations[i].y;
            apoint++;
            bpoint = 0;
        }
        else
        {
            bpoint++;
        }
        wormholes[apoint][bpoint].exists = 1;
    }

    // count posible pairings
    int tempn = n;
    // cout << "tempn:" << tempn << endl;
    int numpairings = 1;
    while (tempn > 0)
    {
        // cout << numpairings << tempn << endl;
        numpairings *= tempn-1;
        tempn -= 2;
    }

    // cout << numpairings << endl;

    // cout << numpairings << endl << noloop(n, wormholes) << endl;

    fout << numpairings - noloop(n, wormholes) << endl;

    return 0;
}
