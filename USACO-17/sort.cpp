#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int list[10000];
int n;

void isort()
{
    int sortedPartition = 1;

    for (int i = 1; i < n; i ++)
    {
        int insert = list[i];
        int check = 0;

        while (check < sortedPartition && list[check] < insert)
        {
            check++;
        }

        move(list + check, list + sortedPartition - 1, list + check + 1);
        list[i] = insert;
        sortedPartition++;
    }
}

int main()
{
    ifstream fin("sort.in");

    fin >> n;

    for (int i = 0; i < n; i++)
    {
        fin >> list[i];
    }

    isort();

    for (int i = 0; i< n; i++)
    {
        cout << list[i] << " ";
    }

    return 0;
}
