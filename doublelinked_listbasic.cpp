#include <iostream>
using namespace std;

// double linked list basic....
class node
{

public:
    int data;
    node *next;
    node *prev;

    // constructor

    node(int d)
    {

        this->data = d;
        this->next = NULL;
        this->prev = NULL;
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

void insertathead(node *&tail, node *&head, int d)
{
    if (head == NULL)
    {

        node *temp = new node(d);
        head = temp;
    }
    else
    {
        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertattail(node *&head, node *&tail, int d)
{

    if (tail == NULL)
    {
        node *temp = new node(d);
        tail = temp;
    }

    else
    {
        node *temp = new node(d);
        tail->next = temp;
        temp->prev = tail->next;
        tail = temp;
    }
}

void insertatmiddle(node *&tail, node *&head, int position, int d)
{

    if (position == 1)
    {

        insertathead(tail, head, d);
        return;
    }
    node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {

        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertattail(head, tail, d);
        return;
    }

    node *nodetoinsert = new node(d);

    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}

void print(node *&head)
{

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void deletenode(int position, node *head)
{

    if (position == 1)
    {
        node *temp = head;

        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;

        delete temp;
    }

    else
    {
        node *curr = head;
        node *prev = NULL; // ye ek empty node pointer hai jo sirf desire node tak pahuchne ke liye banya tha
        int cnt = 1;
        while (cnt < position)
        {

            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

int main()
{

    node *node1 = new node(5);
    node *head = node1;
    node *tail = node1;

    print(tail);
    insertattail(head, tail, 25);
    print(tail);
    /*insertathead(head, 15);
     insertathead(head, 15);
     insertathead(head, 15);
     insertathead(head, 15);
     insertatmiddle(tail, head, 3, 56);
     print(head);*/

    insertattail(head, tail, 50);
    print(tail);

    insertattail(head, tail, 75);
    print(tail);

    cout << endl;
    insertatmiddle(tail, head, 3, 56);
    print(head);
    cout << endl
         << endl;
    deletenode(3, head);
    print(head);

    return 0;
}