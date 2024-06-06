#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;

        // If newInterval is not empty and intervals is empty, just return the newInterval.
        if (!newInterval.empty() && intervals.empty())
        {
            ans.push_back(newInterval);
            return ans;
        }

        // If newInterval is empty or intervals is empty, handle accordingly.
        if (newInterval.empty())
        {
            return intervals;
        }

        if (intervals.empty())
        {
            ans.push_back(newInterval);
            return ans;
        }

        // Add the newInterval to the list of intervals
        intervals.push_back(newInterval);
        // Sort intervals based on the starting time
        sort(intervals.begin(), intervals.end());

        // Use a temporary interval for merging
        vector<int> temp = intervals[0];

        for (auto &it : intervals)
        {
            if (it[0] <= temp[1])
            {
                // If intervals overlap, merge them
                temp[1] = max(it[1], temp[1]);
            }
            else
            {
                // If they don't overlap, add the current temp to the answer and move to the next interval
                ans.push_back(temp);
                temp = it;
            }
        }

        // Add the last interval
        ans.push_back(temp);

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> result = sol.insert(intervals, newInterval);

    for (const auto &interval : result)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    return 0;
}
