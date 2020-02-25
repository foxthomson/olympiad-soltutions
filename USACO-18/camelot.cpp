/*
ID: 11athom1
TASK: camelot
LANG: C++
*/

#include <fstream>
#include <queue>
#include <iostream>
#include <ctime>

#define ABS(x) ((x)>0 ? (x) : -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

using namespace std;

int width, height;
int numknight = 0;

int kingcost[30][26];
int shortknight[30][26][30][26];
int knightx[9000];
int knighty[9000];

int main(int argc, char** argv)
{
    ifstream fin("camelot.in");
    ofstream fout("camelot.out");
    
//    cout << fin.peek() << endl;
    
    fin >> width >> height;
//    cout << width << " " << height << endl;
//    cout << fin.peek() << endl;
//    cout << EOF << endl;
    
//    cout << time(0) << endl;
    for (int x1 = 0; x1 < width; x1++)
    for (int x2 = 0; x2 < width; x2++)
    for (int y1 = 0; y1 < height; y1++)
    for (int y2 = 0; y2 < height; y2++)
        shortknight[x1][y1][x2][y2] = 9999999;
    
    for (int x1 = 0; x1 < width; x1++)
    for (int y1 = 0; y1 < height; y1++)
    {
        queue<int> xq;
        queue<int> yq;
        queue<int> depth;
        xq.push(x1);
        yq.push(y1);
        depth.push(0);
        
        bool searched[30][30];
        for (int i = 0; i < 30; i++)
            for (int j = 0; j < 30; j++)
            {
                searched[i][j] = false;
            }
        searched[x1][y1] = true;
//        shortknight[x1][y1][x1][y1] = 0;
        
//        cout << x1 << " " << y1 << endl;
        
        while (!depth.empty())
        {
//            if (x1 == 0 && y1 == 0){ 
//        for (int i = 0; i < 30; i++){
//            for (int j = 0; j < 30; j++)
//            {
//                cout << searched[i][j] << " ";
//            }cout << endl;}cout << endl;}
            
            int currx = xq.front();
            int curry = yq.front();
            int currd = depth.front();
//            cout << " " << currx << " " << curry << " " << currd << endl;
            xq.pop(); yq.pop(); depth.pop();
            shortknight[x1][y1][currx][curry] = currd;
        
            
            for (int xsign = -1; xsign <= 1; xsign+=2)
            for (int ysign = -1; ysign <= 1; ysign+=2)
            for (int xadd = 1; xadd <= 2; xadd++)
            {
                if (0 <= currx+xsign*xadd && currx+xsign*xadd < width)
                if (0 <= curry+ysign*(3-xadd) && curry+ysign*(3-xadd) < height)
                if (!searched[currx+xsign*xadd][curry+ysign*(3-xadd)])
                {
                    xq.push(currx+xsign*xadd);
                    yq.push(curry+ysign*(3-xadd));
                    depth.push(currd+1);
                    searched[currx+xsign*xadd][curry+ysign*(3-xadd)] = true;
                }
            }
        }
        
//        for (int xsign = -1; xsign <= 1; xsign+=2)
//        for (int ysign = -1; ysign <= 1; ysign+=2)
//        for (int xadd = 1; xadd <= 2; xadd++)
//        {
//            if (0 <= x1+xsign*xadd && x1+xsign*xadd < width)
//            if (0 <= y1+ysign*(3-xadd) && y1+ysign*(3-xadd) < height)
//                shortknight[x1][y1][x1+xsign*xadd][y1+ysign*(3-xadd)] = 1;
//        }
    }
    
//    cout << time(0) << endl;
//    for (int x1 = 0; x1 < width; x1++)
//    for (int y1 = 0; y1 < height; y1++)
//        for (int x3 = 0; x3 < width; x3++)
//        for (int y3 = 0; y3 < height; y3++)
//            for (int x2 = 0; x2 < width; x2++)
//            for (int y2 = 0; y2 < height; y2++)
//            {
//                if (shortknight[x1][y1][x3][y3] > shortknight[x1][y1][x2][y2] + shortknight[x2][y2][x3][y3])
//                {
//                    shortknight[x1][y1][x3][y3] = shortknight[x1][y1][x2][y2] + shortknight[x2][y2][x3][y3];
//                    shortknight[x3][y3][x1][y1] = shortknight[x1][y1][x2][y2] + shortknight[x2][y2][x3][y3];
//                }
//            }
//    
//    cout << time(0) << endl;
//    for (int x1 = 0; x1 < width; x1++){
//    for (int y1 = 0; y1 < height; y1++)
//        cout << shortknight[0][0][x1][y1] << "\t"; cout << endl;}
        
    char kingy;
    int kingx;
    fin >> kingy >> kingx;
    kingy -= 'A';
    kingx--;
    
//    cout << fin.peek() << endl;
//    if (fin.peek()==EOF)
//        cout << "EOF" << endl;

    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
        {
            kingcost[x][y] = MAX(ABS(x-kingx), ABS(y-kingy));
        }
    
//    for (int x1 = 0; x1 < width; x1++){
//    for (int y1 = 0; y1 < height; y1++)
//        cout << kingcost[x1][y1] << "\t"; cout << endl;}
        
//    cout << "A" << endl;
    
    char ky;
    int kx;
    while (fin >> ky)
    {
        fin >> kx;
//        cout << "C" << endl;;
        ky -= 'A';
        kx--;
        knightx[numknight] = kx;
        knighty[numknight] = ky;
        numknight++;
//        cout << kx+0 << " " << ky << endl;
    }
    
    int best = 9999999;
    for (int xaim = 0; xaim < width; xaim++)
    for (int yaim = 0; yaim < height; yaim++)
    {
        int cost = 0;
        bool broken = false;
        for (int i = 0; i < numknight; i++){
            cost += shortknight[knightx[i]][knighty[i]][xaim][yaim];
            
//            if (cost > best){broken = true; break;}
//            if (xaim == 1 && yaim == 4)
//                cout << shortknight[knightx[i]][knighty[i]][xaim][yaim] << " ";
        }
//        cout << cost << " ";
//        cout << xaim << " " << yaim << " " << cost << endl;
        if (broken) continue;
//        if (xaim == 1 && yaim == 4)
//            cout << endl;
        
        if (cost > best) continue;
        if (cost+kingcost[xaim][yaim] < best)
        best = cost+kingcost[xaim][yaim];
        
        
        for (int xjoin = MAX(0, xaim-kingcost[xaim][yaim]); xjoin < width && xjoin <= xaim+kingcost[xaim][yaim]; xjoin++)
        for (int yjoin = MAX(0, yaim-kingcost[xaim][yaim]); yjoin < height && yjoin <= yaim+kingcost[xaim][yaim]; yjoin++)
        {
            for (int i = 0; i < numknight; i++)
            {
                int score = cost - shortknight[knightx[i]][knighty[i]][xaim][yaim];
                score += shortknight[knightx[i]][knighty[i]][xjoin][yjoin];
                score += shortknight[xjoin][yjoin][xaim][yaim];
                score += kingcost[xjoin][yjoin];
                if (score < best){
                    best = score;
//                    cout << "Cost: " << cost << endl;
//                    cout << "i to aim: " << shortknight[knightx[i]][knighty[i]][xaim][yaim] << endl;
//                    cout << "i to join: " << shortknight[knightx[i]][knighty[i]][xjoin][yjoin] << endl;
//                    cout << "join to aim: " << shortknight[xjoin][yjoin][xaim][yaim] << endl;
//                    cout << "king cost: " << kingcost[xjoin][yjoin] << endl;
////                    cout << cost << " " << shortknight[knightx[i]][knighty[i]][xjoin][yjoin] << " " << kingcost[xjoin][yjoin] << " " << shortknight[xjoin][yjoin][xaim][yaim] << " " << shortknight[knightx[i]][knighty[i]][xjoin][yjoin] << endl;
//                    cout << score << endl << xaim << " " <<yaim << endl << i << endl << xjoin << " " << yjoin << endl;
                }
//                cout << best << endl;
            }
        }
    }
    
    fout << best << endl;
    
//    for (int x = 0; x < width; x++)
//    {for (int y = 0; y < height; y++)
//    {
//        cout << cost[x][y] << "\t";
//    } cout << endl;
//    } cout << endl;
////    cout << "B" << endl;
//    
//    for (int x = 0; x < width; x++)
//    for (int y = 0; y < height; y++)
//    {
////        cout << x << " " << y << endl;
//        
//        queue<int> xq;
//        queue<int> yq;
//        queue<int> depth;
//        xq.push(x);
//        yq.push(y);
//        depth.push(0);
//        
//        bool searched[30][30];
//        int cost[30][30];
//        for (int i = 0; i < 30; i++)
//            for (int j = 0; j < 30; j++)
//            {
//                searched[i][j] = false;
//                cost[i][j] = 0;
//            }
//        
//        searched[x][y] = true;
//        
//        while (!depth.empty())
//        {
////            cout << xq.empty() << yq.empty() << depth.empty() << endl;
//            
////            cout << " " << xq.front() << " " << yq.front() << endl;
////            cout << " " << depth.size() << " " << xq.size() << endl;
////            cout << depth.front() << endl;
////            cout << "front" << endl;
//            int currx = xq.front();
//            int curry = yq.front();
//            int currd = depth.front();
////            if (x==0 && y==2)
////            {
////                cout << currx << " " << curry << " " << currd << " " << cost[currx][curry] << endl;
////            }
////            cout << "    " << depth.size() << " " << xq.size() << endl;
////            cout << "pop" << endl;
//            xq.pop(); yq.pop(); depth.pop();
//            
////            cout << "    " << depth.size() << " " << xq.size() << endl;
////            cout << "cost" << endl;
//            cost[currx][curry] += currd;
//            
//            
////            cout << "  -2-1" << endl;
//            if (currx - 2 >= 0 && curry - 1 >= 0 && !searched[currx - 2][curry - 1])
//            {
////                cout << "  -2-1" << endl;
//                xq.push(currx-2);
//                yq.push(curry-1);
////                cout << "         " << depth.size() << " " << xq.size() << endl;
//                depth.push(currd + numknight[x][y]);
////                cout << "  " << depth.front() << endl;
//                searched[currx-2][curry-1] = true;
//            }
////            cout << "  -1-2" << endl;
//            if (currx - 1 >= 0 && curry - 2 >= 0 && !searched[currx - 1][curry - 2])
//            {
//                
////                cout << "  -1-2" << endl;
//                xq.push(currx-1);
//                yq.push(curry-2);
////                cout << "         " << depth.size() << " " << xq.size() << endl;
//                depth.push(currd + numknight[x][y]);
////                cout << "e        " << depth.size() << " " << xq.size() << endl;
////                cout << "  " << depth.front() << endl;
//                searched[currx-1][curry-2] = true;
////                cout << "d        " << depth.size() << " " << xq.size() << endl;
//            }
//            
////                cout << "c        " << depth.size() << " " << xq.size() << endl;
////            cout << "  -2+1" << endl;
//            if (currx - 2 >= 0 && curry + 1 < height && !searched[currx - 2][curry + 1])
//            {
////                cout << "  -2+1" << endl;
//                xq.push(currx-2);
//                yq.push(curry+1);
////                cout << "         " << depth.size() << " " << xq.size() << endl;
//                depth.push(currd + numknight[x][y]);
////                cout << "  " << depth.front() << endl;
//                searched[currx-2][curry+1] = true;
//            }
//                
////                cout << "b        " << depth.size() << " " << xq.size() << endl;
////            cout << "  -1+2" << endl;
//            if (currx - 1 >= 0 && curry + 2 < height && !searched[currx - 1][curry + 2])
//            {
////                cout << "  -1+2" << endl;
//                xq.push(currx-1);
//                yq.push(curry+2);
////                cout << "         " << depth.size() << " " << xq.size() << endl;
//                depth.push(currd + numknight[x][y]);
////                cout << "  " << depth.front() << endl;
//                searched[currx-1][curry+2] = true;
//            }
//                
////                cout << "a        " << depth.size() << " " << xq.size() << endl;
////            cout << "  +2-1" << endl;
////            cout << " > > > > " << depth.size() << " " << xq.size() << endl;
//            if (currx + 2 < width && curry - 1 >= 0 && !searched[currx + 2][curry - 1])
//            {
//                xq.push(currx+2);
//                yq.push(curry-1);
////                cout << currx << " " << curry << " " << currd << " " << depth.size() << endl;
////                cout << " > > > > " << depth.size() << " " << xq.size() << endl;
////                cout << currd + numknight[x][y] << endl;
//                depth.push(currd + numknight[x][y]);
//                searched[currx+2][curry-1] = true;
//            }
////            cout << "  +1-2" << endl;
//            if (currx + 1 < width && curry - 2 >= 0 && !searched[currx + 1][curry - 2])
//            {
//                xq.push(currx+1);
//                yq.push(curry-2);
////                cout << "         " << depth.size() << " " << xq.size() << endl;
//                depth.push(currd + numknight[x][y]);
////                cout << "  " << depth.front() << endl;
//                searched[currx+1][curry-2] = true;
//            }
////            cout << "  +2+1" << endl;
//            if (currx + 2 < width && curry + 1 < height && !searched[currx + 2][curry + 1])
//            {
//                xq.push(currx+2);
//                yq.push(curry+1);
////                cout << "         " << depth.size() << " " << xq.size() << endl;
//                depth.push(currd + numknight[x][y]);
////                cout << "  " << depth.front() << endl;
//                searched[currx+2][curry+1] = true;
//            }
////            cout << "  +1+2" << endl;
//            if (currx + 1 < width && curry + 2 < height && !searched[currx + 1][curry + 2])
//            {
//                xq.push(currx+1);
//                yq.push(curry+2);
////                cout << "         " << depth.size() << " " << xq.size() << endl;
//                depth.push(currd + numknight[x][y]);
////                cout << "  " << depth.front() << endl;
//                searched[currx+1][curry+2] = true;
//            }
////            cout << "NONE" << endl;
//        }
////        if (numknight[x][y])
////        {
////            cout << x << " " << y << endl;
////            for (int x = 0; x < width; x++)
////            {for (int y = 0; y < height; y++)
////            {
////                cout << cost[x][y] << "\t";
////            } cout << endl;
////            } cout << endl;
////        }
//    }
//    
//    int best = 0;
//    for (int x = 0; x < width; x++)
//    {for (int y = 0; y < height; y++)
//    {
//        cout << cost[x][y] << "\t";
//        if (!best || best > cost[x][y])
//            best = cost[x][y];
//    } cout << endl;
//    }
//    fout << best << endl;
    
    return 0;
}