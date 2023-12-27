#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    int i, n, ans;

    cout << "enter the binary number\n";
    cin >> n;
    i = 0;
    ans = 0;
    while (n != 0)
    {
        int digit = n % 10;

        if (digit == 1)
        {
            ans = ans + digit * (pow(2, i));
        }
        n = n / 10;
        i++;
    }
    cout << "the decimal number of entered number is\n"
         << ans;

    return 0;
}