/*
ID: 11athom1
TASK: stamps
LANG: C++
*/

#include <fstream>
//#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//vector<int> numreq;
//short int numreq[2000000];
bool makeable[2000000];
int newmade[2000000];
int numnewmade;
int newnewmade[20000];
int numnewnewmade;
//int newmade;
//vector<int> newnewmade

int stamps[50];

int main(int argc, char** argv) 
{
    ifstream fin("stamps.in");
    ofstream fout("stamps.out");
    
    int n, k;
    fin >> n >> k;
//    cout << n << " " << k << endl;
    
    bool stamp1 = false;
    
    for (int i = 0; i < k; i++)
    {
//        int s;
//        fin >> s;
//        numreq[s] = 1;
        fin >> stamps[i];
        if (stamps[i] == 1)
            stamp1 = true;
    }
    
    sort(stamps, stamps+k);
    
//    int best = 0;
    
    makeable[0] = true;
    numnewmade = 1;
    newmade[0] = 0;
    
    for (int i = 0; i < n; i++)
    {
        numnewnewmade = 0;
//        int newbest = best;
        for (int j = 0; j < k; j++)
        {
            for (int r = 0; r < numnewmade; r++)
            {
                if (newmade[r]+stamps[j] < 2000000 && !makeable[newmade[r]+stamps[j]])
                {
                    makeable[newmade[r]+stamps[j]] = true;
                    newnewmade[numnewnewmade] = newmade[r]+stamps[j];
                    numnewnewmade++;
//                    cout << newmade[r]+stamps[j] << " ";
                }
            }
            
//            if (stamps[j] <= newbest+1)
//            {
//                cout << stamps[j] << " ";
//                if (stamps[j]+best > newbest)
//                    newbest = stamps[j]+best;
//            }
//            else
//                break;
        }
        copy(newnewmade, newnewmade+numnewnewmade, newmade);
        numnewmade = numnewnewmade;
//        cout << endl;
//        best = newbest;
//        cout << best << endl;
    }
    int i = 0;
    while (makeable[i]) i++;
    fout << i-1 << endl;
//    fout << best << endl;
    
//    int atomsused = 0;
//    int tomake = 1;
//    
//    while (1)
//    {
////        cout << tomake << " ";
//        if (atomsused < k)
//        {
//            for (int i = 0; i < k; i++)
//            {
//                if (tomake == stamps[i])
//                {
//                    numreq[tomake] = 1;
//                    atomsused++;
//                }
//            }
//            if (numreq[tomake])
//            {
//                tomake++;
//                continue;
//            }
//        }
//        
//        int stampsneeded = 0;
//        if (stampsneeded)
//        {
//            tomake++;
//            continue;
//        }
//        for (int i = 1; i <= tomake/2; i++)
//        {
//            if (numreq[i] + numreq[tomake-i] < stampsneeded || !stampsneeded)
//                stampsneeded = numreq[i] + numreq[tomake-i];
////            cout << i << "-" << numreq[i] << " ";
//        }
////        cout <<  (stampsneeded) << " " << tomake << endl;
//        if (stampsneeded && stampsneeded <= n)
//            numreq[tomake] = stampsneeded;
//        else
//            break;
//        
//        tomake++;
//    }
//    fout << tomake-1 << endl;
    
    return 0;
}

