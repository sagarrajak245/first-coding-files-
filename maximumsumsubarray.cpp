#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // kdanes algo
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = nums[0];     // Initialize maxSum to the first element
        int currentSum = nums[0]; // Initialize currentSum to the first element

        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); ++i)
        {
            // Update currentSum: either continue the current subarray or start a new one
            currentSum = max(nums[i], currentSum + nums[i]);

            // Update maxSum if currentSum is greater
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(nums) << endl;
    return 0;
}
