#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int count = 0;

        while (true)
        {
            unordered_set<int> s(nums.begin(), nums.end());

            // If all elements are distinct
            if (s.size() == nums.size())
            {
                break;
            }

            // Remove first 3 elements (or all if less than 3)
            int removeCount = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + removeCount);
            count++;
        }

        return count;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 4, 4, 5};
    int result = sol.minimumOperations(nums);
    cout << "Minimum operations to make all elements distinct: " << result << endl;

    return 0;
}
