#include <iostream>
using namespace std;
int sqrt(int number)
{
    int start = 0;
    int end = number;
    int ans = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (mid * mid == number)
        {
            return mid;
        }
        else if (mid * mid < number)
        {
            start = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    long double number;
    cout << "enter the number ";
    cin >> number;

    cout << "the square root of number is " << endl
         << sqrt(number);

    return 0;
}
