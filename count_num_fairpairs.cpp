#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         //noob solution TLE
//         int n=nums.size();
//         vector<pair<long long,long long>>p;

//         for(long long  i=0;i<n;i++){
//            for(long long j=i+1;j<n;j++){
//             long long sum=nums[i]+nums[j];
//             if(lower<=sum && sum<=upper){
//                 p.push_back(make_pair(i,j));
//             }
//            }
//         }

//         return p.size();
//     }
// };

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        int right = 0, left = 0;
        long long count = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            count += (right - left);
        }

        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int lower = 3;
    int upper = 7;

    long long result = sol.countFairPairs(nums, lower, upper);
    cout << "Number of fair pairs: " << result << endl;

    return 0;
}