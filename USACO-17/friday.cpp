/*
ID: 11athom1
PROG: friday
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream fin("friday.in");
    ofstream fout("friday.out");

    int n;
    fin >> n;

    // int year = 0;
    int thirteens[7] = {0};
    const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = 5;

    for (int year = 0; year < n; year++)
    {
        for (int month = 0; month < 12; month++)
        {
            thirteens[day]++;
            day = (day + days[month]) % 7;
            if (month == 1 && year % 4 == 0 && (year % 100 != 0 || (year+300) % 400 == 0))
            {
                day = (day + 1) % 7;
                // cout << year;
            }
        }
    }

    fout << thirteens[5] << " "
         << thirteens[6] << " "
         << thirteens[0] << " "
         << thirteens[1] << " "
         << thirteens[2] << " "
         << thirteens[3] << " "
         << thirteens[4] << "\n";

    return 0;
}
