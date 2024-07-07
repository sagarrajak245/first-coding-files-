
#include <iostream>
#include <vector>
#include <algorithm>sub
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

    bool canPartition(vector<int> &nums)
    {

        int sum = 0;
        int n = nums.size();
        bool ans = false;
        for (int i = 0; i < n; i++)
        {

            sum += nums[i];
        }

        if (sum % 2 != 0)
            return false;        // odd sum u cant make equal partition
        int actualsum = sum / 2; // we nee dto search half of the sum half of the sum will be the sum of one partition

        ans = solve(nums, n, actualsum);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 5, 11, 5};
    if (s.canPartition(nums))
    {
        cout << "Equal sum partition is possible." << endl;
    }
    else
    {
        cout << "Equal sum partition is not possible." << endl;
    }

    return 0;
}
modify it to return those sum pair
