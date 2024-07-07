
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>
using namespaceclass Solution{
    public :
        int minIncrementForUnique(vector<int> & nums){
            priority_queue<int, vector<int>, greater<int>> minheap(nums.begin(), nums.end());
int cnt = 0;
int n = nums.size();
int prev = minheap.top(); // to store the previous element
minheap.pop();
while (!minheap.empty())
{
    int currentelement = minheap.top();
    minheap.pop();

    if (currentelement <= prev)
    {
        cnt += prev - currentelement + 1; // store the number of steps required
        prev++;                           // increment the previous element make it unique
    }
    else
    {
        prev = currentelement; // update the previous element
    }
}
return cnt;
}
}
;
std;

int main()
{
    Solution s;
    vector<int> nums = {3, 2, 1, 2, 1, 7};
    cout << "The number of steps are required " << s.minIncrementForUnique(nums) << endl;
    return 0;
}