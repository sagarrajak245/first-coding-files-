#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs_fill(vector<vector<int>> &image, int r, int c, int originalColor, int newColor)
    {
        int rows = image.size();
        int cols = image[0].size();

        // Base case
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return;
        if (image[r][c] != originalColor || image[r][c] == newColor)
            return;

        // Recolor the pixel
        image[r][c] = newColor;

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto dir : directions)
        {
            int nr = r + dir.first;
            int nc = c + dir.second;
            dfs_fill(image, nr, nc, originalColor, newColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int originalColor = image[sr][sc];
        if (originalColor != color)
        {
            dfs_fill(image, sr, sc, originalColor, color);
        }
        return image;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    cout << "Modified Image:" << endl;
    for (const auto &row : result)
    {
        for (int pixel : row)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
