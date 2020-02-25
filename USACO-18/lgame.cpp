/*
ID: 11athom1
TASK: lgame
LANG: C++
*/

#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

string scores = "25441655176352357212466757";
int nextnode = 1;
int trie[30000][8];
int lookup[1000];
string answers[30000];
//string lastword[300000];
int numans = 0;

int main(int argc, char** argv)
{
    ifstream fin("lgame.in");
    ifstream fdict("lgame.dict");
    ofstream fout("lgame.out");

    string letters;
    fin >> letters;
    sort(letters.begin(), letters.end());
//    cout << letters << endl;

    for (int i = 0; i < letters.length(); i++)
    {
        lookup[letters[i]] = i+1;
    }

    while (1)
    {
        string word;
        fdict >> word;
        if (word[0] == '.') break;
//        cout << word << endl;

        bool add = true;
        for (int i = 0; i < word.length(); i++)
        {
            if (!lookup[word[i]])
            {
                add = false;
                break;
            }
        }

        if (!add)
            continue;

//        cout << word << endl;

        int curr = 0;
        for (int i = 0; i < word.length(); i++)
        {
            // add next letter to trie
            if (trie[curr][lookup[word[i]]])
            {
                curr = trie[curr][lookup[word[i]]];
            }
            else
            {
                trie[curr][lookup[word[i]]] = nextnode;
                curr = nextnode;
                nextnode++;
            }
        }

        // add word end
        trie[curr][0] = 1;
    }

//    string check = "program";
//    int curr = 0;
//    for (int i = 0; i < 7; i++)
//    {
//        cout << curr << " " << check[i] << " " << lookup[check[i]] << " " << trie[curr][lookup[check[i]]] << endl;
//        curr = trie[curr][lookup[check[i]]];
//    }

    int bestscore = 0;
    do
    {
//        cout << letters << endl;
//        cout << (1 << letters.length()-1) << endl;
        for (int j = 0; j < (1 << letters.length()-1); j++)
        {
            int curr = 0;
            int score = 0;
            string currstring = "";
            string currword = "";
            string lastword = "";
//            cout << endl;
            for (int i = 0; i < letters.length(); i++)
            {
                score += scores[letters[i]-'a'] - '0';
                currstring += letters[i];
                currword += letters[i];
//                if (letters == "argorpm")
//                cout << currstring << endl;

                if (trie[curr][lookup[letters[i]]])
                {
                    curr = trie[curr][lookup[letters[i]]];
//                    if (letters == "argorpm")
//                    cout << i << " " << j << " " << !(j & (1<<i)) << endl;
                    if (i == letters.length() - 1 || !(j & (1<<i)))
                    {
                        if (trie[curr][0])
                        {
                            if (currword < lastword)
                            {
//                            if (letters == "argorpm")
//                                cout << "break 1" << endl;
                                break;
                            }

                            if (score > bestscore)
                            {
                                bestscore = score;
                                answers[0] = currstring;
//                                lastword[0] = currword;
                                numans = 1;
                            }
                            else if (score == bestscore)
                            {
                                if (!binary_search(answers, answers+numans, currstring))
                                {
                                    answers[numans] = currstring;
                                    numans++;
                                }
                            }
                            curr = 0;
                            currstring += ' ';
                            lastword = currword;
                            currword = "";
                        }
                        else
                        {
//                            if (letters == "argorpm")
//                            cout << "break 2" << endl;
                            break;
                        }
                    }
                }
                else
                {
//                            if (letters == "argorpm")
//                    cout << "break 3" << endl;
                    break;
                }
            }
        }
    } while (next_permutation(letters.begin(), letters.end()));

    fout << bestscore << endl;
    for (int i = 0; i < numans; i++)
    {
        fout << answers[i] << endl;
    }

    return 0;
}

