

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Delete Operation for Two Strings

class Solution
{
public:
    int solve(string x, string y, int n, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                if (x[i - 1] == y[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n][m];
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        int lcs = 0;
        int insert = 0;
        int del = 0;
        int ans = 0;

        lcs = solve(word1, word2, n, m);
        insert = n - lcs;
        del = m - lcs;
        ans = insert + del;

        return ans;
    }
};

int main()
{
    Solution s;
    string x = "sea";
    string y = "eat";
    cout << s.minDistance(x, y) << endl;
    return 0;
}