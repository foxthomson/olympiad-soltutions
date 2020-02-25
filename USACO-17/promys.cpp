#include <iostream>

using namespace std;

int a = 0, b = 0, c = 0;

void add(int choice)
{
    switch (choice) {
        case 0:
            break;
        case 1:
            a++;
            break;
        case 2:
            b++;
            break;
        case 3:
            c++;
            break;
        case 4:
            a++;
            b++;
            break;
        case 5:
            a++;
            c++;
            break;
        case 6:
            b++;
            c++;
            break;
    }
}

int main()
{
    int answer = 0;


    for (int p1 = 0; p1 < 7; p1++)
    for (int p2 = 0; p2 < 7; p2++)
    for (int p3 = 0; p3 < 7; p3++)
    for (int p4 = 0; p4 < 7; p4++)
    for (int p5 = 0; p5 < 7; p5++)
    for (int p6 = 0; p6 < 7; p6++)
    for (int p7 = 0; p7 < 7; p7++)
    for (int p8 = 0; p8 < 7; p8++)
    for (int p9 = 0; p9 < 7; p9++)
    for (int p10 = 0; p10 < 7; p10++)
    {
        add(p1);
        add(p2);
        add(p3);
        add(p4);
        add(p5);
        add(p6);
        add(p7);
        add(p8);
        add(p9);
        add(p10);

        if (a != 0 && b != 0 && c != 0)
            answer++;

        a = 0;
        b = 0;
        c = 0;
    }

    cout << answer;

    return 0;
}
