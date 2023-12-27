#include <iostream>
using namespace std;

// basic of linked list,,,,,,

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

    // destructor bcoz we are using dynamic memory..
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

// 1 st method-- for middle..

int getlen(node *&head)
{

    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

node *getmiddle(node *&head)
{

    int len = getlen(head);
    int ans = len / 2;
    node *temp = head;
    int cnt = 0;
    while (cnt < ans)
    {
        temp = temp->next;
        cnt++;
    }

    return temp;
}

// SECOND METHOD==MOST OPTIMISE APPROACH use two pointer slow and fast mehod.....

node *middle(node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    if (head->next->next == NULL)
    {
        return head->next;
    }
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

int main()
{

    node *node1 = new node(10);
    node *tail = node1;
    node *head = node1;

    inserttail(tail, 100);

    inserttail(tail, 11);

    insertatmiddle(tail, head, 4, 20);

    inserttail(tail, 200);
    cout << endl;
    print(head);
    // cout << tail->next; // null update ho chuka hai....
    cout << endl;
    cout << endl;
    int length = getlen(node1);
    cout << "the len of linked list is"
         << ":" << length << endl;
    cout << endl;
    node *node2 = getmiddle(node1);
    cout << "the middle element of linked list is"
         << " " << node2->data << endl;
    cout << endl;
    cout << endl;

    node *node3 = middle(node1);
    cout << "the middle element of linked list from second method is"
         << " " << node3->data << endl;
    return 0;
}
