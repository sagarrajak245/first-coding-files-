#include <iostream>
#include <vector>
using namespace std;

// code for kth ancestor
// first approach use path vector and retrive  required kth by iterating ove path vector
// but extra space is used

// so second approach
struct Node
{
    int data;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
    Node *left, *right;
};

class Solution
{

public:
    Node *solve(Node *root, int &k, int node)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data == node)
        {
            return root;
        }

        Node *lans = solve(root->left, k, node);
        Node *rans = solve(root->right, k, node);

        if (lans != NULL && rans == NULL)
        {

            k--;
            if (k <= 0)
            {
                k = INT_MAX; // ans lock
                return root;
            }
            return lans;
        }
        if (lans == NULL && rans != NULL)
        {

            k--;
            if (k <= 0)
            {
                k = INT_MAX; // ans lock
                return root;
            }
            return rans;
        }

        return NULL;
    }

    int sumk(Node *root, int k, int node)
    {
        Node *ans = solve(root, k, node);
        if (ans == NULL || ans->data == node) // Corrected condition
        {
            return -1;
        }
        else
        {
            return ans->data;
        }
    }
};

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);

    Solution s;
    cout << s.sumk(root, 3, 4);
    return 0;
}