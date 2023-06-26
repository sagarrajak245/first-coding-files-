#include <iostream>
using namespace std;
int main()
{

    int i, j, n;
    cout << "enter the number\n";
    cin >> n;

    i = n;
    while (i >= 1)
    {

        j = 1;
        while (j <= i)
        {
            cout << i - j + 1;
            j = j + 1;
        }
        cout << "\n";

        i = i - 1;
    }

    return 0;
}