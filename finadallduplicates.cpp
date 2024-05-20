
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;

        for (int num : nums)
        {
            int idx = abs(num) - 1;
            if (nums[idx] < 0)
            {
                ans.push_back(idx + 1);
            }
            else
            {
                nums[idx] = -nums[idx];
            }
        }

        return ans;
    }

    // second approach
    //      vector<int> findDuplicates(vector<int> &nums)
    //      {
    //          vector<int> ans;
    //          int n = nums.size();
    //          unordered_map<int, int> mp;
    //          for (int i = 0; i < n; i++)
    //          {
    //              mp[nums[i]]++;
    //          }
    //          for (auto i : mp)
    //          {
    //              if (i.second > 1)
    //              {
    //                  ans.push_back(i.first);

    //             }
    //         }
    //         return ans;
    //     }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = s.findDuplicates(nums);
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}