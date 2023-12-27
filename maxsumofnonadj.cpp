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
    Node *left, *right;
};

class Solution
{

public:
    Node *solve(Node *root, int &k, int node)

    {
    }

    int sumk(Node *root, int k, int node)
    {

        Node *ans = solve(root, k, node);
    }
};
