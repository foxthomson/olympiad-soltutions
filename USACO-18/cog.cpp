#include <fstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>

#define X first
#define Y second


using namespace std;

int cx[100000];
int cy[100000];
pair<int,int> ts[100000];

int main(int argc, char** argv) 
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int c, t;
    fin >> c >> t;
    
    for (int i = 0; i < c; i++)
    {
        fin >> cx[i] >> cy[i];
    }
    for (int i = 0; i < t; i++)
    {
        int f, s;
        fin >> f >> s;
        ts[i] = make_pair(f,s);
    }
    
    sort(ts, ts+t, [](pair<int, int> a, pair<int, int> b) {
        if (a.first==b.first) return a.Y > b.Y;
        return a.X < b.X;
    });
    
    int upper[100000];
    int usize = 2;
    upper[0] = 0;
    upper[1] = 1;
//    cout << ts[0].X << " " << ts[0].Y << endl;
//    cout << ts[1].X << " " << ts[1].Y << endl;
        
    for (int i = 2; i < t; i++)
    {
//        cout << ts[i].X << " " << ts[i].Y << endl;
        int j = usize/2;
        int u = usize;
        int l = 0;
        while (j>0&&j<usize&&u>l)
        {
//            if (j>0&&j<usize)
//            {
//            cout << j;
            int l1x = ts[upper[j]].X-ts[upper[j-1]].X;
            int l1y = ts[upper[j]].Y-ts[upper[j-1]].Y;
            int l2x = ts[i].X-ts[upper[j]].X;
            int l2y = ts[i].Y-ts[upper[j]].Y;
            int l3x = ts[upper[j+1]].X-ts[upper[j]].X;
            int l3y = ts[upper[j+1]].Y-ts[upper[j]].Y;
            int l4x = ts[i].X-ts[upper[j+1]].X;
            int l4y = ts[i].Y-ts[upper[j+1]].Y;
            int cross1 = l1x*l2y - l1y*l2x;
            int cross2 = l3x*l4y - l3y*l4x;
//                cout << i << " " << j << " " << cross1 << " " << cross2 << endl;
            if (cross1 <= 0 && cross2 >= 0)
            {
                break;
            }
            if (cross1 > 0)
            {
                u = j;
                j = (u-l)/2+l;
            }
            else
            {
                l = j+1;
                j = (u-l)/2+l;
            }
//            }
        }
        usize = j+2;
        upper[j+1] = i;
//        cout << usize << endl;
    }
    
    pair<int, int> ts2[100000];
    copy(ts, ts+t, ts2);
    sort(ts2, ts2+t);
    
    int lower[100000];
    int lsize = 2;
    lower[0] = 0;
    lower[1] = 1;
//    cout << ts2[0].X << " " << ts2[0].Y << endl;
//    cout << ts2[1].X << " " << ts2[1].Y << endl;
    
    for (int i = 2; i < t; i++)
    {
//        cout << ts2[i].X << " " << ts2[i].Y << endl;
        int j = lsize/2;
        int u = lsize;
        int l = 0;
        while (j>0&&j<lsize&&u>l)
        {
//            if (j>0&&j<usize)
//            {
                int l1x = ts2[lower[j]].X-ts2[lower[j-1]].X;
                int l1y = -ts2[lower[j]].Y+ts2[lower[j-1]].Y;
                int l2x = ts2[i].X-ts2[lower[j]].X;
                int l2y = -ts2[i].Y+ts2[lower[j]].Y;
                int l3x = ts2[lower[j+1]].X-ts2[lower[j]].X;
                int l3y = -ts2[lower[j+1]].Y+ts2[lower[j]].Y;
                int l4x = ts2[i].X-ts2[lower[j+1]].X;
                int l4y = -ts2[i].Y+ts2[lower[j+1]].Y;
                int cross1 = l1x*l2y - l1y*l2x;
                int cross2 = l3x*l4y - l3y*l4x;
                if (cross1 <= 0 && cross2 >= 0)
                {
                    break;
                }
                if (cross1 > 0)
                {
                    u = j;
                    j = (u-l)/2+l;
                }
                else
                {
                    l = j+1;
                    j = (u-l)/2+l;
                }
//            }
        }
        lsize = j+2;
        lower[j+1] = i;

    }
    
    for (int i = 0; i < c; i++)
    {
        
    }
    
//    for (int i = 0; i < usize; i++)
//    {
//        cout << ts[upper[i]].X << " " << ts[upper[i]].Y << endl;
//    }
//    cout << endl;
//    
//    for (int i = 0; i < lsize; i++)
//    {
//        cout << ts[lower[i]].X << " " << ts[lower[i]].Y << endl;
//    }
    
    
}

