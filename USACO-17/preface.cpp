/*
ID: 11athom1
PROG: preface
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int numI = 0;
int numV = 0;
int numX = 0;
int numL = 0;
int numC = 0;
int numD = 0;
int numM = 0;

int n;

int main()
{
    ifstream fin("preface.in");
    ofstream fout("preface.out");

    fin >> n;

    // kind of tens
    int tens = ((n/10)%10;
    switch (tens)
    {
        // case 9:
        //     numX += 10;
        //     numC += 10;
        case 9:
            numX += 30;
            numL += 10;
        case 8:
            numX += 20;
            numL += 10;
        case 7:
            numX += 10;
            numL += 10;
        case 6:
            // numI += 1;
            numL += 10;
        case 5:
            numX += 10;
            numL += 10;
        case 4:
            numX += 30;
            // numX += 1;
        case 3:
            numX += 20;
            // numX += 1;
        case 2:
            numX += 10;
            // numX += 1;
    }

    // add units for each ten - last
    numI += (tens-1) * 14;
    numV += (tens-1) * 5;
    numX += tens-1;

    // int lastten = 0;

    int units = n%10;

    switch (tens)
    {
        case 9:
            numX += units + 1;
            numC += units + 1;
            break;
    }

    switch (units)
    {
        case 9:
            numI += 1;
            numX += 1;
        case 8:
            numI += 3;
            numV += 1;
        case 7:
            numI += 2;
            numV += 1;
        case 6:
            numI += 1;
            numV += 1;
        case 5:
            // numI += 1;
            numV += 1;
        case 4:
            numI += 1;
            numV += 1;
        case 3:
            numI += 3;
            // numX += 1;
        case 2:
            numI += 2;
            // numX += 1;
        case 1:
            numI += 1;
            // numX += 1;
    }

    // int hundreds = (n/100)%10;
    // tens += 10*hundreds;
    // switch (hundreds)
    // {
    //     case 9:
    //         numC += 100;
    //         numM += 100;
    //     case 8:
    //         numC += 300;
    //         numD += 100;
    //     case 7:
    //         numC += 200;
    //         numD += 100;
    //     case 6:
    //         numC += 100;
    //         numD += 100;
    //     case 5:
    //         // numI += 1;
    //         numD += 100;
    //     case 4:
    //         numC += 100;
    //         numD += 100;
    //     case 3:
    //         numC += 300;
    //         // numX += 1;
    //     case 2:
    //         numC += 200;
    //         // numX += 1;
    //     case 1:
    //         numC += 100;
    //         // numX += 1;
    // }
    //
    // int thousands = (n/1000)%10;
    // tens += 100*thousands;
    // hundreds += 10*thousands;
    // switch (thousands)
    // {
    //     // case 9:
    //     //     numC += 1;
    //     //     numM += 1;
    //     // case 8:
    //     //     numC += 3;
    //     //     numD += 1;
    //     // case 7:
    //     //     numC += 2;
    //     //     numD += 1;
    //     // case 6:
    //     //     numC += 1;
    //     //     numD += 1;
    //     // case 5:
    //     //     // numI += 1;
    //     //     numD += 1;
    //     // case 4:
    //     //     numC += 1;
    //     //     numD += 1;
    //     case 3:
    //         numM += 3000;
    //         // numX += 1;
    //     case 2:
    //         numM += 2000;
    //         // numX += 1;
    //     case 1:
    //         numM += 1000;
    //         // numX += 1;
    // }
    //
    // numI +=

    return 0;
}
