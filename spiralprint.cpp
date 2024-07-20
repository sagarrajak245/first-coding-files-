
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.empty())
            return ans;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (left <= right && top <= bottom)
        {
            // Traverse from left to right along the top row
            for (int i = left; i <= right; ++i)
            {
                ans.push_back(matrix[top][i]);
            }
            ++top;

            // Traverse from top to bottom along the right column
            for (int i = top; i <= bottom; ++i)
            {
                ans.push_back(matrix[i][right]);
            }
            --right;

            // Traverse from right to left along the bottom row
            if (top <= bottom)
            {
                for (int i = right; i >= left; --i)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                --bottom;
            }

            // Traverse from bottom to top along the left column
            if (left <= right)
            {
                for (int i = bottom; i >= top; --i)
                {
                    ans.push_back(matrix[i][left]);
                }
                ++left;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = sol.spiralOrder(matrix);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}