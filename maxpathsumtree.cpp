

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int solve(TreeNode *root, int &sum)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = solve(root->left, sum);
        int right = solve(root->right, sum);
        // root is not include and without negatuve edge ans

        int temp = max(root->val + max(left, right), root->val);

        // root included
        int ans = max(temp, left + right + root->val);
        sum = max(ans, sum);

        return temp;
    }

    int maxPathSum(TreeNode *root)
    {
        int sum = INT_MIN;
        // Initialize max_len to 0
        solve(root, sum);
        return sum;
    }
};

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    Solution s;
    cout << s.maxPathSum(root) << endl;
    return 0;
}
