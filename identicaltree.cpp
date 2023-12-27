
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if (r1 == NULL && r2 == NULL)
        {
            return 1;
        }

        if (r1 == NULL && r2 != NULL)
        {
            return 0;
        }

        if (r1 != NULL && r2 == NULL)
        {
            return 0;
        }

        bool lidn = isIdentical(r1->left, r2->left);
        bool ridn = isIdentical(r1->right, r2->right);
        bool val = r1->data == r2->data;

        if (lidn && ridn && val)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};