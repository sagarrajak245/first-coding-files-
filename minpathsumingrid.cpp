#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<vector<int>> dp; // Memoization table

    int solve(vector<vector<int>> &grid, int row, int col)
    {
        // Base condition: when you reach the top-left cell
        if (row == 0 && col == 0)
        {
            return grid[0][0];
        }

        // If out of bounds, return a large value (infinity)
        if (row < 0 || col < 0)
        {
            return INT_MAX;
        }

        // Check if the current cell has already been computed
        if (dp[row][col] != -1)
            return dp[row][col];

        // Recursive call for the minimum path from above or from the left
        int fromAbove = solve(grid, row - 1, col);
        int fromLeft = solve(grid, row, col - 1);

        // Store the result in the dp table and return it
        return dp[row][col] = grid[row][col] + min(fromAbove, fromLeft);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        // Initialize the memoization table with -1 to indicate uncomputed values
        dp = vector<vector<int>>(row, vector<int>(col, -1));

        // Start the recursion from the bottom-right corner
        return solve(grid, row - 1, col - 1);
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    Solution s;
    cout << s.minPathSum(grid) << endl;

    return 0;
}