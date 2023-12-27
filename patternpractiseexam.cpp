#include <iostream>
using namespace std;

int main()
{
    int i, j, n;

    cout << "enter the row number\n";
    cin >> n;
    i = 1;
    while (i <= n)
    {
        j = 1;
        int temp = n - i + 1;
        while (j <= n - i + 1)
        {

            cout << temp;
            temp--;

            j++;
        }
        cout << "\n";
        i++;
    }
    return 0;
}