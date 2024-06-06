// Here is the top-down approach of
// dynamic programming
#include <bits/stdc++.h>
using namespace std;
int static t[102][1002];

int knapSack(int W, int wt[], int val[], int n)

{
    // Base condition
    if (n == 0 || W == 0)
        return 0;

    // If the value is already calculated
    // then return that value
    if (t[n][W] != -1)
        return t[n][W];

    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution  ;p
    if (wt[n - 1] > W)
        return t[n][W] = knapSack(W, wt, val, n - 1);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return t[n][W] = max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
                             knapSack(W, wt, val, n - 1));
}

// Driver Code
int main()
{
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    memset(t, -1, sizeof(t));

    cout << "the maximum profit is: " << knapSack(W, weight, profit, n) << "\n";
    return 0;
}
