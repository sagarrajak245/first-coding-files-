
#include <iostream>
using namespace std;

long int sqrt(long int num)
{

    long int s = 0;
    long int e = num;
    long int mid = s + (e - s) / 2;
    long int ans = -1;

    long int sqr = mid * mid;
    if (sqr == num)
        return mid;

    if (sqr > num)
        return;
}

int main()
{
    long int number;
    cout << "enter the number ";
    cin >> number;

    cout << "the square root of number is " << endl
         << sqrt(number);

    return 0;
}