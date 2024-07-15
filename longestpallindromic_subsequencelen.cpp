#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lcs(string x, string y, int n, int m)
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

    int longestPalindromeSubseq(string s)
    {
        string a = s;
        reverse(a.begin(), a.end()); // Correctly reverse the string and assign to 'a'
        int n = s.length();
        int m = a.length();
        int ans = lcs(s, a, n, m);

        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "bbbab";
    cout << "Longest Palindromic Subsequence length: " << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}
