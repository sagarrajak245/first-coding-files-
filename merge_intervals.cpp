
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        vector<vector<int>> ans;

        // edge case

        if (intervals.size() == 0)
        {
            return intervals;
        }

        // sort the intervals

        sort(intervals.begin(), intervals.end());
        // make temp intervals for comaprisions
        vector<int> temp = intervals[0];
        // check merge

        for (auto it : intervals)
        {

            if (it[0] <= temp[1])
            {
                temp[1] = max(it[1], temp[1]);
            }
            else
            {
                ans.push_back(temp);
                temp = it;
            }
        }

        ans.push_back(temp);
        return ans;
    }
};
//{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
int main()
{
    Solution s;
    vector<vector<int>> intervals = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    vector<vector<int>>
        ans = s.merge(intervals);
    for (auto it : ans)
    {
        cout << "[" << it[0] << "," << it[1] << "]";
    }

    cout << "\nthe size: " << ans.size() << endl;
    return 0;
}