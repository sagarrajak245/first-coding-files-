#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == nums[mid - 1])
            {
                if (mid % 2 == 0)
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if ((mid - 1) % 2 != 0)
                {
                    low = mid;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return nums[low];
    }
};