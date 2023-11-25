#include <iostream>
using namespace std;
class node
{

public:
    int data;
    node *left;
    node *right;

    node(int data)
    {

        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *createtree(node *root)
{

    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the data in left node ";
    root->left = createtree(root->left);

    cout << "enter the data in right node ";
    root->right = createtree(root->right);

    return root;
}

void inorder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->right == NULL)
    {
        return (height(root->left)) + 1;
    }
    if (root->left == NULL)
    {
        return (height(root->right)) + 1;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight, rheight) + 1;
}

int main()
{
    node *root = NULL;
    root = createtree(root);

    cout << "inorder traversal is " << endl;
    inorder(root);
    cout << "\nheight is " << height(root);

    return 0;
}