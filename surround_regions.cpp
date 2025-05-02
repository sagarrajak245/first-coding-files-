
#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &board, int r, int c)
    {
        int rows = board.size();
        int cols = board[0].size();

        // Mark the current cell as visited by changing 'O' to 'S'
        board[r][c] = 'S';

        // Directions for up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Perform DFS for all 4 directions
        for (auto dir : directions)
        {
            int nr = r + dir.first;
            int nc = c + dir.second;

            // Check bounds and if the next cell is 'O'
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 'O')
            {
                dfs(board, nr, nc); // Recursively visit the connected 'O' cells
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int rows = board.size();
        if (rows == 0)
            return;
        int cols = board[0].size();

        // Step 1: Perform DFS from the borders to mark safe 'O' cells
        // Top and bottom rows
        for (int i = 0; i < cols; ++i)
        {
            if (board[0][i] == 'O')
                dfs(board, 0, i); // Top border
            if (board[rows - 1][i] == 'O')
                dfs(board, rows - 1, i); // Bottom border
        }

        // Left and right columns
        for (int i = 0; i < rows; ++i)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0); // Left border
            if (board[i][cols - 1] == 'O')
                dfs(board, i, cols - 1); // Right border
        }

        // Step 2: Capture all surrounded 'O' cells and restore safe 'O' cells
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X'; // Flip surrounded 'O' to 'X'
                }
                else if (board[i][j] == 'S')
                {
                    board[i][j] = 'O'; // Restore the safe 'O'
                }
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    sol.solve(board);

    // Print the modified board
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
// Output: