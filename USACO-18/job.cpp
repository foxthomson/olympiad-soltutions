/*
ID: 11athom1
TASK: job
LANG: C++
*/

#include <fstream>
#include <iostream>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int freeatA[30];
int freeatB[30];
int freeuntilB[30];
int finishA[1000];
int timeA[30];
int timeB[30];
int timespentB[30];

int main(int argc, char** argv) 
{
    ifstream fin("job.in");
    ofstream fout("job.out");
    
    int n, m1, m2;
    fin >> n >> m1 >> m2;
    
    for (int i = 0; i < m1; i++)
    {
        fin >> timeA[i];
    }
    
    for (int i = 0; i < m2; i++)
    {
        fin >> timeB[i];
    }
    
    int besttime;
    for (int i = 0; i < n; i++)
    {
        besttime = freeatA[0] + timeA[0];
        int bestindex = 0;
        for (int j = 1; j < m1; j++)
        {
            if (freeatA[j] + timeA[j] < besttime)
            {
                besttime = freeatA[j] + timeA[j];
                bestindex = j;
            }
        }
        finishA[i] = besttime;
        freeatA[bestindex] = besttime;
    }
    fout << besttime << " ";
    
    int time = besttime;
    for (int i = n-1; i >= 0; i--)
    {
        int best = -9999999;
        int bestB = 0;
        for (int j = 0; j < m2; j++)
        {
            // try and fit job[i] into B[j]
            int cost = time - finishA[i] - timespentB[j] - timeB[j];
            if (cost > best)
            {
                bestB = j;
                best = cost;
            }
        }
        timespentB[bestB] += timeB[bestB];
        if (best < 0)
        {
            time -= best;
        }
    }
    fout << time << endl;
    
//    for (int i = n-1; i >= 0; i--)
//    {
//        int newbesttime = MAX(finishA[i], freeatB[0]) + timeB[0];
//        int bestindex = 0;
//        bool update = true;
//        for (int j = 0; j < m2; j++)
//        {
//            if (MAX(finishA[i], freeatB[j]) + timeB[j] < newbesttime) //schedual for next free cause faster
//            {
//                newbesttime = MAX(finishA[i], freeatB[j]) + timeB[j];
//                bestindex = j;
//            }
////            else if (MAX(finishA[i], freeatB[j]) + timeB[j] == besttime && timeB[j] > timeB[bestindex]) // schedual for next free cause slower machine
////            {
////                besttime = MAX(finishA[i], freeatB[j]) + timeB[j];
////                bestindex = j;
////            }
//            if (freeuntilB[j] && freeuntilB[j] >= timeB[j] + finishA[i])
//            {
////                cout << i << j << endl;
//                update = false;
//                freeuntilB[j] -= timeB[j];
//                bestindex = j;
//                break;
//            }
//        }
////        finishA[i] = besttime;
//        if (update) 
//        {
//            besttime = newbesttime;
//            freeatB[bestindex] = besttime;
//            if (!freeuntilB[bestindex])
//            {
//                freeuntilB[bestindex] = freeatB[bestindex] - timeB[bestindex];
//            }
//        }
////        cout << i << " " << finishA[i] << " " << bestindex << " " << freeuntilB[bestindex] << " " << freeatB[bestindex] << " " << timeB[bestindex] << endl;
//    }
//    fout << besttime << endl;
    
    return 0;
}

