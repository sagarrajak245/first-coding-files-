
#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int solve(int e, int n, vector<vector<int>>& dp) {
//         if (n == 0 || n == 1) return n;
//         if (e == 1) return n;
//         if (dp[e][n] != -1) return dp[e][n];

//         int ans = INT_MAX;

//         for (int k = 1; k <= n; k++) {
//             int left,right;

// if(dp[e-1][k-1]!=-1){
//     left=dp[e-1][k-1];

// }
// else{
//     left=solve(e - 1, k - 1, dp);
//     dp[e-1][k-1]=left;
// }

// if(dp[e][n-k]!=-1){
//     left=dp[e][n-k];

// }
// else{
//     left=solve(e , n-k, dp);
//     dp[e-1][k-1]=left;
// }

//             int temp = 1 + left+right;
//             ans = min(ans, temp);
//         }

//         return dp[e][n] = ans;
//     }

//     int twoEggDrop(int n) {
//         vector<vector<int>> dp(3, vector<int>(n + 1, -1));  // Initialize DP array
//         return solve(2, n, dp);
//     }
// };
class Solution
{
public:
    int solve(int e, int n, vector<vector<int>> &dp)
    {
        if (n == 0 || n == 1)
            return n;
        if (e == 1)
            return n;
        if (dp[e][n] != -1)
            return dp[e][n];

        int ans = INT_MAX;

        int low = 1, high = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int left = dp[e - 1][mid - 1] != -1 ? dp[e - 1][mid - 1] : solve(e - 1, mid - 1, dp);
            int right = dp[e][n - mid] != -1 ? dp[e][n - mid] : solve(e, n - mid, dp);

            int temp = 1 + max(left, right);
            ans = min(ans, temp);

            if (left < right)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return dp[e][n] = ans;
    }

    int twoEggDrop(int n)
    {
        vector<vector<int>> dp(3, vector<int>(n + 1, -1)); // Initialize DP array
        return solve(2, n, dp);
    }
};

// Time Complexity: O(2*N*log(N))
// Space Complexity: O(2*N)
int main()
{
    Solution sol;
    int n = 100;
    cout << sol.twoEggDrop(n) << endl;
    return 0;
}