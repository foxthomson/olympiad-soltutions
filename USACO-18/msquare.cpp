/*
ID: 11athom1
TASK: msquare
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int convtoindex(string arrange, int size)
{
    if (size == 0) return 0;
    int add = (arrange[0]-'0'-1)*fact[size-1];
//    cout << add << " " << size << endl;
    for (int i = 0; i < size; i++)
    {
//        cout << arrange[i] << " ";
        if (arrange[i] > arrange[0])
        {
            arrange[i]--;
        }
    }
//    cout << endl;
    return add + convtoindex(arrange.substr(1), size - 1);
}

string convtoarrange(int n, int size)
{
    if (size == 0)
    {
        return "";
    }
    char add = (n/fact[size-1] + 1) + '0';
    string prev = convtoarrange(n%fact[size-1], size-1);
    for (int i = 0; i < size-1; i++)
    {
        if (prev[i] >= add)
        {
            prev[i] = prev[i] + 1;
        }
    }
    return add + prev;
}

string a(string to)
{
    string from = "00000000";
    from[0] = to[7];
    from[1] = to[6];
    from[2] = to[5];
    from[3] = to[4];
    from[4] = to[3];
    from[5] = to[2];
    from[6] = to[1];
    from[7] = to[0];
    return from;
}

string b(string to)
{
    string from = "00000000";
    from[0] = to[3];
    from[1] = to[0];
    from[2] = to[1];
    from[3] = to[2];
    from[4] = to[5];
    from[5] = to[6];
    from[6] = to[7];
    from[7] = to[4];
    return from;
}

string c(string to)
{
    string from = to;
    from[1] = to[6];
    from[2] = to[1];
    from[5] = to[2];
    from[6] = to[5];
    return from;
}


bool found[40320];
int prev[40320];
char move[40320];
int depth[40320];

int main(int argc, char** argv) 
{
    ifstream fin("msquare.in");
    ofstream fout("msquare.out");
    
    string aim = "";
    for (int i = 0; i < 8; i++)
    {
        char c;
        fin >> c;
        aim += c;
    }
    
    queue<int> q;
    q.push(0);
    int aimindex = convtoindex(aim, 8);
    found[0] = true;
    depth[0] = 0;
    
    if (aimindex == 0)
    {
        fout << 0 << endl << endl;
        return 0;
    }
    
    while (1)
    {
        int searching = q.front();
        string searchingarrange = convtoarrange(searching, 8);
        q.pop();
        // A
        int aindex = convtoindex(a(searchingarrange), 8);
        if (!found[aindex])
        {
            found[aindex] = true;
            prev[aindex] = searching;
            move[aindex] = 'A';
            q.push(aindex);
            depth[aindex] = depth[searching] + 1;
            if (aindex == aimindex)
                break;
        }

        // B
        int bindex = convtoindex(b(searchingarrange), 8);
        if (!found[bindex])
        {
            found[bindex] = true;
            prev[bindex] = searching;
            move[bindex] = 'B';
            q.push(bindex);
            depth[bindex] = depth[searching] + 1;
            if (bindex == aimindex)
                break;
        }

        // C
        int cindex = convtoindex(c(searchingarrange), 8);
        if (!found[cindex])
        {
            found[cindex] = true;
            prev[cindex] = searching;
            move[cindex] = 'C';
            q.push(cindex);
            depth[cindex] = depth[searching] + 1;
            if (cindex == aimindex)
            {
                
                break;
            }
        }
    }
    
    
    int curr = aimindex;
    char ans[40320];
    for (int i = 0; curr != 0; i++)
    {
        ans[i] = move[curr];
        curr = prev[curr];
    }
    int j = depth[aimindex];
    fout << j;
    for (int i = j-1; i>=0; i--)
    {
        if ((j-i-1)%60==0)
        {
            fout << endl;
        }
        fout << ans[i];
    }
    fout << endl;
    if (0 == aimindex)
        fout << endl;
    
//    int asearch[40320];
//    int bsearch[40320];
//    int csearch[40320];
//    int numa = 1;
//    int numb = 0;
//    int numc = 0;
//    asearch[0] = aimindex;
//    found[aimindex] = true;
//    prev[aimindex] = -1;
//    
//    int nextasearch[40320];
//    int nextbsearch[40320];
//    int nextcsearch[40320];
//    int nextnuma = 0;
//    int nextnumb = 0;
//    int nextnumc = 0;    
//    
//    int j = 0;
//    
//    while (!found[0])
//    {
//        j++;
//        for (int i = 0; i < numa; i++)
//        {
//            int searching = asearch[i];
//            string searchingarrange = convtoarrange(searching, 8);
//            
//            // A
//            int aindex = convtoindex(a(searchingarrange), 8);
//            if (!found[aindex])
//            {
//                found[aindex] = true;
//                prev[aindex] = searching;
//                move[aindex] = 'A';
//                nextasearch[nextnuma] = aindex;
//                nextnuma++;
//            }
//        }
//        for (int i = 0; i < numb; i++)
//        {
//            int searching = bsearch[i];
//            string searchingarrange = convtoarrange(searching, 8);
//            
//            // A
//            int aindex = convtoindex(a(searchingarrange), 8);
//            if (!found[aindex])
//            {
//                found[aindex] = true;
//                prev[aindex] = searching;
//                move[aindex] = 'A';
//                nextasearch[nextnuma] = aindex;
//                nextnuma++;
//            }
//        }
//        for (int i = 0; i < numc; i++)
//        {
//            int searching = csearch[i];
//            string searchingarrange = convtoarrange(searching, 8);
//            
//            // A
//            int aindex = convtoindex(a(searchingarrange), 8);
//            if (!found[aindex])
//            {
//                found[aindex] = true;
//                prev[aindex] = searching;
//                move[aindex] = 'A';
//                nextasearch[nextnuma] = aindex;
//                nextnuma++;
//            }
//        }
//        
//        for (int i = 0; i < numa; i++)
//        {
//            int searching = asearch[i];
//            string searchingarrange = convtoarrange(searching, 8);
//            
//            // B
//            int bindex = convtoindex(b(searchingarrange), 8);
//            if (!found[bindex])
//            {
//                found[bindex] = true;
//                prev[bindex] = searching;
//                move[bindex] = 'B';
//                nextbsearch[nextnumb] = bindex;
//                nextnumb++;
//            }
//        }
//        for (int i = 0; i < numb; i++)
//        {
//            int searching = bsearch[i];
//            string searchingarrange = convtoarrange(searching, 8);
//            
//            // B
//            int bindex = convtoindex(b(searchingarrange), 8);
//            if (!found[bindex])
//            {
//                found[bindex] = true;
//                prev[bindex] = searching;
//                move[bindex] = 'B';
//                nextbsearch[nextnumb] = bindex;
//                nextnumb++;
//            }
//        }
//        for (int i = 0; i < numc; i++)
//        {
//            int searching = csearch[i];
//            string searchingarrange = convtoarrange(searching, 8);
//            
//            // B
//            int bindex = convtoindex(b(searchingarrange), 8);
//            if (!found[bindex])
//            {
//                found[bindex] = true;
//                prev[bindex] = searching;
//                move[bindex] = 'B';
//                nextbsearch[nextnumb] = bindex;
//                nextnumb++;
//            }
//        }
//            
//        for (int i = 0; i < numa; i++)
//        {
//            int searching = asearch[i];
//            string searchingarrange = convtoarrange(searching, 8);
//            
//            // C
//            int cindex = convtoindex(c(searchingarrange), 8);
//            if (!found[cindex])
//            {
//                found[cindex] = true;
//                prev[cindex] = searching;
//                move[cindex] = 'C';
//                nextcsearch[nextnumc] = cindex;
//                nextnumc++;
//            }
//        }
//        for (int i = 0; i < numb; i++)
//        {
//            int searching = bsearch[i];
//            string searchingarrange = convtoarrange(searching, 8);
//            
//            // C
//            int cindex = convtoindex(c(searchingarrange), 8);
//            if (!found[cindex])
//            {
//                found[cindex] = true;
//                prev[cindex] = searching;
//                move[cindex] = 'C';
//                nextcsearch[nextnumc] = cindex;
//                nextnumc++;
//            }
//        }
//        for (int i = 0; i < numc; i++)
//        {
//            int searching = csearch[i];
//            string searchingarrange = convtoarrange(searching, 8);
//            
//            // C
//            int cindex = convtoindex(c(searchingarrange), 8);
//            if (!found[cindex])
//            {
//                found[cindex] = true;
//                prev[cindex] = searching;
//                move[cindex] = 'C';
//                nextcsearch[nextnumc] = cindex;
//                nextnumc++;
//            }
//        }
//        
//        
//        copy(nextasearch, nextasearch+nextnuma, asearch);
//        numa = nextnuma;
//        copy(nextbsearch, nextbsearch+nextnumb, bsearch);
//        numb = nextnumb;
//        copy(nextcsearch, nextcsearch+nextnumc, csearch);
//        numc = nextnumc;
//    }
//    
//    fout << j;
//    int curr = 0;
//    for (int i = 0; curr != aimindex; i++)
//    {
//        if (i%60==0)
//        {
//            fout << endl;
//        }
//        fout << move[curr];
//        curr = prev[curr];
//    }
//    fout << endl;
//    if (0 == aimindex)
//        fout << endl;
    
    return 0;
}

