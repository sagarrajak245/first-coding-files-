
// search in rotated and sorted array type two
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {

            int mid = (start + end) >> 1;

            if (nums[mid] == target)
                return 1;
            // else check bereaking condition
            if (nums[start] == nums[mid] && nums[mid] == nums[end])
            {
                start++; // if true reduce the search space
                end--;
                continue;
            }
            // left half is sorted then

            if (nums[start] <= nums[mid])
            {

                if (nums[start] <= target && target <= nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }

            // right part sorted then
            else
            {
                if (nums[mid] <= target && target <= nums[end])
                {
                    start = mid + 1;
                }

                else
                {
                    end = mid - 1;
                }
            }
        }
        return 0;
    }
};

int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = ;
    Solution s;
    cout << s.search(nums, target);
    return 0;
}