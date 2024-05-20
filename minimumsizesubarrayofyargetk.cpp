
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int minLength = INT32_MAX;
        int left = 0, sum = 0;

        for (int right = 0; right < n; ++right)
        {
            sum += nums[right]; // Expand the window to the right

            // Contract the window from the left until sum is less than target
            while (sum >= target)
            {
                minLength = min(minLength, right - left + 1); // Update the minimal length
                sum -= nums[left++];                          // Shrink the window from the left
            }
        }

        return minLength == INT32_MAX ? 0 : minLength;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << s.minSubArrayLen(target, nums) << endl;
    return 0;
}
