#include <iostream>
#include <vector>
using namespace std;

// code for number of path which have target sum K

struct Node
{
    int data;
    Node *left, *right;
};
https : // github.com/sagarrajak245/first-coding-files-.git
        class Solution
{
    void solve(Node *root, int k, int &cnt, vector<int> path)
    {
        .vscode / kthsumtree.cpp

                  if (root == NULL)
        {
            return;
        }
        path.push_back(root->data);

        solve(root->left, k, cnt, path);
        solve(root->right, k, cnt, path);

        int sum = 0;
        int size = path.size();
        for (int i = size - 1; i >= 0; i--)
        {

            sum = sum + path[i];
            if (sum == k)
            {
                cnt++;
            }
        }
        path.pop_back();
    }

public:
    int sumk(Node *root, int k)
    {
        vector<int> path;
        int cnt = 0;
        solve(root, k, cnt, path);
        return cnt;
    }
};

int main()
{

    return 0;
}