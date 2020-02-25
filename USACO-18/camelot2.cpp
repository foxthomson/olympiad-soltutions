/*
ID: 11athom1
TASK: camelot
LANG: C++
*/

#include <fstream>
#include <queue>
#include <iostream>

#define ABS(x) ((x)>0 ? (x) : -(x))

using namespace std;

int width, height;
int numknight[30][30];

int cost[30][30];

int main(int argc, char** argv)
{
    ifstream fin("camelot.in");
    ofstream fout("camelot.out");
    
//    cout << fin.peek() << endl;
    
    fin >> width >> height;
//    cout << width << " " << height << endl;
//    cout << fin.peek() << endl;
//    cout << EOF << endl;
    
    char kingx;
    int kingy;
    fin >> kingx >> kingy;
    kingx -= 'A';
    kingy--;
    
//    cout << fin.peek() << endl;
//    if (fin.peek()==EOF)
//        cout << "EOF" << endl;

    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
        {
            cost[x][y] = ABS(x-kingx) + ABS(y-kingy);
        }
    
//    cout << "A" << endl;
    
    char knightx;
    int knighty;
    while (fin >> knightx)
    {
        fin >> knighty;
//        cout << "C" << endl;;
        knightx -= 'A';
        knighty--;
        numknight[knightx][knighty]++;
//        cout << knightx+0 << " " << knighty << endl;
    }
    for (int x = 0; x < width; x++)
    {for (int y = 0; y < height; y++)
    {
        cout << cost[x][y] << "\t";
    } cout << endl;
    } cout << endl;
//    cout << "B" << endl;
    
    for (int x = 0; x < width; x++)
    for (int y = 0; y < height; y++)
    {
//        cout << x << " " << y << endl;
        
        queue<int> xq;
        queue<int> yq;
        queue<int> depth;
        xq.push(x);
        yq.push(y);
        depth.push(0);
        
        bool searched[30][30];
        for (int i = 0; i < 30; i++)
            for (int j = 0; j < 30; j++)
                searched[i][j] = false;
        
        searched[x][y] = true;
        
        while (!depth.empty())
        {
//            cout << xq.empty() << yq.empty() << depth.empty() << endl;
            
//            cout << " " << xq.front() << " " << yq.front() << endl;
//            cout << " " << depth.size() << " " << xq.size() << endl;
//            cout << depth.front() << endl;
//            cout << "front" << endl;
            int currx = xq.front();
            int curry = yq.front();
            int currd = depth.front();
//            if (x==0 && y==2)
//            {
//                cout << currx << " " << curry << " " << currd << " " << cost[currx][curry] << endl;
//            }
//            cout << "    " << depth.size() << " " << xq.size() << endl;
//            cout << "pop" << endl;
            xq.pop(); yq.pop(); depth.pop();
            
//            cout << "    " << depth.size() << " " << xq.size() << endl;
//            cout << "cost" << endl;
            cost[currx][curry] += currd;
            
            
//            cout << "  -2-1" << endl;
            if (currx - 2 >= 0 && curry - 1 >= 0 && !searched[currx - 2][curry - 1])
            {
//                cout << "  -2-1" << endl;
                xq.push(currx-2);
                yq.push(curry-1);
//                cout << "         " << depth.size() << " " << xq.size() << endl;
                depth.push(currd + numknight[x][y]);
//                cout << "  " << depth.front() << endl;
                searched[currx-2][curry-1] = true;
            }
//            cout << "  -1-2" << endl;
            if (currx - 1 >= 0 && curry - 2 >= 0 && !searched[currx - 1][curry - 2])
            {
                
//                cout << "  -1-2" << endl;
                xq.push(currx-1);
                yq.push(curry-2);
//                cout << "         " << depth.size() << " " << xq.size() << endl;
                depth.push(currd + numknight[x][y]);
//                cout << "e        " << depth.size() << " " << xq.size() << endl;
//                cout << "  " << depth.front() << endl;
                searched[currx-1][curry-2] = true;
//                cout << "d        " << depth.size() << " " << xq.size() << endl;
            }
            
//                cout << "c        " << depth.size() << " " << xq.size() << endl;
//            cout << "  -2+1" << endl;
            if (currx - 2 >= 0 && curry + 1 < height && !searched[currx - 2][curry + 1])
            {
//                cout << "  -2+1" << endl;
                xq.push(currx-2);
                yq.push(curry+1);
//                cout << "         " << depth.size() << " " << xq.size() << endl;
                depth.push(currd + numknight[x][y]);
//                cout << "  " << depth.front() << endl;
                searched[currx-2][curry+1] = true;
            }
                
//                cout << "b        " << depth.size() << " " << xq.size() << endl;
//            cout << "  -1+2" << endl;
            if (currx - 1 >= 0 && curry + 2 < height && !searched[currx - 1][curry + 2])
            {
//                cout << "  -1+2" << endl;
                xq.push(currx-1);
                yq.push(curry+2);
//                cout << "         " << depth.size() << " " << xq.size() << endl;
                depth.push(currd + numknight[x][y]);
//                cout << "  " << depth.front() << endl;
                searched[currx-1][curry+2] = true;
            }
                
//                cout << "a        " << depth.size() << " " << xq.size() << endl;
//            cout << "  +2-1" << endl;
//            cout << " > > > > " << depth.size() << " " << xq.size() << endl;
            if (currx + 2 < width && curry - 1 >= 0 && !searched[currx + 2][curry - 1])
            {
                xq.push(currx+2);
                yq.push(curry-1);
//                cout << currx << " " << curry << " " << currd << " " << depth.size() << endl;
//                cout << " > > > > " << depth.size() << " " << xq.size() << endl;
//                cout << currd + numknight[x][y] << endl;
                depth.push(currd + numknight[x][y]);
                searched[currx+2][curry-1] = true;
            }
//            cout << "  +1-2" << endl;
            if (currx + 1 < width && curry - 2 >= 0 && !searched[currx + 1][curry - 2])
            {
                xq.push(currx+1);
                yq.push(curry-2);
//                cout << "         " << depth.size() << " " << xq.size() << endl;
                depth.push(currd + numknight[x][y]);
//                cout << "  " << depth.front() << endl;
                searched[currx+1][curry-2] = true;
            }
//            cout << "  +2+1" << endl;
            if (currx + 2 < width && curry + 1 < height && !searched[currx + 2][curry + 1])
            {
                xq.push(currx+2);
                yq.push(curry+1);
//                cout << "         " << depth.size() << " " << xq.size() << endl;
                depth.push(currd + numknight[x][y]);
//                cout << "  " << depth.front() << endl;
                searched[currx+2][curry+1] = true;
            }
//            cout << "  +1+2" << endl;
            if (currx + 1 < width && curry + 2 < height && !searched[currx + 1][curry + 2])
            {
                xq.push(currx+1);
                yq.push(curry+2);
//                cout << "         " << depth.size() << " " << xq.size() << endl;
                depth.push(currd + numknight[x][y]);
//                cout << "  " << depth.front() << endl;
                searched[currx+1][curry+2] = true;
            }
//            cout << "NONE" << endl;
        }
        if (numknight[x][y])
        {
            cout << x << " " << y << endl;
            for (int x = 0; x < width; x++)
            {for (int y = 0; y < height; y++)
            {
                cout << cost[x][y] << "\t";
            } cout << endl;
            } cout << endl;
        }
    }
    
    int best = 0;
    for (int x = 0; x < width; x++)
    {for (int y = 0; y < height; y++)
    {
        cout << cost[x][y] << "\t";
        if (!best || best > cost[x][y])
            best = cost[x][y];
    } cout << endl;
    }
    fout << best << endl;
    
    return 0;
}