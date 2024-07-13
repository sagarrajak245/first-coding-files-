#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

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
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main()
{

    string s1 = "abcde";
    string s2 = "ace";
    int n = s1.length();
    int m = s2.length();
    cout << "len of longest common subsequence is " << lcs(s1, s2, n, m) << endl;

    return 0;
}
