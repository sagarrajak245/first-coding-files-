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

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 0;
        if (n == 1) return 1;

        // Sort intervals by their end points
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;  // At least one arrow is needed
        int end = points[0][1];  // First balloon burst position

        for (const auto& balloon : points) {
            if (balloon[0] > end) {
                // A new arrow is needed
                arrows++;
                end = balloon[1];  // Update end to new balloon burst position
            }
        }

        return arrows;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int result = sol.findMinArrowShots(points);
    cout << "Minimum number of arrows needed: " << result << endl;
    return 0;
}

