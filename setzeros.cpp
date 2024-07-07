
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        unordered_set<int> rowsToZero;
        unordered_set<int> colsToZero;

        // Step 1: Identify rows and columns to be zeroed
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    rowsToZero.insert(i);
                    colsToZero.insert(j);
                }
            }
        }

        // Step 2: Zero out marked rows
        for (int r : rowsToZero)
        {
            for (int j = 0; j < col; ++j)
            {
                matrix[r][j] = 0;
            }
        }

        // Step 3: Zero out marked columns
        for (int c : colsToZero)
        {
            for (int i = 0; i < row; ++i)
            {
                matrix[i][c] = 0;
            }
        }
    }
};

int main()
{

    Solution s;

    return 0;
}