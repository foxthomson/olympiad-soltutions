#include <iostream>
#include <stack>

using namespace std;

int trie[500001][27];
int nextnode = 1;
int nodecount[500001];

int main()
{
    int m;
    cin >> m;

//    if (!m) return 0;

    long long numopps = 0;
    string bestword = "";
    int bestlength = 0;
    for (int i = 0; i < m; i++)
    {
        string word;
        cin >> word;

        if (word.length() > bestlength)
        {
            bestword = word;
            bestlength = word.length();
        }

        // add to trie
        int curr = 0;
        for (int j = 0; j < word.length(); j++)
        {
            if (trie[curr][word[j]-'a'+1])
            {
                curr = trie[curr][word[j]-'a'+1];
            }
            else
            {
                trie[curr][word[j]-'a'+1] = nextnode;
                curr = nextnode;
                nextnode++;
            }
        }
        numopps++; // for P
        if (trie[curr][0])
        {
            trie[curr][0]++;
        }
        else
        {
            trie[curr][0]++;
            // add to counts
            int curr = 0;
            for (int j = 0; j < word.length(); j++)
            {
                curr = trie[curr][word[j]-'a'+1];
                if (!nodecount[curr])
                {
                    numopps+=2;
//                    cout << word[j] << " " << curr << endl;
                }
                nodecount[curr]++;
            }
        }
//        cout << numopps << endl;

    }

    numopps -= bestlength;
    cout << numopps << endl;

    int length = 0;
    string currword = "";
    int currnode = 0;
    char nextchar = 'a';
    int currlength = 0;
//    string longestbranch = "";
//    int bestbranch = 0;
//    int branchlength = 0;
    stack<int> nodes;
//    nodes.push(0);
    int depth = 0;
    if (bestword[depth] == nextchar) nextchar++;
    while (1)
    {
//        if (!depth) cout << nextchar << "," << currnode << " ";
        if (trie[currnode][nextchar-'a'+1])
        {
            // extend word, check if branch/end of word
            currword += nextchar;
            nodes.push(currnode);
            currnode = trie[currnode][nextchar-'a'+1];
            cout << nextchar << endl;
            nextchar = 'a';
            depth++;
            if (depth < bestword.length() && bestword[depth] == 'a') nextchar++;

//            if (nodecount[currnode] == 1)
//            {
//                branchlength++;
//            }
//            else
//            {
//                branchlength = 0;
//            }

            if (trie[currnode][0])
            {
//                length += 2*branchlength + trie[currnode][0];
//                if (bestbranch < branchlength)
//                {
//                    bestbranch = branchlength;
//                    longestbranch = currword;
//                }
                for (int i = 0; i < trie[currnode][0]; i++)
                    cout << "P\n";
                if (currword == bestword)
                    break;
            }
        }
        else
        {
            if (nextchar == bestword[depth])
            {
                depth--;
                cout << "-\n";
//                cout << currnode << " " << nodes.top() << endl;
                currnode = nodes.top();
                nodes.pop();
//                cout << currword << " " << currword.length() << endl;
                nextchar = currword[currword.length() - 1];
                currword.pop_back();
//                cout << nextchar << " " << depth << " " << currnode << endl;
//                branchlength = 0;
//                cout << bestword[depth] << " " << nextchar << endl;
                if (bestword[depth] == nextchar) {trie[currnode][nextchar-'a'+1] = 0; continue;}
            }
            nextchar++;
//            if (nextchar == )
            if (bestword[depth] == nextchar) nextchar++;
            if (nextchar > 'z')
            {
                nextchar = bestword[depth];
            }
        }
    }

    return 0;
}
