/*
ID: 11athom1
TASK: shopping
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

int bestprice[6][6][6][6][6];

int offercode[99][5];
int offernum[99][5];
int offerprice[99];
int offersize[99];

int required[5];
int codes[5];
int anticodes[999];
int price[5];

int main(int argc, char** argv) 
{
    ifstream fin("shopping.in");
    ofstream fout("shopping.out");
    
    int s;
    fin >> s;
    
    for (int i = 0; i < s; i++)
    {
        fin >> offersize[i];
        for (int j = 0; j < offersize[i]; j++)
        {
            fin >> offercode[i][j] >> offernum[i][j];
        }
        fin >> offerprice[i];
    }
    
    int b;
    fin >> b;
    
    for (int i = 0; i < b; i++)
    {
        fin >> codes[i] >> required[i] >> price[i];
        anticodes[codes[i]] = i+1;
    }
    
    for (int a = 0; a <= required[0]; a++)
    for (int b = 0; b <= required[1]; b++)
    for (int c = 0; c <= required[2]; c++)
    for (int d = 0; d <= required[3]; d++)
    for (int e = 0; e <= required[4]; e++)
    {
        bestprice[a][b][c][d][e] = a*price[0]
                                 + b*price[1]
                                 + c*price[2]
                                 + d*price[3]
                                 + e*price[4];
    }
    
    for (int i = 0; i < s; i++)
    {
        int numa = 0;
        int numb = 0;
        int numc = 0;
        int numd = 0;
        int nume = 0;
        
        for (int j = 0; j < offersize[i]; j++)
        {
            if (offercode[i][j] == codes[0]) numa = offernum[i][j];
            if (offercode[i][j] == codes[1]) numb = offernum[i][j];
            if (offercode[i][j] == codes[2]) numc = offernum[i][j];
            if (offercode[i][j] == codes[3]) numd = offernum[i][j];
            if (offercode[i][j] == codes[4]) nume = offernum[i][j];
        }
        
        for (int a = 0; a <= required[0]-numa; a++)
        for (int b = 0; b <= required[1]-numb; b++)
        for (int c = 0; c <= required[2]-numc; c++)
        for (int d = 0; d <= required[3]-numd; d++)
        for (int e = 0; e <= required[4]-nume; e++)
        {
//            cout << a << " " << b << " " << bestprice[a+numa][b+numb][c+numc][d+numd][e+nume] << " " << bestprice[a][b][c][d][e] + offerprice[i] << endl;
            if (bestprice[a+numa][b+numb][c+numc][d+numd][e+nume] > bestprice[a][b][c][d][e] + offerprice[i])
            {
                bestprice[a+numa][b+numb][c+numc][d+numd][e+nume] = bestprice[a][b][c][d][e] + offerprice[i];
            }
        }
//            for (int aa = 0; aa <= required[0]; aa++)
//            {
//                for (int bb = 0; bb <= required[1]; bb++)
//                {
//                    cout << bestprice[aa][bb][0][0][0] << " ";
//                }
//                cout << endl;
//            }
//            cout << endl;
    }
    
//    cout << required[0] << endl << required[1] << endl << required[2] << endl << required[3] << endl << required[4] << endl;
//    cout << bestprice[required[0]][required[1]][required[2]][required[3]][required[4]] << endl;
//    cout << bestprice[3][2][0][0][0];
    fout << bestprice[required[0]][required[1]][required[2]][required[3]][required[4]] << endl;
    
    return 0;
}

