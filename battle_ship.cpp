#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Count number of battleships on a board

class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int row = board.size();
        int col = board[0].size();
        int count = 0;

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == '.')
                    continue;
                if (i > 0 && board[i - 1][j] == 'X')
                    continue; // part of vertical ship
                if (j > 0 && board[i][j - 1] == 'X')
                    continue; // part of horizontal ship
                count++;
            }
        }

        return count;
    }
};

int main()
{

    vector<vector<char>> board = {
        {'X', '.', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'.', '.', '.', 'X'}};
    Solution sol;
    int result = sol.countBattleships(board);

    cout << "Number of battleships: " << result << endl;

    return 0;
}
