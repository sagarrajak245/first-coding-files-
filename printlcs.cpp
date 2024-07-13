#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string solve(string x, string y, int n, int m)
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

    int i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    string s1 = "abcde";
    string s2 = "ace";
    int n = s1.length();
    int m = s2.length();
    string ans = "";
    ans = solve(s1, s2, n, m);
    cout << "longest common subsequence is " << ans << endl;

    return 0;
}
