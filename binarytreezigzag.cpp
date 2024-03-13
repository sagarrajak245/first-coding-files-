
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return {};
        }
        queue<TreeNode *> q;
        bool ltor = true;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> p;

            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                p.push_back(temp->val);

                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            if (!ltor)
            {
                reverse(p.begin(), p.end());
            }
            ans.push_back(p);
            ltor = !ltor;
        }
        return ans;
    }
};