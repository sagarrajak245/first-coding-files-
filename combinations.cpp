
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> result;

    void solve(int start, int n, int k, vector<int> &temp)
    {
        // Base case: if k is 0, we have a valid combination
        if (k == 0)
        {
            result.push_back(temp);
            return;
        }

        // Base case: if start is greater than n, return
        if (start > n)
            return;

        // Take the current item
        temp.push_back(start);
        solve(start + 1, n, k - 1, temp);
        temp.pop_back(); // backtrack

        // Do not take the current item
        solve(start + 1, n, k, temp);
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        solve(1, n, k, temp);
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> result = s.combine(4, 2);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
