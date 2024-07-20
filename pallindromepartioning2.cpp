#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool isPalindrome(const string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// Function to find the minimum number of cuts needed to partition the string into palindromes
int solve(const string &s, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j) // Base case: single character or empty string
    {
        return 0;
    }
    if (isPalindrome(s, i, j)) // If the substring is already a palindrome
    {
        return 0;
    }
    if (dp[i][j] != -1) // If the value is already computed
    {
        return dp[i][j];
    }

    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int left, right;

        if (dp[i][k] != -1)
            left = dp[i][k];
        else
        {
            left = solve(s, i, k, dp);
            dp[i][k] = left;
        }

        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
        {
            right = solve(s, k + 1, j, dp);
            dp[k + 1][j] = right;
        }

        int temp = 1 + left + right;
        mn = min(mn, temp);
    }
    return dp[i][j] = mn;
}

int minCutPalindromePartitioning(const string &s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(s, 0, n - 1, dp);
}

int main()
{
    string s = "abacbc";
    cout << "Minimum cuts needed for palindrome partitioning: " << minCutPalindromePartitioning(s) << endl;
    return 0;
}
