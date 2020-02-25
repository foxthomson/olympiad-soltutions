#include <fstream>
#include <iostream>

using namespace std;

int f(int* groups, int numgroups)
{
    if (!numgroups) return 1;
    
    int numnone = 0;
    for (int i = 0; i < numgroups; i++)
    {
        if (groups[i])
        {
            numnone++;
        }
    }
    if (numnone <= 1) return 1;
//    cout << endl;
    int ans = 0;
    for (int i = 0; i < numgroups; i++)
    {
        if (groups[i])
        {
            groups[i]--;
            ans += f(groups, numgroups);
            groups[i]++;
        }
    }
    return ans;
}

//int fact(int n)
//{
//    if (!n) return 1;
//    return n*fact(n-1);
//}

int murderer[128];
int murdered[128];
int numdead[128];
int deadways[128][128];
bool dead[128];
int bodycount[128][128];
int deadmult[128];

int main(int argc, char** argv) 
{
    ifstream fin("murder.in");
    ofstream fout("murder.out");
    
    for (int i = 0; i < 128; i++)
    {
        deadmult[i] = 1;
    }
    
    int n;
    fin >> n;
    
    for (int i = 0; i < n-1; i++)
    {
        int inp;
        fin >> inp;
        murdered[i] = inp-1;
        murderer[murdered[i]]++;
    }
    
    while (murderer[n-1])
    {
        for (int i = 0; i < n; i++)
        {
            if (!murderer[i] && !dead[i])
            {
                
//                cout << i+1 << " " << murdered[i]+1 << " " << murderer[murdered[i]] << endl;
                int murderedby = murdered[i];
                deadmult[murderedby] *= deadmult[i]*f(bodycount[i], numdead[i]);
                for (int j = 0; j < numdead[i]; j++)
                {
                    bodycount[murderedby][numdead[murderedby]] += bodycount[i][j];
                }
                bodycount[murderedby][numdead[murderedby]]++;
//                deadways[murderedby][numdead[murderedby]] = f(bodycount[i], numdead[i]);
                numdead[murderedby]++;
                murderer[murderedby]--;
                dead[i] = true;
            }
        }
//        cout << endl << "####\n";
//        for (int j = 0; j < n; j++)
//        {
//            for (int i = 0; i < numdead[j]; i++)
//                cout << deadways[j][numdead[j]] << " ";
//            cout << " | " << murderer[j] << endl;
//        }
//        cout << endl << "----\n";
    }
    
//    for (int j = 0; j < n; j++)
//    {
//        for (int i = 0; i < numdead[j]; i++)
//            cout << deadways[j][numdead[j]] << " ";
//        cout << endl;
//    }
    
    fout << deadmult[n-1]*f(bodycount[n-1], numdead[n-1]) << endl;
    
    return 0;
}

