#include <iostream>
#include <math.h>
using namespace std;
// don't use loop  use recursive method;
int printcount(int n)
{
    int num;

    if (n == 0)
    {
        return 1;
    } // base case

    cout << n << " ";

    return printcount(n - 1);
}

int main()
{

    int num, rev;

    cout << "enter number\n";
    cin >> num;
    rev = printcount(num);

    return 0;
}