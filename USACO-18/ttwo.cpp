/*
ID: 11athom1
TASK: ttwo
LANG: C++
*/

#include <fstream>
//#include <iostream>

using namespace std;

bool states[3][3][10][10][3][3][10][10];

int main(int argc, char** argv) 
{
    ifstream fin("ttwo.in");
    ofstream fout("ttwo.out");
    
    int ofx; int ofy; int ocx; int ocy;
    bool board[10][10];
    
    for (int y = 0; y < 10; y++)
        for (int x = 0; x < 10; x++)
        {
            char inp;
            fin >> inp;
            
            if (inp == '*')
                board[x][y] = true;
            else
                board[x][y] = false;
            
            if (inp == 'F')
            {
                ofx = x; ofy = y;
            }
            
            if (inp == 'C')
            {
                ocx = x; ocy = y;
            }
        }
    
    int fx = ofx; int fy = ofy;
    int fvx = 0; int fvy = -1;
    int cx = ocx; int cy = ocy;
    int cvx = 0; int cvy = -1;
    
    int c = 0;
    
    while (1)
    {
        c++;
        
        states[(fvx+1)][(fvy+1)][fx][fy][(cvx+1)][(cvy+1)][cx][cy] = true;
        
//        cout << fx << fy << " " << cx << cy << endl;
        
        // move farmer
        if (fx+fvx < 0 || fx+fvx > 9 || fy+fvy < 0 || fy+fvy > 9 || board[fx+fvx][fy+fvy])
        {
            // turn
            int temp = fvx;
            fvx = -fvy;
            fvy = temp;
        }
        else
        {
            // move
            fx += fvx;
            fy += fvy;
        }
        
        // move cows
        if (cx+cvx < 0 || cx+cvx > 9 || cy+cvy < 0 || cy+cvy > 9 || board[cx+cvx][cy+cvy])
        {
            // turn
            int temp = cvx;
            cvx = -cvy;
            cvy = temp;
        }
        else
        {
            // move
            cx += cvx;
            cy += cvy;
        }
        
        // they meet
        if (fx == cx && fy == cy)
        {
            fout << c << endl;
            break;
        }
        
        // return to a point
        if (states[(fvx+1)][(fvy+1)][fx][fy][(cvx+1)][(cvy+1)][cx][cy])
        {
            fout << 0 << endl;
            break;
        }
        
//        for (int y = 0; y < 10; y++)
//        {
//            for (int x = 0; x < 10; x++)
//            {
//                if (board[x][y])
//                {
//                    cout << '*';
//                }
//                else if (fx == x && fy == y)
//                {
//                    cout << 'F';
//                }
//                else if (cx == x && cy == y)
//                {
//                    cout << 'C';
//                }
//                else
//                {
//                    cout << '.';
//                }
//            }
//            cout << endl;
//        }
//        cout << c << (fvx+1)/2 << endl;
    }
    
    return 0;
}