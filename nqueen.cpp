#include <iostream>
#include <vector>

using namespace std;

// Function to check if a queen can be placed on board[row][col]
bool isSafe(vector<vector<int>> &board, int row, int col)
{
    int n = board.size();

    // Check this row on the left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N Queens problem
bool solveNQueensUtil(vector<vector<int>> &board, int col)
{
    int n = board.size();

    // Base case: If all queens are placed, return true
    if (col >= n)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col))
        {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueensUtil(board, col + 1))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution, then backtrack
            board[i][col] = 0; // BACKTRACK
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

// Function to solve the N Queens problem
bool solveNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solveNQueensUtil(board, 0))
    {
        cout << "Solution does not exist" << endl;
        return false;
    }

    // Print the solution
    for (const auto &row : board)
    {
        for (int cell : row)
            cout << (cell ? "Q " : ". ");
        cout << endl;
    }
    return true;
}

// Main function to test the N Queens solution
int main()
{
    int n = 4; // Size of the board (N x N)
    solveNQueens(n);
    return 0;
}
