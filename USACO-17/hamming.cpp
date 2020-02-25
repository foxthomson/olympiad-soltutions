/*
ID: 11athom1
PROB: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int hamming(int a, int b, int bits)
{
    int ans = 0;

    int power = 1;
    for (int i = 0; i < bits; i++)
    {
        // cout << power << endl;
        // cout << a << " "  << b << " "  << power << " " << (a&power) << " "  << (b&power) << " "  << ((a&power) ^ (b&power)) << endl;
        if (((a&power) ^ (b&power)))
        {
            ans++;
        }

        power *= 2;
    }

    return ans;
}

int main()
{
    // cout << hamming(7, 7, 7) << hamming(0, 25, 7) << hamming(25, 7, 7) << hamming(42, 7, 7);

    // open files
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");

    // input
    int n, b, d;
    fin >> n >> b >> d;

    // calculate 2^b
    int largest = 1;
    for (int i = 0; i < b; i++)
    {
        largest *= 2;
    }
    // cout << largest;

    // list of answers
    int answers[64];
    int numanswers = 0;

    // itterate though each posible 'codeword'
    for (int codeword = 0; codeword < largest; codeword++)
    {
        cout << codeword << endl;
        bool works = 1;
        for (int i = 0; i < numanswers; i++)
        {
            if (hamming(codeword, answers[i], b) < d)
            {
                works = 0;
                break;
            }
        }

        // output
        if (works)
        {
            if (numanswers % 10 == 0 && numanswers != 0)
            {
                fout << endl;
            }
            else if (numanswers != 0)
            {
                fout << " ";
            }
            fout << codeword;
            answers[numanswers] = codeword;
            numanswers++;
        }

        // found all
        if (numanswers == n)
        {
            break;
        }
    }

    fout << endl;

    return 0;
}
