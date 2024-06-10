

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// combination sum two leetcode

class Solution
{
public:
    vector<vector<int>> ans;

    void solve(int start, int sum, vector<int> &candidates, int target, vector<int> &temp)
    {
        // Base case: if sum is equal to target, add the current combination to the results
        if (sum == target)
        {
            ans.push_back(temp);
            return;
        }

        // If sum exceeds target, there's no point in continuing
        if (sum > target)
            return;

        for (int i = start; i < candidates.size(); i++)
        {
            // Skip duplicate elements
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Take the current element
            temp.push_back(candidates[i]);

            // Move to the next element, and include the current element in the sum
            solve(i + 1, sum + candidates[i], candidates, target, temp);

            // Backtrack: remove the last element before the next iteration
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> temp;
        sort(candidates.begin(), candidates.end()); // Sort the candidates to handle duplicates
        int sum = 0;
        solve(0, sum, candidates, target, temp);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
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