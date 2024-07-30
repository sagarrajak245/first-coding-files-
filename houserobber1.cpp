#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// int solve(vector<int> nums, int n)
// {
//     vector<int> dp(n + 1, 0);
//     dp[0] = 0;
//     dp[1] = nums[0];
//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
//     }
//     return dp[n];
// }

// recursion
// int solve(vector<int> nums, int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     if (n == 1)
//     {
//         return nums[0];
//     }
//     return max(solve(nums, n - 1), solve(nums, n - 2) + nums[n - 1]);
// }

// memoization
int solve(vector<int> nums, int n)
{
    vector<int> dp(n + 1, 0);
   




}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    int n = nums.size();
    int money = 0;
    money = solve(nums, n);
    cout << money;

    return 0;
}