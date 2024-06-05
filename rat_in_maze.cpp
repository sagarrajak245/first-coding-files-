#include <bits/stdc++.h>
using namespace std;

// Initialize a string direction which represents all the
// directions.
string direction = "DLRU";

// Arrays to represent change in rows and columns
int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, -1, 1, 0};

// Function to check if cell(row, col) is inside the maze
// and unblocked
bool isValid(int row, int col, int n, vector<vector<int>> &maze)
{
    return row >= 0 && col >= 0 && row < n && col < n && maze[row][col];
}

// Function to get all valid paths
void findPath(int row, int col, vector<vector<int>> &maze,
              int n, vector<string> &ans,
              string &currentPath)
{
    // If we reach the destination, we add the current path
    // to the result vector
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(currentPath);
    }
    for (int i = 0; i < n; i++)
    {

        int newrow = row + dr[i];
        int newcol = col + dc[i];
        bool path = isValid(newrow, newcol, n, maze);

        if (path)
        {

            maze[row][col] = 0; // mark visited

            currentPath.push_back(direction[i]);
            findPath(newrow, newcol, maze, n, ans, currentPath);

            // backtrack
            // mark unvisited
            maze[row][col] = 1;
            currentPath.pop_back();
        }
    }
}

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    int n = maze.size();
    // vector to store all the valid paths
    vector<string> result;
    // Store current path
    string currentPath = "";

    if (maze[0][0] != 0 && maze[n - 1][n - 1] != 0)
    {
        // Function call to get all valid paths
        findPath(0, 0, maze, n, result, currentPath);
    }

    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    cout << endl;

    return 0;
}
