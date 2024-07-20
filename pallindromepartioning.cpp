#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

// Function to compute the minimum number of scalar multiplications
int mcm(int arr[], int i, int j)
{
    if (i >= j) // Base case: no matrix or one matrix
        return 0;
    if (dp[i][j] != -1) // Return already computed value
        return dp[i][j];

    int mn = INT_MAX;

    // Place parenthesis at different positions between first and last matrix
    for (int k = i; k <= j - 1; k++)
    {
        int temp = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        mn = min(mn, temp);
    }

    return dp[i][j] = mn; // Store and return minimum cost
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));

    // Compute and print the minimum number of multiplications
    cout << "Minimum number of multiplications is " << mcm(arr, 1, n - 1) << endl;

    return 0;
}
