#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// merge two binary trees

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *mergeTrees(node *root1, node *root2)
{
    if (root1 == NULL)
    {
        return root2;
    }
    if (root2 == NULL)
    {
        return root1;
    }
    root1->data += root2->data;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}

void levelorder(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;

    q.push(root); // initial  size di

    while (!q.empty())
    {

        node *temp = q.front();

        cout << temp->data << " ";

        q.pop();

        if (temp->left != NULL)
        {
            q.push(temp->left);
        }

        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root1 = new node(1);
    root1->left = new node(3);
    root1->right = new node(2);
    root1->left->left = new node(5);

    node *root2 = new node(2);
    root2->left = new node(1);
    root2->right = new node(3);
    root2->left->right = new node(4);
    root2->right->right = new node(7);

    node *root = mergeTrees(root1, root2);
    levelorder(root);
    return 0;
}
