#include "game.h"
#include <stack>
#include <iostream>

#define GCD4(a, b, c, d) gcd2(gcd2(a, b), gcd2(c, d))

using namespace std;

long long gcd2(long long X, long long Y) {
    long long tmp;
    if (X == -1) return Y;
    while (X != Y && Y != 0) {
        tmp = X;
        X = Y;
        Y = tmp % Y;
    }
    return X;
}

long long grid[1000000];
// long long grid01[11000000];
// long long grid10[11000000];
// long long grid11[11000000];
int nextcell = 1;
int nextnodes[1000000][4];

void init(int R, int C)
{
    for (int i = 0; i < 1000000; i++)
    for (int j = 0; j < 4; j++)
    {
        nextnodes[i][j] = 999999;
        // cout << i << " " << j << " ";
    }
}

void update(int P, int Q, long long K)
{
    stack<int> toupdate;

    int lastnode = 0;

    for (int size = 1 << 29; size; size >>= 1)
    {
        int corner = 0;
        if (P >= size)
        {
            corner += 1;
            P -= size;
        }
        if (Q >= size)
        {
            corner += 2;
            Q -= size;
        }

        // cout << nextnodes[lastnode][corner] << " ";

        if (nextnodes[lastnode][corner] == 999999)
        {
            nextnodes[lastnode][corner] = nextcell;
            nextcell++;
        }

        toupdate.push(lastnode);
        lastnode = nextnodes[lastnode][corner];
        // lastnode++;
    }

    grid[lastnode] = K;

    while (!toupdate.empty())
    {
        int c = toupdate.top();
        toupdate.pop();
        // cout << grid[nextnodes[c][0]] << " " << grid[nextnodes[c][1]] << " " << grid[nextnodes[c][2]] << " " << grid[nextnodes[c][3]] << endl;
        // cout << nextnodes[c][0] << " " << nextnodes[c][1] << " " << nextnodes[c][2] << " " << nextnodes[c][3] << endl;
        grid[c] = GCD4(grid[nextnodes[c][0]], grid[nextnodes[c][1]], grid[nextnodes[c][2]], grid[nextnodes[c][3]]);
    }
}

