#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcstring(string x, string y, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLength = 0; // To keep track of the maximum length of the common substring

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxLength = max(maxLength, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return maxLength;
}

int main()
{
    string s1 = "abcdgh";
    string s2 = "abcdfgh";
    int n = s1.length();
    int m = s2.length();
    cout << "Length of longest common substring is " << lcstring(s1, s2, n, m) << endl;

    return 0;
}
