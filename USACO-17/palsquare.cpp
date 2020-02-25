/*
ID: 11athom1
PROG: palsquare
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

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
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");

    // cout << convbase(2, 50) << "\n";
    // cout << convbase(20, 19);

    int base;
    fin >> base;

    for (int n = 1; n <= 300; n++)
    {
        // cout << base;
        string square = convbase(base, n*n);
        string reversed = square;
        reverse(reversed.begin(), reversed.end());

        if (square.compare(reversed) == 0)
        {
            // cout << n;
            fout << convbase(base, n) << " " << square << "\n";
        }
    }

    return 0;
}
