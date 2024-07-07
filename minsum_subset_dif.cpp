#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int ans = INT_MAX;
        int range = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            range += nums[i];
        }

        // DP table initialization
        vector<vector<bool>> t(n + 1, vector<bool>(range + 1, false));

        // Initialize DP table
        for (int i = 0; i <= n; i++)
        {
            t[i][0] = true; // Subset sum of 0 is always possible with an empty subset
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= range; j++)
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

        // Find the minimum difference
        for (int j = range / 2; j >= 0; j--)
        {
            if (t[n][j] == true)
            {
                ans = min(ans, range - 2 * j);
                break; // We found the closest possible sum to range/2
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 7};
    int ans = s.minimumDifference(nums);
    cout << "The minimum difference between subset sums is " << ans << "\n";

    return 0;
}
// Compare this snippet from .vscode/subsetsum.cpp: