#include <iostream>
#include <vector>

using namespace std;

bool isSubsetSum(vector<int> &v, int n, int sum)
{
    // DP table initialization
    bool t[n + 1][sum + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
            {
                t[i][j] = false; // If no elements in the array, subset sum is not possible
            }
            if (j == 0)
            {
                t[i][j] = true; // Subset sum of 0 is always possible with an empty subset
            }
        }
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (v[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - v[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum]; // Return whether subset sum 'sum' is possible with 'n' elements of array 'v'
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 12;
    int n = v.size();
    bool ans = isSubsetSum(v, n, sum);
    cout << "Is subset possible: " << ans << "\n";

    return 0;
}
