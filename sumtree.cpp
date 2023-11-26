#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
    pair<bool, int> isSumTF(Node *root)
    {
        if (root == NULL)
        {
            return make_pair(true, 0);
        }
        if (root->left == NULL && root->right == NULL)
        {
            return make_pair(true, root->data);
        }

        pair<bool, int> left = isSumTF(root->left);
        pair<bool, int> right = isSumTF(root->right);

        bool leftans = left.first;
        bool rightans = right.first;

        bool val = root->data == left.second + right.second;

        pair<bool, int> ans;
        if (leftans && rightans && val)
        {
            ans.first = true;
            ans.second = 2 * root->data;
        }
        else
        {
            ans.first = false;
            ans.second = 0;
        }
        return ans;
    }

public:
    bool isSumTree(Node *root)
    {
        return isSumTF(root).first;
    }
};