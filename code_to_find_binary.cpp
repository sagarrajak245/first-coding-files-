#include <iostream>
using namespace std;

int main()
{
    int i, n, ans;

    cout << "Enter the number: ";
    cin >> n;

    i = 1; // Use i as a multiplier for binary place values
    ans = 0;

    while (n != 0)
    {
        int bit = n & 1;       // Extract the least significant bit
        ans = (bit * i) + ans; // Add the bit to the current result
        n = n >> 1;            // Shift right to process the next bit
        i = i * 10;            // Move to the next place value (10, 100, 1000, etc.)
    }

    cout << "The binary representation of the entered number is: " << ans << endl;

    return 0;
}
