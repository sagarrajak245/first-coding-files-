#include <iostream>
using namespace std;

// basic of linked list,,,,,,
// node ek block hai jo sirf ek part me data and other part me addressstore karta hai....
class node
{

public:
    int data;
    node *next;
    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor bcoz we are using dynamic memory
    ~node()
    {

        if (this->next != NULL)
        {

            delete next;
            this->next = NULL;
        }
    }
};

void insertathead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void inserttail(node *&tail, int d)
{
    node *temp = new node(d);

    tail->next = temp;
    tail = temp;
}

void insertatmiddle(node *&tail, node *&head, int position, int data)
{
    node *temp = head;
    int cnt = 1;

    if (position == 1)
    {

        insertathead(head, data);
        return;
    }

    while (cnt < position - 1)
    {
        cnt++;
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        inserttail(tail, data);
        return;
    }
    node *nodetoinsert = new node(data);

    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void deletetion(int position, node *&head)
{

    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
    // for all middle and last position deletetion

    else
    {
        node *curr = head;
        node *prev = NULL; // ye ek empty node hai jo sirf desire node tak pahuchne ke liye banya tha
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

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;

        temp = temp->next;
    }
}
// 1st method--- recursive solution for reversing linked list........
node *rev(node *&head)
{

    // base case..
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *shead = rev(head->next);
    head->next->next = head;
    head->next = NULL;
    return shead;
}

// 2 nd method--- iterative approach...
node *rev2(node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *prev = NULL;
    node *curr = head;
    node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

int main()
{

    node *node1 = new node(10);
    node *tail = node1;
    node *head = node1;
    /* insertathead(node1, 12);
     insertathead(node1, 13);
     insertathead(node1, 14);
     insertathead(node1, 15);*/

    inserttail(tail, 100);

    inserttail(tail, 11);

    insertatmiddle(tail, head, 4, 20);

    inserttail(tail, 200);
    print(head);
    // cout << tail->next; // null update ho chuka hai....
    cout << endl;
    cout << endl;
    node *node2 = rev2(node1);
    cout << "linked list after the first rev is(using iterative approach) " << endl;
    print(node2);
    cout << endl;

    // node *d3 = new node(-1);  // dummynode
    // cout << d3;

    return 0;
}