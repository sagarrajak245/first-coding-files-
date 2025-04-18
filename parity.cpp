#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to process each test case and return the minimum operations needed
int min_operations_to_same_parity(const vector<int> &arr)
{
    int odd_count = 0;
    int even_count = 0;

    // Count the number of odd and even numbers
    for (int num : arr)
    {
        if (num % 2 == 0)
        {
            even_count++;
        }
        else
        {
            odd_count++;
        }
    }

    // The result is the minimum of odd_count and even_count
    return min(odd_count, even_count);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> array[i];
        }

        // Process the current test case and output the result
        cout << min_operations_to_same_parity(array) << endl;
    }

    return 0;
}
