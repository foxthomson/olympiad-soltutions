#include <iostream>
#include <fstream>

using namespace std;

int runs[1000001];
int numruns = 1;
int best = -100;
int totgames = 0;

int main()
{
    runs[0] = 0;

    // setup
    ifstream fin("retcomp.in");
    ofstream fout("retcomp.out");

    fin >> totgames;

    int prevneg = 0;
    int prevpos = 0;
    int curr = 0;
    bool currpos = 0;

    cout << "game\tprevpos\tprevneg\tcurr\tcurrpos\tbest" << endl;

    // input and format as inputing
    for (int i = 0; i < totgames; i++)
    {
        int game;
        fin >> game;

        if (game > best)
        {
            best = game;
        }

        cout << game << "\t" << prevpos << "\t" << prevneg << "\t" << curr << "\t" << currpos << "\t" << best << endl;

        if (game < 0)
        {
            // game is negitive
            if (!currpos)
            {
                // currently looking at negitives
                curr += game;
            }
            else
            {
                // switching to neg
                currpos = 0;

                // // go backwards though runs
                // // keep a total
                // int best = game;
                // int i = totgames-2
                // while (i > 0)
                // {
                //     int addition = runs[i] + runs[i+1];
                //
                //     if (addition < 0)
                //     {
                //         break;
                //     }
                //     else
                //     {
                //         // add to best
                //         best += addition;
                //
                //         // remove from
                //     }
                //
                //     i -= 2;
                // }

                // look at prev
                if (prevneg + prevpos > 0)
                {
                    curr += prevneg + prevpos;
                }
                // curr is now local best

                // update
                prevpos = curr;
                curr = game;
                if (prevpos > best)
                {
                    best = prevpos;
                }
            }
        }
        if (game > 0)
        {
            // game is positive
            if (currpos)
            {
                // contiueing positives
                curr += game;
            }
            else
            {
                // switching to pos
                currpos = 1;

                prevneg = curr;

                // insert curr
                runs[numruns] = curr;

                // reset curr
                curr = game;
            }
        }
        // ignore 0s
        if (game == 0)
        {
            if (best < 0)
            {
                best = 0;
            }
        }
    }

    // // look at prev
    // if (prevneg + prevpos > 0)
    // {
    //     curr += prevneg + prevpos;
    // }
    // // curr is now local best
    //
    // // update
    // prevpos = curr;
    // curr = game;
    // if (curr < best)
    // {
    //     best = curr;
    // }
    // ended on positive
    if (currpos)
    {
        if (prevneg + prevpos > 0)
        {
            curr += prevneg + prevpos;
        }
        // curr is now local best

        // update
        // prevpos = curr;
        // curr = game;
        if (curr > best)
        {
            best = curr;
        }
    }

    cout << best << endl;

    return 0;
}
