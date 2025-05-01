#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// rotten oranges problem

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        int rows = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        // step 1
        // fill the queue with rotten oranges

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        // step 2
        // if there are no fresh oranges, return 0
        if (fresh == 0)
        {
            return 0;
        }

        // step 3
        // if there are no rotten oranges, return -1
        if (q.empty())
        {
            return -1;
        }

        int time = 0;
        // step 4
        // bfs
        // directons
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while ((!q.empty()))
        {

            int size = q.size();
            bool rotten = false;
            // step 5
            // for each rotten oranges check neighbour

            for (int i = 0; i < size; i++)
            {
                pair<int, int> single_node = q.front();
                q.pop();

                int dr = single_node.first;
                int dc = single_node.second;
                // check all 4 directions
                for (auto dir : directions)
                {
                    int new_row = dr + dir.first;
                    int new_col = dc + dir.second;
                    // check if the new position is valid
                    if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < col && grid[new_row][new_col] == 1)
                    {
                        // if it is valid, make it rotten
                        grid[new_row][new_col] = 2;
                        // push it to the queue
                        q.push({new_row, new_col});
                        // decrease the count of fresh oranges
                        fresh--;
                        rotten = true;
                    }
                }
                        }

            // if there are rotten oranges, increase the time
            if (rotten)
            {
                time++;
            }
        }

        // step 6
        // if there are still fresh oranges, return -1
        if (fresh > 0)
        {
            return -1;
        }
        // step 7
        // return the time taken to rot all oranges
        return time;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int result = sol.orangesRotting(grid);
    cout << "Time taken to rot all oranges: " << result << endl;

    return 0;
}