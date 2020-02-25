/*
ID: 11athom1
TASK: fence6
LANG: C++
*/

#include <fstream>
#include <queue>
#include <utility>
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

typedef pair<int, pair<int, int> > triple;

int n;
bool connected1[100][100];
bool connected2[100][100];
int length[100];

int main(int argc, char** argv) 
{
    ifstream fin("fence6.in");
    ofstream fout("fence6.out");
    
    fin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int s, n1, n2;
        fin >> s;
        fin >> length[s-1] >> n1 >> n2;
        
        for (int j = 0; j < n1; j++)
        {
            int join;
            fin >> join;
            connected1[s-1][join-1] = true;
        }
        
        for (int j = 0; j < n2; j++)
        {
            int join;
            fin >> join;
            connected2[s-1][join-1] = true;
        }
    }
    
//    for (int x = 0; x < n; x++) {
//    for (int y = 0; y < n; y++)
//        cout << connected1[x][y] << " ";
//    cout << endl; }
//    
//    cout << endl;
//    for (int x = 0; x < n; x++) {
//    for (int y = 0; y < n; y++)
//        cout << connected2[x][y] << " ";
//    cout << endl; }
    
    int best = 0;
    for (int i = 0; i < n; i++)
    {
//        cout << endl << i+1 << endl;
        bool first = true;
        priority_queue<triple, vector<triple>, greater<triple> > tosearch; // length, fence, side
        pair<int, int> p1(i, 0);
        triple p2(0, p1);
        tosearch.push(p2);
        
        bool searched[100][2];
        for (int j = 0; j < 100; j++)
        {
            searched[j][0] = false;
            searched[j][1] = false;
        }
        
        while (1)
        {
            triple searching = tosearch.top();
            tosearch.pop();
            int index = searching.second.first;
            int currlen = searching.first;
            int end = searching.second.second;
//            cout << currlen << " " << index+1 << " " << end << endl;
            if (searched[index][end]) continue;
            
            if (!first && index == i && end == 0)
            {
                if (!best || currlen < best)
                {
                    best = currlen;
                }
                break;
            }
            
            if (!end)
            {
                for (int j = 0; j < n; j++)
                {
                    if (connected1[index][j])
                    {
//                        cout << " 1! ";
                        if (connected1[j][index])
                        {
//                            if (j == i)
//                            {
//                                if (!best || currlen - length[index] < best)
//                                {
//                                    best = currlen - length[index];
//                                }
//                                break;
//                            }
                            
                            if (!searched[j][1])
                            {
//                                cout << " " << j+1 << endl;
                                pair<int, int> p3(j, 1);
                                triple p4(currlen + length[j], p3);
                                tosearch.push(p4);
                            }
                        }
                        else if (connected2[j][index] && !searched[j][0])
                        {
//                            cout << " " << j+1 << endl;
                            pair<int, int> p3(j, 0);
                            triple p4(currlen + length[j], p3);
                            tosearch.push(p4);
                        }
                    }
                }
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    if (connected2[index][j])
                    {
//                        cout << " 2! ";
                        if (connected1[j][index] && !searched[j][1])
                        {
//                            cout << " " << j+1 << endl;
                            pair<int, int> p3(j, 1);
                            triple p4(currlen + length[j], p3);
                            tosearch.push(p4);
                        }
                        else if (connected2[j][index] && !searched[j][0])
                        {
//                            cout << " " << j+1 << endl;
                            pair<int, int> p3(j, 0);
                            triple p4(currlen + length[j], p3);
                            tosearch.push(p4);
                        }
                    }
                }
            }
            if (!first)
            searched[index][end] = true;
            first = false;
        }
//        cout << best << endl;
    }
    
    fout << best << endl;
    
    return 0;
}

