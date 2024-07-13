#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxProfit(vector<int> rodlength, vector<int> price, int n, int L)
{
    int dp[n + 1][L + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= L; j++)
            if (j == 0 || i == 0)
                dp[i][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            if (rodlength[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j],
                               price[i - 1] + dp[i][j - rodlength[i - 1]]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][L];
}

int main()
{
    vector<int> rodlength = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};  //
    int n = rodlength.size();
    int L = 8;
    cout << getMaxProfit(rodlength, price, n, L) << endl;

    return 0;
}
