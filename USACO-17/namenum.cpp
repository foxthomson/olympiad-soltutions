/*
ID: 11athom1
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


int main()
{
    ifstream fin("namenum.in");
    ifstream dict("dict.txt");
    ofstream fout("namenum.out");

    bool none = 1;

    stringstream strstream;
    long long brandl;
    string brand;
    fin >> brandl;
    strstream << brandl;
    strstream >> brand;

    // name(dict, fout, brand, "");

    while (!dict.eof())
    {
        string conv = "";

        string name;
        dict >> name;

        for (int i = 0; i < name.length(); i++)
        {
            switch (name[i])
            {
                case 'A':
                case 'B':
                case 'C':
                    conv += "2";
                    break;
                case 'D':
                case 'E':
                case 'F':
                    conv += "3";
                    break;
                case 'G':
                case 'H':
                case 'I':
                    conv += "4";
                    break;
                case 'J':
                case 'K':
                case 'L':
                    conv += "5";
                    break;
                case 'M':
                case 'N':
                case 'O':
                    conv += "6";
                    break;
                case 'P':
                case 'R':
                case 'S':
                    conv += "7";
                    break;
                case 'T':
                case 'U':
                case 'V':
                    conv += "8";
                    break;
                case 'W':
                case 'X':
                case 'Y':
                    conv += "9";
                    break;
            }
        }
        if (conv == brand)
        {
            fout << name << "\n";
            none = 0;
        }
    }

    if (none)
    {
        fout << "NONE\n";
    }

    return 0;
}
