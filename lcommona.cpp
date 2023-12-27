
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    Node *lca(Node *root, int n1, int n2)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data == n1 || root->data == n2)
        {
            return root;
        }

        Node *lans = lca(root->left, n1, n2);
        Node *rans = lca(root->right, n1, n2);

        if (lans != NULL && rans != NULL)
        {
            return root;
        }
        else if (rans != NULL && lans == NULL)
        {
            return rans;
        }

        else if (lans != NULL && rans == NULL)
        {
            return lans;
        }

        else
        {
            return NULL;
        }
    }
};

int main()
{

    return 0;
}