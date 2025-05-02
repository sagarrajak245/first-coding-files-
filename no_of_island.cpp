
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int r, int c)
    {
        int rows = grid.size(), cols = grid[0].size();
        grid[r][c] = '0';
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto dir : directions)
        {
            int nr = dir.first + r;
            int nc = dir.second + c;

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1')
            {
                dfs(grid, nr, nc);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        if (grid.empty())
            return 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {

                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    int result = sol.numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}
//     return 0;