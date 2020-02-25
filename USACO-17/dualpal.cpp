/*
ID: 11athom1
PROG: dualpal
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

char dict[21] = "0123456789ABCDEFGHIJ";

string convbase(int base, int num)
{
    // 90000

    string ans = "";

    // bool zeros = 0;

    int unit = 1;
    int power = 0;

    while (unit <= num)
    {
        unit *= base;
        power++;
    }

    unit /= base;
    power--;

    // cout << unit << base << power;

    while (power >= 0)
    {
        // cout << num << " " << unit << " " << ans << "\n";

        ans = ans + dict[num / unit];
        // cout << num % unit << "\n";
        num -= unit * (num / unit);
        // cout << num << "\n";
        unit /= base;
        power--;
    }

    return ans;
}

int main()
{
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");

    int n, s;
    fin >> n >> s;

    int count = 0;

    while (count < n)
    {
        s++;
        int pals = 0;
        for (int i = 2; i <= 10; i++)
        {
            string conv = convbase(i, s);
            int digits = conv.length();
            bool eql = 1;
            for (int j = 0; j < digits; j++)
            {
                if (conv[digits-j-1] != conv[j])
                {
                    eql = 0;
                    break;
                }
            }
            if (eql)
            {
                pals++;
                if (pals == 2)
                {
                    count++;
                    fout << s << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}
