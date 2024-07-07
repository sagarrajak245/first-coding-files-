

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &nums, int n, int actualsum)
    {
        if (actualsum < 0)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(actualsum + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= actualsum; j++)
            {
                if (nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][actualsum];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = 0;

        for (int num : nums)
        {
            sum += num;
        }

        if (sum < abs(target) || (sum + target) % 2 != 0)
        {
            return 0;
        }

        int actualsum = (sum + target) / 2;
        return solve(nums, n, actualsum);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << s.findTargetSumWays(nums, target) << "\n";

    return 0;
}