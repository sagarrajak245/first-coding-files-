
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
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n][m];
    }

    int minInsertions(string s)
    {
        string a = s;
        reverse(a.begin(), a.end());
        int n = s.length();
        int m = a.length();
        int ans = 0;
        ans = n - lcs(s, a, n, n); // number of deletiton is same as number of insertion
                                   // and lcs is inversely  proportional to lcs
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "geeks";
    cout << "Minimum insertions to make a string palindrome: " << sol.minInsertions(s) << endl;
    return 0;
}