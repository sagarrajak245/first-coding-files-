
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> key;
    vector<int> nums = {3, 2, 1, 2, 1, 7};
    int cnt = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        key.insert(nums[i]);
    }
}