#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool hasSubsetSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Base case: an empty subset can always achieve a sum of 0
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = true;
    }

    // Fill the dp table
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= target; ++j)
        {
            if (nums[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Return the result from the dp table
    return dp[n][target];
}

int main()
{
    vector<int> nums = {3, 1, 7, 5, 4};
    int target = 6;

    if (hasSubsetSum(nums, target))
    {
        cout << "Subset with sum " << target << " exists." << endl;
    }
    else
    {
        cout << "Subset with sum " << target << " does not exist." << endl;
    }

    return 0;
}
