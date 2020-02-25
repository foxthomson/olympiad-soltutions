/*
ID: 11athom1
TASK: maze1
LANG: C++11
*/

#include <fstream>
#include <queue>
#include <array>
#include <iostream>

using namespace std;

char maze[201][77];

bool visited[201][77];
queue<array<int, 2>> tovisit;

int main(int argc, char** argv) 
{
    ifstream fin("maze1.in");
    ofstream fout("maze1.out");
    
    // input
    int w, h;
    fin >> w >> h;
    
    if (w == 1 && h == 1)
    {
        fout << "1" << endl;
        return 0;
    }
    
    for (int i = 0; i < 2*h+1; i++)
    {
        char check = 'X';
        while (check!=' ' && check!='+' && check!='|' && check!='-')
            fin >> noskipws >> check;
        
        maze[i][0] = check;
        
        for (int j = 1; j < 2*w+1; j++)
            fin >> noskipws >> maze[i][j];
    }
        
    for (int i = 0; i < 2*h+1; i++)
    {
        for (int j = 0; j < 2*w+1; j++)
            cout << maze[i][j];
        cout << endl;
    }
    
    // find exits
    int x, y;
    bool first = true;
    int tosearch = 0;
    
    for (int i = 1; i < 2*h+1; i+=2)
    {
//        cout << i << " ";
        if (maze[i][0] == ' ')
        {
            if (first || x!=i || y!= 1)
            {
                tovisit.push({i, 1});
                visited[i][1] = true;
                tosearch++;
                x = i; y = 1;
                first = false;
            }
        }
        if (maze[i][2*w] == ' ')
        {
            if (first || x!=i || y!=2*w-1)
            {
                tovisit.push({i, 2*w-1});
                visited[i][2*w-1] = true;
                tosearch++;
                x = i; y = 2*w-1;
                first = false;
            }
        }
    }
//    cout << endl;
    
    for (int i = 1; i < 2*w+1; i+=2)
    {
//        cout << i << " ";
        if (maze[0][i] == ' ')
        {
            if (first || x!=1 || y!=i)
            {
                tovisit.push({1, i});
                visited[1][i] = true;
                tosearch++;
                x = 1; y = i;
                first = false;
            }
        }
        
        if (maze[2*h][i] == ' ')
        {
            if (first || x!=2*h-1 || y!=i)
            {
                tovisit.push({2*h-1, i});
                visited[2*h-1][i] = true;
                tosearch++;
                x = 2*h-1; y = i;
                first = false;
            }
        }
    }
//    cout << endl;
    
    // BFS
    int nexttosearch = 0;
    int searched = 0;
    cout << searched << endl;
    int dist = 0;
    while (searched < w*h)
    {
        cout << "-----" << endl;
        dist++;
        for (int _ = 0; _ < tosearch; _++)
        {
            int y = tovisit.front()[0];
            int x = tovisit.front()[1];
            tovisit.pop();
            
            cout << (x-1)/2 << " " << (y-1)/2 << endl;
            
            if (y != 1 && !visited[y-2][x] && maze[y-1][x] == ' ')
            {
                tovisit.push({y-2, x});
                visited[y-2][x] = true;
//                searched++;
                nexttosearch++;
            }
            
            if (y != 2*h-1 && !visited[y+2][x] && maze[y+1][x] == ' ')
            {
                tovisit.push({y+2, x});
                visited[y+2][x] = true;
//                searched++;
                nexttosearch++;
            }
            
            if (x != 1 && !visited[y][x-2] && maze[y][x-1] == ' ')
            {
                tovisit.push({y, x-2});
                visited[y][x-2] = true;
//                searched++;
                nexttosearch++;
            }
            
            if (x != 2*w-1 && !visited[y][x+2] && maze[y][x+1] == ' ')
            {
                tovisit.push({y, x+2});
                visited[y][x+2] = true;
//                searched++;
                nexttosearch++;
            }
            searched++;
        }
        
        tosearch = nexttosearch;
        nexttosearch = 0;
    }
    
    fout << dist << endl;
    
    return 0;
}

