
// path sum for targetted sum
#include <iostream>
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
    bool solve(TreeNode *root, int targetSum, int sum)
    {
        // Base case: check if the current node is a leaf node
        if (root == NULL)
        {
            return false;
        }

        // Update the sum with the current node's value
        sum = sum + root->val;

        // Check if the current node is a leaf node and if the sum equals the targetSum
        if (root->left == NULL && root->right == NULL && sum == targetSum)
        {
            return true;
        }

        // Recursively check for the targetSum in the left and right subtrees
        return solve(root->left, targetSum, sum) || solve(root->right, targetSum, sum);
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // Check if the root is NULL (empty tree)
        if (root == NULL)
        {
            return false;
        }

        // Start the recursion with the initial sum of 0
        return solve(root, targetSum, 0);
    }
};
