#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, pair<int, int> > tii;

tii bridgelengths[1000000];
int numconnections[1000000];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        tii inp;
        int inp1;
        inp.second.first = i;
        cin >> inp1 >> inp.first;
        inp.second.second = inp1 - 1;

        if (inp.second.second < inp.second.first)
        {
            if (bridgelengths[inp.second.second].second.second == inp.second.first)
            {
                if (bridgelengths[inp.second.second].first > inp.first)
                {
                    inp.first = 0;
                }
                else
                {
                    bridgelengths[inp.second.second].first = 0;
                }
            }
        }
        bridgelengths[i] = inp;
    }

    sort(bridgelengths, bridgelengths + n);

    bool completeloop = true;
    long long ans = 0;
//    cout << endl;
    for (int i = n-1; (i >= 0 && !completeloop) || i > 0; i--)
    {
//        cout << ans << " " << bridgelengths[i].first << endl;
        if (numconnections[bridgelengths[i].second.first] == 2 || numconnections[bridgelengths[i].second.second] == 2)
        {
            completeloop = false;
        }
        else
        {
            ans += bridgelengths[i].first;
            numconnections[bridgelengths[i].second.first]++;
            numconnections[bridgelengths[i].second.second]++;
        }
    }

    cout << ans << endl;

    return 0;
}
