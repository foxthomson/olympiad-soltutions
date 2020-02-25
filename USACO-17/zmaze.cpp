#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int n;

// 1(true) is good
//             x    z
bool surface1[100][100];
//             y    z
bool surface2[100][100];
//             x    y
bool surface3[100][100];

//            x    y    z
bool visited[100][100][100];

int startx, starty, startz;
int endx, endy, endz;

struct point
{
    int x;
    int y;
    int z;
    int length;
    int prevx;
    int prevy;
    int prevz;
};

queue<point> pointqueue;

int good(int x, int y, int z)
{
    return (surface1[x][z] && surface2[y][z] && surface3[x][y]);
}

void queue_point(point p)
{
    if (good(p.x, p.y, p.z) &&
        !visited[p.x][p.y][p.z] &&
        p.x >= 0 && p.y >= 0 && p.z >= 0 &&
        p.x < n && p.y < n && p.z < n)
    {
        // push
        // add to visited
    }
}

int main()
{
    ifstream fin("zmaze.in");

    // input
    fin >> n;

    // surface1
    for (int z = 0; z < n; z++)
    {
        string row;
        fin >> row;
        for (int x = 0; x < n; x++)
        {
            surface1[x][z] = (row[x] == '.');
            // cout << surface1[x][z];
        }
        // cout << endl;
    }

    // surface2
    for (int z = 0; z < n; z++)
    {
        string row;
        fin >> row;
        for (int y = 0; y < n; y++)
        {
            surface2[y][z] = (row[y] == '.');
            // cout << surface2[y][z];
        }
        // cout << endl;
    }

    // surface3
    for (int y = 0; y < n; y++)
    {
        string row;
        fin >> row;
        for (int x = 0; x < n; x++)
        {
            surface1[x][y] = (row[x] == '.');
            // cout << surface1[x][y];
        }
        // cout << endl;
    }

    fin >> startx >> starty >> startz;
    fin >> endx >> endy >> endz;

    // push start
    point s;
    s.x = startx; s.y = starty; s.z = startz;
    s.length = 0;

    pointqueue.push(s);
    visited[startx][starty][startz] = 1;

    // exit when done
    // bfs
    while (1)
    {
        // pop new point
        point consider = pointqueue.pop();

        // udnsew

    }

    return 0;
}
