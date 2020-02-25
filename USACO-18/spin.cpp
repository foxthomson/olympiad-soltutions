/*
ID: 11athom1
TASK: spin
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

bool timewheels[360][360];
int vel[5];
int numwheels[5];
int theta1[5][5];
int theta2[5][5];
int extent[5][5];

int main(int argc, char** argv)
{
    ifstream fin("spin.in");
    ofstream fout("spin.out");
    
    // input
    for (int w = 0; w<5; w++)
    {
        fin >> vel[w] >> numwheels[w];
        for (int i = 0; i < numwheels[w]; i++)
        {
            fin >> theta1[w][i] >> extent[w][i];
            theta2[w][i] = (theta1[w][i] + extent[w][i]) % 360;
        }
    }
    
    int t;
    for (t = 0; t < 360; t++)
    {
        // check for alignment
        // Check each sliver
        for (int s = 0; s < 360; s++)
        {
            bool passed = true;
            // check if all wheels have gaps there
            for (int w = 0; w < 5; w++)
            {
                // check for gap
                bool gap = false;
                for (int i = 0; i < numwheels[w]; i++)
                {
                    if (theta1[w][i] > theta2[w][i])
                    {
                        if ((s >= theta1[w][i]) || (s <= theta2[w][i]))
                        {
//                            if (t==9)
//                            {
//                                cout << theta1[w][i] << " " << s << " " << theta2[w][i] << " " << i << " " << w << endl;
//                            }
                            gap = true;
                            break;
                        }
                    }
                    if (theta1[w][i] < theta2[w][i])
                    {
                        if (((s >= theta1[w][i]) && (s <= theta2[w][i])))
                        {
//                            if (t==9)
//                            {
//                                cout << theta1[w][i] << " " << s << " " << theta2[w][i] << " " << i << " " << w << endl;
//                            }
//                            cout << theta1[w][i] << " " << s << " " << theta2[w][i] << " " << i << " " << w << endl;
                            gap = true;
                            break;
                        }
                    }
                }
                if (!gap)
                {
//                    cout << w << endl;
                    passed = false;
                    break;
                }
            }
            if (passed)
            {
                fout << t << endl;
                return 0;
            }
        }
        
        //  rotate wheels
        for (int w = 0; w < 5; w++)
        {
            for (int i = 0; i < numwheels[w]; i++)
            {
//                if (t==8)
//                cout << theta1[w][i]  << " " << theta2[w][i] << endl;
                theta1[w][i] += vel[w];
                theta2[w][i] += vel[w];
                theta1[w][i] %= 360;
                theta2[w][i] %= 360;
            }
        }
//        cout << endl;
    }
    // if they haven't alligned by t=360 they never will/
    fout << "none" << endl;

    return 0;
}

