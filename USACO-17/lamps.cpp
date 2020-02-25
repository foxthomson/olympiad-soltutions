/*
ID: 11athom1
PROG: lamps
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, c;

int tobin(bool a[6])
{
    // cout << c << endl;
    // cout << a[(n - 6) % 6] << a[(n - 5) % 6] << a[(n - 4) % 6] << a[(n - 3) % 6] << a[(n - 2) % 6] << a[(n - 1) % 6] << endl;
    int abin = ((a[5]) ?  1 : 0) +
               ((a[4]) ?  2 : 0) +
               ((a[3]) ?  4 : 0) +
               ((a[2]) ?  8 : 0) +
               ((a[1]) ? 16 : 0) +
               ((a[0]) ? 32 : 0);

   return abin;

   // int bbin = 1  * b[(c - 1) % 6] +
   //            2  * b[(c - 2) % 6] +
   //            4  * b[(c - 3) % 6] +
   //            8  * b[(c - 4) % 6] +
   //            16 * b[(c - 5) % 6] +
   //            32 * b[(c - 6) % 6];

    // return abin < bbin;
}

int main()
{
    ifstream fin("lamps.in");
    ofstream fout("lamps.out");

    // int n, c;
    fin >> n >> c;

    bool required[6];
    bool requiredon[6];

    // reset required
    for (int i = 0; i < 6; i++)
    {
        required[i] = 0;
    }

    // bool possible = 1;
    // input required false
    int inp;
    fin >> inp;

    cerr << 1;
    cerr << 1;

    while (inp != -1)
    {
        inp--;
        // if (!required[inp%6]) // if required must be false as true not inputted
        // {
        required[inp%6] = 1;
        requiredon[inp%6] = 1;

        if (inp%6 == 1)
        {
            required[5] = 1;
            requiredon[5] = 1;
        }

        if (inp%6 == 5)
        {
            required[1] = 1;
            requiredon[1] = 1;
        }

        if (inp%6 == 2)
        {
            required[4] = 1;
            requiredon[4] = 1;
        }

        if (inp%6 == 4)
        {
            required[2] = 1;
            requiredon[2] = 1;
        }
        // }

        fin >> inp;
    }
    cerr << 2;

    // input required true
    // int inp;
    fin >> inp;
    while (inp != -1)
    {
        inp--;
        // if (!required[inp%6]) // if required must be false as true not inputted
        // {
        if (required[inp%6] && requiredon[inp%6])
        {
            fout << "IMPOSSIBLE\n";
            return 0;
        }
        required[inp%6] = 1;
        requiredon[inp%6] = 0;

        if (inp%6 == 1)
        {
            required[5] = 1;
            requiredon[5] = 0;
        }

        if (inp%6 == 5)
        {
            required[1] = 1;
            requiredon[1] = 0;
        }

        if (inp%6 == 2)
        {
            required[4] = 1;
            requiredon[4] = 0;
        }

        if (inp%6 == 4)
        {
            required[2] = 1;
            requiredon[2] = 0;
        }
        // }

        fin >> inp;
    }
    cerr << 3;

    bool answers[16][6];
    int numans = 0;

    // cout << c << endl;

    for (int button1 = 0; button1 < 2; button1++)
    for (int button2 = 0; button2 < 2; button2++)
    for (int button3 = 0; button3 < 2; button3++)
    for (int button4 = 0; button4 < 2; button4++)
    {
        // cout << (button1 + button2 + button3 + button4-c) << " " << button1 << " " << button2 << " " << button3 << " " << button4 << endl;
        if (button1 + button2 + button3 + button4 > c || (c - button1 - button2 - button3 - button4)%2 == 1)
        {
            continue;
        }

        // cout << button1 << " " << button2 << " " << button3 << " " << button4 << " " << button1 + button2 + button3 + button4 << " " << (button1 + button2 + button3 + button4)%2 << endl;

        bool newans[6];
        bool works = 1;
        for (int light = 0; light < 6; light++)
        {
            bool lit = 1;
            if (button1) lit = !lit;
            if (button2 && light % 2 == 1) lit = !lit;
            if (button3 && light % 2 == 0) lit = !lit;
            if (button4 && light % 3 == 0) lit = !lit;
            if (!required[light])
            {
                newans[light] = lit;
            }
            else if (requiredon[light])
            {
                if (lit)
                {
                    newans[light] = lit;
                }
                else
                {
                    works = 0;
                    break;
                }
            }
            else
            {
                if (!lit)
                {
                    newans[light] = lit;
                }
                else
                {
                    works = 0;
                    break;
                }
            }
            // cout << lit << newans[light];
        }
        // cout << endl;

        if (works)
        {
            for (int i = 0; i < 6; i++)
            {
                answers[numans][i] = newans[i];
            }
            numans++;
        }
    }
    if (numans == 0)
    {
        fout << "IMPOSSIBLE\n";
    }
    else
    {
        // sort(answers, answers + numans, cmparr);

        cerr << 3;
        // arrays of solutions as binary
        int mapped[16];
        for (int i = 0; i < numans; i++)
        {
            mapped[i] = tobin(answers[i]);
            // for (int j = 0; j < n; j++)
            // {
            //     cout << answers[i][j % 6];
            // }
            // cout << " " << mapped[i] << endl;
        }

        for (int _ = 0; _ < numans; _++)
        {
            cerr << "(";
            int minid;
            int min = 64;
            for (int i = 0; i < numans; i++)
            {
                if (mapped[i] != -1 && mapped[i] < min)
                {
                    minid = i;
                    min = mapped[i];
                }
            }
            cerr << "){";
            cerr << minid;
            // cout << min << endl;

            mapped[minid] = -1;
            for (int i = 0; i < n; i++)
            {
                fout << answers[minid][i % 6];
            }
            fout << endl;
            cerr << "}";
        }
        cerr << 3;
    }
    cerr << 5;

    return 0;
}
