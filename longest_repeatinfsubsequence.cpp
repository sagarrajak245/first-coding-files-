#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int lcs(string x, string y, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // Ensure that we are not considering the same index
            if ((x[i - 1] == y[j - 1]) && (i != j))
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main()
{
    string s1 = "abcdeabdef";
    string s2 = s1;
    int n = s1.length();
    int m = s2.length();
    cout << "Length of longest repeating subsequence is " << lcs(s1, s2, n, m) << endl;

    return 0;
}
