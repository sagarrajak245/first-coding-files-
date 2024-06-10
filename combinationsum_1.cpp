#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// combination sum one leetcode

class Solution
{
public:
    vector<vector<int>> ans;

    void solve(int start, int sum, vector<int> &candidates, int target, vector<int> &temp)
    {

        // base case
        if (sum == target)
        {

            ans.push_back(temp);
            return;
        }
        // edge case
        if (sum > target)
        {
            return;
        }
        // recurse then backtrack
        for (int i = start; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]);                           // take the current element
            solve(i, sum + candidates[i], candidates, target, temp); // here not i+1 because we can take the same element again
            // for the next iteration
            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        solve(0, 0, candidates, target, temp);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = s.combinationSum(candidates, target);
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