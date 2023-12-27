#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

class node
{

    int data;
    node *next;

    // constructor
    node(int val)
    {
        this->data = val;
        this->next = NULL;
    }

    // destructor
    ~node()
    {

        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void insertAtHead(node *&head, int val)
{
}

int main()

{

    return 0;
}