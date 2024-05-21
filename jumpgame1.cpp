#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int maxireach = 0;

        if (n == 1)
            return true; // edge case

        for (int i = 0; i < n; i++)
        {

            if (i > maxireach)
                return false;

            maxireach = max(maxireach, i + nums[i]);
        }

        if (maxireach >= n - 1)
            return true;

        return false;
    }
};

int main()
{

    Solution s;
    // vector<int> v = {2, 3, 1, 1, 4};

    vector<int> v = {3, 2, 1, 0, 4};

    bool ans = s.canJump(v);

    if (ans)
    {
        cout << "the jump is possible to the last index" << endl;
    }
    else
    {
        cout << "the jump is not  possible to the last index" << endl;
    }

    return 0;
}
