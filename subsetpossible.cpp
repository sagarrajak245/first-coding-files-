
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool solve(vector<int> &nums, int n, int sum)
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
                if (nums[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j - nums[i - 1]] || t[i - 1][j];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][sum]; // Return whether subset sum 'sum' is possible with 'n' elements of array 'v'
    }
};

int main()
{

    Solution s;
    vector<int> nums = {1, 5, 11, 5};
    int sum = 6;

    bool ans = s.solve(nums, nums.size(), sum);
    if (ans)
    {
        cout << "subset is possible" << endl;
    }
    else
    {
        cout << "subset is not possible" << endl;
    }

    return 0;
}