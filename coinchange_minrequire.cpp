
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// most optimised way to solve the problem

// class Solution
// {
// public:
//     int coinChange(vector<int> &coins, int amount)
//     {
//         vector<int> dp(amount + 1, amount + 1); // Initialize DP array with a large number
//         dp[0] = 0;                              // Zero coins needed to make amount 0

//         for (int coin : coins)
//         {
//             for (int i = coin; i <= amount; i++)
//             {
//                 dp[i] = min(dp[i], dp[i - coin] + 1);
//             }
//         }

//         return dp[amount] == amount + 1 ? -1 : dp[amount];
//     }
// };

class Solution
{
public:
    int solve(vector<int> &coins, int n, int amount)
    {
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));

        // Initialize DP table
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0; // Zero coins needed to make amount 0
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] <= j)
                {
                    if (dp[i][j - coins[i - 1]] != INT_MAX)
                    {
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                    }
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
        }

        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        if (n == 0)
            return -1;

        return solve(coins, n, amount);
    }
};

int main()
{
    Solution s;
    vector<int> coins = {1, 2, 3};
    int amount = 5;

    cout << "The minimum number of coins required to make the amount is " << s.coinChange(coins, amount) << endl;

    return 0;
}