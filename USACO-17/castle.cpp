/*
ID: 11athom1
PROB: castle
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int m, n;

// adjacency list
//         mx  ny
int castle[50][50];

// room labling
// 0 denotes not labled
int room[50][50];

// sizes of rooms (1-indexed)
int sizes[50*50 + 1];

int flood_fill(int room_num, int x, int y)
{
    // returns size of room

    if (room[x][y] == 0 && x < m && y < n && y >= 0 && x >= 0)
    {
        // cout << x << y << "\n{\n";
        // can be filled
        room[x][y] = room_num;

        // size of flood room
        int size = 1;

        // west
        if (!(castle[x][y] & 1))
        {
            size += flood_fill(room_num, x-1, y);
        }

        // north
        if (!(castle[x][y] & 2))
        {
            size += flood_fill(room_num, x, y-1);
        }

        // east
        if (!(castle[x][y] & 4))
        {
            size += flood_fill(room_num, x+1, y);
        }

        // south
        if (!(castle[x][y] & 8))
        {
            size += flood_fill(room_num, x, y+1);
        }

        // cout << "}\n";

        return size;
        // return 1 + flood_fill(room_num, x+1) + flood_fill(room_num, x-1) + flood_fill(room_num, y+1) + flood_fill(room_num, y-1);
    }
    else
    {
        // can't be filled
        return 0;
    }
}

int main()
{
    // input
    ifstream fin("castle.in");
    ofstream fout("castle.out");

    fin >> m >> n;

    // input grid
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            fin >> castle[x][y];
            // cout << castle[x][y] << " ";
        }
        // cout << endl;
    }

    // cout << castle[1][0] << endl;
    // cout << !(castle[1][0]&1) << !(castle[1][0]&2) << !(castle[1][0]&4) << !(castle[1][0]&8) << endl;

    // keep track of number of rooms
    int totrooms = 0;
    // keep track of size of rooms
    int maxroom = 0;

    // lable rooms
    for (int x = 0; x < m; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (room[x][y] == 0)
            {
                totrooms++;
                int size = flood_fill(totrooms, x, y);

                sizes[totrooms] = size;

                if (size > maxroom)
                {
                    maxroom = size;
                }
                // cout << endl;
            }
        }
    }

    // output number of rooms
    fout << totrooms << endl;
    // output largest room
    fout << maxroom << endl;

    // keep track of best
    int maxpair = 0;
    int wall_x, wall_y;
    char dir;

    // work west to east then up each column
    for (int x = 0; x < m; x++)
    {
        for (int y = n-1; y >= 0; y--)
        {
            // cout << x << y << endl;
            // check north then east
            // find rooms being connected and add sizes if different
            // north
            if (y != 0)
            {
                if (castle[x][y] & 2)
                {
                    // get size
                    int groupedsize;

                    if (room[x][y] == room[x][y-1])
                    {
                        // cout << groupedsize << x << y << endl;
                        groupedsize = sizes[room[x][y]];
                    }
                    else
                    {
                        groupedsize = sizes[room[x][y]] + sizes[room[x][y-1]];
                    }

                    // update max
                    if (groupedsize > maxpair)
                    {
                        // cout << x << " " << y << " " << sizes[room[x][y]] << " " << room[x][y] << " " << room[x][y-1] << " " << (room[x][y] == room[x][y-1]) << endl;
                        // cout << groupedsize << " " << sizes[room[x][y]] << x << y << endl;
                        maxpair = groupedsize;
                        wall_x = x;
                        wall_y = y;
                        dir = 'N';
                    }
                }
            }

            // east
            if (x != m-1)
            {
                if (castle[x][y] & 4)
                {
                    // get size
                    int groupedsize;

                    if (room[x][y] == room[x+1][y])
                    {
                        groupedsize = sizes[room[x][y]];
                    }
                    else
                    {
                        groupedsize = sizes[room[x][y]] + sizes[room[x+1][y]];
                    }

                    // update max
                    if (groupedsize > maxpair)
                    {
                        // cout << x << " " << y << " " << sizes[room[x][y]] << "E" << endl;
                        maxpair = groupedsize;
                        wall_x = x;
                        wall_y = y;
                        dir = 'E';
                    }
                }
            }
        }
    }

    // output best size and position
    fout << maxpair << endl << wall_y + 1 << " " << wall_x + 1 << " " << dir << endl;
}
