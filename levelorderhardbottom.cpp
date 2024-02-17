
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> ans;

        if (root == NULL)
            return {};

        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp;

            while (size--)
            {
                TreeNode *curr = q.front();
                q.pop();

                temp.push_back(curr->val);

                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *n1 = new TreeNode(9);
    TreeNode *n2 = new TreeNode(20);
    TreeNode *n3 = new TreeNode(15);
    TreeNode *n4 = new TreeNode(7);

    root->left = n1;
    root->right = n2;
    n2->left = n3;
    n2->right = n4;

    Solution s;
    vector<vector<int>> ans = s.levelOrderBottom(root);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}