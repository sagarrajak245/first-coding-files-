#include <iostream>
using namespace std;
int main()
{
    int a, i;
    cout << "enter the number of rows\n";
    cin >> a;
    i = 1;
    while (i <= a)
    {
        int j = 1;
        while (j <= a)
        {
            cout << "*";
            j = j + 1;
        }
        cout << "\n";
        i = i + 1;
    }

    return 0;
}