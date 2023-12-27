#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int amount;
    int notes[10];

    cout << "enter the notes\n";
    for (int i = 0; i < 10; i++)
    {
        cin >> notes[i];
    }

    for (int i = 0; i < 10; i++)
    {
        cout << notes[i] << " ";
    }
    cout << endl;
    cout << "enter the amount\n";
    cin >> amount;

    int noteCounter[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        if (amount >= notes[i])
        {
            noteCounter[i] = amount / notes[i];
            amount = amount - noteCounter[i] * notes[i];
        }
    }
    cout << "the notes are\n";
    for (int i = 0; i < 10; i++)
    {
        if (noteCounter[i] != 0)
        {
            cout << notes[i] << " " << noteCounter[i] << endl;
        }
    }

    return 0;
}
