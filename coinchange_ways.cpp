#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &coins, int n, int amount)
    {
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        // Initialize DP table
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1; // There's one way to make the amount 0 (use no coins)
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        if (n == 0)
            return -1;

        int ans = solve(coins, n, amount);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> coins = {1, 2, 3};
    int amount = 5;

    cout << "the number of ways to arrange the coin is " << s.coinChange(coins, amount) << endl;

    return 0;
}