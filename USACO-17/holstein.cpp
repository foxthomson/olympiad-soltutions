/*
ID: 11athom
PROG: holstein
LANG: C++
*/

#include <iostream>
#include <fstream>
// #include <queue>

using namespace std;

int required[25];
int v;

int feeds[25][15];
int g;

bool queue[100000][15];
int qstart = 0;
int qend = 0;

int main()
{
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");

    // input requred
    fin >> v;
    for (int i = 0; i < v; i++)
    {
        fin >> required[i];
    }

    // clear queue
    for (int i = 0; i < 120; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            queue[i][j] = 0;
        }
    }

    // input feeds
    fin >> g;
    for (int i = 0; i < g; i++)
    {
        for (int j = 0; j < v; j++)
        {
            fin >> feeds[j][i];
        }
        // add to queue
        queue[qend][i] = 1;
        qend++;
    }

    // bfs
    // bool found = 0;
    while (1)
    {
        // cout << qstart << " " << qend << endl;
        // cout << qstart << " ";
        // 'pop'
        int qid = qstart;
        // cout << qstart << " ";
        qstart++;

        // cout << qid << " " << qstart << endl;

        // // DEBUG
        // for (int feedid = 0; feedid < g; feedid++)
        // {
        //     if (queue[qid][feedid])
        //     {
        //         cout << " " << feedid + 1;
        //     }
        // }
        // cout << endl;
        // // DEBUG

        // viable set of feeds
        int works = 1;

        // last feed used
        int last = 0;
        // cout << qstart << " ";

        // find if viable solution and find last feed used for queueing
        for (int vitid = 0; vitid < v; vitid++)
        {
            // calculate amount of vitimin
            int tot = 0;
            for (int feedid = 0; feedid < g; feedid++)
            {
                // cout << "loop"; // DEBUG
                if (queue[qid][feedid])
                {
                    // add to tot
                    tot += feeds[vitid][feedid];
                    // this is the last feed used
                    last = feedid;
                }
            }

            // cout << vitid << " " << qid << endl;
            // check if not enough
            if (tot < required[vitid])
            {
                works = 0;
                // cout << vitid << " " << qid << endl;
                break;
            }
        }
        // cout << qstart << " ";

        if (works)
        {
            // count number used
            int count = 0;
            for (int feedid = 0; feedid < g; feedid++)
            {
                if (queue[qid][feedid])
                {
                    count++;
                }
            }

            fout << count;

            // output feeds
            for (int feedid = 0; feedid < g; feedid++)
            {
                if (queue[qid][feedid])
                {
                    fout << " " << feedid + 1;
                }
            }

            fout << endl;
            break;
        }
        // cout << qstart << " ";

        // queue
        for (int newfeedid = last+1; newfeedid < g; newfeedid++)
        {
            // cout << newfeedid << " ";

            // copy curr
            for (int qfeedid = 0; qfeedid <= last; qfeedid++)
            {
                queue[qend][qfeedid] = queue[qid][qfeedid];
                // cout << queue[qid][qfeedid] << " ";
            }
            // cout << endl;

            // add new feed
            queue[qend][newfeedid] = 1;

            // 'push'
            qend++;
        }
        // cout << endl;
        // cout << "\n}" << qid;
        // cout << qstart << " ";
    }


    return 0;
}
