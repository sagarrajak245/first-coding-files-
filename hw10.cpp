#include <iostream>
using namespace std;

int main()
{
    int i, j, n, space;

    cout << "enter the row number\n";
    cin >> n;
    i = 1;
    while (i <= n)
    {

        space = 1;
        while (space <= n - i)
        {
            cout << " ";
            space++;
        }
        j = 1;
        char k = i + 64;
        while (j <= i)
        {
            cout << k;
            j++;
            k--;
        }
        cout << "\n";
        i++;
    }
    return 0;
}