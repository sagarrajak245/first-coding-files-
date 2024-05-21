#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0; // If there is only one element, no jumps are needed.

        int maxReach = 0, jumps = 0, endOfRange = 0;

        for (int i = 0; i < n - 1; i++)
        {
            // Update the maximum reach from the current index.
            maxReach = max(maxReach, i + nums[i]);

            // If we have reached the end of the current range of jumps.
            if (i == endOfRange)
            {
                jumps++;
                endOfRange = maxReach; // Set the new range to the maximum reach.

                if (endOfRange >= n - 1)
                    break;
            }
        }

        return endOfRange >= n - 1 ? jumps : -1;
    }
};

// class Solution {
// public:

//     int jump(vector<int>& nums) {

//       for(int i = 1; i < nums.size(); i++)
//       {
//         nums[i] = max(nums[i] + i, nums[i-1]);
//       }

//       int ind = 0;
//       int ans = 0;

//       while(ind < nums.size() - 1)
//       {
//         ans++;
//         ind = nums[ind];
//       }

//       return ans;
//     }
// };

int main()
{

    Solution s;
    vector<int> v = {2, 3, 0, 1, 4};
    int ans = s.jump(v);
    cout << "the minimum jumps required are " << ans << endl;

    return 0;
}