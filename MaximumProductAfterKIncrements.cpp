// Maximum Product After K Increments
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int maxproduct(vector<int> arr, int k)
{
    int mod = pow(10, 9) + 7;
    int n = arr.size();

    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

    while (k > 0)
    {

        int temp = pq.top();
        temp++;
        pq.pop();
        pq.push(temp);

        k--;
    }

    long long ans = 1;
    while (!pq.empty())
    {

        int temp2 = pq.top();
        pq.pop();
        ans = (ans * temp2) % mod;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 2;
    cout << maxproduct(arr, k) << endl;
    return 0;
}
