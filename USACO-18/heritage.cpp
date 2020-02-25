/*
ID: 11athom1
TASK: heritage
LANG: C++
*/

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int order[500];

char tleft[500];
char tright[500];
//char parent[500];

string inorder, preorder;

ofstream fout("heritage.out");
void output(char root)
{
    if (tleft[root])
        output(tleft[root]);
    if (tright[root])
        output(tright[root]);
    fout << root;
}

void addtotree(char root, char add)
{
    if (order[add] < order[root])
    {
        if (tleft[root])
            addtotree(tleft[root], add);
        else
            tleft[root] = add;
    }
    else
    {
        if (tright[root])
            addtotree(tright[root], add);
        else
            tright[root] = add;
    }
}

//void maketree(char curr, int nexti)
//{
//    cout << curr << " " << nexti << endl;
//    output(preorder[0]);
//    cout << endl;
//    if (nexti != preorder.length())
//    {
//        if (order[preorder[nexti]] < order[curr])
//        {
//            parent[preorder[nexti]] = curr;
//            tleft[curr] = preorder[nexti];
//            maketree(tleft[curr], nexti+1);
//        }
//        else
//        {
//            if (!parent[curr] || order[preorder[nexti]] < order[parent[curr]])
//            {
//                if (!tright[curr])
//                {
//                    parent[preorder[nexti]] = curr;
//                    tright[curr] = preorder[nexti];
//                    maketree(tright[curr], nexti+1);
//                }
//                else
//                {
//                    maketree(tright[curr], nexti);
//                }
//            }
//            else
//            {
//                maketree(parent[curr], nexti);
//            }
//        }
//    }
//}

int main(int argc, char** argv) 
{
    ifstream fin("heritage.in");
    
    fin >> inorder >> preorder;
    
    for (int i = 0; i < inorder.length(); i++)
    {
        order[inorder[i]] = i;
    }
    
    for (int i = 1; i < preorder.length(); i++)
    {
        addtotree(preorder[0], preorder[i]);
    }
    
    output(preorder[0]);
    fout << endl;
    
    return 0;
}

