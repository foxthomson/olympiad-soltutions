/*
ID: 11athom1
TASK: buylow
LANG: C++
*/

#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

long stocks[5000];
vector<int> paths[5000];
vector<int> newpaths[5000];

vector<int> addbignum(vector<int> a, vector<int> b)
{
    vector<int> sum;
    int carry = 0;
    int min = (a.size() < b.size()) ? a.size() : b.size();
    for (int i = 0; i < min; i++)
    {
        int part = a[i] + b[i] + carry;
        sum.push_back(part % 100000000);
        carry = part / 100000000;
//        cout << a[i] << " + " << b[i] << " = " << carry << " " << part % 10 << endl;
    }
    if (a.size() < b.size())
    {
        for (int i = min; i < b.size(); i++)
        {
            int part = b[i] + carry;
            sum.push_back(part % 100000000);
            carry = part / 100000000;
        }
    }
    else
    {
        for (int i = min; i < a.size(); i++)
        {
            int part = a[i] + carry;
            sum.push_back(part % 100000000);
            carry = part / 100000000;
        }
    }
    if (carry)
    {
        sum.push_back(carry);
    }
//    cout << endl;
    return sum;
}

int main(int argc, char** argv) 
{
    ifstream fin("buylow.in");
    ofstream fout("buylow.out");
    
    int n;
    fin >> n;
    
    vector<int> one, zero;
    one.push_back(1);
    zero.push_back(0);
    
    for (int i = 0; i < n; i++)
    {
        fin >> stocks[i];
        newpaths[i] = one;
    }
    
    int length = 0;
    bool running = true;
    while (running)
    {
        length++;
        running = false;
        copy(newpaths, newpaths+n, paths);
        for (int i = 0; i < n; i++)
        {
            newpaths[i] = zero;
        }
        for (int i = length-1; i < n; i++)
        {
            if (paths[i].size() == 1 && !paths[i][0])
                continue;
            int best = 0;
            for (int j = i+1; j < n; j++)
            {
                if (stocks[i] == stocks[j])
                    break;
                else if (stocks[i] > stocks[j])
                {
//                    cout << "AAAAAAA" << endl;
                    if (stocks[j] >= best)
                    {
                        paths[j] = zero;
                        newpaths[j] = addbignum(newpaths[j], paths[i]);
                        running = true;
                        best = stocks[j];
                    }
                }
            }
        }
    }
    
    int prev = 0;
    vector<int> ans = zero;
    for (int i = n-1; i>=0; i--)
    { 
//        fout << stocks[i] << " " << paths[i][length] << " " << i << endl;
        if ((stocks[i] < prev || (ans.size() == 1 && !ans[0])) && !(paths[i].size() == 1 && !paths[i][0]))
        {
            prev = stocks[i];
//            cout << "BBBBB" << endl;
            ans = addbignum(ans, paths[i]);
        }
    }
    
    fout << length << " ";

    fout << ans[ans.size()-1];
    for (int i = ans.size()-1; i > 0; i--)
    {
        if (ans[i-1])
        {
            int j = 10000000;
            while (ans[i-1] < j)
            {
                j /= 10;
                fout << 0;
            }
            fout << ans[i-1];
        }
        else
            fout << "000000";
    }

    fout << endl;
    
    return 0;
}

