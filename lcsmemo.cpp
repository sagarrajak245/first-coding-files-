#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// memoization
int lcs(string x, string y, int n, int m)
{
    int t[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            t[i][j] = -1;
        }
    }

    if (n == 0 || m == 0)
        return 0;

    if (t[n][m] != -1)
        return t[n][m];

    if (x[n - 1] == y[m - 1])
    {
        return t[n][m] = 1 + lcs(x, y, n - 1, m - 1);
    }
    else
    {
        return t[n][m] = max(lcs(x, y, n - 1, m), lcs(x, y, n, m - 1)); // return max of two cases
    }
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
