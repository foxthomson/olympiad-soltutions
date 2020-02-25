/*
ID: 11athom1
PROG: gift1
LANG: C++
*/

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct Person
{
    string name;
    int bank;
};

int main()
{
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");

    int np;
    fin >> np;

    Person people[np];

    // cout << np;

    for (int i = 0; i < np; i++)
    {
        fin >> people[i].name;
        people[i].bank = 0;
    }

    for (int i = 0; i < np; i++)
    {
        string giver;
        int amount, ng;
        fin >> giver >> amount >> ng;

        if (ng != 0)
        {
            int share = amount / ng;
            int left = amount % ng;

            int giverid;

            // cout << np << giver << "start\n";

            for (int j = 0; j < np; j++)
            {
                // cout << people[j].name << "\n";
                if (people[j].name.compare(giver) == 0)
                {
                    giverid = j;
                    people[j].bank -= amount - left;
                    break;
                    // cout << j;
                }
            }

            // cout << people[giverid].name << "!!!\n";

            for (int j = 0; j < ng; j++)
            {
                string receiver;
                fin >> receiver;

                for (int k = 0; k < np; k++)
                {
                    if (people[k].name.compare(receiver) == 0)
                    {
                        people[k].bank += share;
                        break;
                        // cout << j;
                    }
                }
            }
        }
        cout << "a";
    }
    cout << "b";

    for (int i = 0; i < np; i++)
    {
        cout << people[i].name << " " << people[i].bank << "\n";
    }

    return 0;
}
