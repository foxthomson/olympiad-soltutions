/*
ID: 11athom1
TASK: fracdec
LANG: C++
*/

#include <fstream>
//#include <iostream>

using namespace std;

int remainders[1000000];

int digits[1000000];

int main(int argc, char** argv) 
{
    ifstream fin("fracdec.in");
    ofstream fout("fracdec.out");
    
    int n, d;
    fin >> n >> d;
    
    fout << n/d << '.';
    
    int printed = 1 + (n/d==0);
    for (int out = n/d; out > 0; out/=10)
        printed++;
    
    int i = 1;
    int rem = n%d;
    int digit;
    
    while (1)
    {
        digit = (rem*10)/d;
        digits[i-1] = digit;
        remainders[rem] = i;
        
        if (remainders[(rem*10)%d] || (rem*10)%d==0)
            break;
        
        rem = (rem*10)%d;
        
        i++;
    }
    
//    cout << rem << "<rem i>" << i << " remainders[rem]>" << remainders[rem] << " digit>" << digit << endl;
//    cout << digits[remainders[rem]-1] << endl;
//    for (int j = 0; j < i; j++)
//        cout << digits[j];
    
    for (int j = 0; j < i - ((rem*10)%d==0 && i==1 && digit == 0); j++)
    {
        if (j == remainders[(rem*10)%d]-1 && (rem*10)%d!=0)
        {
            fout << "(";
            printed++;
        
            if (printed == 76)
            {
                fout << endl;
                printed = 0;
            }
        }
        
        fout << digits[j];
        printed++;
        
        if (printed == 76)
        {
            fout << endl;
            printed = 0;
        }
    }
    if ((rem*10)%d!=0)
        fout << ")";
    if (i == 1 && (rem*10)%d==0 && digit == 0)
        fout << 0;
    fout << endl;
    
    return 0;
}

