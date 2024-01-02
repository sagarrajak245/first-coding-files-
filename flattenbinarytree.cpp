#include <iostream>
#include <algorithm>

using namespace std;

// my code

/*
 class Solution {
public:
    void flatten(TreeNode* root) {
        if (root==NULL){
            return ;
        }
TreeNode* curr=root;
while(curr!=NULL){

if(curr->left){
 TreeNode* pred= curr->left;
while(pred->right!=NULL){
    pred=pred->right;
}
pred->right=curr->right;
curr->right=curr->left;
curr->left=NULL;
}

curr=curr->right;
}


    }
};  */

/*
optimised mine

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        flattenHelper(root);
    }

private:
    TreeNode* flattenHelper(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        // Save right subtree
        TreeNode* rightSubtree = root->right;

        // Flatten left subtree
        TreeNode* flattenedLeft = flattenHelper(root->left);

        // Connect the flattened left subtree to the right
        root->right = flattenedLeft;

        // Make the left subtree NULL
        root->left = NULL;

        // Find the rightmost node of the flattened left subtree
        TreeNode* rightmost = root;
        while (rightmost != NULL && rightmost->right != NULL) {
            rightmost = rightmost->right;
        }

        // Connect the right subtree to the rightmost node of the flattened left subtree
        rightmost->right = rightSubtree;

        // Continue flattening the right subtree
        flattenHelper(rightSubtree);

        return root;
    }
};
*/

// best solution
// this code will make right skew tree
// and will work like linked list 
//space is O(1)
// time is O(n)
struct TreeNode
{
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    int val = 0;
};

class Solution
{
private:
    TreeNode *pre = nullptr;

public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
};
flattenbinarytree
