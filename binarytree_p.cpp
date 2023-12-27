#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
// Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).
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
    cout << "enter the tree data" << endl;
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

vector<int> levelorder(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<node *> q;

    q.push(root); // initial  size di

    while (!q.empty())
    {
        int size = q.size();

        node *temp = q.front();
        for (int i = 0; i < size; i++)
        {
            ans.push_back(temp->data);
            cout << "im here";
        }
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

    return ans;
}
vector<vector<int>> store(node *root)
{
    vector<vector<int>> p;
    vector<int> ans = levelorder(root);
    p.push_back(ans);
    return p;
}

int main()
{
    node *root = NULL;
    root = createtree(root);

    cout << "level order traversal is " << endl;
    // levelorder(root);
    // cout << "\nheight is " << height(root);
    vector<vector<int>> p = store(root);
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = 0; j < p[i].size(); j++)
        {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}