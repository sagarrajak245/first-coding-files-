#include <iostream>
using namespace std;

int pow(int x, int n)

{

    if (n == 0 || x == 1)
    {

        return 1;
    }

    return x * pow(x, n - 1);
}

int main()
{

    int n, x;

    cout << "enter the base number" << endl;
    cin >> x;
    cout << "enter the power number" << endl;
    cin >> n;

    int ans = pow(x, n);

    cout << "the power is " << ans << "\n";

    return 0;
}