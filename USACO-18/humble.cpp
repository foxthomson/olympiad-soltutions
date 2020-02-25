/*
ID: 11athom1
TASK: humble
LANG: C++
*/

#include <fstream>
#include <set>
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

set<long int, less<long int> > q;
//priority_queue<long int, vector<long int>, greater<long int> > q;
long int s[100];

int main(int argc, char** argv) 
{
    ifstream fin("humble.in");
    ofstream fout("humble.out");
    
    long int k, n;
    fin >> k >> n;
    
    for (long int i = 0; i < k; i++)
        fin >> s[i];
    
    q.insert(1);
//    q.push(1);
    
    int largestpush = 1;
    int numpush = 0;
    
    for (long int _ = 0; _ < n; _++)
    {
        long int next = *(q.begin());
        q.erase(q.begin());
//        long int next = q.top();
//        cout << next << endl;
//        while (!q.empty() && q.top() == next)
//            q.pop();
        
        for (long int i = 0; i < k; i++)
        {
//            cout << next*s[i]%s[i] << " " << s[i] << " " << next*s[i] << " " << next << endl;
            if (numpush < n || next*s[i] < largestpush)
                if (next*s[i]%s[i] == 0 && next*s[i]>=next)
                {
//                q.push(next*s[i]);
                    numpush += q.insert(next*s[i]).second;
                    if (next*s[i] > largestpush)
                        largestpush = next*s[i];
                }
        }
    }
    
    fout << *(q.begin()) << endl;

    return 0;
}

