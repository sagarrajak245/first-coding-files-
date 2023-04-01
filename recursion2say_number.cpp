#include <iostream>
using namespace std;

void saynum(int n, string arr[])
{

    if (n == 0)
        return;

    int rev = 0;
    int digit = n % 10;
    n = n / 10;
    saynum(n, arr);
    cout << arr[digit] << " ";
}

int main()
{

    string arr[10] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    };

    int num;
    cout << "enter the number";

    cin >> num;

    saynum(num, arr);

    return 0;
}