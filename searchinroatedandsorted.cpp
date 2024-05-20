
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {

            int mid = (start + end) >> 1;

            if (nums[mid] == target)
                return mid;

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
        return -1;
    }
};

int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 6;
    Solution s;

    int ans = s.search(nums, target);
    cout << "the index is at " << ans << endl;
    return 0;
}
