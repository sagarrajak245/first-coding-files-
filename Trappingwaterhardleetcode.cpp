#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        if (n == 0)
            return 0; // edge case

        vector<int> lheight(n);
        vector<int> rheight(n);

        // fill left array

        lheight[0] = height[0];

        for (int i = 1; i < n; i++)
        {

            lheight[i] = max(lheight[i - 1], height[i]);
        }

        // fill right array

        rheight[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            rheight[i] = max(rheight[i + 1], height[i]);
        }

        int water = 0;
        int twater = 0;
        for (int i = 0; i < n; i++)
        {

            water = min(lheight[i], rheight[i]) - height[i];
            if (water > 0)
            {

                twater += water;
            }
        }

        return twater;
    }
};

int main()
{
    Solution s;
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ans = s.trap(v);
    cout << "The trapped water is: " << ans << endl;
    return 0;
}