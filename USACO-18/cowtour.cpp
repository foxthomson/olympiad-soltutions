/*
ID: 11athom1
TASK: cowtour
LANG: C++
*/

#include <fstream>
#include <cmath>
//#include <iostream>
#include <iomanip>

#define len(x1, y1, x2, y2) sqrt(pow((x1)-(x2), 2) + pow((y1)-(y2), 2))

using namespace std;

int n;
long pos[2][150];
bool adj[150][150];

// for flood fill
int field[150];
bool searched[150];

// for Floyd Warshall
long double lengths[150][150];
long double shortest[150][150];

// for dijkstra
long double dijk[150][150];
bool minimal[150][150];

// For getting best pair
long double maxs[150];
long double diams[150];

void ff(int node, int colour)
{
    field[node] = colour;
    searched[node] = true;
    
    for (int i = 0; i < n; i++)
        if (adj[node][i] && !searched[i])
            ff(i, colour);
}

int main(int argc, char** argv) 
{
    ifstream fin("cowtour.in");
    ofstream fout("cowtour.out");
    
    fin >> n;
    
    for (int i = 0; i < n; i++)
        fin >> pos[0][i] >> pos[1][i];
    
    for (int i = 0; i < n; i++)
    {
        string temp;
        fin >> temp;
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = temp[j] == '1';
        }
    }
    // Flood fill
    int numcols = 0;
    for (int i = 0; i < n; i++)
        if (!searched[i])
        {
            ff(i, numcols);
            numcols++;
        }
    
    // get lengths of each pair of point for FW and help later
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            lengths[i][j] = len(pos[0][i], pos[1][i], pos[0][j], pos[1][j]);
            if (adj[i][j] || i == j)
            {
                shortest[i][j] = lengths[i][j];
            }
            else
            {
                shortest[i][j] = INFINITY;
            }
            dijk[i][j] = INFINITY;
        }
    
    // FW on each field
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (field[i] == field[j] && field[i] == field[k] && field[j] == field[k] && i!=j && i!=k && j!=k)
                {
                    if (shortest[i][k] + shortest[k][j] < shortest[i][j])
                    {
                        shortest[i][j] = shortest[i][k] + shortest[k][j];
                        shortest[j][i] = shortest[i][k] + shortest[k][j];
                    }
                }  
//                for (int i = 0; i < n; i++)
//                {
//                    for (int j = 0; j < n; j++)
//                        cout << shortest[i][j] << "\t";
//                    cout << endl;
//                }       
//                cout << endl;
            }
    
//    for (int source = 0; source < n; source++)
//    {
//        dijk[source][source] = 0;
//        minimal[source][source] = true;
//        int curr = source;   
//        while (1)
//        {
////            cout << "!!!!! " << curr << " !!!!!\n";
//            
//            int nextnode = -1;
//            for (int i = 0; i < n; i++)
//            {
//                if (!minimal[source][i])
//                {
//                    if (field[i] == field[source])
//                    {
//                        if (adj[i][curr])
//                        {
////                            cout << " " << i << " " << curr << endl;
//                            
////                            cout << " -- " << i << " " << curr << " " << dijk[source][i] << " " << dijk[source][curr] << " " << lengths[i][curr] << endl;
//                            dijk[source][i] = (dijk[source][i] < (dijk[source][curr]+lengths[i][curr])) ? dijk[source][i] : (dijk[source][curr]+lengths[i][curr]);
//    //                        cout << dijk[source][i] << endl;
//                        }
//                        if (nextnode < 0 || dijk[source][i] < dijk[source][nextnode])
//                        {
//                            nextnode = i;
//                        }
//                    }
//                }
//            }
//            if (nextnode == -1)
//            {
//                break;
//            }
//            minimal[source][nextnode] = true;
//            curr = nextnode;
//            cout << nextnode << endl;
//        }
//        cout << endl << endl;
//    }
    
    // get max length for each point
    for (int i = 0; i < n; i++)
    {
        long double longest = 0;
        for (int j = 0; j < n; j++)
            if ((shortest[i][j] > longest) && (field[i] == field[j]))
                longest = shortest[i][j];
//            if ((dijk[i][j] > longest) && (field[i] == field[j]))
//                longest = dijk[i][j];
        maxs[i] = longest;
    }
    
    // get diam for each field
    for (int i = 0; i < n; i++)
    {
        if (maxs[i] > diams[field[i]])
            diams[field[i]] = maxs[i];
    }
    
    // get shortest pair
    long double bestdiam = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (field[i] != field[j])
            {
                if ((lengths[i][j] + maxs[i] + maxs[j]) > diams[field[i]] && (lengths[i][j] + maxs[i] + maxs[j]) > diams[field[j]])
                {
                    if (bestdiam > (lengths[i][j] + maxs[i] + maxs[j]) || !bestdiam)
                        bestdiam = (lengths[i][j] + maxs[i] + maxs[j]);
//                cout << i << " " << j << " " << pos[0][i] << "," << pos[1][i] << " " << pos[0][j] << "," << pos[1][j] << " " << lengths[i][j] << " " << maxs[i] << " " << maxs[j] << endl;
                }
                else if (diams[field[i]] > diams[field[j]])
                {
                    if (bestdiam > diams[field[i]] || !bestdiam)
                        bestdiam = diams[field[i]];
                }
                else
                {
                    if (bestdiam > diams[field[j]] || !bestdiam)
                        bestdiam = diams[field[j]];
                }
            }
        }
    }
    
    fout << fixed << setprecision(6) << bestdiam << endl;
//    cout << bestdiam << endl;
//    
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = 0; j < 10; j++)
//            cout << dijk[i][j] << "\t";
//        cout << endl;
//    }       
//    cout << endl;
//    for (int i = 0; i < n; i++)
//    {
////        for (int j = 0; j < 10; j++)
////            cout << field[i] << "\t";
////        cout << endl;
//        cout << field[i] << " " << maxs[i] << endl;
//    }           
////    fout << endl;
////    for (int i = 0; i < n; i++)
////    {
////        for (int j = 0; j < n; j++)
////            fout << adj[i][j] << " ";
////        fout << endl;
////    }        
    
    return 0;
}
