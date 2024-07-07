#include <vector>
#include <set>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        if (n == 0)
            return -1; // Edge case: empty array

        int left = 0, right = 0;
        int maxLength = 0;

        multiset<int> window; // to keep track of the current window elements

        while (right < n)
        {
            // Add the current element to the window
            window.insert(nums[right]);

            // Check if the current window is valid
            while (*window.rbegin() - *window.begin() > limit)
            {
                window.erase(window.find(nums[left]));
                left++;
            }

            // Update the maximum length of the valid window
            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};

int main()
{

    Solution s;
    vector<int> nums = {8, 2, 4, 7};
    int limit = 4;
    int ans = s.longestSubarray(nums, limit);
    cout << ans << endl;

    return 0;
}