long long calculate(int P, int Q, int U, int V)
{
    // cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";

    int ans = -1;
    stack<int> search;
    stack<int> depth;
    stack<int> addPU;
    stack<int> addQV;
    search.push(0);
    depth.push(29);
    addPU.push(0);
    addQV.push(0);

    while (!search.empty())
    {
        int node = search.top();
        int dep = depth.top();
        int pu = addPU.top();
        int qv = addQV.top();
        search.pop();
        depth.pop();
        addPU.pop();
        addQV.pop();

        if (node == 999999) continue;

        int pedge1 = pu;
        int pedge2 = pu + (1 << dep);
        int pedge3 = pu + (1 << (dep+1));
        int qedge1 = qv;
        int qedge2 = qv + (1 << dep);
        int qedge3 = qv + (1 << (dep+1));

        // cout << "(" << pedge1 << ", " << qedge1 << ") - (" << pedge3 << ", " << qedge3 << ") " << ans << endl;
        // cout << node << " -> " << nextnodes[node][0] << " " << nextnodes[node][1] << " " << nextnodes[node][2] << " " << nextnodes[node][3] << endl;

        bool coveredTL = false;
        bool coveredTR = false;
        bool coveredBL = false;
        bool coveredBR = false;

        if (P <= pedge1)
        {
            if (Q <= qedge1)
            {
                if (U >= pedge2-1)
                {
                    if (V >= qedge2-1)
                    {
                        // covers TL
                        ans = gcd2(ans, grid[nextnodes[node][0]]);
                        coveredTL = true;
                        // cout << "> (" << pedge1 << ", " << qedge1 << ") - (" << pedge2 << ", " << qedge2 << ") " << grid[nextnodes[node][0]] << " " << nextnodes[node][0] << endl;
                    }
                }

                if (!coveredTL)
                {
                    search.push(nextnodes[node][0]);
                    // cout << grid[nextnodes[node][0]] << " ";
                    depth.push(dep-1);
                    addPU.push(pu);
                    addQV.push(qv);
                    coveredTL = true;
                }
            }
        }

        if (!coveredTL && (P <= pedge2-1 && Q <= qedge2-1))
        {
            search.push(nextnodes[node][0]);
            // cout << grid[nextnodes[node][0]] << " ";
            depth.push(dep-1);
            addPU.push(pu);
            addQV.push(qv);
            coveredTL = true;
        }


        if (P <= pedge2)
        {
            if (Q <= qedge1)
            {
                if (U >= pedge3-1)
                {
                    if (V >= qedge2-1)
                    {
                        // covers TL
                        ans = gcd2(ans, grid[nextnodes[node][1]]);
                        coveredTR = true;
                        // cout << "> (" << pedge2 << ", " << qedge1 << ") - (" << pedge3 << ", " << qedge2 << ") " << grid[nextnodes[node][1]] << " " << nextnodes[node][1] << endl;
                    }
                }

                if (!coveredTR && U >= pedge2)
                {
                    search.push(nextnodes[node][1]);
                    // cout << grid[nextnodes[node][1]] << " ";
                    depth.push(dep-1);
                    addPU.push(pedge2);
                    addQV.push(qv);
                    coveredTR = true;
                }
            }
        }

        if (!coveredTR && (P <= pedge3-1 &&  Q <= qedge2-1 && U >= pedge2))
        {
            search.push(nextnodes[node][1]);
            // cout << grid[nextnodes[node][1]] << " ";
            depth.push(dep-1);
            addPU.push(pedge2);
            addQV.push(qv);
            coveredTR = true;
        }

        if (P <= pedge1)
        {
            if (Q <= qedge2)
            {
                if (U >= pedge2-1)
                {
                    if (V >= qedge3-1)
                    {
                        // covers TL
                        ans = gcd2(ans, grid[nextnodes[node][2]]);
                        coveredBL = true;
                        // cout << "> (" << pedge1 << ", " << qedge2 << ") - (" << pedge2 << ", " << qedge3 << ") " << grid[nextnodes[node][2]] << " " << nextnodes[node][2] << endl;
                    }
                }

                if (!coveredBL && V >= qedge2)
                {
                    search.push(nextnodes[node][2]);
                    // cout << grid[nextnodes[node][2]] << " ";
                    depth.push(dep-1);
                    addPU.push(pu);
                    addQV.push(qedge2);
                    coveredBL = true;
                }
            }
        }

        if (!coveredBL && (P <= pedge2-1 &&  Q <= qedge3-1 && V >= qedge2))
        {
            search.push(nextnodes[node][2]);
            // cout << grid[nextnodes[node][2]] << " ";
            depth.push(dep-1);
            addPU.push(pu);
            addQV.push(qedge2);
            coveredBL = true;
        }

        if (P <= pedge2)
        {
            if (Q <= qedge2)
            {
                if (U >= pedge3-1)
                {
                    if (V >= qedge3-1)
                    {
                        // covers TL
                        ans = gcd2(ans, grid[nextnodes[node][3]]);
                        coveredBR = true;
                        // cout << "> (" << pedge2 << ", " << qedge2 << ") - (" << pedge3 << ", " << qedge3 << ") " << grid[nextnodes[node][3]] << " " << nextnodes[node][3] << endl;
                    }
                }

                if (!coveredBR && U >= pedge2 && V >= qedge2)
                {
                    search.push(nextnodes[node][3]);
                    // cout << grid[nextnodes[node][3]] << " ";
                    depth.push(dep-1);
                    addPU.push(pedge2);
                    addQV.push(qedge2);
                    coveredBR = true;
                }
            }
        }

        if (!coveredBR && (P <= pedge3-1 && Q <= qedge3-1 && U >= pedge2 && V >= qedge2))
        {
            search.push(nextnodes[node][3]);
            // cout << grid[nextnodes[node][3]] << " ";
            depth.push(dep-1);
            addPU.push(pedge2);
            addQV.push(qedge2);
            coveredBR = true;
        }

        // cout << endl;
    }




    if (ans == -1) ans = 0;
    return ans;
}
