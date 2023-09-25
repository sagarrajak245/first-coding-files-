
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int len = nums.size();

        if (nums.size() == 0)
            return false;
        if (nums.size() == 1)
            return true;

        int mid = len / 2;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len; i++)
        {
            nums[i] = nums[i] % len;
        }

        for (int i = 0; i < len / 2; i++)
        {
            nums[i] = true;
        }

        for (int i = (len / 2) + 1; i <= len; i++)
        {
            nums[i] = false;
        }
        while (mid--)
        {
            int i = 0;

            if (nums[i] && nums[i] == len)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};