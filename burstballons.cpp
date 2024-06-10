// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// class Solution
// {
// public:
//     int findMinArrowShots(vector<vector<int>> &points)
//     {
//         int n = points.size();
//         if (n == 0)
//             return 0;

//         // Sort intervals by their end points
//         sort(points.begin(), points.end());
//         // At least one arrow is needed
//         int arrows = 1;
//         int end = points[0][1];

//         // Iterate through the sorted intervals
//         for (int i = 1; i < n; ++i)
//         {
//             // If the current interval starts after the end of the last burst interval
//             if (points[i][0] > end)
//             {
//                 // Increment the number of arrows
//                 arrows++;
//                 // Update the end to the end of the current interval
//                 end = points[i][1];
//             }
//         }

//         return arrows;
//     }
// };

// int main()
// {
//     Solution sol;
//     vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
//     int result = sol.findMinArrowShots(points);
//     cout << "Minimum number of arrows needed: " << result << endl;
//     return 0;
// }

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        // Sort intervals by their start points
        sort(points.begin(), points.end());

        vector<vector<int>> ans;
        vector<int> temp = points[0];

        for (const auto &it : points)
        {
            if (it[0] <= temp[1])
            {
                // Merge intervals by updating the end of temp
                temp[1] = min(it[1], temp[1]);
            }
            else
            {
                // No overlap, push temp to ans and update temp to current interval
                ans.push_back(temp);
                temp = it;
            }
        }

        // Add the last interval
        ans.push_back(temp);

        // The number of merged intervals is the number of arrows needed
        return ans.size();
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int result = sol.findMinArrowShots(points);
    cout << "Minimum number of arrows needed: " << result << endl;
    return 0;
}
