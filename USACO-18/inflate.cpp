/*
ID: 11athom1
TASK: inflate
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int bestscore[10001]; // bestscore[j] = max points up to the (ith) all problem class with j mins
//int newbestscore[10001]; // bestscore[j] = max points up to the (i+1)th problem class with j mins
int points[10000];
int times[10001];
//bool searched[10001][10000];

//int inflate(int i, int j)
//{
//    if (searched[j][i])
//        return bestscore[j][i];
//    
//    if (i == 0)
//    {
//        
//        return (i/times[0])*points[0];
//    }
//    
//    int best = 0;
////            cout << i << " " << j << endl;
//    for (int k = 0; k*times[i] <= j; k++)
//    {
////                cout << i << j << k << endl;
//        int ans = inflate(i-1, j-k*times[i]) + k*points[i];
//        if (ans > best)
//            best = ans;
//    }
//    bestscore[j][i] = best;
//    searched[j][i] = true;
//    return best;
//}

int main(int argc, char** argv) 
{
    ifstream fin("inflate.in");
    ofstream fout("inflate.out");
    
    int m, n;
    fin >> m >> n;
    
//    cout << m << n;
    
    for (int i = 0; i < n; i++)
    {
        int p, t;
        fin >> p >> t;
        if (p > times[t])
            times[t] = p;
    }
//        fin >> points[i] >> times[i];
    
//    // base case, only one problem
//    for (int i = 0; i <= m; i++)
//    {
////        cout << time[i] << endl;
//        bestscore[i] = (i/times[0])*points[0];
//    }
//        
//    // all other cases
//    // find the max you can get taking bestscore[i-1][j], bestscore[i-1][j-time], bestscore[i-1][j-2time]...
//    for (int i = 1; i < n; i++)
//    {
//        for (int j = 0; j <= m; j++)
//        {
//            int best = 0;
////            cout << i << " " << j << endl;
//            for (int k = 0; k*times[i] <= j; k++)
//            {
////                cout << i << j << k << endl;
//                if (bestscore[j-k*times[i]] + k*points[i] > best)
//                    best = bestscore[j-k*times[i]] + k*points[i];
//            }
//            newbestscore[j] = best;
////            cout << best << " ";
//       }
////       cout << endl;
//       copy(newbestscore, newbestscore + m+1, bestscore);
//    }
    
    for (int j = 0; j <= m; j++)
    {
        int best = times[j];
        for (int minsplit = 1; minsplit <= j/2; minsplit++)
        {
//            cout << minsplit << " ";
            if (bestscore[minsplit] + bestscore[j-minsplit] > best)
                best = bestscore[minsplit] + bestscore[j-minsplit];
        }
         
//        cout << endl;
//        cout << j << " " << best << endl;
        bestscore[j] = best;
    }
    
    fout << bestscore[m] << endl;
    
    return 0;
}
