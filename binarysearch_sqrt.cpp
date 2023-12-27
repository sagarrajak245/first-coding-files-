#include <iostream>
using namespace std;

long double sqrt(int num)
{

    long double s = 0;
    long double e = num;
    long double mid = s + (e - s) / 2;
    long double ans = -1;
    while (s <= e)
    {

        long double sqr = mid * mid;

        if (sqr == num)
            return mid;
        if (sqr < num)
        {
            s = mid + 1;
            ans = mid;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
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
