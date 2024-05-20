#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num = 0;

    cout << "Enter a number: ";
    cin >> num;
    int count = 0;

    count = floor(log10(num) + 1);

    cout << "Number of digits: " << count << endl;
    return 0;
}