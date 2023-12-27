#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
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

node *createtree(node *root) // creating using recursion
{
    int data;

    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "enter the data in left node" << endl;
    root->left = createtree(root->left);
    cout << "enter the data in right node" << endl;
    root->right = createtree(root->right);
    return root;
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

void inorder(node *root)
{ // lcr

    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// postorder

/* function to delete the given deepest node
(d_node) in binary tree */
void deletDeepest(node *root, struct node *d_node)
{
    queue<node *> q;
    q.push(root);

    // Do level order traversal until last node
    node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == d_node)
        {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right)
        {
            if (temp->right == d_node)
            {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }

        if (temp->left)
        {
            if (temp->left == d_node)
            {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}

node *deletion(node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
            return NULL;
        else
            return root;
    }

    queue<struct node *> q;
    q.push(root);

    struct node *temp;
    struct node *key_node = NULL;

    // Do level order traversal to find deepest
    // node(temp) and node to be deleted (key_node)
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == key)
            key_node = temp;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    if (key_node != NULL)
    {
        int x = temp->data;
        deletDeepest(root, temp);
        key_node->data = x;
    }
    return root;
}

int height(node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }
    if (root->right == NULL)
    {
        return height(root->left) + 1;
    }
    if (root->left == NULL)
    {
        return height(root->right) + 1;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);

    return max(lheight, rheight) + 1;
}

int main()
{
    node *root = NULL;
    root = createtree(root);
    // cout << "level order traversal" << endl;
    // levelorder(root); // level order traversal of tree using queue
    cout << "Inorder traversal is " << endl;
    inorder(root);

    cout << "the height of tree is " << height(root) << endl;

    return 0;
}
