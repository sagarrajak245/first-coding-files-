
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int lheight = 0;
        int rheight = 0;
        int maxarea = -1;
        int distance = 0;
        int r = n - 1;
        if (height.empty())
            return 0;
        for (int l = 0; l < r;)
        {
            lheight = height[l];
            rheight = height[r];
            distance = r - l;
            int aheight = min(height[l], height[r]);
            maxarea = max(maxarea, distance * aheight);

            // Move the pointer pointing to the shorter line inward
            if (lheight < rheight)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return maxarea;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int ans = s.maxArea(v);
    cout << "The max area is: " << ans << endl;
    return 0;
}