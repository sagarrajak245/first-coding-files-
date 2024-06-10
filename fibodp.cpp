#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// int static dp[1000];

// int fibo(int n)
// { //memoization
//     if (n == 0)
//     {
//         return 0;
//     }
//     if (n == 1)
//     {
//         return 1;
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     return dp[n] = fibo(n - 1) + fibo(n - 2);
// }

// Tabulation approac

int fibo(int n)
{

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    cout << "Enter the number: " << endl;
    int n;
    cin >> n;
    // memset(dp, -1, sizeof(dp));  memoization

    int a = fibo(n);
    cout << "The Fibonacci number is " << a << endl;
    return 0;
}
