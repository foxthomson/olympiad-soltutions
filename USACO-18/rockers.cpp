/*
ID: 11athom1
TASK: rockers
LANG: C++
*/

#include <fstream>

using namespace std;

int songs[30];
int numsong[31][30]; // [using disks][using songs]
int timeremaining[31][30];

int main(int argc, char** argv) 
{
    ifstream fin("rockers.in");
    ofstream fout("rockers.out");
    
    int n, t, m;
    fin >> n >> t >> m;
    int j = 0;
    int nn = n;
    for (int i = 0; i < nn; i++)
    {
        fin >> songs[j];
        if (songs[j] > t)
            n--;
        else
            j++;
    }
    
    for (int disksused = 1; disksused <= m; disksused++)
    {
        for (int usingsongs = 0; usingsongs < n; usingsongs++)
        {
            numsong[disksused][usingsongs] = numsong[disksused-1][usingsongs-1] + 1;
            timeremaining[disksused][usingsongs] = songs[usingsongs];
            
            if (numsong[disksused][usingsongs] <= numsong[disksused-1][usingsongs])
            {
                numsong[disksused][usingsongs] = numsong[disksused-1][usingsongs];
                timeremaining[disksused][usingsongs] = 0;
            }
            
            for (int usedsongs = 0; usedsongs < usingsongs; usedsongs++)
            {
                // can add new song
                if (timeremaining[disksused][usedsongs] + songs[usingsongs] <= t)
                {
                    // improves numsongs
                    if (numsong[disksused][usingsongs] < numsong[disksused][usedsongs] + 1)
                    {
                        numsong[disksused][usingsongs] = numsong[disksused][usedsongs] + 1;
                        timeremaining[disksused][usingsongs] = timeremaining[disksused][usedsongs] + songs[usingsongs];
                    }
                    // improves timeremaining
                    if (numsong[disksused][usingsongs] == numsong[disksused][usedsongs] + 1 && 
                        timeremaining[disksused][usingsongs] > timeremaining[disksused][usedsongs] + songs[usingsongs])
                    {
                        numsong[disksused][usingsongs] = numsong[disksused][usedsongs] + 1;
                        timeremaining[disksused][usingsongs] = timeremaining[disksused][usedsongs] + songs[usingsongs];
                    }
                }
                
                // is better numsongs
                if (numsong[disksused][usingsongs] < numsong[disksused][usedsongs])
                {
                    numsong[disksused][usingsongs] = numsong[disksused][usedsongs];
                    timeremaining[disksused][usingsongs] = timeremaining[disksused][usedsongs];
                }
                // is better timeremaining
                if (numsong[disksused][usingsongs] == numsong[disksused][usedsongs] && 
                    timeremaining[disksused][usingsongs] > timeremaining[disksused][usedsongs])
                {
                    numsong[disksused][usingsongs] = numsong[disksused][usedsongs];
                    timeremaining[disksused][usingsongs] = timeremaining[disksused][usedsongs];
                }
            }
        }
    }
    
    fout << numsong[m][n-1] << endl;
    
    return 0;
}

