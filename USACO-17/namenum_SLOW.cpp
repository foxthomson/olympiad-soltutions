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

bool none = 1;

bool testdict(ifstream &dict, string search)
{
    string curr;
    int pos;
    int pos2;
    pos2 = dict.tellg();

    do {
        dict.seekg(pos2, ios_base::beg);
        pos = dict.tellg();
        dict >> curr;
        pos2 = dict.tellg();
        dict.seekg(pos, ios_base::beg);
        // cout << search.compare(curr);
    } while(search.compare(curr) > 0);

    // cout << search << " " << curr << "\n";
    dict.seekg(pos, ios_base::beg);
    return search.compare(curr) == 0;
}

// void name(ifstream dict, ofstream fout, string brand, string prev);

void name(ifstream &dict, ofstream &fout, string brand, string prev)
{
    // cout << brand;
    if (brand.length() == 1)
    {
        // cout << prev << "\n";
        switch (brand[0])
        {
            case '2': {
                if (testdict(dict, prev + "A"))
                {
                    fout << prev + "A" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "B"))
                {
                    fout << prev + "B" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "C"))
                {
                    fout << prev + "C" << "\n";
                    none = 0;
                }
                break;
            }
            case '3': {
                if (testdict(dict, prev + "D"))
                {
                    fout << prev + "D" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "E"))
                {
                    fout << prev + "E" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "F"))
                {
                    fout << prev + "F" << "\n";
                    none = 0;
                }
                break;
            }
            case '4': {
                if (testdict(dict, prev + "G"))
                {
                    fout << prev + "G" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "H"))
                {
                    fout << prev + "H" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "I"))
                {
                    fout << prev + "I" << "\n";
                    none = 0;
                }
                break;
            }
            case '5': {
                if (testdict(dict, prev + "J"))
                {
                    fout << prev + "J" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "K"))
                {
                    fout << prev + "K" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "L"))
                {
                    fout << prev + "L" << "\n";
                    none = 0;
                }
                break;
            }
            case '6': {
                if (testdict(dict, prev + "M"))
                {
                    fout << prev + "M" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "N"))
                {
                    fout << prev + "N" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "O"))
                {
                    fout << prev + "O" << "\n";
                    none = 0;
                }
                break;
            }
            case '7': {
                if (testdict(dict, prev + "P"))
                {
                    fout << prev + "P" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "R"))
                {
                    fout << prev + "R" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "S"))
                {
                    fout << prev + "S" << "\n";
                    none = 0;
                }
                break;
            }
            case '8': {
                if (testdict(dict, prev + "T"))
                {
                    fout << prev + "T" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "U"))
                {
                    fout << prev + "U" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "V"))
                {
                    fout << prev + "V" << "\n";
                    none = 0;
                }
                break;
            }
            case '9': {
                if (testdict(dict, prev + "W"))
                {
                    fout << prev + "W" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "X"))
                {
                    fout << prev + "X" << "\n";
                    none = 0;
                }
                if (testdict(dict, prev + "Y"))
                {
                    fout << prev + "Y" << "\n";
                    none = 0;
                }
                break;
            }
        }
    }
    else
    {
        switch (brand[0])
        {
            case '2': {
                brand.erase(brand.begin());
                name(dict, fout, brand, prev + "A");
                name(dict, fout, brand, prev + "B");
                name(dict, fout, brand, prev + "C");
                break;
            }
            case '3': {
                brand.erase(brand.begin());
                name(dict, fout, brand, prev + "D");
                name(dict, fout, brand, prev + "E");
                name(dict, fout, brand, prev + "F");
                break;
            }
            case '4': {
                brand.erase(brand.begin());
                name(dict, fout, brand, prev + "G");
                name(dict, fout, brand, prev + "H");
                name(dict, fout, brand, prev + "I");
                break;
            }
            case '5': {
                brand.erase(brand.begin());
                name(dict, fout, brand, prev + "J");
                name(dict, fout, brand, prev + "K");
                name(dict, fout, brand, prev + "L");
                break;
            }
            case '6': {
                brand.erase(brand.begin());
                name(dict, fout, brand, prev + "M");
                name(dict, fout, brand, prev + "N");
                name(dict, fout, brand, prev + "O");
                break;
            }
            case '7': {
                brand.erase(brand.begin());
                name(dict, fout, brand, prev + "P");
                name(dict, fout, brand, prev + "R");
                name(dict, fout, brand, prev + "S");
                break;
            }
            case '8': {
                brand.erase(brand.begin());
                name(dict, fout, brand, prev + "T");
                name(dict, fout, brand, prev + "U");
                name(dict, fout, brand, prev + "V");
                break;
            }
            case '9': {
                brand.erase(brand.begin());
                name(dict, fout, brand, prev + "W");
                name(dict, fout, brand, prev + "X");
                name(dict, fout, brand, prev + "Y");
                break;
            }
        }
    }
}

int main()
{
    ifstream fin("namenum.in");
    ifstream dict("dict.txt");
    ofstream fout("namenum.out");


    stringstream strstream;
    long long brandl;
    string brand;
    fin >> brandl;
    strstream << brandl;
    strstream >> brand;

    name(dict, fout, brand, "");

    // cout << brand;

    // for (int i; i < strlen(brand); i++)
    // {
    //
    // }

    if (none)
    {
        fout << "NONE\n";
    }

    return 0;
}
